#include "libft.h"

long long		ft_lenlong_base(long long n, int base)
{
	long	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}