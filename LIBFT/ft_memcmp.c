/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:49:25 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/18 06:09:00 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_p;
	const unsigned char	*s2_p;
	size_t				index;

	index = 0;
	s1_p = (const unsigned char *)s1;
	s2_p = (const unsigned char *)s2;
	while (index < n)
	{
		if (s1_p[index] != s2_p[index])
			return (s1_p[index] - s2_p[index]);
		index++;
	}
	return (0);
}
