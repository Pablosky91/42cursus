/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:41:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/04/01 22:07:16 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const AForm &other);
		AForm(std::string name);
		AForm(int grade_sign, int grade_execute);
		AForm(std::string name, int grade_sign, int grade_execute);
		virtual	~AForm();
		AForm	&operator =(const AForm &other);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		void				setSigned(bool is_signed);
		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;

		bool			beSigned(const Bureaucrat &bureaucrat);
		void			execute(const Bureaucrat &executor) const;

	private:
		const std::string	_kName;
		bool				_is_signed;
		const int			_kGrade_sign;
		const int			_kGrade_execute;

		static int	validateGrade(int grade);

		virtual void	executeAction(void) const = 0;
};

std::ostream	&operator<<(std::ostream &ostream, const AForm &form);

#endif
