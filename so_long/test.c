#include <stdio.h>

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int main()
{
	int temp = create_trgb(0, 0xff, 0xaa, 0xbb);
	printf("%x",temp);
}