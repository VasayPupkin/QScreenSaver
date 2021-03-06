#include "BubbleMovementManagment.h"

#include <ctime>
#include <assert.h>

BubbleMovementManagment::BubbleMovementManagment(const int movement_interval, QObject *parent) :
    QObject(parent),
    _movement_interval{movement_interval}
{
    CreateMovementTimer();
}

void BubbleMovementManagment::CreateMovementTimer()
{
    _movement_timer.reset(new QTimer());
    _movement_timer.get()->setInterval(_movement_interval);
    connect(_movement_timer.get(), SIGNAL(timeout()),SLOT(RecalculateBubblesPositions()));
}

BubblePtr BubbleMovementManagment::CreateRndBubble()
{
//    static int x = 0;
//    x += 20;
//    int radius = GenerateRndValue(MIN_RADIUS, MAX_RADIUS);
    int radius = 20;
//    VectorCoordinate vector_course(GenerateRndValue(MIN_COURSE_VECTOR_VALUE,MAX_COURSE_VECTOR_VALUE),
//                                   GenerateRndValue(MIN_COURSE_VECTOR_VALUE,MAX_COURSE_VECTOR_VALUE));
//    assert(vector_course.first != 0 && "vetor_course.x == 0");
//    assert(vector_course.second != 0 && "vetor_course.y == 0");
    VectorCoordinate vector_course(0,0);
//    Coordinate centr(GenerateRndValue(0, _window_frame._width/2),
//                     GenerateRndValue(0,_window_frame._height/2));
    static int d = 0;
    Coordinate centr(0+d,0+d);//TODO must be rnd generate
    d += 200;

//    QColor bubbleColor(static_cast<Qt::GlobalColor>(GenerateRndValue(MIN_COLOR_CODE, MAX_COLOR_CODE)));
    QColor bubbleColor(Qt::GlobalColor::darkBlue);
    BubblePtr bubble(new BubbleShape(radius, vector_course, centr, bubbleColor));
    return std::move(bubble);
}

void BubbleMovementManagment::CreateBubbleList()
{
    _bubble_ptr_list.push_back(CreateRndBubble());
    _bubble_ptr_list.push_back(CreateRndBubble());
//    _bubble_ptr_list.push_back(CreateRndBubble());
//    _bubble_ptr_list.push_back(CreateRndBubble());
//    _bubble_ptr_list.push_back(CreateRndBubble());
}

void BubbleMovementManagment::Start()
{
    CreateBubbleList();
    _movement_timer.get()->start();
}

int BubbleMovementManagment::GenerateRndValue(const int lower_bounde, const int upper_bounde)
{
    static unsigned int pseudo_rnd = rand();
    pseudo_rnd += 20;
    srand(time(NULL) + pseudo_rnd);
    return(lower_bounde + (rand() % (upper_bounde - lower_bounde + 1)));
}

bool BubbleMovementManagment::CheckFrameCollision(BubblePtr &bubble_ptr, BarrierType &barrier)
{
    bool result = false;
    int delta_top = bubble_ptr.get()->get_top() - _window_frame._top;
    int delta_bottom = _window_frame._bottom - bubble_ptr.get()->get_bottom();
    int delta_left = bubble_ptr.get()->get_left() - _window_frame._left;
    int delta_right = _window_frame._right - bubble_ptr.get()->get_right();

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

void BubbleMovementManagment::DoNextStep(BubblePtr &bubble_ptr)
{
    Coordinate centr_coord = bubble_ptr.get()->get_centr_coord();
    float float_delta{0.01};
    float divider{4.0};
    float lambda = bubble_ptr.get()->get_course_vector_module()/(bubble_ptr.get()->get_radius()/divider);
    if(fabsf(0 - lambda) >= float_delta){
        VectorCoordinate move_vector;
        move_vector.first = static_cast<int>(ceilf(bubble_ptr.get()->get_course_vector().first/lambda));
        move_vector.second = static_cast<int>(ceilf(bubble_ptr.get()->get_course_vector().second/lambda));
        centr_coord.first += move_vector.first;
        centr_coord.second += move_vector.second;
        //    centr_coord.first += bubble_ptr.get()->get_course_vector().first;
        //    centr_coord.second += bubble_ptr.get()->get_course_vector().second;
    }
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
    emit RepaintBubbles(_bubble_ptr_list);
}

void BubbleMovementManagment::SetFrame(Frame &win_frame)
{
    _window_frame = win_frame;
}
