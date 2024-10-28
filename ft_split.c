/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:33:36 by ien-niou          #+#    #+#             */
/*   Updated: 2024/10/27 12:31:03 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **res, int j)
{
	while (j > 0)
		free(res[--j]);
	free(res);
}

static char	*ft_strcpy_w(char const *src, char sep)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (src[len] && (src[len] != sep))
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = src[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	count_word(char const *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && !(str[i] == sep))
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
		{
			res[j] = ft_strcpy_w(&s[i], c);
			if (!res[j])
				ft_free(res, j);
			j++;
			while (s[i] && (s[i] != c))
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}