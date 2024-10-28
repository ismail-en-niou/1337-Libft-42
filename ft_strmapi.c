/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:03:28 by ien-niou          #+#    #+#             */
/*   Updated: 2024/10/27 12:43:34 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rest;
	int				len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	rest = malloc((len + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	i = 0;
	while (s[i] < len)
	{
		rest[i] = f(i, s[i]);
		i++;
	}
	rest[i] = 0;
	return (rest);
}
