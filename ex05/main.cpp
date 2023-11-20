/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:38:43 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 21:58:48 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of parameter\n";
		return 1;
	}

	Harl harl2;

	harl2.complain(std::string(argv[1]));
}