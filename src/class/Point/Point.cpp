/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:38:30 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/25 16:27:47 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Scene.hpp"

Point::Point() 
{
	this->mass = 0.1;
	next = nullptr;
} 

Point::Point(int32_t x, int32_t y) : Cord(x, y)
{
	this->mass = 0.1;
	next = nullptr;
}

Point::Point(vector2df _cord) : Cord(_cord)
{
	this->mass = 0.1;
	next = nullptr;
}

void Point::update(void)
{
	Force = gravity * this->mass;
	this->Velocity = Velocity + Force;
	this->Cord = Cord + Velocity;
	if (Cord.y >= 590)
	{
		Cord.y = 590;
		Velocity.y = 0;
	}
	if (Cord.x >= 600)
	{
		Cord.x = 600;
		Velocity.x = 0;
	}
}



Point::~Point()
{
}
