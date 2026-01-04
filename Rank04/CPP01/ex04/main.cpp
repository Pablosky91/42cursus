/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:53:15 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/01/04 00:53:06 by pdel-olm         ###   ########.fr       */
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
	if (s1.empty())
	{
		std::cerr << "The string to replace may not be empty" << std::endl;
		return (2);
	}
	std::string s2 = argv[3];
	std::ifstream file_in(infile.c_str());
	if (!file_in)
	{
		std::perror((((std::string)"Could not open file ").append(infile)).c_str());
		return (3);
	}
	std::ofstream file_out(outfile.c_str());
	if (!file_out)
	{
		std::perror((((std::string)"Could not open file ").append(outfile)).c_str());
		file_in.close();
		return (4);
	}
	std::string line;
	while (std::getline(file_in, line))
	{
		std::size_t pos = line.find(s1);
		while (pos != line.npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + 1);
		}
		file_out << line;
		if (!file_in.eof())
			file_out << std::endl;
	}
	file_in.close();
	file_out.close();
	return (0);
}
