#include <stdio.h>

int main(void)
{
	// 課題1
	int var1, var2, var3, min;

	puts("課題1");
	printf("3つの整数を入力してください。:");
	scanf("%d %d %d", &var1, &var2, &var3);

	min = var1;
	if (var2 < min) { min = var2; }
	if (var3 < min) { min = var3; }
	
	printf("入力された値の最小値は、%dです。\n", min);
	
	// 課題2
	int var4, var5, var6, var7, max;
	
	puts("\n課題2");
	printf("4つの整数を入力してください。:");
	scanf("%d %d %d %d", &var4, &var5, &var6, &var7);
	
	max = var4;
	if (var5 > max) { max = var5; }
	if (var6 > max) { max = var6; }
	if (var7 > max) { max = var7; }
	
	printf("入力された値の最大値は、%dです。\n", max);
	
	// 課題3
	int month = 1;
	
	puts("\n課題3");
	printf("Input number?\n");
	scanf("%d", &month);
	
	switch (month)
	{
		case 1: printf("1月は英語でJanuaryです。\n"); break;
		case 2: printf("2月は英語でFebruaryです。\n"); break;
		case 3: printf("3月は英語でMarchです。\n"); break;
		case 4: printf("4月は英語でAprilです。\n"); break;
		case 5: printf("5月は英語でMayです。\n"); break;
		case 6: printf("6月は英語でJuneです。\n"); break;
		case 7: printf("7月は英語でJulyです。\n"); break;
		case 8: printf("8月は英語でAugustです。\n"); break;
		case 9: printf("9月は英語でSeptemberです。\n"); break;
		case 10: printf("10月は英語でOctoberです。\n"); break;
		case 11: printf("11月は英語でNovemberです。\n"); break;
		case 12: printf("12月は英語でDecemberです。\n"); break;
		default: printf("入力エラー\n"); break;
	}
	
	return 0;
}