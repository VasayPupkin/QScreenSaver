#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <memory>
#include <QOpenGLWidget>

#include "mainwindow.h"
#include "BubbleMovementManagment.h"

using OpenGLWdgtPtr = std::shared_ptr<QOpenGLWidget>;
using MainWindowPtr = std::shared_ptr<MainWindow>;
using BubbleManagerPtr = std::shared_ptr<BubbleMovementManagment>;

class Mediator : public QObject
{
    Q_OBJECT
public:
    explicit Mediator(QObject *parent = nullptr);

    void Start();

private:
    void CreateObjs();
    void SetConnection();
signals:

public slots:

private:
    MainWindowPtr _main_window;
    BubbleManagerPtr _bubble_mgr;
    int _movement_interval = 1;
    OpenGLWdgtPtr _open_GL_widget;
};

#endif // MEDIATOR_H
