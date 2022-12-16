/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:08:30 by mstrantz          #+#    #+#             */
/*   Updated: 2021/07/11 10:31:58 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_conv_spec
{
	char	type;
	int		f_zero;
	int		f_minus;
	int		f_hash;
	int		f_space;
	int		f_plus;
	int		f_width;
	int		f_precision;
	int		f_length;
	int		pre_buff;
	int		buff;
}			t_conv_spec;

int			ft_printf(const char *format, ...);
int			ft_string(t_conv_spec *spec, va_list arg);
int			ft_char(t_conv_spec *spec, va_list arg);
t_conv_spec	*ft_new_list(void);
int			ft_read_conv_spec(char **format, va_list arg);
int			ft_pointer(t_conv_spec *spec, va_list arg);
void		ft_print_p_edgecase(t_conv_spec *spec, int buff);
int			ft_int(t_conv_spec *spec, va_list arg);
void		ft_print_int(t_conv_spec *spec, long num);
int			ft_unsigned_int(t_conv_spec *spec, va_list arg);
void		ft_print_uns_int(t_conv_spec *spec, unsigned long num);
int			ft_hex(t_conv_spec *spec, va_list arg);
void		ft_print_hex_left(t_conv_spec *spec, unsigned int num);
void		ft_print_hex(t_conv_spec *spec, unsigned int num);
int			ft_percentage(t_conv_spec *spec);
int			ft_uns_int_null(t_conv_spec *spec);
int			ft_get_len(long num);
int			ft_get_len_str(t_conv_spec *spec, char *str);
int			ft_specifier(char **format, t_conv_spec *ptr_spec, va_list arg);

#endif
