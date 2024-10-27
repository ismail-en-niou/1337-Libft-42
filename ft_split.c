/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:33:36 by ien-niou          #+#    #+#             */
/*   Updated: 2024/10/27 10:20:38 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_separator(char c, char sep)
{
	if (sep == c)
		return (1);
	return (0);
}

char	*ft_strcpy_w(char *src, char sep)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (src[len] && !is_separator(src[len], sep))
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

int	count_word(char *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], sep))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && !is_separator(str[i], sep))
			i++;
	}
	return (count);
}

int	ft_strlen_w(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && !is_separator(str[i], sep))
		i++;
	return (i);
}
char	**ft_split(char *str, char sep)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = malloc((count_word(str, sep) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_separator(str[i], sep))
			i++;
		if (str[i])
		{
			res[j] = ft_strcpy_w(&str[i], sep);
			if (!res[j])
				return (NULL);
			j++;
			while (str[i] && !is_separator(str[i], sep))
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}
#include <stdio.h>
#include <stdlib.h>

// Helper function to print split result
void print_split(char **result) {
    if (!result) {
        printf("(null)\n");
        return;
    }
    int i = 0;
    while (result[i]) {
        printf("'%s'", result[i]);
        if (result[i + 1])
            printf(", ");
        i++;
    }
    printf("\n");
}

// Test cases for ft_split
int main() {
    char **result;

    // Case 1: Simple split with spaces
    result = ft_split("Hello world welcome to C programming", ' ');
    printf("Case 1: ");
    print_split(result);

    // Case 2: Split with commas
    result = ft_split("apple,orange,banana,grape", ',');
    printf("Case 2: ");
    print_split(result);

    // Case 3: Consecutive delimiters
    result = ft_split("apple,,orange,,,banana", ',');
    printf("Case 3: ");
    print_split(result);

    // Case 4: Only delimiters
    result = ft_split(",,,,,", ',');
    printf("Case 4: ");
    print_split(result);

    // Case 5: Delimiters at start and end
    result = ft_split(",apple,orange,banana,", ',');
    printf("Case 5: ");
    print_split(result);

    // Case 6: Single word
    result = ft_split("apple", ' ');
    printf("Case 6: ");
    print_split(result);

    // Case 7: Empty string
    result = ft_split("", ' ');
    printf("Case 7: ");
    print_split(result);

    // Case 8: Only delimiter character as input
    result = ft_split(",", ',');
    printf("Case 8: ");
    print_split(result);

    // Case 9: Long string with repeated pattern
    result = ft_split("123-123-123-123", '-');
    printf("Case 9: ");
    print_split(result);

    // Case 10: Mixed character delimiters in input
    result = ft_split("Split|this|string|with|pipes", '|');
    printf("Case 10: ");
    print_split(result);

    // Free memory after each case if ft_split allocates dynamically (implementation-specific)
    // Implement freeing function if needed, for example:
    // free_split(result);

    return 0;
}
