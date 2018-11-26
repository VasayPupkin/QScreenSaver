#ifndef BUBBLESHAPE_H
#define BUBBLESHAPE_H

#include <utility>
#include <QColor>
#include <cmath>
#include <memory>
#include <list>

class BubbleShape;

using Coordinate = std::pair<int,int>;
using VectorCoordinate = std::pair<int,int>;
using BubblePtr = std::shared_ptr<BubbleShape>;
using BubblePtrList = std::list<BubblePtr>;

enum class BarrierType : uchar
{
    NO_BARRIER,
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

struct Frame{
    //Y-coordinate
    int _top;
    int _bottom;
    //X-coordinate
    int _left;
    int _right;
    //size
    int _height;
    int _width;
};

class BubbleShape
{
public:
    explicit BubbleShape() = default;
    explicit BubbleShape(const BubbleShape &value) = default;
//    explicit BubbleShape(BubbleShape &&value) = default;
    BubbleShape(const int radius, const VectorCoordinate &course_vector, const Coordinate &centr_coord, const QColor &color);

    void set_radius(const int radius){ _radius = radius;
                                       set_boundaryes();
                                     }
    void set_course_vector(const VectorCoordinate &course_vector){ _course_vector = course_vector;}
    void set_centr_coord(const Coordinate &centr_coord){ _centr_coord = centr_coord;
                                                         set_boundaryes();
                                                       }
    void set_color(const QColor &color){ _color = color; }

    int get_radius()                        const { return _radius; }
    VectorCoordinate get_course_vector()    const { return _course_vector; }
    Coordinate get_centr_coord()            const { return _centr_coord; }
    QColor get_color()                      const { return _color; }

    int get_top()                           const { return _top; }
    int get_bottom()                        const { return _bottom; }
    int get_left()                          const { return _left; }
    int get_right()                         const { return _right; }

    void change_bubble_course(BarrierType &barrier);

private:
    void set_boundaryes();

private:
    int _radius;
    VectorCoordinate _course_vector;
    Coordinate _centr_coord;
    QColor _color;

    //Y-coordinate
    int _top;
    int _bottom;
    //X-coordinate
    int _left;
    int _right;
};

#endif // BUBBLESHAPE_H
