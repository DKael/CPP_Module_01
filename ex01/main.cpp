/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:58:04 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/30 19:42:06 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "only number of zombies and name of zombie accepted\n";
		return 1;
	}
	if (std::string(argv[1]).find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "first input have to be a positive number\n";
		return 1;
	}
	
	int number = atoi(argv[1]);
	std::string zombie_name(argv[2]);

	Zombie *horde;
	horde = zombieHorde(number, zombie_name);

	for (int i = 0; i < number; i++)
		horde[i].announce();

	delete[] horde;
}