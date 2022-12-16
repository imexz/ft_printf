/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:31:14 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid(t_conv_spec *spec)
{
	if (spec->f_zero == 1)
		return (0);
	if (spec->f_precision > (-1))
		return (0);
	if (spec->f_space == 1)
		return (0);
	if (spec->f_hash == 1)
		return (0);
	if (spec->f_plus == 1)
		return (0);
	return (1);
}

static void	ft_print_char_left(t_conv_spec *spec, char c)
{
	int	i;

	write(1, &c, 1);
	i = 1;
	while (i < (spec->f_width))
	{
		write(1, " ", 1);
		i++;
	}
}

static void	ft_print_char_right(t_conv_spec *spec, char c)
{
	int	i;

	i = 1;
	while (i < (spec->f_width))
	{
		write(1, " ", 1);
		i++;
	}
	write(1, &c, 1);
}

int	ft_char(t_conv_spec *spec, va_list arg)
{
	char	c;

	if (ft_valid(spec) == 0)
		return (-1);
	c = va_arg(arg, int);
	if (spec->f_width < 2)
	{
		write(1, &c, 1);
		return (1);
	}
	if (spec->f_minus == 1)
		ft_print_char_left(spec, c);
	else if (spec->f_minus == 0)
		ft_print_char_right(spec, c);
	return (spec->f_width);
}
