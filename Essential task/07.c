#include <stdio.h>

// プロトタイプ宣言
int sumFunc(int); // 課題1
int nabeatu(int); // 課題2

int main(void)
{
	// 課題1
	int num1 = 0;

	printf("整数を入力してください：");
	scanf("%d", &num1);
	
	printf("1から%dまでの和は%dです。\n", num1, sumFunc(num1));
	
	// 課題2
	int num2 = 0;
	
	while (1)
	{
		printf("整数を入力してください：");
		scanf("%d", &num2);
		
		if (num2 == 999)
		{
			printf("動作を終了します。\n");
			break;
		}
		
		switch (nabeatu(num2))
		{
			case 1:
				printf("アホワン\n");
				break;
			case 2:
				printf("アホ\n");
				break;
			case 3:
				printf("ワン\n");
				break;
			default:
				printf("%d\n", num2);
				break;
		}
	}

	return 0;
}

// 課題1の関数
int sumFunc(int n)
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	
	return sum;
}

// 課題2の関数
int nabeatu(int n)
{
	int check = 0;
	
	// 3と5の公倍数
	if (n % 15 == 0)
	{
		check = 1;
	}

	// 3の公倍数
	else if (n % 3 == 0)
	{
		check = 2;
	}
	
	// 5の公倍数
	else if (n % 5 == 0)
	{
		check = 3;
	}
	
	return check;
}