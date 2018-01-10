/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:19:01 by bhalderm          #+#    #+#             */
/*   Updated: 2017/09/29 16:41:39 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *temp;

	temp = str;
	temp = temp + ft_strlen(str);
	while (*temp != (char)c && temp != str)
		temp--;
	if (*temp == (char)c)
		return ((char *)temp);
	return (0);
}
