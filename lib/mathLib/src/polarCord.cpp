/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polarCord.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:29:35 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/23 18:33:15 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/polarCord.hpp"

polarCord::polarCord() : r(0), theta(0) {}

polarCord::polarCord(int32_t x, int32_t y)
{
	
	
}
	
polarCord::polarCord(double _r, double _theta) : r(_r), theta(_theta) {}


polarCord::~polarCord()
{
}
