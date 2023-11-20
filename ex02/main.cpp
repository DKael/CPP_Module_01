/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:15:19 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 17:45:08 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str("HI THIS IS BRAIN");
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "memory address of the str : " << &str << '\n';
	std::cout << "memory address held by stringPTR : " << stringPTR << '\n';
	std::cout << "memory address held by stringREF : " << &stringREF << '\n';

	std::cout << "value of str : " << str << '\n';
	std::cout << "value pointed to by stringPTR : " << *stringPTR << '\n';
	std::cout << "value pointed to by stringREF : " << stringREF << '\n';
}