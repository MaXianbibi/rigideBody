/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:16:55 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/25 20:32:42 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Mesh.hpp"

Mesh::Mesh()
{
    head = nullptr;
}

Mesh::~Mesh()
{
}

int Mesh::addPoint(int32_t x, int32_t y)
{
    Point *tmp = head;

    if (!head)
    {
        head = new Point(x, y);
        return (0);
    }
    while (tmp->next)
        tmp = tmp->next;
    if (vector2df(x, y).distance(head->Cord) > 15)
        tmp->next = new Point(x, y);
    else
    {
        tmp->next = head; 
        return (1);
    }
    return (0);  
}

void Mesh::drawMesh(Win &win)
{
    Point *tmp = head;

    if (!tmp)
        return ;
    do
    {
        win.drawRecrangle(tmp->Cord.x - 2, tmp->Cord.y - 2, 5, 5, 0xffffff);
        if (tmp->next)
            win.drawLine(tmp->Cord.x, tmp->next->Cord.x, tmp->Cord.y, tmp->next->Cord.y);
        tmp = tmp->next;
    } while (tmp && tmp != head);
}

void Mesh::updateMesh(void)
{
    Point *tmp = head;

    if (!tmp)
        return ;
    do
    {
        tmp->update();
        tmp = tmp->next;
    } while (tmp != head);
}