#include "OpenGLView.h"

OpenGLView::OpenGLView(QObject *parent) : QObject(parent)
{
    _open_GL_widget.reset(new QOpenGLWidget());
}

void OpenGLView::Show()
{
    _open_GL_widget.get()->show();
}

void OpenGLView::RepaintBubbles()
{

}
