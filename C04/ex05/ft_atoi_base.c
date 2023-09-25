/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:10:38 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/09/25 15:52:53 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_pass(char *str, int *i, int *sign)
{
	while (str[*i] && ((9 <= str[*i] && str[*i] <= 13) || str[*i] == 32))
	{
		*i = *i + 1;
	}
	while (str[*i] != '\0' && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i += 1;
	}
}

int	ft_strlen(char *str)
{
	int	len;
	int	arr[1000000];
	int	i;

	i = 0;
	len = 0;
	while (i < 1000000)
		arr[i++] = 0;
	while (str[len])
	{
		if (str[len] != '+' && str[len] != '-' && str[len] != ' ')
		{
			if (arr[(unsigned int)str[len] % 1000000] == 0)
			{
				arr[(unsigned int)str[len] % 1000000]++;
				len++;
			}
			else
				return (-1);
		}
		else 
			return (-1);
	}
	return (len);
}

int	ft_helper(char *str, int len, int sign)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			num = num * len + (str[i] - '0');
		else if ('A' <= str[i] && str[i] <= 'F' && len > 10)
			num = num * len + (str[i] - 'A') + 10;
		else if ('a' <= str[i] && str[i] <= 'f' && len > 10)
			num = num * len + (str[i] - 'a') + 10;
		else
			break ;
		i++;
	}
	return (sign * num);
}

int	ft_atoi(char *str, int len)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		if (('0' <= str[i] && str[i] <= '9')
			|| ('A' <= str[i] && str[i] <= 'F'))
		{
			return (ft_helper(&str[i], len, sign));
		}
		if ('a' <= str[i] && str[i] <= 'f')
			return (ft_helper(&str[i], len, sign));
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	i;
	int	sign;
	int	num;

	sign = 1;
	ft_pass(str, &i, &sign);
	len = ft_strlen(base);
	i = 0;
	num = 0;
	if (len <= 1)
		return (0);
	return (ft_atoi(str, len));
}
/*
#include <stdio.h>
int main(){
	char str[] = " ---+--+17ab567";
	char *base = "0123456789";
	char *base2 = "01";
	char *base3 = "01234567";
	char *base4 = "0123456789ABCDEF";
	char *base5 = "";
	char *base6 = "0";
	char *base7 = "11";
	int num = ft_atoi_base(str, base);
	int num2 = ft_atoi_base(str, base2);
	int num3 = ft_atoi_base(str, base3);
	int num4 = ft_atoi_base(str, base4);
	int num5 = ft_atoi_base(str, base5);
	int num6 = ft_atoi_base(str, base6);
	int num7 = ft_atoi_base(str, base7);
	printf("%d\n", num);
	printf("%d\n", num2);
	printf("%d\n", num3);
	printf("%d\n", num4);
	printf("%d\n", num5);
	printf("%d\n", num6);
	printf("%d\n", num7);
	return (0);
}*/
/*
#include <stdio.h>


int	ft_atoi_base(char *str, char *base);


int	main(void)

{

	char	test1[] = "\t\n\v\f\r  --+--+ab";

	char	test2[] = "\t\n\v\f\r  ---+--+1234ab567";

	int		a = -1234;

	char	test3[] = "  --+--+123445z67-";

	int		b = 1193029;

	char	test4[] = "  --+--+62532ab567-";

	int		c = 62532;

	char	test5[] = "  --+---+999999b567-";

	int		e = -999999;

	char	test6[] = "  --+---+b-";

	char	test7[] = "  --+---+12053b567-";

	int		f = -5163;

	char	test8[] = "  --+--+abcdz67-";

	int		g = 43981;

	char	test9[] = "";

	char	test10[] = "  -- +--+abcdz67-";

	int 	retval;

	int		d;


	d = 0;

	retval = ft_atoi_base(test1, "0123456789");

	if (retval != 0)

	{

		d++;

		printf("\e[0;31mTest 1 failed: %d should be 0\n", retval);

	}

	retval = ft_atoi_base(test2, "0123456789");

	if (retval != a)

	{

		d++;

		printf("\e[0;31mTest 2 failed: %d should be %d\n", retval, a);

	}

	retval = ft_atoi_base(test3, "0123456789abcdef");

	if (retval != b)

	{

		d++;

		printf("\e[0;31mTest 3 hex failed: %d should be %d\n", retval, b);

	}

	retval = ft_atoi_base(test4, "0123456789");

	if (retval != c)

	{

		d++;

		printf("\e[0;31mTest 4: dec normal neg  failed: %d should be %d\n", retval, c);

	}

	retval = ft_atoi_base(test5, "0123456789");

	if (retval != e)

	{

		d++;

		printf("\e[0;31mTest 5: decimal big failed: %d should be %d\n", retval, d);

	}

	retval = ft_atoi_base(test6, "0123456789");

	if (retval != 0)

	{

		d++;

		printf("\e[0;31mTest 6 : no number failed: %d should be 0\n", retval);

	}

	retval = ft_atoi_base(test7, "01234567");

	if (retval != f)

	{

		d++;

		printf("\e[0;31mTest 7: octal failed: %d should be %d\n", retval, g);

	}

	retval = ft_atoi_base(test8, "0123456789abcdef");

	if (retval != g)

	{

		d++;

		printf("\e[0;31mTest 8: hex failed: %d should be %d\n", retval, g);

	}

	retval = ft_atoi_base(test9, "0123456789abcdf");

	if (retval != 0)

	{

		d++;

		printf("\e[0;31mTest 8: empty str failed: %d should be 0\n", retval);

	}

	retval = ft_atoi_base(test10, "0123456789abcdf");

	if (retval != 0)

	{

		d++;

		printf("\e[0;31mTest 8: empty str failed: %d should be 0\n", retval);

	}

	if (d == 0)

		printf("\e[0;32mTest passed\n");

    // Test error in str

    printf("Start of error check, should have 5 empty lines\n-");

    ft_atoi_base("-123124", "");

    printf("\n-");

    ft_atoi_base("-123124", "a");

    printf("\n-");

    ft_atoi_base("-123124", "adsfzr+");

    printf("\n-");

    ft_atoi_base("-123124", "-abcde-");

    printf("\n-");

    ft_atoi_base("-123124", "abcedfjklb123");

    printf("\n-");

    ft_atoi_base("-123124", "abce dfjklb123");

    printf("\n-");

    ft_atoi_base("-123124", "abce\tdfjklb123");

    printf("\n-");

    ft_atoi_base("-123124", "abce\rdfjklb123");

    printf("\n-");

    ft_atoi_base("-123124", "abce\ndfjklb123");

    printf("\n-");

    ft_atoi_base("-123124", "abce\vdfjklb123");

    printf("\n-");

    ft_atoi_base("-123124", "abce\vdfjklb123");

    printf("\n-");

    ft_atoi_base("-123124", "abce\fdfjklb123");

    printf("\n-");

    printf("End of those test\n");

	return (0);

}
*/