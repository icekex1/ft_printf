/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:11:43 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/18 11:51:27 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"
#include <stdio.h>

t_flags	ft_default_chart(void)
{
	t_flags	default_chart;

	default_chart.minus = 0;
	default_chart.plus = 0;
	default_chart.zero = 0;
	default_chart.hashtag = 0;
	default_chart.space = 0;
	default_chart.min_field_width = 0;
	default_chart.dot = 0;
	default_chart.precision = -1;
	return (default_chart);
}

int	ft_set_mfw_p(const char **input, t_flags *chart, char *specifier)
{
	if (**input <= '9' && **input >= '0')
		chart->min_field_width = ft_atoi(*input);
	while (ft_isdigit(**input) && ft_isdigit(*(*input + 1)))
		(*input)++;
	if (**input == '.')
	{
		chart->dot = 1;
		(*input)++;
		if (**input <= '9' && **input >= '0')
			chart->precision = ft_atoi(*input);
		if (ft_strchr(specifier, **input))
		{
			chart->precision = 0;
			return (1);
		}
		while (ft_isdigit(**input) && ft_isdigit(*(*input + 1)))
			(*input)++;
	}
	return (0);
}

t_flags	ft_set_flags(const char **input)
{
	t_flags	chart;
	char	*specifier;

	chart = ft_default_chart();
	specifier = "cspdiuxX%";
	(*input)++;
	while (ft_strchr(specifier, **input) == NULL)
	{
		if (**input == '-')
			chart.minus = 1;
		if (**input == '+')
			chart.plus = 1;
		if (**input == '0')
			chart.zero = 1;
		if (**input == '#')
			chart.hashtag = 1;
		if (**input == ' ')
			chart.space = 1;
		if (ft_set_mfw_p(&(*input), &chart, specifier) == 1)
			return (chart);
		(*input)++;
	}
	return (chart);
}

int	ft_specifier(char input, t_flags chart, va_list para, int counter)
{
	if (input == 'c')
		counter = ft_print_c(chart, para);
	else if (input == 's')
		counter = ft_print_s_left(chart, para);
	else if (input == 'p')
	{
		chart.hashtag = 1;
		counter = ft_print_p_left(chart, para);
	}
	else if (input == 'd' || input == 'i')
		counter = ft_print_d_i_left(chart, para);
	else if (input == 'u')
		counter = ft_print_u_left(chart, para);
	else if (input == 'x')
		counter = ft_print_hex_left(chart, para, 0);
	else if (input == 'X')
		counter = ft_print_hex_left(chart, para, 1);
	else if (input == '%')
		counter = ft_print_percentage_sign(chart);
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	para;
	t_flags	chart;
	int		babo_count;

	babo_count = 0;
	va_start(para, input);
	while (input != NULL && *input != '\0')
	{
		if (*input == '%')
		{
			chart = ft_set_flags(&input);
			babo_count += ft_specifier(*input, chart, para, babo_count);
		}
		else
			babo_count += write(1, input, 1);
		input++;
	}
	va_end(para);
	return (babo_count);
}
#include<stdio.h>

int	main()
{
	printf("%d", printf("hello, %s.\n", NULL));
	printf("%d", ft_printf("hello, %s.\n", NULL));
	return (0);
}