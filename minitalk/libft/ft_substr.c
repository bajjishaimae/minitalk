/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:00:13 by cbajji            #+#    #+#             */
/*   Updated: 2023/11/15 10:55:03 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	size;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	l = len;
	size = ft_strlen(s + start);
	if (size <= len)
		l = size;
	ptr = (char *)malloc(l * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (i < l)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
