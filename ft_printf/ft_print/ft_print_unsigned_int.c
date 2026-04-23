/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:23:13 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/07 08:23:14 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft/libft.h"
#include "../ft_printf.h"

static void	ft_putnumber(unsigned int u);
static int	ft_unsigned_int_length(unsigned int nbr);

int	ft_print_unsigned_int(unsigned int u)
{
	int	length;

	length = ft_unsigned_int_length(u);
	ft_putnumber(u);
	return (length);
}

static void	ft_putnumber(unsigned int u)
{
	char	c;

	if (u <= 9)
	{
		c = '0' + u;
		write(1, &c, 1);
	}
	else
	{
		ft_putnumber(u / 10);
		ft_putnumber(u % 10);
	}
}

static int	ft_unsigned_int_length(unsigned int nbr)
{
	int	count;

	count = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
