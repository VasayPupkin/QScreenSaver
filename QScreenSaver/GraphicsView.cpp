#include "GraphicsView.h"

GraphicsView::GraphicsView(QObject *parent) : QObject(parent)
{
    CreateObjects();
}

void GraphicsView::Show()
{
//    _graphics_view.get()->
    _graphics_view.get()->setGeometry(0,0,800,600);
    _graphics_view.get()->show();
//    _graphics_view.get()->showFullScreen();
}

void GraphicsView::CreateObjects()
{
    _graphics_view.reset(new QGraphicsView());
    _scene.reset(new QGraphicsScene());
    _graphics_view.get()->setScene(_scene.get());

    //Scene settings
    _scene.get()->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    _graphics_view.get()->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void GraphicsView::DrawCircle(const BubblePtr &bubble)
{
    int x = bubble.get()->get_centr_coord().first;
    int y = bubble.get()->get_centr_coord().second;
    int w = bubble.get()->get_radius();
    int h = w;
    QBrush brush(bubble.get()->get_color(), Qt::BrushStyle::SolidPattern);
    QPen pen(brush, w);
    _scene.get()->addEllipse(x,y,w,h,pen,brush);
}

void GraphicsView::RepaintBubbles(BubblePtrList &bubble_list)
{
    _scene.get()->clear();
    for(auto bubble : bubble_list){
        DrawCircle(bubble);
    }
}
