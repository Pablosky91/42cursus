/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 10:32:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/08/20 17:09:09 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN	&operator =(const RPN &other);

		void	new_token(std::string token);
		int		get_result(void);

	private:
		std::stack<long>	_stack;

		void	operate(std::string token);
};

#endif
