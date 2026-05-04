#include <iostream>
#include <stack>
#include <string>

bool isnum(std::string& a) {
	if (a[0] == '+' || a[0] == '*' || a[0]=='/' || a[0] == '(' || a[0] == ')')
		return false;
	else if (a[0]=='-')
	{
		if (a.length()==1)
			return false;
		else
			return true;
	}
	else
		return true;
}

int main() {
	std::string temp;
	std::string ssnums;
	std::stack<char> stack;
	while (std::cin >> temp)
	{
		if (temp=="exit") break;
		if (isnum(temp)==true)
		{
			ssnums+=temp;
			ssnums += " ";
		}
		else 
		{
			if (stack.size()!=0) 
			{
				while ((stack.size()!=0) && (stack.top()!='(')&&(((temp=="*" || temp=="/") && (stack.top()=='*' || stack.top()=='/')) || ((temp=="-" || temp=="+")&& stack.size()!=0)))
				{
					ssnums += stack.top();
					ssnums += " ";
					stack.pop();
				}
			}
			if (temp==")")
			{
				while (stack.size()!=0 && stack.top()!='(')
				{
					ssnums += stack.top();
                                        ssnums += " ";
                                        stack.pop();
				}
				if (stack.size()==0)
				{
					std::cout << "Отсутствует скобка!" << std::endl;
					return -1;
				}
				stack.pop();
			}
			if (temp!=")")
				stack.push(temp[0]);
		}
	}
	std::cout << ssnums;
	while (stack.size()!=0)
	{
		if (stack.top()=='(')
		{
			std::cout << "Нет скобки!" << std::endl;
			return -1;
		}
		std::cout << stack.top() << " ";
		stack.pop();
	}
	return 0;
}

