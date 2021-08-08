/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:09:01 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/07 10:52:58 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int				minus;
	int				zero;
	int				dot_n;
	int				plus;
	int				space;
	int				hash;
	struct s_flags	*next;
}					t_flags;

int	write_char(struct s_flags *flags, va_list args);
int	write_string(struct s_flags *flags, va_list args);
int	write_pointer(struct s_flags *flags, va_list args);
int	write_int(struct s_flags *flags, va_list args);
int	write_uint(struct s_flags *flags, va_list args);
int	write_hexa(struct s_flags *flags, va_list args);
int	write_hexa(struct s_flags *flags, va_list args);

static void plus_minus_space(struct s_flags *flags, int n);

#endif