/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:44:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/31 21:44:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat	&operator =(const Bureaucrat &other);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int grade);

		void	increment(void);
		void	decrement(void);
		void	signForm(AForm &form) const;
		void	executeForm(AForm const &form) const;

	private:
		const std::string	_kName;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif
