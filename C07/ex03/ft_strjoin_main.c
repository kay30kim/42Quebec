#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		len;
	int		i;
	int		j;

	if (size <= 0)
		return (NULL);
	i = 0;
	len = 0;
	while (i < size)
		len += sizeof(strs[i++]) + sizeof(sep);
	arr = (char *)malloc(sizeof(char) * len + 1);
	i = -;
	len = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			arr[len++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			arr[len++] = sep[j++];
	}
	arr[len] = '\0';
	return arr;
}