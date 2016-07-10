/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-07

Description: LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ���
�κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),
��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�
Ϊ�˷������,�������Ϊ��С����0��
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
