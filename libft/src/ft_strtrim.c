/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:36:34 by tzeck             #+#    #+#             */
/*   Updated: 2022/02/16 16:19:38 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	front;
	size_t	back;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = 0;
	back = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[back - 1] && ft_strchr(set, s1[back - 1]) && back > front)
		back--;
	p = (char *)malloc((back - front + 1) * sizeof(char));
	if (p)
		ft_strlcpy(p, &s1[front], back - front + 1);
	return (p);
}
