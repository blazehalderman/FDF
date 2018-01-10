/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:59:37 by bhalderm          #+#    #+#             */
/*   Updated: 2017/10/02 12:34:09 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- > 0)
	{
		if (((char *)src)[i] == c)
		{
			((char *)dst)[i] = ((char *)src)[i];
			return (&dst[i + 1]);
		}
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (NULL);
}
