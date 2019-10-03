/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:05:45 by koparker          #+#    #+#             */
/*   Updated: 2019/10/03 18:56:58 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_wsp(char wsp)
{
	if (wsp == ' ' || wsp == '\t' || wsp == '\n' ||
			wsp == '\v' || wsp == '\f' || wsp == '\r')
		return (1);
	return (0);
}

long long	ft_atoil(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_is_wsp(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res < 0)
			return (sign == 1 ? -1 : 0);
	}
	if (sign == -1)
		return (res * -1);
	return (res);
}
