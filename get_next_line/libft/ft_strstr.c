/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:56:48 by bhalderm          #+#    #+#             */
/*   Updated: 2017/09/29 17:01:41 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int x;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (!*big || !*little)
		return (0);
	while (big[i])
	{
		x = 0;
		while (big[i] == little[x] && big[i])
		{
			i++;
			x++;
		}
		if (!little[x])
			return ((char *)&big[i - x]);
		i = i - x + 1;
	}
	return (NULL);
}
