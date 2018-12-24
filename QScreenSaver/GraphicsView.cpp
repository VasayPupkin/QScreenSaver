#include "GraphicsView.h"
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QScrollBar>

GraphicsView::GraphicsView(QGraphicsView *parent) : QGraphicsView(parent)
{
    CreateObjects();
}

void GraphicsView::Show()
{
    this->show();
}

void GraphicsView::CreateObjects()
{
//    QRect rect = QApplication::desktop()->screenGeometry();
//    auto x = rect.width()/2;
//    auto y = rect.height()/2;
//    this->setGeometry(0,0,800,600);

    _scene.reset(new QGraphicsScene());
    this->setScene(_scene.get());

    //Scene settings
    _scene.get()->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
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

void GraphicsView::DrawTestBubble()
{
    static int delta = 0;
    delta += 1;
    BubbleShape bubble(40,VectorCoordinate(0,0),Coordinate(delta,delta),Qt::blue);
    int x = bubble.get_centr_coord().first;
    int y = bubble.get_centr_coord().second;
    int w = bubble.get_radius();
    int h = w;
    QBrush brush(bubble.get_color(), Qt::BrushStyle::SolidPattern);
    QPen pen(brush, w);
    _scene.get()->addEllipse(x,y,w,h,pen,brush);
}

void GraphicsView::resizeEvent(QResizeEvent *e)
{
    if (e->type() == QResizeEvent::Resize) {
        Frame wdg_frame;
        wdg_frame._height = Height();
        wdg_frame._width = Width();
        wdg_frame._top = Top();
        wdg_frame._bottom = Bottom();
        wdg_frame._left = Left();
        wdg_frame._right = Right();
        emit GraphicsViewResize(wdg_frame);
    }
}

void GraphicsView::RepaintBubbles(BubblePtrList &bubble_list)
{
    _scene.get()->clear();
    for(auto bubble : bubble_list){
        DrawCircle(bubble);
//        DrawTestBubble();
    }
}
