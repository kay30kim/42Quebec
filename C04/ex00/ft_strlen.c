/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:06:05 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/09/24 12:06:07 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}
/*#include <stdio.h>
#include <string.h>
int main(void) {
	char str[] = "hello World\n";
	int num = ft_strlen(str);
	printf("%lu %d\n", strlen(str), ft_strlen(str));
	return (0);
}*/
