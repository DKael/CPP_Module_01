/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:53:43 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 18:28:03 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name), wp(0)
{
	;
}

void HumanB::setWeapon(Weapon& _wp)
{
	wp = &_wp;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << wp->getType() << '\n';
}