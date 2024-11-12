#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*longestCommonPrefix(char **str, int strsSize)
{
	static char	test[250] = {};
	char		currentChar;

	if (strsSize == 0)
		return (test);
	for (int i = 0; i < strlen(str[0]); i++)
	{
		currentChar = str[0][i];
		for (int j = 1; j < strsSize; j++)
		{
			if (i >= strlen(str[j]) || str[j][i] != currentChar)
			{
				test[i] = '\0';
			}
		}
		test[i] = currentChar;
	}
	return (test);
}

int	main(void)
{
	strdup(NULL);
}
