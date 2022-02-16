/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:32 by tzeck             #+#    #+#             */
/*   Updated: 2022/02/16 16:38:34 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	print_c(t_flags chart, va_list parameters)
{
	char	c;
	int		counter;

	c = va_arg(parameters, int);
	counter = 0;
	if (chart.minus == 1)
	{
		ft_putchar_fd(c, 1);
		counter++;
		counter += mfw(chart, 1, c, ' ');
	}
	else
	{
		counter += mfw(chart, 1, c, ' ');
		ft_putchar_fd(c, 1);
		counter++;
	}
	return (counter);
}

int	print_percent(t_flags chart)
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
			counter += mfw(chart, 1, c, ' ');
	}
	else
	{
		if (chart.min_field_width > 0)
		{
			if (chart.zero == 1)
				counter += mfw(chart, 1, c, '0');
			else
				counter += mfw(chart, 1, c, ' ');
		}
		ft_putchar_fd(c, 1);
		counter++;
	}
	return (counter);
}
