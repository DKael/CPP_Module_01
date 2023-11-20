/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:41:58 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 22:34:27 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n\
I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n\
I really do!\n";
}
void Harl::info(void)
{
	std::cout << "[ INFO ]\n \
I cannot believe adding extra bacon costs more money.\n\
You didn’t put enough bacon in my burger!\n\
If you did, I wouldn’t be asking for more!\n";
}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n\
I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years whereas you started working here since last month.\n";
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]\n\
This is unacceptable!\n\
I want to speak to the manager now.\n";
}

Harl::Harl()
{
	this->func_ptr[0] = &Harl::debug;
	this->func_ptr[1] = &Harl::info;
	this->func_ptr[2] = &Harl::warning;
	this->func_ptr[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	std::string level_list[LIST_SIZE] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < LIST_SIZE; i++)
	{
		if (level == level_list[i])
		{
			(this->*func_ptr[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}