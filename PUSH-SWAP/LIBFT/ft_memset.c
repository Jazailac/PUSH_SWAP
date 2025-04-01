/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:56:08 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/15 04:30:17 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*bucket;

	index = 0;
	bucket = (unsigned char *)b;
	while (index < len)
	{
		bucket[index] = (unsigned char )c;
		index++;
	}
	return (b);
}
