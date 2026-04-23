/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:54:16 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/08 13:54:19 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft/libft.h"
#include "../ft_printf.h"

int	ft_basic_conversions(int c, va_list ap)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = ft_print_char(va_arg(ap, int));
	else if (c == 's')
		length = ft_print_string(va_arg(ap, char *));
	else if (c == 'p')
		length = ft_print_pointer(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		length = ft_print_int(va_arg(ap, int));
	else if (c == 'u')
		length = ft_print_unsigned_int(va_arg(ap, unsigned int));
	else if (c == 'x')
		length = ft_print_hex_lower(va_arg(ap, int));
	else if (c == 'X')
		length = ft_print_hex_upper(va_arg(ap, int));
	else if (c == '%')
		length = ft_print_percent('%');
	return (length);
}
