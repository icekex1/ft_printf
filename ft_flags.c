/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_with_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:58:03 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/19 11:58:05 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	plus_space(t_flags chart, long n)
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

int	precision(t_flags chart, int length)
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

int	hashtag(int b)
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
