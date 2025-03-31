/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:36:35 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/15 04:32:02 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	x;

	index = ft_strlen(s);
	x = (char)c;
	while ((index + 1) > 0)
	{
		if (s[index] == x)
			return ((char *)&s[index]);
		index--;
	}
	return (NULL);
}
