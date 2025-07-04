/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:17:24 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/07/04 12:50:07 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook(void);

		bool	add(void);
		bool	search(void);

	private:
		static const int	MAX_CONTACTS = 8;

		Contact	contacts[MAX_CONTACTS];
		int		contact_count;

		void	display_table(void);
		void	display_row(std::string str0, std::string str1, std::string str2, std::string str3);
		void	display_row(int row, std::string str1, std::string str2, std::string str3);

};

#endif
