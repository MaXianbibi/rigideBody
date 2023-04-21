/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:06:02 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 01:01:47 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Win.hpp"

void fatal(std::string msg)
{
    perror(msg.c_str());
    // free
    exit( 1 );
}

void fatal_SDL(std::string msg)
{
    std::cerr << msg << std::endl;
    SDL_GetError();
    // free
    exit( 1 );
}