#ifndef DES_H
#define DES_H

char	*ft_base64_encode(char *st);




void	ft_IP(int *a);
void	ft_IP_back(int *a);
int *ft_xor(int *a, int *b, int n);

int key_arr[16][48];
int		*ft_zsuv(int *key, int n, int m);
void  ft_P_key(int *main_key, int *key);
void ft_key_array(int *main_key);
int		*ft_do56_key(int *key);


int		*ft_E(int *part, int *md_key);
int		*ft_S(int *part);
int 		*ft_P(int *part);
int		*ft_F(int *part, int *key);

int *ft_des_decode(int *text, int *main_key);
int *ft_des_encode(int *block, int *main_key);
void	ft_des_ecb(char *text, char *key);

#include<stdio.h>
void print_vec(int *a, int n);



   
#endif