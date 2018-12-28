#ifndef BUBBLESHAPE_H
#define BUBBLESHAPE_H

#include <QColor>

#include <utility>
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
                                       calc_bubble_geometry();
                                       set_boundaryes();
                                     }
    void set_course_vector(const VectorCoordinate &course_vector){ _course_vector = course_vector;}
    void set_centr_coord(const Coordinate &centr_coord){ _centr_coord = centr_coord;
                                                         set_boundaryes();
                                                       }
    void set_color(const QColor &color){ _color = color; }

    int get_radius()                        const { return _radius; }
    int get_diameter()                      const { return _diameter; }
    int get_rect_side()                     const { return _rect_side; }
    int get_half_rect_side()                const { return _half_rect_side; }
    int get_pen_width()                     const { return _pen_width; }

    VectorCoordinate get_course_vector()    const { return _course_vector; }
    float get_course_vector_module()        const { return _course_vector_module; }
    Coordinate get_centr_coord()            const { return _centr_coord; }
    QColor get_color()                      const { return _color; }

    int get_top()                           const { return _top; }
    int get_bottom()                        const { return _bottom; }
    int get_left()                          const { return _left; }
    int get_right()                         const { return _right; }

    void change_bubble_course(BarrierType &barrier);

private:
    void set_boundaryes();
    void calc_course_vector_module();
    void calc_bubble_geometry();

private:
    int _radius;
    int _diameter;
    int _rect_side;
    int _half_rect_side;
    int _pen_width;
    VectorCoordinate _course_vector;
    float _course_vector_module;
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
