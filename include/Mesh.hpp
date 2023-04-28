/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:16:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/27 18:40:16 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_HPP
# define MESH_HPP

#include "Point.hpp"
#include "Win.hpp"
#include "../lib/mathLib/include/mathLib.hpp"

bool intersect(vector2df a, vector2df b, vector2df p);

class Win;
class vector2df;

class Mesh
{
private:
public:
    Mesh();
    ~Mesh();

    std::pair<vector2df, vector2df> Collision;
    Point *head;
    int  addPoint(int32_t x, int32_t y);
    void drawMesh(Win &win);
    void updateMesh(void);
    void creatCollision(void);
	int		checkCircle(void);
    bool    shapeComplete;

    bool    checkIntersec(vector2df &point);
    
};

#endif