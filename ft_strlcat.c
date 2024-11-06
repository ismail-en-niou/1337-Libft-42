/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:22:23 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/06 13:36:47 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	if (!dst)
		return (0);
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dest_size)
		return (src_size + size);
	i = dest_size;
	while (*src && i + 1 < size)
		dst[i++] = *(src++);
	dst[i] = '\0';
	return (src_size + dest_size);
}
