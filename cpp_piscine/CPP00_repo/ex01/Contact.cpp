/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:59:26 by jgalian-          #+#    #+#             */
/*   Updated: 2021/09/30 08:46:07 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void Contact::addFirstName(std::string name)
{
	this->firstName = name;
	std::cout << "\t" << name << " was added as the first name of the new contact." << std::endl;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getShortFirstName() const
{
	std::string	str;

	if (this->firstName.length() <= 10)
		return (this->firstName);
	str = this->firstName.substr(0, 9);
	str.append(".");
	return (str);
}

void Contact::addLastName(std::string name)
{
	this->lastName = name;
	std::cout << "\t" << name << " was added as the last name of the new contact." << std::endl;
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getShortLastName() const
{
	std::string	str;

	if (this->lastName.length() <= 10)
		return (this->lastName);
	str = this->lastName.substr(0, 9);
	str.append(".");
	return (str);
}

void Contact::addNickname(std::string name)
{
	this->nickname = name;
	std::cout << "\t" << name << " was added as the nickname of the new contact." << std::endl;
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}

std::string Contact::getShortNickname() const
{
	std::string	str;

	if (this->nickname.length() <= 10)
		return (this->nickname);
	str = this->nickname.substr(0, 9);
	str.append(".");
	return (str);
}

void Contact::addDarkestSecret(std::string name)
{
	this->darkestSecret = name;
	std::cout << "\t" << name << " was added as the darkest secret of the new contact.\n";
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}

void Contact::addPhoneNumber(std::string num)
{
	this->phoneNumber = num;
	std::cout << "\t" << num << " was added as the phone number of the new contact." << std::endl;
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}
