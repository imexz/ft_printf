/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_edgecase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:16:08 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p_edgecase(t_conv_spec *spec, int buff)
{
	if (spec->f_minus == 1)
	{
		ft_putstr_fd("0x", 1);
		while (buff > 0)
		{
			ft_putchar_fd(' ', 1);
			buff--;
		}
	}
	else
	{
		while (buff > 0)
		{
			ft_putchar_fd(' ', 1);
			buff--;
		}
		ft_putstr_fd("0x", 1);
	}
}
