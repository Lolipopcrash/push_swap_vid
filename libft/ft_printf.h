/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:15:38 by kelevequ          #+#    #+#             */
/*   Updated: 2024/11/02 14:23:06 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

void	ft_format(va_list args, const char c, int *counter);
int		ft_printf(const char *str, ...);
void	ft_printf_ch(char c, int *counter);
void	ft_printf_hex(unsigned long n, const char c, int *counter);
void	ft_printf_ptr(void *ptr, int *counter);
void	ft_printf_putnbr(int n, int *counter);
void	ft_printf_str(char *str, int *counter);
void	ft_printf_unsigned(unsigned int n, int *counter);
void	ft_printf_base(unsigned long n, char *base, int *counter);

#endif
