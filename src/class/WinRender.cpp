/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WinRender.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:28:38 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 21:28:48 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Win.hpp"

void Win::drawPixel(u_int32_t y, u_int32_t x, u_int32_t color)
{
    if (y >= this->h || x >= this->w)
        return ;
    this->colorBuffer[y * this->w + x] = color;
}

void           Win::clear_color_buffer(u_int32_t color)
{
    for (u_int32_t i = 0; i < this->n_pixel; i++)
        this->colorBuffer[i] = color;
}

void Win::draw_grid(void)
{
    for (u_int32_t i = 0; i < this->h; i++)
        for (uint32_t j = 0; j < this->w; j++)
            if (!(i % 10) || !(j % 10))
                drawPixel(i, j, 0x101010);
}

void Win::drawRecrangle(u_int32_t posX, u_int32_t posY, u_int32_t w, u_int32_t h, u_int32_t color)
{
    for (u_int32_t i = 0; i < h; i++)
        for (uint32_t j = 0; j < w; j++)
            drawPixel(i + posY, j + posX, color);
}

void           Win::drawLine(int32_t start_x, int32_t finish_x, int32_t start_y, int32_t finish_y)
{
        
    int32_t dx = std::abs(finish_x - start_x);
    int32_t dy = std::abs(finish_y - start_y);

    int32_t sx = start_x < finish_x ? 1 : -1;
    int32_t sy = start_y < finish_y ? 1 : -1;

    int32_t err = (dx > dy ? dx : -dy) / 2;
    int32_t e2;

    u_int32_t color = 0xFFFFFFFF; // Vous pouvez modifier la couleur ici

    while (true) {
        this->drawPixel(start_y, start_x, color);

        if (start_x == finish_x && start_y == finish_y) {
            break;
        }

        e2 = err;

        if (e2 > -dx) {
            err -= dy;
            start_x += sx;
        }

        if (e2 < dy) {
            err += dx;
            start_y += sy;
        }
    }
}