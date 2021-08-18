/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:46:03 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/17 22:40:18 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_p_right(t_flags chart, int counter, unsigned long n)
{
	if (chart.min_field_width > 0)
	{
		if (chart.hashtag)
			chart.min_field_width -= 2;
		counter += ft_min_field_width(chart, ft_hexa_length(n), n, ' ');
	}
	counter += ft_hashtag(0);
	if (n == 0)
		ft_putchar_fd('0', 1);
	else
		ft_puthexa(n);
	counter += ft_hexa_length(n);
	return (counter);
}

int	ft_print_p_left(t_flags chart, va_list parameters)
{
	unsigned long	n;
	int				counter;

	n = va_arg(parameters, unsigned long);
	counter = 0;
	if (chart.minus == 1)
	{
		if (chart.hashtag)
			counter += ft_hashtag(0);
		if (n == 0)
			ft_putchar_fd('0', 1);
		else
			ft_puthexa(n);
		counter += ft_hexa_length(n);
		if (chart.min_field_width > 0)
			counter += ft_min_field_width(chart, ft_hexa_length(n) + 2, n, ' ');
	}
	else
		counter = ft_print_p_right(chart, counter, n);
	return (counter);
}
