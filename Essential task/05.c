#include <stdio.h>

int main(void)
{
	// 課題1
	int length = 0,
		sum1 = 0,
		var1;

	printf("整数は何個ですか？：");
	scanf("%d", &length);
	
	for (int i = 0; i < length; i++)
	{
		printf("整数%d：", i + 1);
		scanf("%d", &var1);
		sum1 += var1;
	}

	printf("合計値:%d\n", sum1);
	printf("平均値:%.2lf\n", (double) sum1 / length);
	
	// 課題2
	int max = 0,
		sum2 = 0,
		j = 1,
		var2;

	printf("最大値を入力してください：");
	scanf("%d", &max);
	
	while (1) {
		printf("%d回目：", j);
		scanf("%d", &var2);
		
		sum2 += var2;
		printf("%d回目までの合計値：%d\n", j, sum2);
		
		if (sum2 >= max)
		{
			break;
		}
		
		j++;
	}

	printf("繰り返し回数は%d、合計値は%dです。\n", j, sum2);
	
	return 0;
}