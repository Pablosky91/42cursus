/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:58:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/12 21:20:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

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

		const std::string	get_name(void) const;
		int					get_grade(void) const;
		void				set_grade(int grade);

		void	increment();
		void	decrement();

		class GradeTooHighException: public std::exception
		{
			virtual const char	*what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			virtual const char	*what() const throw();
		};

	private:
		const std::string	_kName;
		int					_grade;

};

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif
