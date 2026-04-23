/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:22:51 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/07 08:23:42 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_handle_percent(const char *s, int i, va_list ap);

int	ft_printf(const char *s, ...)
{
	int		i;
	int		length;
	va_list	ap;

	i = 0;
	length = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			length = length + ft_handle_percent(s, i, ap);
			i++;
		}
		else
		{
			length++;
			ft_putchar_fd(s[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (length);
}

static int	ft_handle_percent(const char *s, int i, va_list ap)
{
	int	length;

	length = 0;
	length = length + ft_basic_conversions(s[i + 1], ap);
	return (length);
}
