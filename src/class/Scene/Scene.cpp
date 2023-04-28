/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:02:38 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/27 21:09:03 by justinmorne      ###   ########.fr       */
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
            } while (tmp != start && tmp);
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
            if (this->Meshs.back().shapeComplete)
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

void Scene::drawCollisionBox(void)
{
    for (auto &element : this->Meshs)
    {
        if (element.shapeComplete)
        {
            win.drawLine(element.Collision.first.x, element.Collision.second.x, element.Collision.first.y, element.Collision.first.y, 0xffffff);
            win.drawLine(element.Collision.first.x, element.Collision.second.x, element.Collision.second.y, element.Collision.second.y, 0xffffff);
            win.drawLine(element.Collision.first.x, element.Collision.first.x, element.Collision.first.y, element.Collision.second.y, 0xffffff);
            win.drawLine(element.Collision.second.x, element.Collision.second.x, element.Collision.first.y, element.Collision.second.y, 0xffffff);
        }
    }
}

double distance(vector2df p, vector2df a, vector2df b) {
    return abs((b.x - a.x) * (a.y - p.y) - (a.x - p.x) * (b.y - a.y)) /
           sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}



Point *findClosestWall(Mesh mesh_tmp, vector2df point)
{
    Point *tmp = mesh_tmp.head;

    if (tmp == nullptr)
        return (nullptr);

    double min_dist = DBL_MAX;
    Point *min_dist_point = tmp;
    do
    {
        double dist = 0;
    
        
        dist = distance(point, tmp->Cord, tmp->next->Cord);
        if (min_dist > dist)
        {
            min_dist = dist;
            min_dist_point = tmp;
        }
        tmp = tmp->next;
    } while (tmp != mesh_tmp.head);
    return (min_dist_point);
}

void Scene::drawClosetWall(void)
{
    int x, y;

    SDL_GetMouseState(&x, &y);
    vector2df tmp(x, y);
    for (auto &element : this->Meshs)
    {
        if (element.shapeComplete &&
            ((x > element.Collision.first.x && x <= element.Collision.second.x) &&
            (y > element.Collision.first.y && y <= element.Collision.second.y)) &&
            element.checkIntersec(tmp))
        {
            Point *tmp_point = findClosestWall(element, tmp);
            if (tmp_point)
            {
                this->win.drawLine(tmp_point->Cord.x, tmp_point->next->Cord.x, tmp_point->Cord.y, tmp_point->next->Cord.y, 0x0000ff);
            }
        }
    }
}
