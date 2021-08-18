/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:24:25 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/18 11:31:58 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	mfw(t_flags chart, int length)
{
	int	counter;

	counter = 0;
	while (chart.min_field_width > length)
	{
		ft_putchar_fd(' ', 1);
		chart.min_field_width--;
		counter++;
	}
	return (counter);
}

char	*ft_null_check(char	*string)
{
	if (string == NULL)
		return ("(null)");
	else
		return (string);
}

int	ft_print_s_right(t_flags chart, char *string, int counter, int length)
{
	if (chart.precision >= 0 && chart.precision < length)
		length = chart.precision;
	counter = mfw(chart, length);
	write(1, string, length);
	counter += length;
	return (counter);
}

int	ft_print_s_left(t_flags chart, va_list parameters)
{
	int		counter;
	char	*string;
	int		length;

	counter = 0;
	string = ft_null_check(va_arg(parameters, char *));
	length = ft_strlen(string);
	if (chart.minus)
	{
		if (chart.precision >= 0 && chart.precision < length)
			length = chart.precision;
		write(1, string, length);
		counter = length;
		if (chart.min_field_width)
			counter += mfw(chart, length);
	}
	else
		counter = ft_print_s_right(chart, string, counter, length);
	return (counter);
}
