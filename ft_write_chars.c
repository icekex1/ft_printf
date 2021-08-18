/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:52:25 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/17 22:31:34 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_c(t_flags chart, va_list parameters)
{
	char	c;
	int		counter;

	c = va_arg(parameters, int);
	counter = 0;
	if (chart.minus == 1)
	{
		ft_putchar_fd(c, 1);
		counter++;
		counter += ft_min_field_width(chart, 1, c, ' ');
	}
	else
	{
		counter += ft_min_field_width(chart, 1, c, ' ');
		ft_putchar_fd(c, 1);
		counter++;
	}
	return (counter);
}

int	ft_print_percentage_sign(t_flags chart)
{
	char	c;
	int		counter;

	c = '%';
	counter = 0;
	if (chart.minus == 1)
	{
		ft_putchar_fd(c, 1);
		counter++;
		if (chart.min_field_width > 0)
			counter += ft_min_field_width(chart, 1, c, ' ');
	}
	else
	{
		if (chart.min_field_width > 0)
		{
			if (chart.zero == 1)
				counter += ft_min_field_width(chart, 1, c, '0');
			else
				counter += ft_min_field_width(chart, 1, c, ' ');
		}
		ft_putchar_fd(c, 1);
		counter++;
	}
	return (counter);
}
