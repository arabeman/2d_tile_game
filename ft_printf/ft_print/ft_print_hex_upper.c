/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:22:26 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/07 08:22:28 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft/libft.h"
#include "../ft_printf.h"

static void	ft_puthex(unsigned int n);
static int	ft_hex_length(unsigned int n, int length);

int	ft_print_hex_upper(unsigned int x)
{
	int	length;

	length = ft_hex_length(x, 0);
	ft_puthex(x);
	return (length);
}

static void	ft_puthex(unsigned int n)
{
	char	*hex;
	char	c;

	hex = "0123456789ABCDEF";
	if (n < 16)
	{
		c = hex[n];
		write(1, &c, 1);
	}
	else
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
}

static int	ft_hex_length(unsigned int n, int length)
{
	if (n < 16)
		return (length + 1);
	else
	{
		length = ft_hex_length(n / 16, length);
		ft_hex_length(n % 16, length);
	}
	length++;
	return (length);
}
