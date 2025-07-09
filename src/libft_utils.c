/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:29:06 by nakunwar          #+#    #+#             */
/*   Updated: 2025/07/08 19:44:53 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && (n > 0))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

static int	ft_sizeofn(long m)
{
	int	i;

	i = 1;
	if (m < 0)
		i++;
	while (m > 9 || m < -9)
	{
		if (m < 0)
			m = -m;
		m = m / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	nlong;

	nlong = (long)n;
	len = ft_sizeofn(nlong);
	ptr = calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (nlong < 0)
	{
		ptr[0] = '-';
		nlong = -nlong;
	}
	while (len-- >= 0 && nlong > 0 && ptr[len] != '-')
	{
		ptr[len] = nlong % 10 + '0';
		nlong = nlong / 10;
	}
	return (ptr);
}
