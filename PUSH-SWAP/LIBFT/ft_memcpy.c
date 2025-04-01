/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 04:02:50 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/17 06:13:12 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				index;

	if (!src && !dst)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s == d)
		return (dst);
	index = 0;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (dst);
}
