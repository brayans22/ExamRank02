#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char bit = 0;
	int	index = 7;

	while (index >= 0)
	{
		bit = (((octet >> index) & 1) + '0'); 
		write(1, &bit, 1);
		index--;
	}
}
