/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:42:08 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/18 06:27:28 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0 || !dst)
		return (srclen);
	index = 0;
	while (index < (dstsize - 1) && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (srclen);
}
