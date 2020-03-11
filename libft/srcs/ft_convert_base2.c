/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:32:39 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/01 12:13:18 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				verification_atoi(char *base)
{
	unsigned int	nb;
	unsigned int	compt;

	nb = 0;
	compt = 0;
	while (base[nb] != '\0')
	{
		while (base[compt] != '\0')
		{
			if (base[compt] == base[nb] && compt != nb)
				return (0);
			compt++;
		}
		compt = 0;
		nb++;
		if (((base[nb] >= 9 && base[nb] <= 13)
			|| (base[nb] == '-' || base[nb] == '+' || base[nb] == ' '))
				&& base[nb] != '\0')
			return (0);
	}
	return (nb);
}

static int		signe(char *str, unsigned int *nb)
{
	unsigned int	i;
	unsigned int	a;

	i = 1;
	a = 0;
	while (str[a] == ' ' || (str[a] >= 9 && 13 >= str[a]))
		a++;
	while (str[a] == '+' || str[a] == '-')
	{
		if (str[+a] == '-')
			i *= -1;
		a++;
	}
	*nb = a;
	return (i);
}

static int		position(char str, char *base)
{
	int	bs;

	bs = 0;
	while (base[bs] != str && base[bs] != '\0')
		bs++;
	return (bs);
}

unsigned int	ft_atoi_base(char *str, char *base)
{
	unsigned int	tail;
	unsigned int	i;
	unsigned int	nb;
	unsigned int	renvoie;
	unsigned int	bs;

	nb = 0;
	tail = verification_atoi(base);
	if (0 == tail)
		return (0);
	i = signe(str, &nb);
	bs = 0;
	renvoie = 0;
	while (bs < tail)
	{
		renvoie *= tail;
		renvoie = renvoie + bs;
		bs = position(str[nb], base);
		if (bs >= tail)
			return (i * renvoie);
		nb++;
	}
	return (i * renvoie);
}
