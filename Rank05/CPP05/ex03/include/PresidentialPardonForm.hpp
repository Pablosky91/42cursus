/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:43:59 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:44:00 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator =(const PresidentialPardonForm &other);

	private:
		std::string	_target;

		virtual void	executeAction(void) const;
};

#endif
