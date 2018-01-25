#include <stdio.h>
#include <math.h>

// 構造体 point を定義
typedef struct
{
	double x, y;
} point;

// 構造体 triangle を定義
typedef struct
{
	point a, b, c;
} triangle;

// プロトタイプ宣言
double SidesLength(point, point);
double DefineS(double, double, double);
double AnswerArea(triangle *);

int main(void)
{
	// 構造体関係
	point point_use;
	triangle triangle_use;

	// 計算に使う変数
	double sides[3] = { 0 };
	double s = 0.0;
	double area = 0.0;

	for (int i = 0; i < 3; i++)
	{
		printf("%d点目のx座標を入力してください：", (i + 1));
		scanf("%lf", &point_use.x);

		printf("%d点目のx座標を入力してください：", (i + 1));
		scanf("%lf", &point_use.y);

		if (i == 0)
		{
			triangle_use.a = point_use;
		}

		else if (i == 1)
		{
			triangle_use.b = point_use;
		}

		else
		{
			triangle_use.c = point_use;
		}
	}

	// 面積を求める -> ヘロンの公式を使用
	sides[0] = SidesLength(triangle_use.a, triangle_use.b);
	sides[1] = SidesLength(triangle_use.b, triangle_use.c);
	sides[2] = SidesLength(triangle_use.c, triangle_use.a);
	s = DefineS(sides[0], sides[1], sides[2]);
	area = sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));

	printf("三角形の面積は：%.2lfです。\n", area);

	return 0;
}

double SidesLength(point s1, point s2)
{
	return sqrt(pow((s1.x - s2.x), 2.0) + pow((s1.y - s2.y), 2.0));
}

double DefineS(double a, double b, double c)
{
	return (a + b + c) / 2;
}