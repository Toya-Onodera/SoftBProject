#include <stdio.h>

int main(void)
{
	for (int i = 2; i <= 10000; i++)
	{
		if (i == 2) { printf("%5d", i); continue; }
		if (i % 2 == 0) { continue; }
		
		for (int j = 3; j <= i; j += 2)
		{
			if (i % j == 0)
			{
				if (j == i)
				{
					printf("%5d", i);
				}
				
				break;
			}
		}
	}

	printf("\n");
	
	return 0;
}