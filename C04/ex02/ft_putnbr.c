/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:07:30 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/09/25 18:22:34 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb > 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}
#include <stdio.h>
int main(){
	ft_putnbr(1243);
	printf("\n");
	ft_putnbr(-123);
	printf("\n");
	ft_putnbr(531);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(2147483647);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	return 0;
}
