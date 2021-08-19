/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mfw_extensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/19 11:57:58 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	mfw(t_flags chart, int length, long n, char zero)
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
		counter = mfw_2(x, chart, length, zero);
	else if (chart.min_field_width > chart.precision
		&& chart.min_field_width > length)
		counter = mfw_3(x, chart, length, zero);
	return (counter);
}

int	mfw_2(int x, t_flags chart, int length, char zero)
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

int	mfw_3(int x, t_flags chart, int length, char zero)
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
