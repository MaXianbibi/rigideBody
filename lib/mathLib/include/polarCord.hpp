/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polarCord.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:27:57 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/23 18:34:15 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLARCORD_HPP
# define POLARCORD_HPP

#include <cmath>

class polarCord
{
public:
	double r;
	double theta;
	polarCord();
	polarCord(int32_t x, int32_t y);
	polarCord(double _r, double _theta);

	// void polar_to_cartesian()

	~polarCord();
};



#endif