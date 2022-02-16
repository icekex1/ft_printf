/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:43 by tzeck             #+#    #+#             */
/*   Updated: 2022/02/16 16:38:27 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_flags	default_chart(void)
{
	t_flags	chart;

	chart.minus = 0;
	chart.plus = 0;
	chart.zero = 0;
	chart.hashtag = 0;
	chart.space = 0;
	chart.min_field_width = 0;
	chart.dot = 0;
	chart.precision = -1;
	return (chart);
}

int	set_mfw_prec(const char **input, t_flags *chart, char *specifier)
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

t_flags	set_flags(const char **input)
{
	t_flags	chart;
	char	*specifier;

	chart = default_chart();
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
		if (set_mfw_prec(&(*input), &chart, specifier) == 1)
			return (chart);
		(*input)++;
	}
	return (chart);
}

int	specifier(char input, t_flags chart, va_list para, int counter)
{
	if (input == 'c')
		counter = print_c(chart, para);
	else if (input == 's')
		counter = print_s_left(chart, para);
	else if (input == 'p')
	{
		chart.hashtag = 1;
		counter = print_p_left(chart, para);
	}
	else if (input == 'd' || input == 'i')
		counter = print_d_left(chart, para);
	else if (input == 'u')
		counter = print_u_left(chart, para);
	else if (input == 'x')
		counter = print_x_left(chart, para, 0);
	else if (input == 'X')
		counter = print_x_left(chart, para, 1);
	else if (input == '%')
		counter = print_percent(chart);
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	para;
	t_flags	chart;
	int		count;
	int		fail;

	count = 0;
	va_start(para, input);
	while (input != NULL && *input != '\0')
	{
		if (*input == '%')
		{
			chart = set_flags(&input);
			fail = specifier(*input, chart, para, count);
			if (fail == -1)
				va_end(para);
			if (fail == -1)
				return (-1);
			count += fail;
		}
		else
			count += write(1, input, 1);
		input++;
	}
	va_end(para);
	return (count);
}

// #include<stdio.h>

// int	main()
// {
// 	printf("%d", printf("hello, %s.\n", NULL));
// 	printf("%d", ft_printf("hello, %s.\n", NULL));
// 	return (0);
// }