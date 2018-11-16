#include "Mediator.h"

Mediator::Mediator(QObject *parent) : QObject(parent)
{
    CreateObjs();
}

void Mediator::Start()
{
    _main_window.get()->showFullScreen();
    Frame win_frame;
    win_frame._top = _main_window.get()->geometry().top();
    win_frame._bottom = _main_window.get()->geometry().bottom();
    win_frame._left = _main_window.get()->geometry().left();
    win_frame._right = _main_window.get()->geometry().right();
    _bubble_mgr.get()->SetFrame(win_frame);
    _bubble_mgr.get()->Start();
}

void Mediator::CreateObjs()
{
    _main_window.reset(new MainWindow());
    _bubble_mgr.reset(new BubbleMovementManagment(_movement_interval));
}

void Mediator::SetConnection()
{

}
