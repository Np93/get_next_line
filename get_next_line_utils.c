/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:20:06 by nhirzel           #+#    #+#             */
/*   Updated: 2021/11/15 23:19:00 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char) c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *) s + i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	ii;
	char			*ss;
	unsigned int	si;

	ii = 0;
	i = start;
	if (s == NULL)
		return (0);
	si = ft_strlen(s);
	if (si < start)
		len = 0;
	if (si - start < len)
		ss = malloc(si - start + 1 * sizeof(char));
	else
		ss = malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (0);
	while (s[i] != '\0' && i < len + start && start < si)
		ss[ii++] = s[i++];
	ss[ii] = '\0';
	return (ss);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	is1;
	size_t	is2;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (0);
	is1 = ft_strlen(s1);
	is2 = ft_strlen(s2);
	s3 = malloc(is1 + is2 + 1 * sizeof(char));
	if (s3 == NULL)
		return (0);
	is1 = 0;
	while (s1[is1] != '\0')
	{
		s3[is1] = s1[is1];
		is1++;
	}
	is2 = 0;
	while (s2[is2] != '\0')
		s3[is1++] = s2[is2++];
	s3[is1] = '\0';
	return (s3);
}
