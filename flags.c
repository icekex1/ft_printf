/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:29:55 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/06 10:37:53 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void plus_minus_space(struct s_flags *flags, int n)
{
	if (flags->plus == 1)
		if (n >= 0)
			write(1, '+', 1);
		else
			write(1, '-', 1);
	if (flags->space == 1 && flags->plus == 0) // space gets  ignored when plus is  present
	{
		if (n >= 0)
			write(1, ' ', 1);
	}	
}