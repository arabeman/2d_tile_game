/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:23:02 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/07 08:23:04 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft/libft.h"
#include "../ft_printf.h"

int	ft_print_string(char *s)
{
	int	length;

	length = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	length = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (length);
}
