#include <stdio.h>

int main (void)
{
	// 必須課題1で使う変数
	int n1, n2;
	int wa;

	// 必須課題3で使う変数 -> 年齢用
	int age = 0;

	// 必須課題1
	puts("二つの整数を入力してください。");
	printf("整数1："); scanf("%d", &n1);
	printf("整数2："); scanf("%d", &n2);

	wa = n1 + n2;

	printf("それらの和は%dです。\n", wa);

	// 必須課題2
	puts("風");
	puts("  林");
	puts("   火");
	puts("     山");

	// 必須課題3
	printf("あなたは何歳ですか？\n");
	scanf("%d", &age);

	printf("あなたは%d歳ですね。\n", age);

	return 0;
}