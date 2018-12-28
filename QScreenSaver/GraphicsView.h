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

    int Height()    const { return this->geometry().height(); }
    int Width()     const { return this->geometry().width(); }
    int Top()       const { return (-Height()/2); }
    int Bottom()    const { return (Height()/2); }
    int Left()      const { return (-Width()/2); }
    int Right()     const { return (Width()/2); }

private:
    void CreateObjects();
    void DrawCircle(const BubblePtr &bubble);
    void DrawTestBubble();
    void CenteredOnPseudoItem();
    void SetFrameParametrs();

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
