/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2df.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:02:37 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/24 21:02:51 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector2df.hpp"

vector2df::vector2df() : x(0), y(0) {}

vector2df::vector2df(double _x, double _y) : x(_x), y(_y) {}

vector2df::~vector2df() {}

vector2df &vector2df::operator=(const vector2df& other)
{
	this->x = other.x;
	this->y = other.y;

	return (*this);
}

vector2df::vector2df(vector2df &cpy)
{
	*this = cpy;
}

vector2df vector2df::operator+(const vector2df& other) const 
{
        return (vector2df(this->x + other.x, this->y + other.y));
}

vector2df vector2df::operator-(const vector2df& other) const 
{
        return (vector2df(this->x - other.x, this->y - other.y));
}

vector2df vector2df::operator*(const double scalar) const 
{
        return (vector2df(this->x * scalar, this->y * scalar));
}

vector2df vector2df::operator/(const double scalar) const 
{
        return (vector2df(this->x / scalar, this->y / scalar));
}

double vector2df::dot(const vector2df& other) const
{
	return (x * other.x + y * other.y);
}

double vector2df::cross(const vector2df& other) const
{
        return (x * other.y - y * other.x);
}

vector2df vector2df::operator+=(const vector2df& cpy)
{
	return (*this + cpy);
}

vector2df vector2df::operator-=(const vector2df& cpy)
{
	return (*this - cpy);
}



double vector2df::distance(const vector2df& other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}