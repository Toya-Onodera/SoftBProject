#include <stdio.h>
int main(void)
{
	// 必須課題1
	int points[5] = { 0, 0, 0, 0, 0 };
	int sum = 0;
	
	printf("5人の点数を入力してください\n");
	
	for (int i = 0; i < 5; i++)
	{
		printf("%d人目の点数：", i + 1);
		scanf("%d", &points[i]);
		sum += points[i];
	}

	printf("合計点：%d点\n", sum);
	printf("平均値：%.2lf点\n", (double) sum / 5);
	
	// 必須課題2
	int num_array[5] = {0, 0, 0, 0, 0};
	int check_num = 0,

	check_flg = 0;
	printf("5つの整数値を入力してください。\n");
	
	for (int i = 0; i < 5; i++)
	{
		printf("整数%d：", i + 1);
		scanf("%d", &num_array[i]);
	}
	
	while (1)
	{
		printf("整数値を入力してください：");
		scanf("%d", &check_num);

		if (check_num == 999)
		{
			printf("動作を終了します。\n");
			break;
		}

		check_flg = 0;
		
		for (int i = 0; i < 5; i++)
		{
			if (num_array[i] == check_num)
			{
				check_flg = 1;
				break;
			}
		}

		if (check_flg == 1)
		{
			printf("TRUE\n");
		}

		else
		{
			printf("FALSE\n");
		}
	}
	
	return 0;
}