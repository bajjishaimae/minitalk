/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:49 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/04 12:34:52 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	res;

	res = count * size;
	if (count && (res / count) != size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
