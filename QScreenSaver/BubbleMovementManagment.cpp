#include "BubbleMovementManagment.h"

#include <ctime>

BubbleMovementManagment::BubbleMovementManagment(const Frame &window_frame, const int movement_interval, QObject *parent) :
    QObject(parent),
    _window_frame(window_frame),
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
    int course = GenerateRndValue(MIN_COURSE, MAX_COURSE);
    Coordinate centr(10 + radius, 10 + radius);//TODO must be rnd generate
    int r_color = GenerateRndValue(MIN_COLOR_CODE, MAX_COLOR_CODE);
    int g_color = GenerateRndValue(MIN_COLOR_CODE, MAX_COLOR_CODE);
    int b_color = GenerateRndValue(MIN_COLOR_CODE, MAX_COLOR_CODE);
    QColor bubbleColor(r_color, g_color, b_color);
    BubblePtr bubble(new BubbleShape(radius, course, centr, bubbleColor));
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

}

Frame BubbleMovementManagment::CalculateNextStep(BubblePtr bubble_ptr)
{
    Frame bubble_frame;
    bubble_frame._top = bubble_ptr.get()->get_upper_boundary();
    bubble_frame._bottom = bubble_ptr.get()->get_lower_boundary();
    bubble_frame._left = bubble_ptr.get()->get_left_boundary();
    bubble_frame._right = bubble_ptr.get()->get_right_boundary();
    Coordinate centr_coord = bubble_ptr.get()->get_centr_coord();
    centr_coord.first += ceil(MOVE_DELTA*(cos(DEG_TO_RAD(bubble_ptr.get()->get_course()))));
    centr_coord.second += ceil(MOVE_DELTA*(sin(DEG_TO_RAD(bubble_ptr.get()->get_course()))));

}

void BubbleMovementManagment::DoNextStep(BubblePtr bubble_ptr)
{
    Coordinate centr_coord = bubble_ptr.get()->get_centr_coord();
    centr_coord.first += ceil(MOVE_DELTA*(cos(DEG_TO_RAD(bubble_ptr.get()->get_course()))));
    centr_coord.second += ceil(MOVE_DELTA*(sin(DEG_TO_RAD(bubble_ptr.get()->get_course()))));
    bubble_ptr.get()->set_centr_coord(centr_coord);
    BarrierType barrier;
    if (!CheckFrameCollision(bubble_ptr, barrier)) {
        ChangeBubbleCourse(bubble_ptr, barrier);
    }
}

void BubbleMovementManagment::ChangeBubbleCourse(BubblePtr bubble_ptr, const BarrierType &barrier)
{
    int course = bubble_ptr.get()->get_course();
    switch (static_cast<int>(barrier)) {
    case static_cast<int>(BarrierType::TOP):
    {

    }
        break;
    case static_cast<int>(BarrierType::BOTTOM):
    {}
        break;
    case static_cast<int>(BarrierType::LEFT):
    {}
        break;
    case static_cast<int>(BarrierType::RIGHT):
    {}
        break;
    default:
        break;
    }

}

void BubbleMovementManagment::RecalculateBubblesPositions()
{

}
