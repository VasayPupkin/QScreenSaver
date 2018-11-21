#include "Mediator.h"

Mediator::Mediator(QObject *parent) : QObject(parent)
{
    CreateObjs();
    SetConnection();
}

void Mediator::Start()
{
    _graphics_view.get()->Show();
    Frame win_frame;
    win_frame._top = _graphics_view.get()->Top();
    win_frame._bottom = _graphics_view.get()->Bottom();
    win_frame._left = _graphics_view.get()->Left();
    win_frame._right = _graphics_view.get()->Right();
    _bubble_mgr.get()->SetFrame(win_frame);
    _bubble_mgr.get()->Start();
}

void Mediator::CreateObjs()
{
    _graphics_view.reset(new GraphicsView());
    _bubble_mgr.reset(new BubbleMovementManagment(_movement_interval));
}

void Mediator::SetConnection()
{
    connect(_bubble_mgr.get(), SIGNAL(RepaintBubbles(BubblePtrList&)), _graphics_view.get(), SLOT(RepaintBubbles(BubblePtrList&)));
}
