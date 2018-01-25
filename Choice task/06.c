#include <stdio.h>

int main(void)
{
	// 必須課題
	int matrixA[3][2] = { 0 };
	int matrixB[2][3] = { 0 };
	int matrixTrue[3][3] = { 0 };
	
	puts("選択課題");
	printf("行列Aの要素を入力してください\n");
	
	// 行列Aに代入
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("行列Aの、%d行%d列の値を入力してください：", i + 1, j + 1);
			scanf("%d", &matrixA[i][j]);
		}
	}
	
	// 行列Bに代入
	printf("\n行列Bの要素を入力してください\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("行列Bの、%d行%d列の値を入力してください：", i + 1, j + 1);
			scanf("%d", &matrixB[i][j]);
		}
	}

	// 計算を行う
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixTrue[i][j] = matrixA[i][0] * matrixB[0][j] + matrixA[i][1] * matrixB[1][j];
		}
	}

	// 表示
	printf("行列Aと行列Bの積は3行3列であり、各要素の値は\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%5d", matrixTrue[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
