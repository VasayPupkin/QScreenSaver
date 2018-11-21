#include "OpenGLView.h"

OpenGLView::OpenGLView(QWidget *parent) :
    QGLWidget(parent)
{
    _open_GL_widget.reset(new QOpenGLWidget());
    this->resize(400,200);
}

void OpenGLView::Draw(int xOffset, int yOffset, GLenum type)
{
    int n = 8;

    glPointSize(2);
    glBegin(type);
        glColor3f(0, 0, 0);
        for (int i = 0; i < n; ++i) {
            float fAngle = 2 * 3.14 * i / n;
            int   x      = (int)(50 + cos(fAngle) * 40 + xOffset);
            int   y      = (int)(50 + sin(fAngle) * 40 + yOffset);
            glVertex2f(x, y);
        }
    glEnd();
}

void OpenGLView::DrawCircle(const BubbleShape &bubble)
{
    Q_UNUSED(bubble)
}

void OpenGLView::initializeGL()
{
    qglClearColor(Qt::white);
}

void OpenGLView::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glOrtho(0, 400, 200, 0, -1, 1);
}

void OpenGLView::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Draw(200, 100, GL_LINE_LOOP);
}

void OpenGLView::Show()
{
//    _open_GL_widget.get()->show();
    this->show();
}

void OpenGLView::RepaintBubbles()
{

}
