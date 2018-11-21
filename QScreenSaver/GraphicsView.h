#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <memory>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

#include "BubbleShape.h"

using QGraphicsViewPtr = std::shared_ptr<QGraphicsView>;
using QGraphicsScenePtr = std::shared_ptr<QGraphicsScene>;

class GraphicsView : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsView(QObject *parent = nullptr);

    void Show();
    int Top()       const { return _graphics_view.get()->geometry().top(); }
    int Bottom()    const { return _graphics_view.get()->geometry().y() +
                                   _graphics_view.get()->geometry().height(); }
    int Left()      const { return _graphics_view.get()->geometry().left(); }
    int Right()     const { return _graphics_view.get()->geometry().x() +
                                   _graphics_view.get()->geometry().width(); }

private:
    void CreateObjects();
    void DrawCircle(const BubblePtr &bubble);

signals:

public slots:
    void RepaintBubbles(BubblePtrList &bubble_list);
private:
    QGraphicsViewPtr _graphics_view;
    QGraphicsScenePtr _scene;
};

#endif // GRAPHICSVIEW_H
