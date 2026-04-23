/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:22:54 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/07 08:22:55 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft/libft.h"
#include "../ft_printf.h"

static void	ft_puthex(unsigned long n);
static int	ft_pointer_length(unsigned long n, int length);

int	ft_print_pointer(void *p)
{
	unsigned long	decimal;
	int				length;

	decimal = (unsigned long)p;
	length = 0;
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_puthex(decimal);
	length = ft_pointer_length(decimal, 2);
	return (length);
}

static void	ft_puthex(unsigned long n)
{
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
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

static int	ft_pointer_length(unsigned long n, int length)
{
	if (n < 16)
	{
		return (length + 1);
	}
	else
	{
		length = ft_pointer_length(n / 16, length);
		ft_pointer_length(n % 16, length);
	}
	length++;
	return (length);
}
