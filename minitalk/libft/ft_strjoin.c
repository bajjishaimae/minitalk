/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:41:06 by cbajji            #+#    #+#             */
/*   Updated: 2023/11/28 20:05:22 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	b = ft_strlen(s2);
	new = (char *)malloc(b + i + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, (char *) s1, i);
	ft_memcpy(new + i, (char *) s2, b);
	new[i + b] = '\0';
	return (new);
}
