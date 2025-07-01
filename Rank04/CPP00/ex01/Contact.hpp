/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:17:27 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/07/01 19:32:14 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

		bool		set_field(std::string *field, std::string name);
		std::string	get_field_short(std::string field);

	public:		
		bool		add(void);
		void		display(void);

		std::string	get_first_name_short(void);
		std::string	get_last_name_short(void);
		std::string	get_nickname_short(void);
};

#endif
