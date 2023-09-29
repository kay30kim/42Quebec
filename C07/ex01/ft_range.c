#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	num;

	i = 0;
	num = min;
	if (min >= max)
		return (0);
	int* arr = (int*)malloc(max - min + 1);
	if (arr == NULL)
		return (0);
	while (i < max)
	{
		arr[i] = num;
	}
	return (arr);
}

int	main(void)
{
	int* arr = ft_range(-1, 5);
	for (int i = 0; i < sizeof(arr); i++)
	{
		printf("%d ", arr[i]);
	}
	return (0);
}