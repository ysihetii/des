#include <stdio.h>

/*
3n            -> 4n
3n+1, 3n+2    -> 4n + 4
_       _
| k + 2 |
|-------| * 4 new length
|_  3  _|
*/
char	*ft_strnew(size_t size);
int		ft_strlen(char *str);

void	ft_to_binary(char *dest, int n)
{
	int i;
	i = 0;
	while (i < 8)
	{
		dest[7 - i] = (n % 2) + '0';
		n /= 2;
		i++; 
	}
}

char	ft_from_binary(char *src)
{
	int i;
	int q;
	char *string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	i = 0;
	q = 0;
	while (i < 6)
	{
		q = q * 2 + (src[i] - '0');
		i++;
	}
	return (string[q]);
}
	

void	ft_base64_encode_block(char **st, char **res, int i)
{
	char block[24];
	for (int j = 0; j < 24; j++)
		block[j] = '0';
	ft_to_binary(&(block[0]), (int)(*st)[i]);
	if ((*st)[i + 1])
		ft_to_binary(&(block[8]), (int)(*st)[i + 1]);
	if ((*st)[i + 1] && (*st)[i + 2])
		ft_to_binary(&(block[16]), (int)(*st)[i + 2]);
	(*res)[i / 3 * 4] = ft_from_binary(&block[0]);
	(*res)[i / 3 * 4 + 1] = ft_from_binary(&block[6]);
	if ((*st)[i + 1])
		(*res)[i / 3 * 4 + 2] = ft_from_binary(&block[12]);
	else
		(*res)[i / 3 * 4 + 2] = '=';
	if ((*st)[i + 1] && (*st)[i + 2])
		(*res)[i / 3 * 4 + 3] = ft_from_binary(&block[18]);
	else
		(*res)[i / 3 * 4 + 3] = '=';
}

char	*ft_base64_encode(char *st)
{
	char *res;
	int i;
	int len;

	i = 0;
	len = ft_strlen(st);
	res = ft_strnew(((len + 2) / 3) * 4);
	while (res[i])
		res[i++] = '\0' ;
	i = 0;
	while (len - i > 0)
	{
		ft_base64_encode_block(&st, &res, i);
		i += 3;
	}
	return (res);
}
/*
int main()
{
	printf("%s\n", ft_base64_encode("foobar\n"));
	return (0);
}
*/


















