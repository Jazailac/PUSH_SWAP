/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:27:07 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/10 23:48:16 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	index;
	char	*duplicated;
	size_t	len;

	index = 0;
	len = ft_strlen(s1);
	duplicated = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicated)
		return (NULL);
	while (s1[index])
	{
		duplicated[index] = s1[index];
		index++;
	}
	duplicated[index] = '\0';
	return (duplicated);
}
