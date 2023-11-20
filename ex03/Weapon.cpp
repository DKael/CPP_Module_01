/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:53:55 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 18:23:19 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
	type = _type;
}

const std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string _type)
{
	type = _type;
}
