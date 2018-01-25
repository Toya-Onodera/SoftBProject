#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int AsciiCast(char);

int main(void)
{
	// �{�E�����O�̃X�R�A���i�[����֐�
	// ������Ŋi�[������
	// 0 ~ 9, / (�X�y�A), X(�X�g���C�N)
	char bowlingScoreList[21] = { '\0' };
	int inputScoreList[21] = { 0 };

	puts("/*************** �{�E�����O�̃X�R�A�v�Z ***************/");
	puts("�u0�v, �u1�v, �u2�v, �u3�v, �u4�v, �u5�v, �u6�v, �u7�v, �u8�v, �u9�v, �u10�v");
	puts("�u10�v�́u/�v(�X�y�A)�ƁuX�v(�X�g���C�N)���Ӗ����܂��B\n");
	
	// 9���ڂ܂�
	for (int i = 0; i <= 17; i++)
	{
		printf("%d�t���[����%d���ځF", (i / 2 + 1), (i % 2 + 1));
		scanf("%d", &inputScoreList[i]);

		// �X�g���C�N�̏ꍇ
		if (i % 2 == 0 && inputScoreList[i] == 10)
		{
			bowlingScoreList[i] = 'X';
			bowlingScoreList[i + 1] = ' ';

			// ���̃t���[���̓X�L�b�v
			i++;
		}
		
		// �X�y�A�̏ꍇ
		else if (i % 2 == 1 && (inputScoreList[i - 1] + inputScoreList[i] == 10))
		{
			bowlingScoreList[i] = '/';
		}

		// 2���ڂō��v10�𒴂���ꍇ
		else if (inputScoreList[i - 1] + inputScoreList[i] > 10)
		{
			puts("������x���͂��Ă��������B");
			i--;
		}

		// �X�g���C�N�ȊO
		else if (inputScoreList[i] >= 0 && inputScoreList[i] <= 9)
		{
			bowlingScoreList[i] = '0' + inputScoreList[i];
		}

		else
		{
			puts("0�`10�͈̔͂œ��͂��Ă��������B");
			i--;
		}
	}

	// 10���ڂ�1�A2����
	for (int i = 18; i <= 19; i++)
	{
		printf("%d�t���[����%d���ځF", (i / 2 + 1), (i - 17));
		scanf("%d", &inputScoreList[i]);

		// �X�g���C�N�̏ꍇ
		if (inputScoreList[i] == 10)
		{
			bowlingScoreList[i] = 'X';
		}

		// �X�y�A�̏ꍇ
		else if (i % 2 == 1 && (inputScoreList[i - 1] + inputScoreList[i] == 10))
		{
			bowlingScoreList[i] = '/';
		}

		// 2���ڂō��v10�𒴂���ꍇ
		else if (i == 19 && inputScoreList[i - 1] + inputScoreList[i] > 10)
		{
			puts("������x���͂��Ă��������B");
			i--;
		}

		// �X�g���C�N�ȊO
		else if (inputScoreList[i] >= 0 && inputScoreList[i] <= 9)
		{
			bowlingScoreList[i] = '0' + inputScoreList[i];
		}

		else
		{
			puts("0�`10�͈̔͂œ��͂��Ă��������B");
			i--;
		}
	}

	// 10���ڂ�3����
	if (bowlingScoreList[18] == 'X' || bowlingScoreList[19] == '/')
	{
		do
		{
			printf("10�t���[����3���ځF");
			scanf("%d", &inputScoreList[20]);

			// �X�g���C�N�̏ꍇ
			if (inputScoreList[20] == 10)
			{
				bowlingScoreList[20] = 'X';
			}

			// �X�y�A�̏ꍇ
			else if ((inputScoreList[19] + inputScoreList[20] == 10))
			{
				bowlingScoreList[20] = '/';
			}

			// 2���ڂō��v10�𒴂���ꍇ
			else if (inputScoreList[19] + inputScoreList[20] > 10)
			{
				puts("������x���͂��Ă��������B");
				continue;
			}

			// �X�g���C�N�ȊO
			else if (inputScoreList[20] >= 0 && inputScoreList[20] <= 9)
			{
				bowlingScoreList[20] = '0' + inputScoreList[20];
			}

			else
			{
				puts("0�`10�͈̔͂œ��͂��Ă��������B");
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