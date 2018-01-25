#include <stdio.h>

// プロトタイプ宣言
char *string_cat(char[], char[]);

int main(void)
{
	char str[2][128] = { '\0' };

	// 入力
	puts("文字列を入力してください。");

	for (int i = 0; i < 2; i++)
	{
		printf("文字列%d：", i + 1);
		scanf("%s", str[i]);
	}

	printf("文字列を連結しました（最大10文字）：%s\n", string_cat(str[0], str[1]));

	return 0;
}

char *string_cat(char s1[], char s2[])
{
	char newStr[256] = { '\0' };

	// 文字列の結合
	sprintf(newStr, "%s%s", s1, s2);

	// 10文字目以降は切り捨て
	newStr[10] = '\0';

	return newStr;
}