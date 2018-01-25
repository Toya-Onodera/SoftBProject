#include <stdio.h>
#include <string.h>
#include <ctype.h>

// プロトタイプ宣言
void del_digit(char);

int main(void)
{
	char str[256] = { '\0' };

	// 課題1
	printf("文字列を入力してください：");
	scanf("%s", &str);

	// 文字列表示
	printf("格納された文字列を表示します：%s\n", str);

	// 文字列のlengthを表示
	printf("文字列カウント：%d\n", strlen(&str));

	// 文字列クリア
	printf("文字列をクリアします。\n");
	str[0] = '\0';

	printf("格納された文字列を表示します：%s\n", str);

	// 課題2
	printf("文字列を入力してください：");
	scanf("%s", &str);

	del_digit(&str);

	printf("数字を削除しました：%s\n", str);
	
	return 0;
}

void del_digit(char s[])
{
	int _i = 0;

	for (int i = 0; i < strlen(s); i++)
	{
		// 数字以外なら
		if (!isdigit(s[i]))
		{
			s[_i] = s[i];
			_i++;
		}
	}

	s[_i] = '\0';
}