void	initialize(int *arr)
{
	int	i;

	i = 0;
	while (i < 1000000)
	{
		arr[i] = 0;
	}
}

int	checkerror(char *str)
{
	int	i;
	int arr[1000000];

	i = 0;
	initialize(arr);
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32
			|| str[i] == 43 || str[i] == 45)
			return (0);
		if (arr[(unsigned char*)str[i]] == 0)
			arr[(unsigned char*)str[i]] = 1;
		i++;
	}
	return (i);
}

int	whitespaces(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] != '\0') && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	count;
	int	nb;
	int	nb2;
	int	base_lenght;

	nb = 0;
	i = 0;
	base_lenght = checkerror(base);
	if (base_lenght >= 2)
	{
		count = whitespaces(str, &i);
		nb2 = nb_base(str[i], base);
		while (nb2 != -1)
		{
			nb = (nb * base_lenght) + nb2;
			i++;
			nb2 = nb_base(str[i], base);
		}
		return (nb *= count);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ans;
	int		num;
	int		len;
	char	*arr;

	if (check(base_to) == 0 || check(base_from) == 0)
		return (0);
	/*
	mednbr = ft_atoi_base(nbr, base_from);
	lenght_nbrf = lenght_nbr(mednbr, base_to, 0);
	finalnbr = (char *)malloc(sizeof(char) * (lenght_nbrf + 1));
	d = (finalnbr);
	if (!d)
		return (0);
	ft_putnbr_base_v2(mednbr, base_to, finalnbr);
	finalnbr[lenght_nbrf] = '\0';
	return (finalnbr);
	*/
}