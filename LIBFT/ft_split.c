/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:27:41 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/18 04:29:56 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c && x != 0)
			x = 0;
		str++;
	}
	return (count);
}

static char	*get_words(const char *str, int start, int end)
{
	char	*word;
	int		index;

	index = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[index] = str[start];
		index++;
		start++;
	}
	word[index] = '\0';
	return (word);
}

static char	**free_split(char **str, int j)
{
	while (j--)
		free(str[j]);
	free(str);
	return (NULL);
}

static char	**check_and_return(const char *s, char c)
{
	char	**str;
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	start = 0;
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] && j < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[j] = get_words(s, start, i);
		if (!str[j])
			return (free_split(str, j));
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	if (!s)
		return (NULL);
	return (check_and_return(s, c));
}
