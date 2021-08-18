/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_with_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:16:00 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/17 22:11:39 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_plus_space(t_flags chart, long n)
{
	int	counter;

	counter = 0;
	if (chart.plus && n >= 0)
	{
		ft_putchar_fd('+', 1);
		counter++;
	}
	else if (chart.space && n >= 0)
	{
		ft_putchar_fd(' ', 1);
		counter++;
	}
	return (counter);
}

int	ft_precision(t_flags chart, int length)
{
	int	x;
	int	counter;

	counter = 0;
	x = (chart.precision - length);
	while (x > 0)
	{
		ft_putchar_fd('0', 1);
		x--;
		counter++;
	}
	return (counter);
}

int	ft_hashtag(int b)
{
	if (b == 0)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
	}
	else
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('X', 1);
	}
	return (2);
}
