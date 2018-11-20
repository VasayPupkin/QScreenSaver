#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QObject>
#include <memory>
#include <QOpenGLWidget>

#include "BubbleShape.h"

using OpenGLWdgtPtr = std::shared_ptr<QOpenGLWidget>;

class OpenGLView : public QObject
{
    Q_OBJECT
public:
    explicit OpenGLView(QObject *parent = nullptr);

    int Top()       const { return _open_GL_widget.get()->geometry().top(); }
    int Bottom()    const { return _open_GL_widget.get()->geometry().bottom(); }
    int Left()      const { return _open_GL_widget.get()->geometry().left(); }
    int Right()     const { return _open_GL_widget.get()->geometry().right(); }
signals:

public slots:
    void Show();
    void RepaintBubbles();

private:
    OpenGLWdgtPtr _open_GL_widget;
};

#endif // OPENGLVIEW_H
