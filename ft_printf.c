/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:35:30 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_non_format_chars(int *count, char **dup_format)
{
	while (**dup_format != '%' && **dup_format != 0)
	{
		ft_putchar_fd(**dup_format, 1);
		(*dup_format)++;
		(*count)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			count;
	int			ret;
	char		*dup_format;

	count = 0;
	va_start(arg, format);
	dup_format = ft_strdup(format);
	if (dup_format == 0)
		return (0);
	while (*dup_format != 0)
	{
		ft_print_non_format_chars(&count, &dup_format);
		if (*dup_format == 0)
			break ;
		dup_format++;
		ret = ft_read_conv_spec(&dup_format, arg);
		if (ret == -1)
			return (0);
		count += ret;
	}
	va_end(arg);
	return (count);
}
