/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:22:41 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/07 08:22:42 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft/libft.h"
#include "../ft_printf.h"

static void	ft_putnumber(int d);
static int	ft_int_length(long nbr);

int	ft_print_int(int d)
{
	int	length;

	length = ft_int_length(d);
	ft_putnumber(d);
	return (length);
}

static void	ft_putnumber(int d)
{
	char	c;

	if (d == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		d = 147483648;
	}
	if (d < 0)
	{
		write(1, "-", 1);
		d = -d;
	}
	if (d <= 9)
	{
		c = '0' + d;
		write(1, &c, 1);
	}
	else
	{
		ft_putnumber(d / 10);
		ft_putnumber(d % 10);
	}
}

static int	ft_int_length(long nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
