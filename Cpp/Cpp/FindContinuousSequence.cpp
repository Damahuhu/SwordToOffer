/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-06

Description: С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
			 ���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
			 û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
			 ���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck! 

			 ������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int> > res;

	if (sum < 3){
		return res;
	}

	int smallNum = 1;
	int bigNum = 2;

	int tem = smallNum + bigNum;

	while (smallNum < bigNum){
		while (tem < sum){
			bigNum++;
			tem += bigNum;
		}

		while (tem > sum){
			tem -= smallNum;
			smallNum++;
		}

		if (tem == sum){
			vector<int> vec;
			for (int i = smallNum; i <= bigNum; i++){
				vec.push_back(i);
			}
			res.push_back(vec);

			tem -= smallNum;
			smallNum++;
		}
	}

	return res;
}

void PrintRes(vector<vector<int> > res)
{
	for (auto i = 0; i < res.size(); i++){
		vector<int> &tem = res[i];

		for (auto j = 0; j < tem.size(); j++){
			std::cout << tem[j] << " ";
		}

		std::cout << std::endl;
	}
}

int main()
{
	int sum = 3;

	DWORD start, stop;
	start = GetTickCount();
	vector<vector<int> > res = FindContinuousSequence(sum);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
