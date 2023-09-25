int	ft_find_next_prime(int nb)
{
	int i;

	i = 3;
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (i <= nb / i)
	{
		if (nb % i == 0)
		{
			nb += 2;
			i = 1;
		}
		i += 2;
	}
	return (nb);	
}