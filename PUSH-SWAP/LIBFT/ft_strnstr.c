/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:11:53 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/15 04:31:51 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	n_index;
	size_t	start;

	index = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[index] && index < len)
	{
		n_index = 0;
		start = index;
		while (haystack[index] && needle[n_index] 
			&& needle[n_index] == haystack[index] && index < len)
		{
			index++;
			n_index++;
			if (needle[n_index] == '\0')
				return ((char *)&haystack[start]);
		}
		index = start + 1;
	}
	return (NULL);
}
