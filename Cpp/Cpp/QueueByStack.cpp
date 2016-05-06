/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。 
**************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <windows.h>

using namespace std;

class Queue
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {

		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		if (!stack2.empty()){
			int top = stack2.top();
			stack2.pop();

			return top;
		}

		return -1;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main(){
	Queue queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	std::cout << queue.pop() << std::endl;
	queue.push(4);
	std::cout << queue.pop() << std::endl;
	queue.push(5);
	std::cout << queue.pop() << std::endl;

	return 0;
}