/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 04:26:36 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/18 06:12:56 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		index;
	const char	*src_p;
	char		*dst_p;

	dst_p = (char *)dst;
	src_p = (const char *)src;
	index = 0;
	if (dst_p == src_p)
		return (dst);
	if (!dst_p && !src_p)
		return (NULL);
	if (dst_p > src_p)
	{
		while (len-- > 0)
			dst_p[len] = src_p[len];
	}
	else 
	{
		while (index < len)
		{
			dst_p[index] = src_p[index];
			index++;
		}
	}
	return (dst);
}
