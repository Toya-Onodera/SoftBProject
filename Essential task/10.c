#include <stdio.h>
#include <stdlib.h>

// プロトタイプ宣言
void sort(int *, int);

int main(void)
{
	int varList[5] = { 0 };
	int varList_length = (sizeof(varList) / sizeof(int));

	// 入力
	printf("整数を5つ入力してください。\n");

	for (int i = 0; i < 5; i++)
	{
		printf("整数%d：", i + 1);
		scanf("%d", &varList[i]);
	}

	// 計算
	sort(varList, varList_length);

	// 表示
	printf("小さい順に並び変えました：");

	for (int i = 0; i < 5; i++)
	{
		printf("%3d", varList[i]);
	}

	printf("\n");

	return 0;
}

void sort(int vList[], int num)
{
	// バブルソート用の変数
	int var = 0;

	// ソートを行う
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vList[i] < vList[j])
			{
				var = vList[j];
				vList[j] = vList[i];
				vList[i] = var;
			}
		}
	}
}
