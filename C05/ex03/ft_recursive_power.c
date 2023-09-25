int	ft_recursive_power(int nb, int power)
{
	if (nb < 0)
		return 0;
	else if (nb == 0)
		return (1);
	else
	{
		return nb * ft_recursive_power(nb, power - 1);
	}
}#include <stdio.h>
int main() {
	printf("%d\n", ft_iterative_power(2, 1));
	printf("%d\n", ft_iterative_power(2, 2));
	printf("%d\n", ft_iterative_power(2, 3));
	printf("%d\n", ft_iterative_power(2, 0));
	printf("%d\n", ft_iterative_power(2, -1));
}