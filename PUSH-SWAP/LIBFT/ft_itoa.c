/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:35:42 by jazailac          #+#    #+#             */
/*   Updated: 2024/11/18 03:32:48 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_count(int n)
{
	int	index;

	index = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n *= -1;
		index += 1;
	}
	while (n)
	{
		n = n / 10;
		index++; 
	}
	return (index);
}

static void	handle(char *str, int *n)
{
	if (*n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		*n = 147483648;
	}
	else if (*n < 0)
	{
		str[0] = '-';
		*n *= (-1);
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		index;

	count = get_count(n);
	str = malloc((sizeof(char) * count) + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	handle(str, &n);
	index = count - 1;
	while (n >= 10)
	{
		str[index] = (n % 10) + '0';
		n = n / 10;
		index--;
	}
	str[index] = n + '0';
	return (str);
}
