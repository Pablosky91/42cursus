/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:02:37 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/27 13:23:39 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char** argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
			for (size_t j = 0; j < ((std::string)argv[i]).length(); j++)
				std::cout << (char)std::toupper(((std::string)argv[i])[j]);
	std::cout << std::endl;
	return 0;
}
