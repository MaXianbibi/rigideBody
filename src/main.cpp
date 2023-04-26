/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:48:56 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/25 22:04:39 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Win.hpp"
#include "../include/Scene.hpp"

int update(Win &win, void *ptr)
{
	Scene &i = *static_cast<Scene *>(ptr);
	(void)win;
	(void)i;
	win.clear_color_buffer(0);
	i.drawScene();
	i.startSimulation();

	return (1);
}

void setupScene(Scene &scene, Win &win)
{
	Mesh tmp;

	scene.addMesh(tmp);
	while (!scene.runSimulation && win.is_running)
	{	
		win.clear_color_buffer(0);
		scene.drawScene();
		scene.drawCollisionBox();
		win.render();

		scene.sceneEvent();
		SDL_Delay(1000 / 60);
	}
}

int main(void)
{
	Win win(600, 600, "SoftBody");

	Scene scene(win);

	setupScene(scene, win);

	win.updateFunc = update;
	win.loop(&scene);
}