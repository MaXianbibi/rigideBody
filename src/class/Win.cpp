/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:52:58 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 21:33:01 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Win.hpp"

Win::Win(u_int16_t _w, u_int16_t _h, std::string name) : w(_w), h(_h)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        fatal_SDL("SDL_INIT");
    SDL_DisplayMode display_mode;
    if (SDL_GetCurrentDisplayMode(0, &display_mode) < 0)
        fatal_SDL("SDL_GetCurrentDisplayMode");
    this->win = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->w, this->h, SDL_WINDOW_SHOWN);
    if (!this->win)
        fatal_SDL("SDL_CreateWindow");
    this->colorBuffer = (u_int32_t *)calloc(sizeof(u_int32_t), this->h * this->w);
    if (!this->colorBuffer)
        fatal("malloc");
    memset(this->colorBuffer, 0, this->h * this->w);
    this->renderer = SDL_CreateRenderer(this->win, -1, 0);
    if (!this->renderer)
        fatal_SDL("SDL_CreateRenderer");
    this->texture = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, this->w, this->h);
    if (!this->texture)
        fatal_SDL("SDL_CreateTexture");
        
    this->is_running = 1;

    this->defaultEventFunction = &Win::defaultEvent;
    this->eventsFunc = NULL;
    this->updateFunc = NULL;
    this->FRAME_RATE = 1000 / 60;
    this->n_pixel = this->w * this->h;
}

Win::Win() : Win(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_NAME)
{
}

Win::~Win()
{
    free(this->colorBuffer);
    SDL_DestroyTexture(this->texture);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}

void Win::defaultEvent(void)
{
    SDL_Event event;

    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        this->is_running = 0;
        break;
    case SDL_KEYDOWN:
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            this->is_running = 0;
            break;
        }
    }
    break;
    }
}

void Win::loop(void *ptr)
{
    while (this->is_running)
    {
        if (!this->updateFunc)
            fatal("No update Function !");
        (this->*defaultEventFunction)();
        if (eventsFunc)
            (this->eventsFunc)(*this);
        (this->updateFunc)(*this, ptr);

        render();        
        SDL_Delay(this->FRAME_RATE);
    }
}

void           Win::change_frame_rate(u_int8_t v)
{
    this->FRAME_RATE = v;
}

void            Win::render(void)
{
    if (SDL_UpdateTexture(this->texture, NULL, this->colorBuffer, this->w * sizeof(u_int32_t)) < 0)
        fatal_SDL("SDL_UpdateTexture");
    if (SDL_RenderCopy(this->renderer, this->texture, NULL, NULL) < 0)
        fatal_SDL("SDL_RenderCopy");

    SDL_RenderPresent(this->renderer);
}

void Win::stop_running(void)
{
    this->is_running = 0;
}
