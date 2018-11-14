#include "BubbleShape.h"

BubbleShape::BubbleShape(const int radius, const int course, const Coordinate &centr_coord, const QColor &color):
    _radius(radius),
    _course(course),
    _centr_coord(centr_coord),
    _color(color)
{
    set_boundaryes();
}

void BubbleShape::set_boundaryes()
{
    _upper_boundary = _centr_coord.second + _radius;
    _lower_boundary = _centr_coord.second - _radius;
    _left_boundary = _centr_coord.first - _radius;
    _right_boundary = _centr_coord.first + _radius;
}
