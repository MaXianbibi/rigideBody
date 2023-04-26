/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:02:38 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/25 20:35:32 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Scene.hpp"

Scene::Scene(Win &_win) : win(_win)
{
    runSimulation = 0;
    Meshs.clear();
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
            this->runSimulation = 1;
        }
    }
    break;
    case SDL_MOUSEBUTTONDOWN:
    {
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (this->Meshs[this->Meshs.size() - 1].addPoint(x, y))
                this->Meshs.emplace_back(); 
        }
    }
    break;
    }
}
