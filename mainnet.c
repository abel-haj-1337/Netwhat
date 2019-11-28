/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainnet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:23:19 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/25 01:37:49 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft/libft.h"

int			ft_free_arr(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (0);
}

void		ft_print_dec_octal(int	n)
{
    int a;
	int o;
	
	a = 128;
    o = 8;
    while (o && (n >= 0 || n <= 255))
    {
        if (n - a >= 0)
        {
            n = n - a;
            ft_putstr("1");
        }
        else
            ft_putstr("0");
        a = a / 2;
        o--;
    }
}

void		ft_print_snetmask_octal(int n)
{
	int	a;
	int	o;

	a = 128;
    o = 32;
	while (o && (n >= 0 || n <= 32))
    {
        if (n)
        {
            n -= 1;
            ft_putstr("1");
        }
        else
            ft_putstr("0");
        o--;
		if (o && !(o % 8))
			ft_putstr(".");
    }
}

void		ft_print_snetmask_dec(int n)
{
	int	a;
	int	b;
	int	c;
	int d;

	a = 128;
    b = 4;
	while (b)
	{
		c = 8;
		d = 0;
		while (c)
		{
			if (n >= 0)
			{
				d = d + a / 2;
				a /= 2;
				n--;
			}
			c--;
		}
		ft_putstr(ft_itoa(d));
		if (b != 1)
			ft_putstr(".");
		b--;
	}
}

int			ft_is_ip_and_submask(const char *s)
{
	size_t	len;
	char	**spl_ip;
	char	**spl_sbmsk;

	len = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	spl_ip = ft_split(s, '.');
	if (spl_ip)
	{
		if (ft_arrlen(spl_ip) == 4)
		{
			if (ft_atoi(spl_ip[0]) >= 0 && ft_atoi(spl_ip[0]) <= 255 &&
					ft_atoi(spl_ip[1]) >= 0 && ft_atoi(spl_ip[1]) <= 255 &&
					ft_atoi(spl_ip[2]) >= 0 && ft_atoi(spl_ip[2]) <= 255 &&
					ft_atoi(spl_ip[3]) >= 0 && ft_atoi(spl_ip[3]) <= 255 &&
					(ft_strindof(spl_ip[3], '/') != -1))
			{
				spl_sbmsk = ft_split(spl_ip[3], '/');
				if (ft_atoi(spl_sbmsk[1]) > 0 && ft_atoi(spl_sbmsk[1]) <= 32)
				{
					ft_free_arr(spl_ip);
					ft_free_arr(spl_sbmsk);
					return (1);
				}
				ft_free_arr(spl_sbmsk);
			}
		}
		ft_free_arr(spl_ip);
	}
	return (0);
}

void		ft_print_class_privacy(char *ip)
{
	int	first;
	int second;

	first = ft_atoi(ip);
	second = ft_atoi(ft_strachr(ip, '.'));
	if (first >= 0 && first <= 127)
		if (first == 10)
			ft_putstr("Privacy:\t\t\tPrivate\nClass:\t\t\t\tClass A\n\n");
		else
			ft_putstr("Privacy:\t\t\tPublic\nClass:\t\t\t\tClass A\n\n");
	else if (first >= 128 && first <= 191)
		if (first == 172 && (second >= 16 && second <= 31))
			ft_putstr("Privacy:\t\t\tprivate\nClass:\t\t\t\tClass B\n\n");
		else
			ft_putstr("Privacy:\t\t\tPublic\nClass:\t\t\t\tClass B\\nn");
	else if (first >= 192 && first <= 223)
		if (first == 192 && second == 168)
			ft_putstr("Privacy:\t\t\tprivate\nClass:\t\t\t\tClass C\n\n");
		else
			ft_putstr("Privacy:\t\t\tPublic\nClass:\t\t\t\tClass C\n\n");
	else if (first >= 224 && first <= 239)
		ft_putstr("Privacy:\t\t\tPublic\nClass:\t\t\t\tClass D\n\n");
	else if (first >= 240 && first <= 255)
		ft_putstr("Privacy:\t\t\tPublic\nClass:\t\t\t\tClass E\n\n");
}

void		ft_print_ip(char *ip)
{
	// print ip
	ft_putstr("IP:\t\t\t\t");
	ft_putstr(ip);
	ft_putstr("\n");
	// print ip in binary
	ft_putstr(":\t\t\t\t");
	ft_print_dec_octal(ft_atoi(ip));
	ft_putstr(".");
	ft_print_dec_octal(ft_atoi(ft_strachr(ip, '.')));
	ft_putstr(".");
	ft_print_dec_octal(ft_atoi(ft_strachr(ft_strachr(ip, '.'), '.')));
	ft_putstr(".");
	ft_print_dec_octal(ft_atoi(ft_strachr(ft_strachr(ft_strachr(ip, '.'), '.'), '.')));
	ft_putstr("\n\n");
}

void		ft_print_netmask(char *subnet)
{
	int	isubnet;

	isubnet = ft_atoi(subnet);
	// print netmask
	ft_putstr("Netmask:\t\t\t");
	ft_putstr(subnet);
	ft_putstr("\nSub Nemtask:\t\t\t");
	ft_print_snetmask_dec(isubnet);
	// print netmask in binary
	ft_putstr("\n:\t\t\t\t");
	ft_print_snetmask_octal(isubnet);
	ft_putstr("\n\n");
}

void		ft_print_network(char *ip)
{
	// print network
	ft_putstr(ip);
	ft_putstr("\n");
	// print network in binary
}

void		ft_print_broadcast(char *ip)
{
	// print broadcast
	ft_putstr(ip);
	ft_putstr("\n");
	// print broadcast in binary
}


void		ft_print_host_range(char *snetmask)
{
	int snm;

	snm = ft_atoi(snetmask);
	// print host min
	// print host max
	// print hosts number
	ft_putstr("Hosts:\t\t\t\t");
	// ft_putstr(ft_itoa((snm - 32)));
	// ft_putstr(ft_itoa((int)pow(2, 32 - (snm - 32))));
	ft_putstr(ft_itoa((pow(2, 32 - snm) - 2)));
	ft_putstr("(+2)\n\n");
}

int			main(int argc, char *argv[])
{
	char	**spl_ip;
	char	*ip;

	if (argc > 1)
	{
		ip = argv[1];
		// ip = "125.25.98.3/12";
		if (ft_is_ip_and_submask(ip))
		{
			// printf("Valid IP.\n");
			spl_ip = ft_split(ip, '/');
			if (!spl_ip)
			{
				printf("ft_split() error!\n");
				return (0);
			}
			// print class & public/private
			ft_print_class_privacy(spl_ip[0]);
			// print ip
			ft_print_ip(spl_ip[0]);
			// print netmask
			ft_print_netmask(spl_ip[1]);
			// print network
			// ft_print_network(spl_ip[0]);
			// broadcast
			// ft_print_broadcast(spl_ip[0]);
			// host min
			// host max
			ft_print_host_range(spl_ip[1]);
			//
			ft_free_arr(spl_ip);
		}
		else
		{
			printf("You are supposed to give an ip address!\nWhat you provided is invalid!\n");
		}
	}
	else
		printf("Nothing to be done!\n");
	return (0);
}
