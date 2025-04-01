/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:00:18 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/18 06:24:35 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	index;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	index = 0;
	if (dst_len >= size)
		return (size + src_len);
	while (src[index] && (dst_len + index + 1) < size)
	{
		dst[dst_len + index] = src[index];
		index++;
	}
	dst[dst_len + index] = '\0';
	return (dst_len + src_len);
}
