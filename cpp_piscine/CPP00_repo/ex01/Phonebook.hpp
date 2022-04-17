/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:59:19 by jgalian-          #+#    #+#             */
/*   Updated: 2021/09/30 10:31:40 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define NUM_CONTACTS 8

class Phonebook
{
	public:
		Phonebook(short num);
		~Phonebook();
		void			incrementIndex();
		void			setIndex();
		unsigned short	getIndex() const;
		Contact contacts[NUM_CONTACTS];

	private:
		short	index;
};

#endif
