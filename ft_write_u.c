/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:30:08 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/18 11:30:24 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_print_u_right(t_flags chart, int counter, long n)
{
	if (chart.min_field_width > 0)
	{
		if (chart.zero == 1 && n < 0 && chart.dot == 0)
		{
			chart.min_field_width--;
			ft_putchar_fd('-', 1);
			counter++;
			n *= -1;
		}
		if (chart.zero == 1 && chart.dot == 0)
			counter += ft_min_field_width(chart, ft_i_d_length(n), n, '0');
		else
			counter += ft_min_field_width(chart, ft_i_d_length(n), n, ' ');
	}
	counter += ft_precision(chart, ft_i_d_length(n));
	ft_putnbr_fd(n, 1);
	counter += ft_i_d_length(n);
	return (counter);
}

int	ft_print_u_left(t_flags chart, va_list parameters)
{
	long	n;
	long	counter;

	n = va_arg(parameters, unsigned int);
	counter = 0;
	if (chart.minus == 1)
	{
		if (chart.dot)
			counter += ft_precision(chart, ft_i_d_length(n));
		ft_putnbr_fd(n, 1);
		counter += ft_i_d_length(n);
		if (chart.min_field_width > 0)
			counter += ft_min_field_width(chart, ft_i_d_length(n), n, ' ');
	}
	else
		counter += ft_print_d_i_right(chart, counter, n);
	return (counter);
}
