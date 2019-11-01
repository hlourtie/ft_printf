/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:43:30 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/30 20:54:45 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to do imrim_p manage_zero


#include "./inc/libft/libft.h"
#include "./inc/ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->precision = 0;
	flags->width = 0;
}

int		imprim_c(char **s, t_flags *flags, va_list ap)
{
	int count;

	count = flags->width ? flags->width : 1;
	if (flags->minus)
	{
		ft_putchar_fd(va_arg(ap, char), 1);
		if (flags->width)
			while (--(flags->width))
				ft_putchar_fd(' ', 1);
	}
	else if (flags->width)
	{
		if (flags->zero)
			while (--(flags->width))
				ft_putchar_fd('0', 1);
		else
			while (--(flags->width))
				ft_putchar_fd(' ', 1);
		ft_putchar_fd(**s, 1);
	}
	else
		ft_putchar_fd(va_arg(ap, char), 1);
	s++;
	return (count);
}

int		imprim_s(char **s, t_flags *flags, va_list ap)
{
	char	*str;
	int		count;

	str = va_arg(ap, char *);
	count = flags->width > ft_strlen(str) ? flags->width : ft_strlen(str);
	if (flags->width > ft_strlen(str))
	{
		flags->width -= ft_strlen(str);
		if (flags->minus)
		{
			ft_putstr_fd(str, 1);
			while ((flags->width)--)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while ((flags->width)--)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(str, 1);
		}
	}
	else
		ft_putstr_fd(str, 1);
	s++;
	return (count);
}

int		imprim_p(char **s, t_flags *flags, va_list ap)
{
	int count;
	void *ptr;

	ptr = va_arg(ap, void *);
	count = flags->width > 11 ? flags->width : 11;
	if (flags->width > 11)
	{
		flags->width -= 11;
		if (flags->minus)
		{
			ft_putstr_fd("0x10", 1);
			ft_putstr_fd(ptr, 1);
			while ((flags->width)--)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while ((flags->width)--)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd("0x10", 1);
			ft_putstr_fd(ptr, 1);
		}
	}
	else
	{
		ft_putstr_fd("0x10", 1);
		ft_putstr_fd(ptr, 1);
	}
	s++;
	return (count);
}

ft_sizenum(int nbr, int pres)
{
	int count;

		count = ((!pres && (nbr < 0)) ? 1 : 0 );	
	while(nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

void fill_ret(int width, char c, char **ret, int present)
{

}

void set_ret(int nbr, char **ret)
{

}

char *manage_zero(int nbr, t_flags *flags, char **ret)
{
	int size;

	size = ft_sizenum(nbr, 0);
	if (flags->width > size)
	{
		flags->width -= size;
		if (flags->minus)
		{
			set_ret(nbr, ret);
			fill_ret(flags->width,' ', ret, 0);
		}
		else
		{
			if (flags->zero)
				fill_ret(flags->width,'0', ret, 1);
			else
				fill_ret(flags->width,' ', ret, 1);
			set_ret(nbr, ret);
		}
	}
}

char *check_precision(int nbr, t_flags *flags)
{
	char *temp;
	int tmpn;
	char *ret;
	
	if (flags->precision > ft_sizenum(nbr, 1))
	{
		temp = (nbr < 0 ? ft_itoa(-nbr) : ft_itoa(nbr));
		if (!(ret = (char *) malloc(sizeof(char) *  (flags->precision - ft_sizenum(nbr,1)))))
			return (NULL);
		bzero(ret, (size_t) (flags->precision - ft_sizenum(nbr,1)));
		ret = (char*)ft_memset(ret, 32, (size_t) (flags->precision - ft_sizenum(nbr,1)));
		ret = ft_strjoin_free(ret, temp, 2);
		if (nbr < 0)
		{
			if (!(temp = (char *)malloc(sizeof(char) * 2)))
		 		return (NULL);
			temp[0] = '-';
			temp[1] = '\0';
			ret = ft_strjoin_free(temp, ret, 2);
		}
	}
	else
		ret = (flags->zero ? manage_zero() : ft_itoa(nbr));
	return (ret);
}

int imprim_d(char **s, t_flags *flags, va_list ap)
{
	int count;
	int var;
	int size;
	char *ret;

	var = va_arg(ap, int);
	ret = check_precision(var, flags);
	size = ft_strlen(ret);

	count = flags->width > size ? flags->width : size;
	if (flags->width > size)
	{
		flags->width -= size;
		if (flags->minus)
		{
			ft_putnbr_fd(var, 1);
			while ((flags->width)--)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			if (flags->zero)
				while ((flags->width)--)
					ft_putchar_fd('0', 1);
			else
				while ((flags->width)--)
					ft_putchar_fd(' ', 1);
			ft_putnbr_fd(var, 1);
		}
	}
	else
		ft_putnbr_fd(var, 1);
	s++;
	return (count);
}

int size_result(long int nbr)
{
	int count;

	count = 0;
	while (nbr)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

char *hex_this(int nbr, char c, int *count)
{
	char *base;
	char *ret;
	int i;
	int res;
    long int plop;

	plop = (nbr < 0 ? 4294967296 + nbr : nbr);
	*count = size_result(plop);
	if(!(base = (char *)malloc(sizeof(char) * 17)) || !(ret = (char *)malloc(sizeof(char) * (*count + 1))))
		return (NULL);
	base = (c == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	i = 0;
	while (i < *count)
	{
		res = plop % 16;
		plop /= 16;
		ret[*count -1 - i] = base[res];
        i++;
	}
	ret[*count] = '\0';
	return (ret);
}


int imprim_x(char **s, t_flags *flags, va_list ap)
{
	int val;
	char *str;
	int count;

	val = va_arg(ap, int);
	str = hex_this(val, **s, &count);
	count = flags->width > count ? flags->width : count;
	if (flags->width > count)
	{
		flags->width -= count;
		if (flags->minus)
		{
			ft_putstr_fd(str, 1);
			while ((flags->width)--)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			if (flags->zero)
				while ((flags->width)--)
					ft_putchar_fd('0', 1);
			else
				while ((flags->width)--)
					ft_putchar_fd(' ', 1);
			ft_putstr_fd(str, 1);
		}
	}
	else
		ft_putstr_fd(str, 1);
	s++;
	return (count);
}

int imprim_u(char **s, t_flags *flags, va_list ap)
{
	

}
int		ft_write(char **s, t_flags *flags, va_list ap)
{
	int count;

	if (**s == 'c')
		count = imprim_c(s, flags, ap);
	else if (**s == 's')
		count = imprim_s(s, flags, ap);
	else if (**s == 'p')
		count = imprim_p(s, flags, ap);
	else if (**s == 'd' || **s == 'i')
		count = imprim_d(s, flags, ap);
	else if (**s == 'u')
		count = imprim_u(s, flags, ap);
	else if (**s == 'x' || **s == 'X')
		count = imprim_x(s, flags, ap);
	else
		return (0);
	return (count);
}

int		handle_gen(char **s, t_flags *flags)
{
	if (**s == '-')
		flags->minus = 1;
	else if (**s == '0')
		flags->zero = 1;
	else
		return (0);
	return (1);
}

int		handle_width(char **s, t_flags *flags, va_list ap)
{
	int width;

	if (ft_atoi(*s) > 0 || **s == '*')
	{
		if (**s == '*')
		{
			width = va_arg(ap, int);
			if (width < 0)
			{
				flags->width = -width;
				flags->minus = 1;
			}
			else
				flags->width = width;
			*s++;
		}
		else
		{
			flags->width = ft_atoi(*s);
			while (width && *(*s++))
				width /= 10;
		}
		return (1);
	}
	return (0);
}

int		handle_precision(char **s, t_flags *flags, va_list ap)
{
	int precision;

	if (**s == '.')
	{
		*s++;
		if (**s == '*')
		{
			flags->precision = va_arg(ap, int);
			*s++;
		}
		else
		{
			precision = ft_atoi(*s);
			flags->precision = ft_atoi(*s);
			while (precision && *(*s++))
				precision /= 10;
		}
		return (1);
	}
}

int		handle_flags(char **s, va_list ap)
{
	int		count;
	t_flags flags;

	init_flags(&flags);
	while (handle_gen(s, &flags) || handle_width(s, &flags, ap)
			|| handle_precision(s, &flags, ap))
		*s++;
	count = ft_write(s, &flags, ap);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	char	*s;
	va_list	ap;
	int		count;

	s = (char*)format;
	count = 0;
	va_start(ap, format);
	while (*s)
		if (*s == '%')
		{
			s++;
			count += handle_flags_print(&s, ap);
		}
		else
		{
			write(1, s++, 1);
			count++;
		}
	va_end(ap);
	return (count);
}

int main()
{
	const char *s = "Hello world\n";
	printf("%0*d\n", 1,printf("%-20p", s));
	//printf("%0*d\n", -6, ft_printf(s));
}
