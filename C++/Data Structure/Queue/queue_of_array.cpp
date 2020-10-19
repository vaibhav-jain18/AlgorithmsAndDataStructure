// in c++ stl <queue> 
// here bulit in functions push() for insert a value in queue
// here bulit in function pop() for delete toppest value from queue
// for print there are two bulit in functions front and back 
// we can print from both sides by front() function print from front side and by back() print from back side 

#include <iostream> 
#include <bits/stdc++.h>
#include <queue> 
using namespace std; 

int main() 
{ 
	queue<int> mystack; 
	mystack.push(1); 
	mystack.push(2); 
	mystack.push(3); 
	mystack.push(4); 


	while (!mystack.empty()) { 
		cout << ' ' << mystack.front(); 
		mystack.pop(); 
	} 
} 


