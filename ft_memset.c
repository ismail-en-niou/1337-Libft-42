/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:58:15 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/06 11:38:49 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len-- > 0)
	{
		*p++ = (unsigned char)c;
	}
	return (b);
}
