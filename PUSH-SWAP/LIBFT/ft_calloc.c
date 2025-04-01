/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:45:59 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/15 04:28:09 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			total_size;

	total_size = size * count;
	str = malloc(total_size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, total_size);
	return (str);
}
