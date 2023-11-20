/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:44:07 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 16:54:56 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new (std::nothrow) Zombie[N];

	if (!horde)
		exit(1);

	for (int i = 0; i < N; i++)
		horde[i].setname(name);
	
	return horde;
}