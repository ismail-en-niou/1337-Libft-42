/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:49:26 by ien-niou          #+#    #+#             */
/*   Updated: 2024/10/24 10:26:34 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				index;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (ptr[index] == (unsigned char)c)
			return ((void *)(ptr + index));
		index++;
	}
	return (NULL);
}
