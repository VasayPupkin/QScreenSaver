#ifndef BUBBLESHAPE_H
#define BUBBLESHAPE_H

#include <utility>
#include <QColor>

using Coordinate = std::pair<int,int>;

class BubbleShape
{
public:
//    BubbleShape() = delete;
//    BubbleShape(const BubbleShape &value) = delete;
//    BubbleShape(const BubbleShape &&value) = delete;
    BubbleShape(const int radius, const int course, const Coordinate &centr_coord, const QColor &color);

    void set_radius(const int radius){ _radius = radius;
                                       set_boundaryes();
                                     }
    void set_course(const int course){ _course = course; }
    void set_centr_coord(const Coordinate &centr_coord){ _centr_coord = centr_coord;
                                                         set_boundaryes();
                                                       }
    void set_color(const QColor &color){ _color = color; }

    int get_radius() const { return _radius; }
    int get_course() const { return _course; }
    Coordinate get_centr_coord() const { return _centr_coord; }
    QColor get_color() const { return _color; }

    int get_upper_boundary() const { return _upper_boundary; }
    int get_lower_boundary() const { return _lower_boundary; }
    int get_left_boundary() const { return _left_boundary; }
    int get_right_boundary() const { return _right_boundary; }

private:
    void set_boundaryes();

private:
    int _radius;
    int _course;//like in trigonometry
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
