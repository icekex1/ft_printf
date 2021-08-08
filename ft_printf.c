/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:03:54 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/07 10:52:40 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	write_intt(struct s_flags *flags, va_list args)
{
	printf("here");
	return (1);
}

static int	check_format(const char *s, int i, va_list args, struct s_flags *flags) //calls format functions
{
	if (s[i] == 'c')
		i = 3;//write_char(flags, args);
	else if (s[i] == 's')
		i = 3;//write_string(flags, args);
	else if (s[i] == 'p')
		i = 3;//write_pointer(flags, args);
	else if (s[i] == 'd' || s[i] == 'i')
		write_intt(flags, args);
	else if (s[i] == 'u')
		i = 3;//write_uint(flags, args);
	else if (s[i] == 'x' || s[i] == 'X')
		i = 3;//write_hexa(flags, args);
	else if (s[i] == '%')
		i = 3;//write(1, "1", 1);
	return 1;
}

static int	check_flag(const char *s, int i, va_list args) // sets flags for format
{
	struct s_flags	*flags;
	flags = malloc(sizeof(struct s_flags));
	if (flags == NULL)
		return (0);
	while (s[i] != 'c' && s[i] != 's' &&  s[i] != 'p' &&  s[i] != 'd' &&  s[i] != 'i' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != '%')
	{
		if (s[i] == '-')
			flags->minus = 1;
		else if (s[i] == '0')
			flags->zero = 1;
		else if (s[i] == '.')
			flags->dot_n = 1;
		else if (s[i] == '+')
			flags->plus = 1;
		else if (s[i] == ' ')
			flags->space = 1;
		else if (s[i] == '#')
			flags->hash = 1;
		i++;
	}
	check_format(s, i, args, flags);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	va_list args;
	
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			check_flag(s, i, args); //calls check_format which calls the write functions
		}
		else
			write(1, &s[i], sizeof(char));
		i++;
	}
	va_end(args);
	return (1);
}

int	main()
{
	ft_printf("hello%d\n", 5);
	return 1;
	njjkjfrkjjfkljfkljkrrjkodfjkodfjviopvdrj jfkjkjfoijrfiojj
}