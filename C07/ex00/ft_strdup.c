#include <stdlib.h>

int	ft_strlen(char* str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char* ft_strdup(char* src)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = ft_strlen(src);
	copy = (char*)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	main(void)
{
	char str[] = "hey ekie kkefifai lefi";
	char* res = ft_strdup(str);
	printf("%s", res);
	return (0);
}