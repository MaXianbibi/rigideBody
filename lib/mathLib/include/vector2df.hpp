/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2df.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:01:01 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/25 21:33:32 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2DF_HPP
# define VECTOR2DF_HPP

#include <cmath>
#include <iostream>

class vector2df
{	
public:
	double x;
	double y;

	vector2df();
	~vector2df();
	vector2df(double _x, double _y);
	vector2df(const vector2df &cpy);

	vector2df &operator=(const vector2df& cpy);
	vector2df operator+(const vector2df& other) const;
	vector2df operator-(const vector2df& other) const;
	
	vector2df operator+=(const vector2df& cpy);
	vector2df operator-=(const vector2df& cpy);
	
	vector2df operator*(const double scalar) const;
	vector2df operator/(const double scalar) const;

	double dot(const vector2df& other) const;
	double cross(const vector2df& other) const;
	double distance(const vector2df& other) const;
};

inline std::ostream& operator<<(std::ostream& os, const vector2df& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

#endif