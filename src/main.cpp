/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:48:56 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/24 21:21:37 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Win.hpp"
#include "../include/Scene.hpp"


int doingnothing(Win &win, void *ptr)
{
	Point &i = *static_cast<Point *>(ptr);

	win.clear_color_buffer(0);
	win.drawRecrangle(i.Cord.x, i.Cord.y, 10, 10, 0xff0000);
	// std::cout << i.Cord << std::endl;

	i.Cord.x++;
	i.Cord.y++;
	// i.update();
    return (1);    
}

int main ( void )
{
    Win win(600, 600, "RigidBody");

	Point i;
    
	// win.change_frame_rate(60 / 1000);
    win.updateFunc = doingnothing;
    win.loop(&i);
}