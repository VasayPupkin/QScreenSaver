#ifndef BUBBLESHAPE_H
#define BUBBLESHAPE_H

#include <utility>
#include <QColor>
#include <cmath>

using Coordinate = std::pair<int,int>;
using VectorCoordinate = std::pair<int,int>;

enum class BarrierType : uchar
{
    NO_BARRIER,
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

class BubbleShape
{
public:
    explicit BubbleShape() = default;
    explicit BubbleShape(const BubbleShape &value) = default;
    BubbleShape(const int radius, const VectorCoordinate &course_vector, const Coordinate &centr_coord, const QColor &color);

    void set_radius(const int radius){ _radius = radius;
                                       set_boundaryes();
                                     }
    void set_course_vector(const VectorCoordinate &course_vector){ _course_vector = course_vector;}
    void set_centr_coord(const Coordinate &centr_coord){ _centr_coord = centr_coord;
                                                         set_boundaryes();
                                                       }
    void set_color(const QColor &color){ _color = color; }

    int get_radius() const { return _radius; }
    VectorCoordinate get_course_vector() const { return _course_vector; }
    Coordinate get_centr_coord() const { return _centr_coord; }
    QColor get_color() const { return _color; }

    int get_upper_boundary() const { return _upper_boundary; }
    int get_lower_boundary() const { return _lower_boundary; }
    int get_left_boundary() const { return _left_boundary; }
    int get_right_boundary() const { return _right_boundary; }

    void change_bubble_course(BarrierType &barrier);

private:
    void set_boundaryes();

private:
    int _radius;
    VectorCoordinate _course_vector;
    Coordinate _centr_coord;
    QColor _color;

    //Y-coordinate
    int _upper_boundary;
    int _lower_boundary;
    //X-coordinate
    int _left_boundary;
    int _right_boundary;
};

#endif // BUBBLESHAPE_H
