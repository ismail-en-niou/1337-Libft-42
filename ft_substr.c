/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:26:13 by ien-niou          #+#    #+#             */
/*   Updated: 2024/10/26 11:36:17 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, &s[start], len);
	return (sub);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(const char *s, unsigned int start, size_t len);

int	main(void)
{
	const char	*test_str = "Hello, world!";
	char		*result;

	// Array to hold results
	// Case 1: Normal substring from the middle
	printf("test for size = %lu \n \n ************************ \n",
		strlen(test_str));
	result = ft_substr(test_str, 7, 5);
	printf("Case 1: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 2: Substring from start with exact length
	result = ft_substr(test_str, 0, 5);
	printf("Case 2: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 3: Substring with length longer than the rest of the string
	result = ft_substr(test_str, 7, 50);
	printf("Case 3: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 4: Empty string with zero length
	result = ft_substr("", 0, 5);
	printf("Case 4: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 5: Length is zero
	result = ft_substr(test_str, 7, 0);
	printf("Case 5: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 6: Start is at the end of the string
	result = ft_substr(test_str, 13, 5);
	printf("Case 6: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 7: Start is beyond the string length
	result = ft_substr(test_str, 20, 5);
	printf("Case 7: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 8: Full string requested
	result = ft_substr(test_str, 0, strlen(test_str));
	printf("Case 8: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 9: Full string with extra length
	result = ft_substr(test_str, 0, strlen(test_str) + 5);
	printf("Case 9: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 10: Single character from the start
	result = ft_substr(test_str, 0, 1);
	printf("Case 10: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 11: Single character from the end
	result = ft_substr(test_str, strlen(test_str) - 1, 1);
	printf("Case 11: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 12: Empty source string with zero length
	result = ft_substr("", 0, 0);
	printf("Case 12: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 13: Empty source string with non-zero length
	result = ft_substr("", 0, 5);
	printf("Case 13: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 14: Zero start and length is the string length
	result = ft_substr(test_str, 0, strlen(test_str));
	printf("Case 14: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 15: Start at 2, length 3
	result = ft_substr(test_str, 2, 3);
	printf("Case 15: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 16: Start in middle, length to the end
	result = ft_substr(test_str, 7, strlen(test_str) - 7);
	printf("Case 16: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 17: Start with entire length beyond the end
	result = ft_substr(test_str, 50, 5);
	printf("Case 17: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 18: Length is very large
	result = ft_substr(test_str, 7, 1000000);
	printf("Case 18: '%s'\n", result ? result : "(null)");
	free(result);
	// Case 19-32: Edge cases with varying start and length
	for (unsigned int i = 0; i <= 15; i++)
	{
		result = ft_substr(test_str, i, 3);
		printf("Case %d: '%s'\n", 19 + i, result ? result : "(null)");
		free(result);
	}
	return (0);
}
