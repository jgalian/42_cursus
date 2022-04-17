/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:59:14 by jgalian-          #+#    #+#             */
/*   Updated: 2021/09/30 10:31:49 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "Phonebook.hpp"

Phonebook::Phonebook(short num) : index(num)
{
	return ;
}

Phonebook::~Phonebook()
{
	return ;
}

void Phonebook::incrementIndex(void)
{
	this->index = this->index + 1;
}

unsigned short Phonebook::getIndex(void) const
{
	return (this->index);
}

void Phonebook::setIndex()
{
	this->index = 0;
}
