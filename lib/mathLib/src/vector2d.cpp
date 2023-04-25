/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:35:08 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/24 20:35:49 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector2di.hpp"

vector2di::vector2di() : x(0), y(0) {}

vector2di::vector2di(int32_t _x, int32_t _y) : x(_x), y(_y) {}

vector2di::~vector2di() {}

vector2di &vector2di::operator=(const vector2di& other)
{
	this->x = other.x;
	this->y = other.y;

	return (*this);
}

vector2di::vector2di(vector2di &cpy)
{
	*this = cpy;
}

vector2di vector2di::operator+(const vector2di& other) const 
{
        return (vector2di(this->x + other.x, this->y + other.y));
}

vector2di vector2di::operator-(const vector2di& other) const 
{
        return (vector2di(this->x - other.x, this->y - other.y));
}

vector2di vector2di::operator*(const double scalar) const 
{
        return (vector2di(this->x * scalar, this->y * scalar));
}

vector2di vector2di::operator/(const double scalar) const 
{
        return (vector2di(this->x / scalar, this->y / scalar));
}

double vector2di::dot(const vector2di& other) const
{
	return (x * other.x + y * other.y);
}

double vector2di::cross(const vector2di& other) const
{
        return (x * other.y - y * other.x);
}

double vector2di::distance(const vector2di& other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}