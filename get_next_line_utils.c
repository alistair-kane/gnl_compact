/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:07:25 by alkane            #+#    #+#             */
/*   Updated: 2021/12/24 13:56:20 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*s;
	int		total;

	total = nmemb * size;
	p = malloc(nmemb * size);
	if (!p)
		return (0);
	s = p;
	while (total--)
		*s++ = '\0';
	return (p);
}

void	ft_memset(char *s,	size_t n)
{
	while (n-- > 0)
		*s++ = '\0';
}

void	ft_memmove(char *dest, char *src, size_t n)
{
	while (n--)
		*dest++ = *src++;
}

size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

int	ft_strchr(const char *s)
{
	unsigned int	i;

	i = 0;
	while (i <= (ft_strlen(s)))
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
