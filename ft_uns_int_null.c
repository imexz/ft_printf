/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_int_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:59:23 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_left_plus(t_conv_spec *spec)
{
	ft_putchar_fd('+', 1);
	while (spec->f_width > 1)
	{
		ft_putchar_fd(' ', 1);
		spec->f_width--;
	}
}

static void	ft_print_right_plus(t_conv_spec *spec)
{
	while (spec->f_width > 1)
	{
		ft_putchar_fd(' ', 1);
		spec->f_width--;
	}
	ft_putchar_fd('+', 1);
}

static int	ft_print_plus_format(t_conv_spec *spec)
{
	int	ret;

	if (spec->f_width == -1)
	{
		ft_putchar_fd('+', 1);
		ret = 1;
	}
	else
	{
		ret = spec->f_width;
		if (spec->f_minus == 1)
			ft_print_left_plus(spec);
		else
			ft_print_right_plus(spec);
	}
	return (ret);
}

static int	ft_print_space_format(t_conv_spec *spec)
{
	int	ret;

	if (spec->f_width == -1)
	{
		ft_putchar_fd(' ', 1);
		ret = 1;
	}
	else
	{
		ret = spec->f_width;
		while (spec->f_width > 0)
		{
			ft_putchar_fd(' ', 1);
			spec->f_width--;
		}
	}
	return (ret);
}

int	ft_uns_int_null(t_conv_spec *spec)
{
	int	ret;

	if (spec->f_plus == 1)
		ret = ft_print_plus_format(spec);
	else if (spec->f_space == 1)
		ret = ft_print_space_format(spec);
	else if (spec->f_width == -1)
		return (0);
	else
	{
		ret = spec->f_width;
		while (spec->f_width > 0)
		{
			ft_putchar_fd(' ', 1);
			spec->f_width--;
		}
	}
	return (ret);
}
