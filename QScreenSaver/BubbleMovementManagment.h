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
#define MIN_COURSE_VECTOR_VALUE 5
#define MAX_COURSE_VECTOR_VALUE 30

#define MOVE_DELTA 10

using BubblePtr = std::shared_ptr<BubbleShape>;
using BubblePtrList = std::list<BubblePtr>;

struct Frame{
    //Y-coordinate
    int _top;
    int _bottom;
    //X-coordinate
    int _left;
    int _right;
    //TODO create default operator =
};

class BubbleMovementManagment : public QObject
{
    Q_OBJECT
public:
    explicit BubbleMovementManagment(const int movement_interval,
                                     QObject *parent = nullptr);

    void Start();
private:
    void CreateMovementTimer();
    BubblePtr CreateRndBubble();
    void CreateBubbleList();

    static int GenerateRndValue(const int lower_bounde, const int upper_bounde);

    bool CheckFrameCollision(BubblePtr bubble_ptr, BarrierType &barrier);
    void DoNextStep(BubblePtr bubble_ptr);

signals:

public slots:
    void RecalculateBubblesPositions();
    void SetFrame(const Frame &win_frame);

private:
    Frame _window_frame;
    int _movement_interval;

    BubblePtrList _bubble_ptr_list;
    std::unique_ptr<QTimer> _movement_timer;

};

#endif // BUBBLEMOVEMENTMANAGMENT_H
