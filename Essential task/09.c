#include <stdio.h>

// プロトタイプ宣言
void swap(int *, int *);

int main(void)
{
	int num1, num2;

	printf("整数値を2つ入力してください。\n");
	printf("整数a："); scanf("%d", &num1);
	printf("整数a："); scanf("%d", &num2);

	swap(&num1, &num2);

	printf("2つの整数値を交換しました。\n");
	printf("整数a：%d\n", num1);
	printf("整数b：%d\n", num2);

	return 0;
}

// ポインタを使用した値の入れ替えを行う関数
void swap(int *pX, int *pY)
{
	int tmp;

	tmp = *pX;
	*pX = *pY;
	*pY = tmp;
}