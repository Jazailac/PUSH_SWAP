/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:19:35 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/18 06:17:50 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	index;
	char			x;
	char			*str;

	index = 0;
	x = (char)c;
	str = (char *)s;
	while (str[index])
	{
		if (str[index] == (x))
			return (&str[index]);
		index++;
	}
	if (str[index] == x)
		return (&str[index]);
	return (NULL);
}
