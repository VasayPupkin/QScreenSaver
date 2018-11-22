#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <memory>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>
#include <QEvent>
#include <QResizeEvent>

#include "BubbleShape.h"

using QGraphicsViewPtr = std::shared_ptr<QGraphicsView>;
using QGraphicsScenePtr = std::shared_ptr<QGraphicsScene>;

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QGraphicsView *parent = nullptr);

    void Show();
    int Top()       const { return this->geometry().top(); }
    int Bottom()    const { return this->geometry().y() + this->geometry().height(); }
    int Left()      const { return this->geometry().left(); }
    int Right()     const { return this->geometry().x() + this->geometry().width(); }

private:
    void CreateObjects();
    void DrawCircle(const BubblePtr &bubble);

protected:
    void resizeEvent(QResizeEvent *e) override;

signals:
    void GraphicsViewResize(Frame &wdg_frame);

public slots:
    void RepaintBubbles(BubblePtrList &bubble_list);
private:
//    QGraphicsViewPtr _graphics_view;
    QGraphicsScenePtr _scene;
};

#endif // GRAPHICSVIEW_H
