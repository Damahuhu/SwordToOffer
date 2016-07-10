/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-07

Description: LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成
任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),
“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。
为了方便起见,你可以认为大小王是0。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void quickSort(vector<int> &numbers, int left, int right){
	if (left >= right){
		return;
	}

	int i = left;
	int j = right;
	int target = numbers[i];

	while (i < j){
		while (i < j && numbers[j] > target){
			j--;
		}
		if (i < j){
			numbers[i++] = numbers[j];
		}

		while (i < j && numbers[i] < target){
			i++;
		}

		if (i < j){
			numbers[j] = numbers[i];
		}

		numbers[i] = target;
	}

	quickSort(numbers, left, i - 1);
	quickSort(numbers, i+1, right);
}

bool IsContinuous(vector<int> numbers) {
	if (numbers.size() == 0){
		return false;
	}

	quickSort(numbers, 0, numbers.size() - 1);

	int countZero = 0;
	int countDelta = 0;

	for (int i = 0; i < numbers.size(); i++){
		if (numbers[i] == 0){
			countZero++;
		}
		else if (i > countZero){
			if (numbers[i] == numbers[i - 1]){
				return false;
			}

			countDelta += (numbers[i] - numbers[i - 1] - 1);
		}
	}

	if (countDelta > countZero){
		return false;
	}

	return true;
}

void PrintRes(bool res)
{
	if (res){
		cout << "yes!" << endl;
	}
	else{
		cout << "no!" << endl;
	}
}

int main()
{
	vector<int> numbers = {0,3,2,6,4};
	
	DWORD start, stop;
	start = GetTickCount();
	bool res = IsContinuous(numbers);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
