/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:29:59 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/20 22:07:40 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# ifndef LIST_SIZE
#  define LIST_SIZE 4
# endif

class Harl
{
private:
	
	void (Harl::*func_ptr[LIST_SIZE])(void);

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl();
	void complain(std::string level);
};

#endif