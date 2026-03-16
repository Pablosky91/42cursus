/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/03/16 15:52:25 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const Form &other);
		Form(std::string name);
		Form(int grade_sign, int grade_execute);
		Form(std::string name, int grade_sign, int grade_execute);
		~Form();
		Form	&operator =(const Form &other);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		void				setSigned(bool is_signed);
		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;

		bool	beSigned(const Bureaucrat &bureaucrat);
		
	private:
		const std::string	_kName;
		bool				_is_signed;
		const int			_kGrade_sign;
		const int			_kGrade_execute;
		
		static int	validateGrade(int grade);
};

std::ostream	&operator<<(std::ostream &ostream, const Form &form);

#endif
