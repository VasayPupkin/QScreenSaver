#include "BubbleMovementManagment.h"

#include <ctime>

BubbleMovementManagment::BubbleMovementManagment(const int movement_interval, QObject *parent) :
    QObject(parent),
    _movement_interval{movement_interval}
{
    CreateMovementTimer();
    CreateBubbleList();
}

void BubbleMovementManagment::CreateMovementTimer()
{
    _movement_timer.reset(new QTimer());
    _movement_timer.get()->setInterval(_movement_interval);
    connect(_movement_timer.get(), SIGNAL(timeout()),SLOT(RecalculateBubblesPositions()));
}

BubblePtr BubbleMovementManagment::CreateRndBubble()
{
    int radius = GenerateRndValue(MIN_RADIUS, MAX_RADIUS);
    VectorCoordinate vector_course(GenerateRndValue(MIN_COURSE_VECTOR_VALUE,MAX_COURSE_VECTOR_VALUE),
                                   GenerateRndValue(MIN_COURSE_VECTOR_VALUE,MAX_COURSE_VECTOR_VALUE));
    Coordinate centr(10 + radius, 10 + radius);//TODO must be rnd generate
    int r_color = GenerateRndValue(MIN_COLOR_CODE, MAX_COLOR_CODE);
    int g_color = GenerateRndValue(MIN_COLOR_CODE, MAX_COLOR_CODE);
    int b_color = GenerateRndValue(MIN_COLOR_CODE, MAX_COLOR_CODE);
    QColor bubbleColor(r_color, g_color, b_color);
    BubblePtr bubble(new BubbleShape(radius, vector_course, centr, bubbleColor));
    return std::move(bubble);
}

void BubbleMovementManagment::CreateBubbleList()
{
    _bubble_ptr_list.push_back(CreateRndBubble());
}

void BubbleMovementManagment::Start()
{
    _movement_timer.get()->start();
}

int BubbleMovementManagment::GenerateRndValue(const int lower_bounde, const int upper_bounde)
{
    srand(time(NULL));
    return(rand() % upper_bounde + lower_bounde);
}

bool BubbleMovementManagment::CheckFrameCollision(BubblePtr bubble_ptr, BarrierType &barrier)
{
    bool result = false;
    int delta_top = _window_frame._top - bubble_ptr.get()->get_upper_boundary();
    int delta_bottom = bubble_ptr.get()->get_lower_boundary() - _window_frame._bottom;
    int delta_left = bubble_ptr.get()->get_left_boundary() - _window_frame._left;
    int delta_right = _window_frame._right - bubble_ptr.get()->get_right_boundary();
    //TODO:check the case, when several delta are equal. maybe use multimap
    std::map<int, BarrierType> negativ_map;
    if (delta_top <= 0)
        negativ_map[delta_top] = BarrierType::TOP;
    if (delta_bottom <= 0)
        negativ_map[delta_bottom] = BarrierType::BOTTOM;
    if (delta_left <= 0)
        negativ_map[delta_left] = BarrierType::LEFT;
    if (delta_right <= 0)
       negativ_map[delta_right] = BarrierType::RIGHT;
    if (negativ_map.empty()) {
        barrier = BarrierType::NO_BARRIER;
        result = true;
    } else
        barrier = negativ_map.rbegin()->second;

    return result;
}

void BubbleMovementManagment::DoNextStep(BubblePtr bubble_ptr)
{
    Coordinate centr_coord = bubble_ptr.get()->get_centr_coord();
    centr_coord.first += bubble_ptr.get()->get_course_vector().first;
    centr_coord.second += bubble_ptr.get()->get_course_vector().second;
    bubble_ptr.get()->set_centr_coord(centr_coord);
    BarrierType barrier;
    if (!CheckFrameCollision(bubble_ptr, barrier)) {
        bubble_ptr.get()->change_bubble_course(barrier);
    }
}

void BubbleMovementManagment::RecalculateBubblesPositions()
{
    for(auto bubble : _bubble_ptr_list){
        DoNextStep(bubble);
    }
}

void BubbleMovementManagment::SetFrame(const Frame &win_frame)
{
    _window_frame = win_frame;
}
