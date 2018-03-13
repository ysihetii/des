/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_ecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:57:11 by ysihetii          #+#    #+#             */
/*   Updated: 2018/01/30 15:57:12 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"


void	ft_to_binary_hex(int *dest, int n)
{
	int i;
	i = 0;
	char *q = "0123456789ABCDEF";
	for (int j = 0; j < 16; j++)
		if (q[j] == (char)n) 
			n = j;
	while (i < 4)
	{
		dest[3 - i] = (n % 2);
		n /= 2;
		i++; 
	}
}
void	ft_to_binary(int *dest, int n)
{
	int i;
	i = 0;
	while (i < 8)
	{
		dest[7 - i] = (n % 2);
		n /= 2;
		i++; 
	}
}
char 	*ft_fill_input(char *input)
{
	int len;
	int i;
	char *new_input;

	len = strlen(input);
	if (len % 8 == 0)
		return (input);
	new_input = (char*)malloc(sizeof(char) * 8 * (len / 8 + 1));
	memmove(new_input, input, sizeof(char) * len);
	i = 0;
	while (i < (8 - len % 8))
	{
		new_input[len + i] = (char)(8 - len % 8);
		i++;
		
	}
	//free(input);
	return (new_input);
}

char	*ft_get_main_key(char *key)
{
	char *new_key;

	new_key = (char*)malloc(17);
	new_key[17] = '\0';
	if (strlen(key) >= 16)
		return (memmove(new_key, key, 16));
	else
	{
		for (int i = 0; i < 16; i++)
			new_key[i] = 0;
		return(memmove(new_key, key, strlen(key)));
	}
}

void	ft_des_ecb(char *text, char *key)
{
	int len;
	int i;
	int block[64];
	int main_key[64];

	printf("\nlen=%lu\n", strlen(text));
	text = ft_fill_input(text);
	printf("\ntext=%s\n", text);
	key = ft_get_main_key(key);
	len = strlen(text);
	printf("\nlen=%i\n", len);
	for(int j = 0; j < 64; j += 4)
			ft_to_binary_hex(&(main_key[j]), key[j / 4]);
	i = 8;
	printf("\n--------------------------\n");
	while (i <= len)
	{
		for(int j = 0; j < 64; j += 8)
			ft_to_binary(&(block[j]), text[i - 8 + j / 4]);
printf("\nbefore\n");
		print_vec(block, 64);
		printf("\n+++++++++++++++++++++++++++++\n");
		//print_vec(ft_base64_encode_block(ft_des_encode(memmove(block, &(text[i - 64]), 64 * sizeof(int)), main_key)), 8);
		//print_vec (ft_des_encode(memmove(block, &(text[i - 64]), 64 * sizeof(int)), main_key), 64);
		i += 8;
	}

}
/*
int main(int argc, char **argv)
{
	printf("in=%s\n", ft_fill_input(argv[1]));
	return (0);
}
*/