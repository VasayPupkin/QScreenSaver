#include "BubbleShape.h"

BubbleShape::BubbleShape(const int radius, const VectorCoordinate &course_vector, const Coordinate &centr_coord, const QColor &color):
    _radius(radius),
    _course_vector(course_vector),
    _centr_coord(centr_coord),
    _color(color)
{
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
