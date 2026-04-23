/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:24:01 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/07 08:23:47 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);

int	ft_print_char(int c);
int	ft_print_string(char *s);
int	ft_print_pointer(void *p);
int	ft_print_int(int d);
int	ft_print_unsigned_int(unsigned int u);
int	ft_print_hex_lower(unsigned int x);
int	ft_print_hex_upper(unsigned int x);
int	ft_print_percent(int c);

int	ft_basic_conversions(int c, va_list ap);

#endif
