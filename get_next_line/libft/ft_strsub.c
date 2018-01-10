/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:11:42 by bhalderm          #+#    #+#             */
/*   Updated: 2017/10/02 16:12:21 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new && s)
	{
		while (i < len)
		{
			new[i] = s[start];
			start++;
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
