/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mfw_extensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:25:23 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/17 22:14:15 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_min_field_width(t_flags chart, int length, long n, char zero)
{
	int	x;
	int	counter;

	x = 0;
	counter = 0;
	if (chart.min_field_width > chart.precision && chart.precision > length)
	{
		if (n < 0)
			x = chart.min_field_width - chart.precision - 1;
		else
			x = chart.min_field_width - chart.precision;
		while (x > 0)
		{
			ft_putchar_fd(zero, 1);
			x--;
			counter++;
		}
	}
	else if (chart.min_field_width > length && chart.dot == 0)
		counter = ft_mfw_2(x, chart, length, zero);
	else if (chart.min_field_width > chart.precision
		&& chart.min_field_width > length)
		counter = ft_mfw_3(x, chart, length, zero);
	return (counter);
}

int	ft_mfw_2(int x, t_flags chart, int length, char zero)
{
	int	counter;

	counter = 0;
	x = chart.min_field_width - length;
	while (x > 0)
	{
		ft_putchar_fd(zero, 1);
		x--;
		counter++;
	}
	return (counter);
}

int	ft_mfw_3(int x, t_flags chart, int length, char zero)
{
	int	counter;

	counter = 0;
	chart.min_field_width--;
	x = chart.min_field_width - length;
	while (x > 0)
	{
		ft_putchar_fd(zero, 1);
		x--;
		counter++;
	}
	return (counter);
}
