#include <stdio.h>

int main(void)
{
	// 選択課題
	int var1, var2, var3, max;

	printf("3つの整数を入力してください。:");
	scanf("%d %d %d", &var1, &var2, &var3);
	
	max = var1;
	if (var2 > max) { max = var2; }
	if (var3 > max) { max = var3; }
	
	printf("入力された値の最大値は、%dです。\n", max);
	
	return 0;
}