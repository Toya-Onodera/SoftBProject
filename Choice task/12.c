#include <stdio.h>

int main(void)
{
	// ボウリングのスコアを格納する関数
	// 文字列で格納させる
	// 0 ~ 9, / (スペア), X(ストライク)
	char bowlingScoreList[21] = { '\0' };
	int inputScoreList[21] = { 0 };

	puts("/*************** ボウリングのスコア計算 ***************/");
	puts("「0」, 「1」, 「2」, 「3」, 「4」, 「5」, 「6」, 「7」, 「8」, 「9」, 「10」");
	puts("「10」は「/」(スペア)と「X」(ストライク)を意味します。\n");
	
	// 9投目まで
	for (int i = 0; i <= 17; i++)
	{
		printf("%dフレームの%d投目：", (i / 2 + 1), (i % 2 + 1));
		scanf("%d", &inputScoreList[i]);

		// ストライクの場合
		if (i % 2 == 0 && inputScoreList[i] == 10)
		{
			bowlingScoreList[i] = 'X';
			bowlingScoreList[i + 1] = ' ';

			// 次のフレームはスキップ
			i++;
		}
		
		// スペアの場合
		else if (i % 2 == 1 && (inputScoreList[i - 1] + inputScoreList[i] == 10))
		{
			bowlingScoreList[i] = '/';
		}

		// 2投目で合計10を超える場合
		else if (inputScoreList[i - 1] + inputScoreList[i] > 10)
		{
			puts("もう一度入力してください。");
			i--;
		}

		// ストライク以外
		else if (inputScoreList[i] >= 0 && inputScoreList[i] <= 9)
		{
			bowlingScoreList[i] = '0' + inputScoreList[i];
		}

		else
		{
			puts("0～10の範囲で入力してください。");
			i--;
		}
	}

	// 10投目の1、2投目
	for (int i = 18; i <= 19; i++)
	{
		printf("%dフレームの%d投目：", (i / 2 + 1), (i - 17));
		scanf("%d", &inputScoreList[i]);

		// ストライクの場合
		if (inputScoreList[i] == 10)
		{
			bowlingScoreList[i] = 'X';
		}

		// スペアの場合
		else if (i % 2 == 1 && (inputScoreList[i - 1] + inputScoreList[i] == 10))
		{
			bowlingScoreList[i] = '/';
		}

		// 2投目で合計10を超える場合
		else if (i == 19 && inputScoreList[i - 1] + inputScoreList[i] > 10)
		{
			puts("もう一度入力してください。");
			i--;
		}

		// ストライク以外
		else if (inputScoreList[i] >= 0 && inputScoreList[i] <= 9)
		{
			bowlingScoreList[i] = '0' + inputScoreList[i];
		}

		else
		{
			puts("0～10の範囲で入力してください。");
			i--;
		}
	}

	// 10投目の3投目
	if (bowlingScoreList[18] == 'X' || bowlingScoreList[19] == '/')
	{
		do
		{
			printf("10フレームの3投目：");
			scanf("%d", &inputScoreList[20]);

			// ストライクの場合
			if (inputScoreList[20] == 10)
			{
				bowlingScoreList[20] = 'X';
			}

			// スペアの場合
			else if ((inputScoreList[19] + inputScoreList[20] == 10))
			{
				bowlingScoreList[20] = '/';
			}

			// 2投目で合計10を超える場合
			else if (inputScoreList[19] + inputScoreList[20] > 10)
			{
				puts("もう一度入力してください。");
				continue;
			}

			// ストライク以外
			else if (inputScoreList[20] >= 0 && inputScoreList[20] <= 9)
			{
				bowlingScoreList[20] = '0' + inputScoreList[20];
			}

			else
			{
				puts("0～10の範囲で入力してください。");
				continue;
			}

		} while (0);
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (i == 0)
			{
				if (j % 2 == 0 && j <= 18)
				{
					printf("%3d", j / 2 + 1);
				}

				else
				{
					printf(" --");
				}
			}

			else
			{
				printf("%3c", bowlingScoreList[j]);
			}
		}

		printf("\n");
	}

	return 0;
}