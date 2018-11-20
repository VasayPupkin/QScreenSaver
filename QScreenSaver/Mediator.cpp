#include "Mediator.h"

Mediator::Mediator(QObject *parent) : QObject(parent)
{
    CreateObjs();
}

void Mediator::Start()
{
    _open_GL_view.get()->Show();
    Frame win_frame;
    win_frame._top = _open_GL_view.get()->Top();
    win_frame._bottom = _open_GL_view.get()->Bottom();
    win_frame._left = _open_GL_view.get()->Left();
    win_frame._right = _open_GL_view.get()->Right();
    _bubble_mgr.get()->SetFrame(win_frame);
    _bubble_mgr.get()->Start();
}

void Mediator::CreateObjs()
{
    _open_GL_view.reset(new OpenGLView());
    _main_window.reset(new MainWindow());
    _bubble_mgr.reset(new BubbleMovementManagment(_movement_interval));
}

void Mediator::SetConnection()
{

}
