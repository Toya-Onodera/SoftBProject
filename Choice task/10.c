#include <stdio.h>

// プロトタイプ宣言
void increment_date(int, int, int, int);

int main(void)
{
	int year = 0,
		month = 0,
		day = 0,
		num = 0;

	// 入力
	printf("日付を入力してください。\n");

	printf("年：");
	scanf("%d", &year);

	printf("月：");
	scanf("%d", &month);

	printf("日：");
	scanf("%d", &day);

	printf("何日進めますか？：");
	scanf("%d", &num);

	increment_date(&year, &month, &day, num);

	printf("%d年%d月%d日になりました。\n", year, month, day);

	return 0;
}

void increment_date(int *y, int *m, int *d, int n)
{
	// 各月の最終日を配列に格納する
	int monthNum[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// 日数の計算に使う変数
	int daySum = *d + n;

	// 入力した年の1月1日から目標の日数が何日目なのかを計算する
	// (入力例) -> 2017, 12, 8, 23 の場合、366となる。
	for (int i = 0; i < (*m - 1); i++)
	{
		daySum += monthNum[i];
	}

	// 年を越すのかチェック
	if (daySum > 365)
	{
		// 複数年にも対応
		while (daySum >= 365)
		{
			// うるう年は4の倍数
			// かつ、100の倍数以外
			// しかし、400の倍数は例外
			if ((*y % 4 == 0) && (*y % 100 != 0)
			|| *y % 400 == 0)
			{
				daySum -= 366;
			}

			else
			{
				daySum -= 365;
			}

			*y += 1;
		}
	}

	// うるう年の2月28日にも対応する
	if ((*y % 4 == 0) && (*y % 100 != 0)
	|| *y % 400 == 0)
	{
		monthNum[1] = 29;
	}

	// 月の計算
	for (int i = 0; i < 12; i++)
	{
		// 月を格納
		*m = i + 1;

		if (daySum <= monthNum[i])
		{
			break;
		}

		daySum -= monthNum[i];
	}

	// 日付を格納
	*d = daySum;
}