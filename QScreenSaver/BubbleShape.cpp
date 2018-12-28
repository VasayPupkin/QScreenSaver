#include "BubbleShape.h"
#include <cmath>

BubbleShape::BubbleShape(const int radius, const VectorCoordinate &course_vector, const Coordinate &centr_coord, const QColor &color):
    _radius(radius),
    _course_vector(course_vector),
    _centr_coord(centr_coord),
    _color(color)
{
    calc_bubble_geometry();
    set_boundaryes();
    calc_course_vector_module();
}

void BubbleShape::change_bubble_course(BarrierType &barrier)
{
    if (barrier == BarrierType::TOP || barrier == BarrierType::BOTTOM) {
        _course_vector.second = -_course_vector.second;
    }
    else if (barrier == BarrierType::LEFT || barrier == BarrierType::RIGHT) {
        _course_vector.first = -_course_vector.first;
    }
    calc_course_vector_module();
}

void BubbleShape::set_boundaryes()
{
    _top = _centr_coord.second - _radius;
    _bottom = _centr_coord.second + _radius;
    _left = _centr_coord.first - _radius;
    _right = _centr_coord.first + _radius;
}

void BubbleShape::calc_course_vector_module()
{
    _course_vector_module = fabsf(sqrtf(pow(_course_vector.first,2.0) + pow(_course_vector.second,2.0)));
}

void BubbleShape::calc_bubble_geometry()
{
    _diameter = 2*_radius;
    _rect_side = static_cast<int>(ceil((_diameter)/sqrt(2)));
    _half_rect_side = static_cast<int>(ceil(_rect_side/2));
    _pen_width = static_cast<int>(ceil(_radius/(sqrt(2))));
}
