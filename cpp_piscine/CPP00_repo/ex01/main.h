/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:58:26 by jgalian-          #+#    #+#             */
/*   Updated: 2021/09/29 08:58:33 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <iostream>
# include <string>
# include <iomanip>

# include "Phonebook.hpp"

# define TRUE 1
# define FALSE 0

void showMenu(void);
short readUserSelection(void);
int exitProgram(void);
void addContact(Phonebook *pMyPhonebook);
void searchContact(Phonebook myPhonebook);

#endif
