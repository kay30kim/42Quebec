/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:39:24 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/09/15 19:48:43 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digit(char *digit, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &digit[i++], 1);
	}
	if (digit[0] != 10 - n + 48)
		write(1, ", ", 2);
}

void	ft_print_comb(int n, int i, char *digit)
{
	if (i >= n)
	{
		ft_print_digit(digit, n);
		return ;
	}
	digit[i] = digit[i - 1] + 1;
	while (digit[i] <= '9')
	{
		ft_print_comb(n, i + 1, digit);
		digit[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	digit[9];

	digit[0] = '0';
	while (digit[0] <= '9')
	{
		ft_print_comb(n, 1, digit);
		digit[0]++;
	}
}
