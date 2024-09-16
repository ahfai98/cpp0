/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:19:08 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 23:11:15 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


int main(void)
{
	PhoneBook 	PhoneBook;
	std::string	command;

	PhoneBook.show_instruction();
	std::cout << "\033[33m$>\033[0m";
	while (std::getline(std::cin, command))
	{
		if (command.compare("ADD") == 0 || command.compare("add") == 0)
			PhoneBook.set_information();
		else if (command.compare("SEARCH") == 0 || command.compare("search") == 0)
			PhoneBook.get_information();
		else if (command.compare("EXIT") == 0 || command.compare("exit") == 0)
		{
			std::cout << "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
			exit(0);
		}
		command.clear();
		PhoneBook.show_instruction();
		std::cout << "\033[33m$>\033[0m";
	}
	std::cout << "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
	return (0);
}