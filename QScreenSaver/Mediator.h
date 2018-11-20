#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <memory>

#include "mainwindow.h"
#include "BubbleMovementManagment.h"
#include "OpenGLView.h"

using OpenGLViewPtr = std::shared_ptr<OpenGLView>;
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
    OpenGLViewPtr _open_GL_view;
};

#endif // MEDIATOR_H
