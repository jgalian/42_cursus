/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 09:03:48 by jgalian-          #+#    #+#             */
/*   Updated: 2020/03/07 13:16:43 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_printf
{
	int		printed_chars_counter;
	int		str_pos;
	char	data_type;
	int		minus;
	int		zero;
	//int		point;
	int		width;
	int		precision;
	int		precision_value;
	int		spaces;
	int		zero_pad;
	va_list	args;
}				t_var;

int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_num_len(long int num);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_uns_fd(unsigned int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			get_data_type(const char *format);
void			get_flags(const char *format, t_var *var);
void			get_precision(const char *format, t_var *var);
void			get_precision_value(const char *format, t_var *var);
void			get_width(const char *format, t_var *var);
void			get_width_value(const char *format, t_var *var);
void			int_to_hex_long_un(long unsigned int num, char **str);
void			int_to_hex(t_var *var, unsigned int num, char **str);
void			itox_lower(unsigned int num, char **str);
void			itox_upper(unsigned int num, char **str);
int				percentage_found(const char *format, t_var *var);
void			print_caracter(t_var *var);
void			print_decimal(t_var *var, int n);
void			print_n_l(t_var *var, int n, int n_len);
void			print_n_r(t_var *var, int n, int n_len);
void			print_n_special(t_var *var);
int				print_sign(int n);
void			print_zeros_pad(t_var *var);
void			print_hexadecimal(t_var *var, unsigned int n);
void			print_hex_l(t_var *var, char *str, int len);
void			print_hex_r(t_var *var, char *str, int len);
void			print_hex_special(t_var *var);
void			print_percentage(t_var *var);
void			print_pointer(t_var *var, long unsigned int pointer);
void			print_ptr_l(t_var *var, char *str, int len);
void			print_ptr_r(t_var *var, char *str, int len);
void			print_ptr_special(t_var *var);
void			add_ptr_prefix(t_var *var);
void			print_spaces(t_var *var);
void			print_string(t_var *var, char *str);
void			print_str_l(t_var *var, char *str, int str_len);
void			print_str_r(t_var *var, char *str, int str_len);
void			print_unsigned(t_var *var, int n);
void			print_un_l(t_var *var, unsigned int n, int n_len);
void			print_un_r(t_var *var, unsigned int n, int n_len);
void			print_un_special(t_var *var);
void			print_zeros(t_var *var);
void			reset_temp_values(t_var *var);
void			print_spaces(t_var *var);
void			reverse_str(char **str);
void			set_initial_values(t_var *var);

#endif
