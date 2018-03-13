#include <stdio.h>

char	*ft_strnew(size_t size);
int		ft_strlen(char *str);

void	ft_to_binary(char *dest, char c)
{
	int i;
	char *string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int n;
	n = 0;
	while (c != string[n])
		n++;
	i = 0;
	while (i < 6)
	{
		dest[5 - i] = (n % 2) + '0';
		n /= 2;
		i++; 
	}
}

char	ft_from_binary(char *src)
{
	int i;
	int q;
	i = 0;
	q = 0;
	while (i < 8)
	{
		q = q * 2 + (src[i] - '0');
		i++;
	}
	return ((char)q);
}
	

void	ft_base64_encode_block(char **st, char **res, int i)
{
	char block[24];
	for (int j = 0; j < 24; j++)
		block[j] = '0';
	ft_to_binary(&(block[0]), (int)(*st)[i]);
	ft_to_binary(&(block[6]), (int)(*st)[i + 1]);
	if ((*st)[i + 2] != '=')
		ft_to_binary(&(block[12]), (int)(*st)[i + 2]);
	if ((*st)[i + 2] != '=' && (*st)[i + 3] != '=')
		ft_to_binary(&(block[18]), (int)(*st)[i + 3]);
	(*res)[i / 4 * 3] = ft_from_binary(&block[0]);
	if ((*st)[i + 2] != '=')
		(*res)[i / 4 * 3 + 1] = ft_from_binary(&block[8]);
	if ((*st)[i + 2] != '=' && (*st)[i + 3] != '=')
		(*res)[i / 4 * 3 + 2] = ft_from_binary(&block[16]);
}

char	*ft_base64_encode(char *st)
{
	char *res;
	int i;
	int len;

	i = 0;
	len = ft_strlen(st);
	if (st[len - 1] == '=')
		len--;
	if (st[len - 2] == '=')
		len--;
	if (len % 4)
		res = ft_strnew(((len / 4) * 3) + (len % 4) - 1);
	else
		res = ft_strnew((len / 4) * 3);
	
	while (res[i])
		res[i++] = '\0' ;
	i = 0;
	while (len - i > 0)
	{
		ft_base64_encode_block(&st, &res, i);
		i += 4;
	}
	return (res);
}

int main()
{
	printf("%s\n", ft_base64_encode("dG90bwo="));
	return (0);
}



















