/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:18:20 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/01 14:25:14 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*u;
	unsigned char	*v;

	v = (unsigned char *)dest;
	u = (unsigned char *)src;
	i = 0;
	if (!u && !v)
		return (NULL);
	if (v != u)
	{
		while (i < n)
		{
			v[i] = u[i];
			i++;
		}
	}
	return (dest);
}
