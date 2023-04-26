/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:02:38 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/25 22:19:20 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Scene.hpp"

Scene::Scene(Win &_win) : win(_win)
{
    runSimulation = 0;
}

Scene::~Scene()
{
    for (auto &element : this->Meshs)
    {
        Point *tmp = element.head;

        if (tmp)
        {
            Point *start = tmp;
            do
            {
                Point *next = tmp->next;
                delete tmp;
                tmp = next;
            } while (tmp != start);
        }
        element.head = nullptr;
    }
}

void Scene::addMesh(Mesh &mesh)
{
    this->Meshs.push_back(mesh);
}

void Scene::drawScene(void)
{
    for (auto &element : this->Meshs)
        element.drawMesh(win);
}

void Scene::startSimulation(void)
{
    for (auto &element : this->Meshs)
        element.updateMesh();
}

void Scene::sceneEvent(void)
{
    SDL_Event event;

    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        this->win.is_running = 0;
        break;
    case SDL_KEYDOWN:
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            this->win.is_running = 0;
            break;
        case SDLK_SPACE:
        {
            if (this->Meshs.back().shapeComplete )
            {
                std::cout << "animation ! " << std::endl;   
                this->runSimulation = 1;
            }
            else
                std::cerr << "you need 2 finish ur shape mf" << std::endl;
        }
        }
    }
    break;
    case SDL_MOUSEBUTTONDOWN:
    {
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (this->Meshs.back().addPoint(x, y))
            {
                this->Meshs.back().creatCollision();                
                this->Meshs.emplace_back(); 
            }
        }
    }
    break;
    }
}

void 	Scene::drawCollisionBox(void)
{
    for (auto &element : this->Meshs)
    {
        if (element.shapeComplete)
        {
                win.drawLine(element.Collision.first.x, element.Collision.second.x, element.Collision.first.y, element.Collision.first.y);
                win.drawLine(element.Collision.first.x, element.Collision.second.x, element.Collision.second.y, element.Collision.second.y);
                win.drawLine(element.Collision.first.x, element.Collision.first.x, element.Collision.first.y, element.Collision.second.y);
                win.drawLine(element.Collision.second.x, element.Collision.second.x, element.Collision.first.y, element.Collision.second.y);
        }
    }
}

