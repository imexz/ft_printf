/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:04:47 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv_spec	*ft_new_list(void)
{
	t_conv_spec	*spec;

	spec = (t_conv_spec *) malloc(sizeof(t_conv_spec));
	if (spec == 0)
		return (0);
	spec->type = 0;
	spec->f_zero = 0;
	spec->f_minus = 0;
	spec->f_hash = 0;
	spec->f_space = 0;
	spec->f_plus = 0;
	spec->f_width = -1;
	spec->f_precision = -1;
	spec->f_length = 0;
	spec->buff = 0;
	spec->pre_buff = 0;
	return (spec);
}
