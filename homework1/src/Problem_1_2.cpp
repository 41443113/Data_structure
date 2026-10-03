#include<iostream>
using namespace std;

void push_s(int* s, int& top, int capacity, int value) {
	if (top >= capacity - 1) {//當超出堆疊上限
		cout << "Stack Overflow";
		return;
	}
	s[++top] = value;//存入堆疊
}

int pop_s(int* s, int& top) {
	return s[top--];//取出堆疊
}

int Ackermann(int m, int n) {
	int capacity = 16;//記憶體大小
	int top = -1;//堆疊位置
	int* s = new int[capacity];
	push_s(s, top, capacity, m);
	while (top >= 0) {
		m = pop_s(s, top);
		if (m == 0) {
			n++;
		}
		else if (n == 0) {
			n = 1;
			push_s(s, top, capacity, m - 1);//存入A(m-1,1)
		}
		else {
			n--;
			push_s(s, top, capacity, m - 1);//先存入A(m-1,  )
			push_s(s, top, capacity, m);//再存入A(m,n-1)先算
		}
	}
	delete[] s;
	return n;
}
int main() {
	int m, n;
	cout << "Input m and n :";
	cin >> m >> n;
	cout << "A(" << m << "," << n << ")=" << Ackermann(m, n);
	return 0;
}