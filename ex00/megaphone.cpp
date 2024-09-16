/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:46:46 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 22:00:53 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i = 1;
	int	j = 0;

	if (ac < 2) 
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; return (0);
	}
	while (i < ac)
	{
		while (av[i][j] != '\0')
		{
			std::cout << (char)std::toupper(av[i][j]);
			j++;
		}
		j = 0;
		i++;
		if (av[i] != NULL)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}