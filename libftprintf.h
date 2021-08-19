/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:56:41 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/19 12:01:10 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include<stdarg.h>
# include<stdlib.h>
# include<unistd.h>
# include"libft/libft.h"
# include <stdio.h>

typedef struct s_flags
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
t_flags	default_chart(void);
t_flags	set_t_flags(const char **input);
int		set_mfw_prec(const char **input, t_flags *chart, char *specifier);
int		specifier(char input, t_flags chart, va_list parameters, int count);
int		d_length(long n);
int		x_length(unsigned long n);
int		print_d_left(t_flags chart, va_list parameters);
int		print_u_left(t_flags chart, va_list parameters);
int		print_d_right(t_flags chart, int count, long n);
int		print_u_right(t_flags chart, int counter, long n);
int		plus_space(t_flags chart, long n);
int		precision(t_flags chart, int length);
int		mfw(t_flags chart, int length, long n, char zero);
int		mfw_2(int x, t_flags chart, int length, char zero);
int		mfw_3(int x, t_flags chart, int length, char zero);
int		print_x_right(t_flags chart, int counter, long n, int b);
int		print_x_left(t_flags chart, va_list parameters, int b);
void	zero_case(long n, int b, t_flags chart);
int		hashtag(int b);
int		print_p_left(t_flags chart, va_list parameters);
int		print_p_right(t_flags chart, int counter, unsigned long n);
int		print_c(t_flags chart, va_list parameters);
int		print_percent(t_flags chart);
int		print_s_left(t_flags chart, va_list parameters);
int		print_s_right(t_flags chart, char *string, int counter, int length);
int		mfw_string(t_flags chart, int length);
char	*null_check(char *string, int *is_null);
int		negative_number(long *n, int counter);
int		print_nothing(t_flags chart, long n);

#endif
