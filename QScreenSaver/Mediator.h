#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <memory>

#include "mainwindow.h"
#include "BubbleMovementManagment.h"
#include "GraphicsView.h"

using GraphicsViewPtr = std::shared_ptr<GraphicsView>;
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
    BubbleManagerPtr _bubble_mgr;
    int _movement_interval = 30;
    GraphicsViewPtr _graphics_view;
};

#endif // MEDIATOR_H
