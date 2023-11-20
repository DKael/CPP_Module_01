/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:53:40 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 18:31:06 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _wp) : name(_name), wp(_wp)
{
	;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << wp.getType() << '\n';
}