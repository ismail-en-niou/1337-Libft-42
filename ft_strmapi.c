/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:03:28 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/14 14:05:34 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rest;
	unsigned int	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	rest = malloc((len + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rest[i] = f(i, s[i]);
		i++;
	}
	rest[i] = 0;
	return (rest);
}
