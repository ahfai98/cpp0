/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:18:22 by jyap              #+#    #+#             */
/*   Updated: 2024/09/17 22:59:31 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_fields_name[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->_informations[i] = std::string();
	return;
}

Contact::~Contact()
{
}

bool	Contact::set_contact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "Please enter the " << Contact::_fields_name[i] << ":\n$>";
		std::getline(std::cin, this->_informations[i]);
		while (1)
		{
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting PhoneBook ..." << std::endl;
				std::exit(0);
			}
			else if (this->_informations[i].length() == 0)
			{
				std::cout << "Empty contact information not allowed." << std::endl;
				std::cout << "Please enter the " << Contact::_fields_name[i] << ":\n$>";
				this->_informations[i].clear();
				std::getline(std::cin, this->_informations[i]);
			}
			else
				break ;
		}
	}
	std::cout << "Contact added successfully." << std::endl;
	return (true);
}

void	Contact::get_contact(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	for (int i = FirstName; i <= NickName; i++)
	{
		std::cout << "|";
		if (this->_informations[i].length() > 10)
			std::cout << this->_informations[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_informations[i];
	}
	std::cout << "|" << std::endl;
}