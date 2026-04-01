/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:50:07 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/04/01 21:54:43 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <iostream>

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern	&operator =(const Intern &other);

		AForm	*makeForm(std::string type, std::string target);
};

#endif
