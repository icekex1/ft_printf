/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:28:57 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/18 11:26:17 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include<stdarg.h>
# include<stdlib.h>
# include<unistd.h>
# include"libft/libft.h"

typedef struct s_bonus_flags
{
	int	minus;
	int	plus;
	int	zero;
	int	hashtag;
	int	space;
	int	min_field_width;
	int	dot;
	int	precision;

}	t_flags;
int		ft_printf(const char *input, ...);
t_flags	ft_default_chart(void);
t_flags	ft_set_t_flags(const char **input);
int		ft_set_mfw_p(const char **input, t_flags *chart, char *specifier);
int		ft_specifier(char input, t_flags chart, va_list parameters, int count);
int		ft_i_d_length(long n);
int		ft_hexa_length(unsigned long n);
int		ft_print_d_i_left(t_flags chart, va_list parameters);
int		ft_print_u_left(t_flags chart, va_list parameters);
int		ft_print_d_i_right(t_flags chart, int count, long n);
int		ft_print_u_right(t_flags chart, int counter, long n);
int		ft_plus_space(t_flags chart, long n);
int		ft_precision(t_flags chart, int length);
int		ft_min_field_width(t_flags chart, int length, long n, char zero);
int		ft_mfw_2(int x, t_flags chart, int length, char zero);
int		ft_mfw_3(int x, t_flags chart, int length, char zero);
int		ft_print_hex_right(t_flags chart, int counter, long n, int b);
int		ft_print_hex_left(t_flags chart, va_list parameters, int b);
void	ft_zero_case(long n, int b);
int		ft_hashtag(int b);
int		ft_print_p_left(t_flags chart, va_list parameters);
int		ft_print_p_right(t_flags chart, int counter, unsigned long n);
int		ft_print_c(t_flags chart, va_list parameters);
int		ft_print_percentage_sign(t_flags chart);
int		ft_print_s_left(t_flags chart, va_list parameters);
int		ft_print_s_right(t_flags chart, char *string, int counter, int length);
int		mfw(t_flags chart, int length);
char	*ft_null_check(char	*string);
void	ft_zero_case(long n, int b);
int		negative_number(long *n, int counter);

#endif
