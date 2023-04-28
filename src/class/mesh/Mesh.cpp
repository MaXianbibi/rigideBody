/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:16:55 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/27 20:56:11 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Mesh.hpp"

const double eps = 1e-9;

Mesh::Mesh()
{
    head = nullptr;
    shapeComplete = 1;
}

Mesh::~Mesh() {}

int Mesh::addPoint(int32_t x, int32_t y)
{
    Point *tmp = head;

    if (!head)
    {
        head = new Point(x, y);
        shapeComplete = 0;
        return (0);
    }
    while (tmp->next)
        tmp = tmp->next;
    if (vector2df(x, y).distance(head->Cord) > 15)
        tmp->next = new Point(x, y);
    else
    {
        tmp->next = head;
        this->shapeComplete = 1;
        return (1);
    }
    return (0);
}

void Mesh::drawMesh(Win &win)
{
    Point *tmp = head;

    if (!tmp)
        return;
    do
    {
        win.drawRecrangle(tmp->Cord.x - 2, tmp->Cord.y - 2, 5, 5, 0xffffff);
        if (tmp->next)
            win.drawLine(tmp->Cord.x, tmp->next->Cord.x, tmp->Cord.y, tmp->next->Cord.y, 0xffffff);
        tmp = tmp->next;
    } while (tmp && tmp != head);
}

void Mesh::updateMesh(void)
{
    Point *tmp = head;

    if (!tmp)
        return;
    do
    {
        tmp->update();
        tmp = tmp->next;
    } while (tmp != head);
}

void Mesh::creatCollision(void)
{
    int x, max_x, y, max_y;
    Point *tmp = head;

    if (!tmp)
        return;
        
    x = tmp->Cord.x;
    max_x = tmp->Cord.x;
    y = tmp->Cord.y;
    max_y = tmp->Cord.y;
    
    do
    {
        if (tmp->Cord.x < x)
            x = tmp->Cord.x;
        if (tmp->Cord.y < y)
            y = tmp->Cord.y;
            
        if (tmp->Cord.x > max_x)
            max_x = tmp->Cord.x;
            
        if (tmp->Cord.y > max_y)
            max_y = tmp->Cord.y;
        tmp = tmp->next;
    } while (tmp != head);

    this->Collision.first.x = x;
    this->Collision.first.y = y;

    this->Collision.second.x = max_x;
    this->Collision.second.y = max_y;
}

int		Mesh::checkCircle(void)
{
    Point *tmp = head;

    if (!tmp)
        return (1);
    do
    {
        tmp = tmp->next;
        if (tmp == nullptr)
            return (0);
    } while (tmp != head);
    return (1);
}

bool intersect(vector2df a, vector2df b, vector2df p)
{
    if (std::fabs(b.y - a.y) < eps) {
        return false;
    }

    if (p.y < std::min(a.y, b.y) || p.y > std::max(a.y, b.y)) {
        return false;
    }

    double x = a.x + (p.y - a.y) * (b.x - a.x) / (b.y - a.y);
    if (x > p.x + eps) {
        return false;
    }
    return true;
}

bool    Mesh::checkIntersec(vector2df &point)
{
    Point *tmp = head;
    int count = 0;
    
    if (!tmp)
        return (0);
    do
    {
        count += intersect(tmp->Cord, tmp->next->Cord, point);
        tmp = tmp->next;
    } while (tmp != head);
        
    return (count & 1);
    
}
