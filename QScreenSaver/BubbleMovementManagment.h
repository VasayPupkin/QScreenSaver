#ifndef BUBBLEMOVEMENTMANAGMENT_H
#define BUBBLEMOVEMENTMANAGMENT_H

#include <QObject>
#include <QTimer>

#include <list>
#include <memory>
#include <cmath>

#include "BubbleShape.h"

#define MIN_RADIUS 5
#define MAX_RADIUS 50
#define MIN_COURSE 1
#define MAX_COURSE 359
#define MIN_COLOR_CODE 0
#define MAX_COLOR_CODE 255

#define MOVE_DELTA 10
#define DEG_TO_RAD(X) ((X)*M_PI)/180


using BubblePtr = std::shared_ptr<BubbleShape>;
using BubblePtrList = std::list<BubblePtr>;

struct Frame{
    //Y-coordinate
    int _top;
    int _bottom;
    //X-coordinate
    int _left;
    int _right;
};

enum class BarrierType : uchar
{
    NO_BARRIER,
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

class BubbleMovementManagment : public QObject
{
    Q_OBJECT
public:
    explicit BubbleMovementManagment(const Frame &window_frame,
                                     const int movement_interval,
                                     QObject *parent = nullptr);

private:
    void CreateMovementTimer();
    BubblePtr CreateRndBubble();
    void CreateBubbleList();
    void Start();

    static int GenerateRndValue(const int lower_bounde, const int upper_bounde);

    bool CheckFrameCollision(BubblePtr bubble_ptr, BarrierType &barrier);
    Frame CalculateNextStep(BubblePtr bubble_ptr);
    void DoNextStep(BubblePtr bubble_ptr);
    void ChangeBubbleCourse(BubblePtr bubble_ptr, const BarrierType &barrier);

signals:

public slots:
    void RecalculateBubblesPositions();

private:
    Frame _window_frame;
    int _movement_interval;

    BubblePtrList _bubble_ptr_list;
    std::unique_ptr<QTimer> _movement_timer;

};

#endif // BUBBLEMOVEMENTMANAGMENT_H
