/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:32:42 by tzeck             #+#    #+#             */
/*   Updated: 2022/02/16 16:19:10 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return (&ptr[i]);
		i++;
	}
	if (c == '\0')
		return (&ptr[i]);
	else
		return (NULL);
}
