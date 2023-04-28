/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:01:23 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/27 18:33:09 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_HPP
# define SCENE_HPP

#include <vector>

#include "../lib/mathLib/include/mathLib.hpp"
#include "Point.hpp"
#include <vector>
#include "Mesh.hpp"

class Mesh;

class Scene
{
private:
	std::vector<Mesh> Meshs;
	Win &win;
public:
	bool runSimulation;
	Scene(Win &_win);
	~Scene();
	void addMesh(Mesh &mesh);
	void drawScene(void);
	void startSimulation(void);
	void 	sceneEvent(void);
	void 	drawCollisionBox(void);

	// test 

	void drawClosetWall(void);
};




#endif