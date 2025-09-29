/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:53:15 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/09/29 19:54:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace filename string_to_replace new_string" << std::endl;
		return (1);
	}
	std::string infile = argv[1];
	std::string outfile = infile + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file_in(infile.c_str()); // Open a file to read
	if (!file_in)
	{
		std::perror((((std::string)"Could not open file ").append(infile)).c_str());
		return (2);
	}
	std::ofstream file_out(outfile.c_str()); // Open a file to write
	if (!file_out)
	{
		std::perror((((std::string)"Could not open file ").append(outfile)).c_str());
		file_in.close();
		return (3);
	}
	std::string line;
	while (std::getline(file_in, line))
	{
		file_out << line << std::endl;
	}
	file_in.close();
	file_out.close();
	return (0);
}
