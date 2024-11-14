/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:22:23 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/14 14:05:26 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dest_size;

	src_size = 0;
	dest_size = 0;
	if (!size)
		return(ft_strlen(src));
	while (dst[src_size] && src_size < size)
		src_size++;
	while (src[src_size] && (src_size + dest_size + 1) < size)
	{
		dst[src_size + dest_size] = src[dest_size];
		dest_size++;
	}
	if (src_size < size)
		dst[src_size + dest_size] = '\0';
	return (src_size + ft_strlen(src));
}
