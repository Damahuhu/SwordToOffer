/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-06

Description: 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
			 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
			 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
			 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 

			 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序。
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
