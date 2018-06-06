/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:09:37 by dlyubich          #+#    #+#             */
/*   Updated: 2018/02/04 13:01:57 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/libft.h"

void	ft_write_random_arr(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(arr[i]);
		if (i + 1 < len)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int		check_rep(int *arr, int i)
{
	int a;

	a = 0;
	if (i)
	{
		while (a < i)
		{
			if (arr[i] == arr[a])
				return (0);
			a++;
		}
	}
	return (1);
}

void	ft_input_rand(int min, int max, int len)
{
	int	i;
	int	*arr;

	i = 0;
	if (max - min < len)
	{
		ft_putstr("Invalid input\n");
		exit(0);
	}
	arr = (int*)malloc(sizeof(int) * len);
	ft_bzero(arr, len);
	while (i < len)
	{
		arr[i] = min + rand() % (max - min);
		while (!check_rep(arr, i))
			arr[i] = min + rand() % (max - min);
		i++;
	}
	ft_write_random_arr(arr, len);
	arr ? free(arr) : 0;
}

int		main(int ac, char **av)
{
	int min;
	int max;
	int len;

	srand(time(NULL));
	if (ac == 4)
	{
		min = ft_atoi(av[1]);
		max = ft_atoi(av[2]);
		len = ft_atoi(av[3]);
		ft_input_rand(min, max, len);
	}
	else
		ft_putstr("Wrong input. Usage ./rand [min] [max] [number]");
	return (0);
}
