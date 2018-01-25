#include <stdio.h>
#include <math.h>

int main(void)
{
	// 課題1
	int a = 0, b = 0;

	printf("二つの整数を入力してください。\n");
	printf("整数a: "); scanf("%d", &a);
	printf("整数b: "); scanf("%d", &b);

	printf("aをbで割ると%dあまり%dです。\n", a / b, a % b);

	// 課題2
	int m = 0, n = 0, h = 0, r = 0;

	printf("四つの整数を入力してください。\n");
	printf("整数m: "); scanf("%d", &m);
	printf("整数n: "); scanf("%d", &n);
	printf("整数h: "); scanf("%d", &h);
	printf("整数r: "); scanf("%d", &r);

	printf("上辺m、下辺n、高さhの台形の面積は%fです。\n", (double) ((m + n) * h) / 2);
	printf("半径rの円の面積は%fです。\n", pow((double)r, 2.0) * 3.14);

	return 0;
}