/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:43:54 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:43:55 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator =(const RobotomyRequestForm &other);

	private:
		std::string	_target;

		virtual void	executeAction(void) const;
};

#endif
