/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:08:13 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/09/25 14:47:25 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	ft_pass(str, &i, &sign);
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
/*
#include <stdio.h>
int	main(void)
{
	char s[] = " ---+-a-+1234ab567";

	int num = ft_atoi(s);
	printf("%d\n",num);
	return (0);
}*/