/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:57:12 by ysihetii          #+#    #+#             */
/*   Updated: 2018/01/30 14:57:13 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "des.h"

int		*ft_zsuv(int *key, int n, int m)
{
	int i;
	int t0;
	int t1;

	i = m;
	t0 = key[m];
	t1 = key[m + 1];
	while (i < m + 28 - n)
	{
		key[i] = key[i + n];
		i++;
	}
	if (n == 1)
		key[27 + m] = t0;
	else
	{
		key[27 + m] = t1;
		key[26 + m] = t0;
	}
	return (key);
}



void  ft_P_key(int *main_key, int *key)
{
	int  b[48] =
	{13, 16, 10, 23,  0,  4,  2, 27, 14,  5, 20, 9,
   22, 18, 11,  3, 25,  7, 15,  6, 26, 19, 12,  1,
   40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47,
   43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31};
   	int i;
	int t[56];
	for (int j=0; j< 56; j++)
		t[j] = main_key[j];
	i = 0;
	while (i < 48)
	{
		key[i] = t[b[i]];
		i++;
	}
	//return (key);
}

void ft_key_array(int *main_key)
{
	int	round_zsuv[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2,1};
	int round;

	round = 0;
	while (round < 16)
	{
		main_key = ft_zsuv(main_key, round_zsuv[round], 0);
		main_key = ft_zsuv(main_key, round_zsuv[round], 28);
		ft_P_key(main_key, key_arr[round]);
		memmove(key_arr[round], key_arr[round], 48 * sizeof(int));
		round++;

	}
	//return (key);
}

int		*ft_do56_key(int *key)
{
	int b[56] =
	{56, 48, 40, 32, 24, 16,  8, 0, 57, 49, 41, 33, 25, 17,
   9,  1, 58, 50, 42, 34, 26, 18, 10,  2, 59, 51, 43, 35,
   62, 54, 46, 38, 30, 22, 14,  6, 61, 53, 45, 37, 29, 21,
   13,  5, 60, 52, 44, 36, 28, 20, 12,  4, 27, 19, 11, 3};
	int *res;
	res = (int*)malloc(sizeof(int) * 56);
	int i = 0;
	while (i < 56)
	{
		res[i] = key[b[i]];
		i++;
	}
	ft_key_array(res);
	return (res);

}
