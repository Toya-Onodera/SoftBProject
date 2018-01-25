#include <stdio.h>

// プロトタイプ宣言
int bowlingScoreCalc(int, int);

/***** グローバル変数 *****/
// 文字列でスコアを格納する
// 0 ~ 9, / (スペア), X(ストライク)
char bowlingScoreList[21] = { '\0' };

// 整数値でスコアを入力させる
int inputScoreList[21] = { 0 };

int main(void)
{
	// スコアの合計を格納する変数
	int totalScore = 0;

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
		else if (i % 2 == 1 && (inputScoreList[i - 1] + inputScoreList[i]) > 10)
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
		else if (i == 19 && (inputScoreList[i - 1] + inputScoreList[i] == 10))
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
			else if (inputScoreList[18] == 10 && (inputScoreList[19] + inputScoreList[20] == 10))
			{
				bowlingScoreList[20] = '/';
			}

			// 2投目で合計10を超える場合
			else if (bowlingScoreList[19] != 'X' && (inputScoreList[19] + inputScoreList[20]) > 10)
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

	// 実際にスコアを計算する
	// 再帰も使用
	for (int i = 0; i <= 20; i++)
	{
		// 10フレーム目3投目に対応
		if (bowlingScoreList[i] != '\0')
		{
			totalScore += bowlingScoreCalc(i, 1);
			printf("%d\n", totalScore);
		}
	}

	// 表示
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

	printf("\nトータルスコア：%d点\n", totalScore);

	return 0;
}

// ボウリングのスコアを計算する関数
int bowlingScoreCalc(int n, int count)
{
	// 9フレーム目まで
	if (n <= 17)
	{
		// ストライク
		if (bowlingScoreList[n] == 'X')
		{
			// スペアのあとにストライクをとった場合
			if (count == -1)
			{
				return 10;
			}

			// ストライク 1回目
			else if (count == 1)
			{
				return 10 + bowlingScoreCalc(n + 2, count + 1) + bowlingScoreCalc(n + 3, count + 1);
			}

			// ストライク 2回目
			else if (count == 2)
			{
				return 10 + bowlingScoreCalc(n + 1, count + 1) + bowlingScoreCalc(n + 2, count + 1);
			}

			// ストライク 3回目以降
			else
			{
				return bowlingScoreCalc(n + 1, count + 1) + bowlingScoreCalc(n + 2, count + 1);
			}
		}

		// スペア
		else if (bowlingScoreList[n] == '/')
		{
			// スペアするときに倒した本数 + (n+1)フレーム1投目のスコア
			return inputScoreList[n] + bowlingScoreCalc(n + 1, -1);
		}

		// それ以外
		else
		{
			return inputScoreList[n];
		}
	}

	// 10フレーム目
	else
	{
		return inputScoreList[n];
	}
}