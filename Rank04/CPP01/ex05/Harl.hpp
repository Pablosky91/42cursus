/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:51:09 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/07 11:01:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <map>

class Harl
{
	public:
		void complain(std::string level);

	private:
		typedef std::map<std::string, void (Harl::*)(void)> t_HarlMap;

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif