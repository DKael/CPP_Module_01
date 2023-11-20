/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:38:43 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 20:54:21 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of parameter\n";
		return 1;
	}
	std::string s1(argv[2]);
	if (s1.length() == 0)
	{
		std::cout << "parameter 2 must not be empty string!\n";
		return 1;
	}
	std::string s2(argv[3]);
	std::ifstream fin;
	std::ofstream fout;
	std::string contents;

	fin.open(std::string(argv[1]));
	if (fin.is_open() == false)
	{
		std::cout << "File open error!\n";
		return 1;
	}
	std::istreambuf_iterator<char> begin(fin), end;
	contents = std::string(begin, end);
	fin.close();

	size_t idx = 0;
	size_t f_idx;
	while ((f_idx = contents.find(s1, idx)) != std::string::npos)
	{
		contents.erase(f_idx, s1.length());
		contents.insert(f_idx, s2);
		idx = f_idx + s2.length();
	}

	fout.open(std::string(argv[1]) + std::string(".replace"));
	if (fout.is_open() == false)
	{
		std::cout << "File open error!\n";
		return 1;
	}
	fout << contents;

	fout.close();
}