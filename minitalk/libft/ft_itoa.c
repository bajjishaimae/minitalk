/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:12:17 by cbajji            #+#    #+#             */
/*   Updated: 2023/11/23 11:30:24 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size = 1;
	while (n)
	{
		size += 1;
		n /= 10;
	}
	return (size);
}

static char	*ft_printy(char *u, int b, long nbr)
{
	while (nbr)
	{
		u[--b] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (u);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*ptr;
	long	nb;

	count = ft_size(n);
	nb = n;
	ptr = malloc(count + 1);
	if (ptr == 0)
		return (0);
	ptr[count] = '\0';
	if (nb == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0' ;
		return (ptr);
	}
	if (nb < 0)
	{
		nb *= -1;
		ptr[0] = '-';
	}
	ptr = ft_printy(ptr, count, nb);
	return (ptr);
}
