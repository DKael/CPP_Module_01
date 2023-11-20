/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:23:46 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 16:49:39 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	name = "";
}

Zombie::Zombie(std::string _name) : name(_name)
{
	;
}

Zombie::~Zombie(void)
{
	std::cout << name << " destroyed\n";
}

void Zombie::setname(std::string _name)
{
	name = _name;
}
std::string Zombie::getname(void)
{
	return name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}