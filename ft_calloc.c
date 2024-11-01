/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:41:23 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/01 15:43:02 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	total;

	total = count * size;
	if (size && count != total / size)
		return (NULL);
	res = (void *)malloc(total);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
