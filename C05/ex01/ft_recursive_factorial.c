int	ft_recursive_factorical(int nb)
{
	if (nb < 0)
		return 0;
	else if (nb == 0)
		return 1;
	else
		return nb * ft_recursive_factorical(nb-1);
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