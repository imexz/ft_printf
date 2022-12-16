/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:15:03 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_valid(t_conv_spec *spec)
{
	if (spec->f_minus == 1 && spec->f_zero == 1)
		spec->f_zero = 0;
	if (spec->f_width == -1)
		spec->f_width = 1;
}

int	ft_percentage(t_conv_spec *spec)
{
	char	*str;

	ft_valid(spec);
	str = malloc(spec->f_width + 1);
	if (str == 0)
		return (-1);
	str[spec->f_width] = 0;
	if (spec->f_zero == 0)
		str = ft_memset(str, ' ', spec->f_width);
	else
		str = ft_memset(str, '0', spec->f_width);
	if (spec->f_minus == 1)
		str[0] = '%';
	else
		str[spec->f_width - 1] = '%';
	ft_putstr_fd(str, 1);
	return (spec->f_width);
}
