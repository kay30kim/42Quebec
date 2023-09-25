/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:08:53 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/09/25 14:55:28 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_clear(int *arr)
{
	int	i;

	i = 0;
	while (i < 1000000)
		arr[i++] = 0;
}

int	ft_check(int *arr, char *str, long *len)
{
	if (arr[(unsigned int)str[*len] % 1000000] == 0)
	{
		arr[(unsigned int)str[*len] % 1000000]++;
		*len = *len +1;
		return (0);
	}
	else
		return (-1);
}

long	ft_strlen(char *str)
{
	long	len;
	int		arr[1000000];

	len = 0;
	ft_clear(arr);
	while (str[len])
	{
		if ((str[len] >= '0' && str[len] <= '9') || 
			(str[len] >= 'A' && str[len] <= 'F'))
		{
			if (ft_check(arr, str, &len) == -1)
				return (-1);
		}
		else if (str[len] >= 'a' && str[len] <= 'f')
		{
			if (ft_check(arr, str, &len) == -1)
				return (-1);
		}
		else 
			return (-1);
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	len;
	long	nbr2;

	len = ft_strlen(base);
	nbr2 = nbr;
	if (len <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr2 = -(long)nbr;
	}
	if (nbr2 >= len)
		ft_putnbr_base((int)(nbr2 / len), base);
	ft_putchar(base[nbr2 % len]);
	return ;
}
/*
#include <stdio.h>
int	main(){
	char *base1 = "01";
	char *base2 = "0123456789";
	char *base3 = "01234567";
	char *base4 = "0123456789ABCDEF";
	char *base5 = "f#";
	char *base6 = "001234";
	char *base7 = "";
	ft_putnbr_base(17, base1);
	printf("\n");
	ft_putnbr_base(17, base2);
	printf("\n");
	ft_putnbr_base(17, base3);
	printf("\n");
	ft_putnbr_base(17, base4);
	printf("\n");
	ft_putnbr_base(17, base5);
	printf("\n");
	ft_putnbr_base(17, base6);
	printf("\n");
	ft_putnbr_base(17, base7);
	printf("\n");
	return (0);
}*//*
#include <stdio.h>

#include <unistd.h>



void	ft_putnbr_base(int nbr, char *base); 



int	main(void)

{

	int		a[] = {0, 1, -1, 2147483647, -2147483648, 54321, -432412};

	int		i;



	i = 0;

	while (i < 7)

	{

		ft_putnbr_base(a[i], "0123456789");

		write(1, &" ",1);

		i++;

	}

	printf("\n");
	
	printf("%i %i %i %i %i %i %i\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6]);

	printf("\n");

	i = 0;

	while (i < 7)

	{

		ft_putnbr_base(a[i], "0123456789abcdef");

		write(1, &", ",2);

		i++;

	}

	printf("\n");

	printf("0, 1, -1, 7FFFFFFF, -80000000, D431, -6991C\n");

	printf("\n");

	i = 0;

	while (i < 7)

	{

		ft_putnbr_base(a[i], "01234567");

		write(1, &" ",1);

		i++;

	}

	printf("\n");

	printf("%o %o -1 %o -%o %o -1514434\n", a[0], a[1], a[3], a[4], a[5]);

	printf("Fun base:\n");

	i = 0;

	while (i < 7)

	{

		ft_putnbr_base(a[i], "poneyvif");

		write(1, &" ",1);

		i++;

	}

	printf("\n");

	i = 0;

	while (i < 7)

	{

		ft_putnbr_base(a[i], "éb9yv0123p4i67â");

		write(1, &" ,",2);

		i++;

	}

	printf("\n");

	// Test error in str

	printf("Start of error check, should have 5 empty lines\n-");

	ft_putnbr_base(a[i], "");

	printf("\n-");

	ft_putnbr_base(a[i], "a");

	printf("\n-");

	ft_putnbr_base(a[i], "adsfzr+");

	printf("\n-");

	ft_putnbr_base(a[i], "-abcde-");

	printf("\n-");

	ft_putnbr_base(a[i], "abcedfjklb123");

	printf("\n");

	printf("End of those test\n");

	return (0);

}*/