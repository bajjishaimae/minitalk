/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:12:32 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/06 11:18:47 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	llen;

	i = 0;
	llen = ft_strlen(little);
	if (!big && !len)
		return (NULL);
	if (!llen)
		return ((char *)big);
	while (*big && i + llen <= len)
	{
		if (*big == *little && !ft_strncmp(big, little, llen))
			return ((char *)big);
		i++;
		big++;
	}
	return (0);
}
