/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:18:51 by jyap              #+#    #+#             */
/*   Updated: 2024/09/17 23:00:42 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_full = false;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::set_information(void)
{
	std::string input;
	if (this->_full == false)
	{
		std::cout << "This is your contact #" << this->_index + 1 << std::endl;
		if (this->_contacts[this->_index].set_contact() == true)
		{
			if (this->_index == 7)
				this->_full = true;
			else
				this->_index++;
		}
		return ;
	}	
	std::cout << "PhoneBook is full.\nAdding a new entry will replace the oldest entry which is stored at index #1." << std::endl;
	std::cout << "To proceed with creating new entry, press '1' and press 'enter'.\nElse, press anything but '1' and 'enter' to go back to main menu." << std::endl;
	std::cout << "Your choice: ";
	std::getline(std::cin, input);
	if (std::cin.eof() == true)
	{
		std::cout << "You Pressed ^D. Exiting PhoneBook ..." << std::endl;
		std::exit(0);
	}
	else if (input.compare("1") == 0)
	{
		for (int i = 1; i < 8; i++)
			this->_contacts[i - 1] = this->_contacts[i];
		std::cout << "This is your contact #8" << std::endl;
		this->_contacts[this->_index].set_contact();
	}
	else
		std::cout << "Back to main menu without deleting and creating a contact." << std::endl;
}

void	PhoneBook::get_information() const
{
	int	index;

	if (this->_index == 0)
	{
		std::cout << "You do not have any contacts saved." << std::endl;
		return ;
	}
	std::string input;
	std::cout << "Please provide the index of the entry to display. (0 to quit search)\nIndex: ";
	std::getline(std::cin, input);
	while (1)
	{
		if (std::cin.eof() == true)
		{
			std::cout << "You Pressed ^D. Exiting PhoneBook ..." << std::endl;
			std::exit(0);
		}
		else if (input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0)
		{
			std::cout << "Only digits in range of 1 to 8 are allowed.\n";
			std::cout << "Please provide the index of the entry to display. (0 to quit search)\nIndex: ";
		}
		else if (std::atoi(input.c_str()) > this->_index)
		{
			std::cout << "You only have " << this->_index << " Contacts saved." << std::endl;
			std::cout << "Please provide the index of the entry to display. (0 to quit search)\nIndex: ";
		}
		else
			break ;
		std::cin.clear();
		std::getline(std::cin, input);
	}
	index = std::atoi(input.c_str());
	if (index > 0)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		this->_contacts[index - 1].get_contact(index);
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	else
		std::cout << "Exiting search mode now." << std::endl;
	
}

void	PhoneBook::show_instruction(void)
{
	std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
}