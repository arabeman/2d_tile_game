/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:18:24 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/08 14:18:27 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft/libft.h"
#include "../ft_printf.h"

int	ft_print_percent(int c)
{
	int	length;

	length = 1;
	ft_putchar_fd((char)c, 1);
	return (length);
}
