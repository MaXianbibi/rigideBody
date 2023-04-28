/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:37:51 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/25 22:44:25 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "../lib/mathLib/include/mathLib.hpp"

const vector2df gravity(0, 1);

class Point
{
private:
	double mass;
	vector2df Velocity;
	vector2df Force;
public:
	Point	*next;
	vector2df Cord;
	Point();
	Point(int32_t x, int32_t y);
	void update(void);
	Point(vector2df _cord);
	~Point();
};



#endif