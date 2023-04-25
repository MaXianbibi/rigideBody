/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:16:55 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/25 16:36:33 by justinmorne      ###   ########.fr       */
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

void Mesh::addPoint(u_int32_t x, u_int32_t y)
{
    Point *tmp = head;

    if (!head)
    {
        head = new Point(x, y);
        return ;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new Point(x, y);
}

void Mesh::drawMesh(Win &win)
{
    Point *tmp = head;

    if (!tmp)
        return;
    while (tmp)
    {
        win.drawRecrangle(tmp->Cord.x - 2, tmp->Cord.y - 2, 5, 5, 0xffffff);
        if (tmp->next)
            win.drawLine(tmp->Cord.x, tmp->next->Cord.x, tmp->Cord.y, tmp->next->Cord.y);
        tmp = tmp->next;
    }
}

void Mesh::updateMesh(void)
{
    Point *tmp = head;

    if (!tmp)
        return;
    while (tmp)
    {
        tmp->update();
        tmp = tmp->next;
    }
}
