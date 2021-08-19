/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:01 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/19 11:57:03 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	mfw_string(t_flags chart, int length)
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

char	*null_check(char *string, int *is_null)
{
	if (string == NULL)
	{
		*is_null = 1;
		return (ft_strdup("(null)"));
	}
	*is_null = 0;
	return (string);
}

int	print_s_right(t_flags chart, char *string, int counter, int length)
{
	if (chart.precision >= 0 && chart.precision < length)
		length = chart.precision;
	counter = mfw_string(chart, length);
	write(1, string, length);
	counter += length;
	return (counter);
}

int	print_s_left(t_flags chart, va_list parameters)
{
	int		counter;
	char	*string;
	int		length;
	int		is_null;

	counter = 0;
	string = null_check(va_arg(parameters, char *), &is_null);
	if (string == NULL)
		return (-1);
	length = ft_strlen(string);
	if (chart.minus)
	{
		if (chart.precision >= 0 && chart.precision < length)
			length = chart.precision;
		write(1, string, length);
		counter = length;
		if (chart.min_field_width)
			counter += mfw_string(chart, length);
	}
	else
		counter = print_s_right(chart, string, counter, length);
	if (is_null == 1)
		free(string);
	return (counter);
}
