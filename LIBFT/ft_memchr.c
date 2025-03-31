/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:38:08 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/18 06:15:12 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_p;
	size_t			index;

	s_p = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (s_p[index] == (unsigned char)c)
			return (&s_p[index]);
		index++;
	}
	return (NULL);
}
