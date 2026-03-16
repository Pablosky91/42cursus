/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:55:19 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/16 16:47:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

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
		void	signForm(Form &form) const;

	private:
		const std::string	_kName;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif
