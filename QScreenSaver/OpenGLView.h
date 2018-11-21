#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

//#include <QObject>
#include <memory>
#include <QOpenGLWidget>
#include <QGLWidget>

#include "BubbleShape.h"

using OpenGLWdgtPtr = std::shared_ptr<QOpenGLWidget>;

class OpenGLView : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLView(QWidget *parent = nullptr);

    int Top()       const { return _open_GL_widget.get()->geometry().top(); }
    int Bottom()    const { return _open_GL_widget.get()->geometry().bottom(); }
    int Left()      const { return _open_GL_widget.get()->geometry().left(); }
    int Right()     const { return _open_GL_widget.get()->geometry().right(); }

private:
    void Draw(int xOffset, int yOffset, GLenum type);
    void DrawCircle(const BubbleShape &bubble);

protected:
    virtual void initializeGL   (                       ) override;
    virtual void resizeGL       (int nWidth, int nHeight) override;
    virtual void paintGL        (                       ) override;

signals:

public slots:
    void Show();
    void RepaintBubbles();

private:
    OpenGLWdgtPtr _open_GL_widget;
};

#endif // OPENGLVIEW_H
