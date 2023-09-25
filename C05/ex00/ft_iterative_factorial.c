int ft_iterative_factorial(int nb)
{
	int num;

	num = 1;
	if (nb < 0)
		return (-1);
	else if (nb == 0)
		return (1);
	while (nb)
	{
		num *= nb;
		nb--;
	}
	return (num);
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(1));
	printf("%d\n", ft_iterative_factorial(-1));
	printf("%d\n", ft_iterative_factorial(5));
	return (0);
}