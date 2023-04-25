/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:16:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/25 16:35:30 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_HPP
# define MESH_HPP

#include "Point.hpp"
#include "Win.hpp"

class Win;

class Mesh
{
private:
public:
    Mesh();
    ~Mesh();

    Point *head;
    void addPoint(u_int32_t x, u_int32_t y);
    void drawMesh(Win &win);
    void updateMesh(void);
};



#endif