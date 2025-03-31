/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:22:10 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/12 06:15:28 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	substr_len;
	char	*substr;

	substr_len = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= ft_strlen(s))
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr); 
	}
	substr_len = len;
	if (substr_len + start >= s_len)
		substr_len = s_len - start;
	substr = malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, substr_len);
	substr[substr_len] = '\0';
	return (substr);
}
