/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:59:22 by jgalian-          #+#    #+#             */
/*   Updated: 2021/09/30 08:45:21 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACTS_HPP_
# define _CONTACTS_HPP_

#include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		void addFirstName(std::string name);
		std::string getFirstName() const;
		std::string getShortFirstName() const;
		void addLastName(std::string name);
		std::string getLastName() const;
		std::string getShortLastName() const;
		void addNickname(std::string name);
		std::string getNickname() const;
		std::string getShortNickname() const;
		void addDarkestSecret(std::string name);
		std::string getDarkestSecret() const;
		void addPhoneNumber(std::string num);
		std::string getPhoneNumber() const;

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif
