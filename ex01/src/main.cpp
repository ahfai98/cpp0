/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:19:08 by jyap              #+#    #+#             */
/*   Updated: 2024/09/17 23:17:53 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>

int main(void)
{
	PhoneBook 	PhoneBook;
	std::string	command;

	PhoneBook.show_instruction();
	std::cout << "$>";
	std::getline(std::cin, command);
	while (1)
	{
		if (std::cin.eof() == true)
		{
			std::cout << "You Pressed ^D. Exiting PhoneBook ..." << std::endl;
			std::exit(0);
		}
		for (size_t i = 0; i < command.length(); ++i)
			command[i] = std::toupper(command[i]);
		if (command.compare("ADD") == 0)
			PhoneBook.set_information();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.get_information();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "Exiting PhoneBook ..." << std::endl;
			exit(0);
		}
		command.clear();
		PhoneBook.show_instruction();
		std::cout << "$>";
		std::getline(std::cin, command);
	}
	return (0);
}