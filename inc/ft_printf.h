/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 09:57:29 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/28 12:46:24 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

typedef struct	s_flags{
	int zero;
	int minus;
	int prec;
	int	precs;
	int pres;
	int width;
	int spec;
}				t_flags;

long			ft_sn(long nbr, long pres);
char			*check_prec_hex(char *str, t_flags *f);
int				imprim_d(char **s, t_flags *flags, va_list ap);
int				imprim_u(char **s, t_flags *flags, va_list ap);
int				imprim_c(char **s, t_flags *flags, va_list ap);
int				imprim_p(char **s, t_flags *flags, va_list ap);
int				imprim_s(char **s, t_flags *flags, va_list ap);
int				imprim_x(char **s, t_flags *flags, va_list ap);
void			init_flags(t_flags *flags);
void			manage_width(char *str, t_flags *flags, int size);
int				imprim_perc(char **s, t_flags *flags);
int				ft_write(char **s, t_flags *flags, va_list ap);
int				handle_gen(char **s, t_flags *flags);
int				handle_width(char **s, t_flags *flags, va_list ap);
int				handle_prec(char **s, t_flags *flags, va_list ap);
int				handle_flags(char **s, va_list ap);
void			special_d(char *str, t_flags *flags);
char			*manage_return(t_flags *f, long nbr);
char			*manage_exta_size(long nbr, t_flags *flags, long size);
char			*manage_zero(long nbr, t_flags *flags);
char			*check_prec(long nbr, t_flags *f);
void			manage_width_d(char *str, t_flags *flags, int size);
int				ft_printf(const char *format, ...);
#endif
