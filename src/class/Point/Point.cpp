/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:38:30 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/24 21:20:09 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Scene.hpp"

Point::Point() 
{
	this->mass = 1;
}

Point::Point(int32_t x, int32_t y) : Cord(x, y)
{
	this->mass = 1;
}

Point::Point(vector2df _cord) : Cord(_cord)
{
	this->mass = 1;
}

void Point::update(void)
{
	Force = gravity * this->mass;
	this->Velocity = Velocity + Force;
	this->Cord = Cord + Velocity;
}



Point::~Point()
{
}
