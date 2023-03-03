/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:14:18 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 16:14:23 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static void	check_minus_and_format(char **str, int *minus)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*minus *= (-1);
		(*str)++;
	}
	if (!ft_isdigit(**str))
		ft_error("worng input : atod() not a number");
}

static double	add_decimal(char *str, double num)
{
	double	tmp;

	tmp = 10;
	while (*str && ft_isdigit(*str))
	{
		num += (*str - '0') / tmp;
		tmp *= 10;
		str++;
	}
	if (*str && !ft_isdigit(*str))
		ft_error("worng input : atod() not a number");
	return (num);
}

double	ft_atod(char *str)
{
	double			num;
	int				minus;

	num = 0;
	minus = 1;
	check_minus_and_format(&str, &minus);
	while (ft_isdigit(*str) && *str)
	{
		if (num == -INFINITY || num == INFINITY)
			ft_error("double : out of range");
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (*str && *(str++) != '.')
		ft_error("worng input : atod() not a number");
	num = add_decimal(str, num);
	return ((double)num * minus);
}
