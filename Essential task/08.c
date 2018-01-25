#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// プロトタイプ宣言
int GetRand(int, int);
char *GetCharacter(int, int);
char *GetTimePrint(int);
char *GetRank(int, int);

int main(void)
{
	// 数値系の変数
	int maxNum = 0,
		minNum = 0,
		targetNum = 0,
		inputNum = 0;

	// 時間計測系の変数
	int elapsedTime = 0;
	clock_t startTime = 0,
			endTime = 0;

	// ゲームモード選択の変数
	int gameMode = 0;

	// ゲームに使う変数
	int playerPeople = 1,
		count = 0,
		enemyVarMin = 0,
		enemyVarMax = 0;

	// モードの選択
	printf("ゲームモードを選択してください。\n");

	do {
		printf("\n1:一人モード、2:対戦モード (CPと対戦)、3:ゲームをやめる\n\n");
		printf("どのモードで遊びますか：");
		scanf("%d", &gameMode);

		switch (gameMode)
		{
			// 一人プレイ選択時
			case 1:
				playerPeople = 1;
				printf("一人プレイを開始します。\n");
				break;

			// 二人プレイの選択時
			case 2:
				playerPeople = 2;
				printf("二人プレイを開始します。\n");
				break;
		
			// ゲームを正常終了
			case 3:
				printf("ゲームを終了します。\n");
				return 0;

			// 1～3以外の数値が入力された場合
			default:
				printf("\n* 1～3の値を入力してください。\n"); break;
		}

	} while (gameMode < 1 || gameMode > 3);

	puts("\nGame Start!");
	srand((unsigned int)time(NULL));

	// 乱数の範囲を設定
	printf("今回のゲームの範囲を入力してください\n");
	
	printf("最小値：");
	scanf("%d", &minNum);
	enemyVarMin = minNum;
	
	printf("最大値：");
	scanf("%d", &maxNum);
	enemyVarMax = maxNum;

	// ターゲットになる値を設定
	targetNum = GetRand(minNum, maxNum);
	
	// 時間の計測開始
	startTime = clock();

	// for文を使用して無限ループさせる
	for (int i = 1;; i++)
	{
		// 二人プレイモードなら
		if (playerPeople == 1 || i % 2 == 1)
		{
			count++;
			printf("\n/***** 自分のターン *****/\n");
			printf("整数を入力してください：");
			scanf("%d", &inputNum);
		}
		
		else
		{
			printf("\n/***** CPのターン *****/\n");

			inputNum = GetRand(enemyVarMin, enemyVarMax);
			printf("整数：%d\n", inputNum);
		}


		// 経過時間 or 終了時間
		endTime = clock();

		// 正解だったら終了
		if (inputNum == targetNum)
		{
			printf("******************************\n\n");
			printf("  正解! 答えは「%d」でした！\n", targetNum);
			printf("  タイム -> %s\n", GetTimePrint(endTime - startTime));

			// 自分がクリアした場合はランク変動
			if (playerPeople == 1 || i % 2 == 1)
			{
				printf("  ランク -> %s\n", GetRank(count, maxNum));
			}

			// 敵にクリアされた場合は強制ランクD
			else
			{
				printf("  あなたのランク -> D\n");
			}
			
			printf("\n******************************\n");
			
			break;
		}

		// それ以外ならヒントを与える
		else
		{
			// 敵のランダム生成の範囲を設定する
			if (targetNum > inputNum && enemyVarMax > inputNum)
			{
				enemyVarMin = inputNum;
			}

			else if (enemyVarMin < inputNum)
			{
				enemyVarMax = inputNum;
			}

			printf("経過タイム -> %s\n", GetTimePrint(endTime - startTime));
			printf("(%d回目) 正解は、%dより%sです。\n", i, inputNum, GetCharacter(targetNum, inputNum));
		}
	}

	return 0;
}

// ランダムで指定された範囲の数値を返す関数
int GetRand(int min, int max)
{
	return min + (int) (rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

// 文字列を返す関数
char *GetCharacter (int TarNum, int InNum)
{
	return (TarNum > InNum) ? "大きい" : "小さい";
}

// 時間を [ms] ではなく mm:ss:vv に変更した文字列を返す関数
char *GetTimePrint(int Time)
{
	char charTime[256] = {'\0'};
	int mm = 0,
		ss = 0,
		vv = 0;

	mm = Time / 60000;
	ss = Time / 1000;
	vv = Time % 100;
	while (ss > 60) { ss -= 60; }

	// 数値を文字列で代入 -> 形式は mm:ss:vv
	sprintf(charTime, "%02d:%02d:%02d", mm, ss, vv);

	return charTime;
}

// ランクを返す関数 -> TODO 範囲によってランク変動させる
char *GetRank(int n, int maxN)
{
	maxN /= 2;

	if (n <= maxN * 0.01)
	{
		return "S";
	}

	else if (n <= maxN * 0.15)
	{
		return "A";
	}

	else if (n <= maxN * 0.3)
	{
		return "B";
	}

	else
	{
		return "C ";
	}
}