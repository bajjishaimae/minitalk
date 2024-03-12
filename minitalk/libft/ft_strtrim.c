/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:55 by cbajji            #+#    #+#             */
/*   Updated: 2023/11/25 13:28:21 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int	s;
	int	f;
	int	vlen;

	if (!s1 || !set)
		return (0);
	if (!(*s1))
		return (ft_strdup(""));
	s = 0;
	f = ft_strlen(s1);
	f--;
	while (ft_strchr(set, s1[s]) && s1[s])
		s++;
	while (ft_strchr(set, s1[f]) && s1[f])
		f--;
	vlen = f - s + 1;
	return (ft_substr(s1, s, vlen));
}
