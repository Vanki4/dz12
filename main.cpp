#include <iostream>
#include "list.h"
#include <cstdlib>

std::pair<DFlist::Node*,size_t> findcic(const DFlist& a) {
	DFlist::Node* tur = a.head;
	DFlist::Node* rab = a.head;
	while (rab->nval!=nullptr && rab->nval->nval!=nullptr)
	{
		tur = tur->nval;
		rab = rab->nval->nval;
		if (tur==rab)
		{
			size_t cnt = 1;
			tur = tur->nval;
			while (tur!=rab)
			{
				tur=tur->nval;
				cnt+=1;
			}
			std::pair<DFlist::Node*,size_t> b;
			b.first = tur;
			b.second = cnt;
			return b;
		}
	}
	return {nullptr,0};
}

int main() {
	DFlist a;
	a.push_back(3.14);
	a.push_back(67.67);
	a.push_back(11.09);
	a.push_back(14.88);
	a.push_back(42.42);
	a.push_back(52.52);
	a.tobreak();
	std::pair<DFlist::Node*,size_t> c = findcic(a);
	std::cout << "Длина: " << c.second << std::endl;
	std::cout << "Значение начала: " << c.first->val <<std::endl;
	DFlist b;
        b.push_back(3.14);
        b.push_back(67.67);
        b.push_back(11.09);
        b.push_back(14.88);
        b.push_back(42.42);
        b.push_back(52.52);
	std::pair<DFlist::Node*,size_t> d = findcic(b);
	/*DFlist a;

    // push_back
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    std::cout << "a after push_back: " << a << "\n";

    // push_front
    a.push_front(0);
    std::cout << "a after push_front: " << a << "\n";

    // pop_front
    a.pop_front();
    std::cout << "a after pop_front: " << a << "\n";

    // pop_back
    a.pop_back();
    std::cout << "a after pop_back: " << a << "\n";

    // insert
    a.insert(1, 10);
    std::cout << "a after insert at index 1: " << a << "\n";

    // operator[]
    std::cout << "a[1] = " << a[1] << "\n";

    // erase
    a.push_back(10);
    a.push_back(10);
    std::cout << "before erase(10): " << a << "\n";
    a.erase(10);
    std::cout << "after erase(10): " << a << "\n";

    // size / empty
    std::cout << "size: " << a.size() << "\n";
    std::cout << "empty: " << a.empty() << "\n";

    // copy constructor
    DFlist b(a);
    std::cout << "b (copy of a): " << b << "\n";

    // operator=
    DFlist c;
    c = a;
    std::cout << "c (assigned from a): " << c << "\n";

    // operator+
    DFlist d;
    d.push_back(100);
    d.push_back(200);

    DFlist e = a + d;
    std::cout << "e = a + d: " << e << "\n";

    // clear
    a.clear();
    std::cout << "a after clear: " << a << "\n";
    std::cout << "a empty: " << a.empty() << "\n";

    // front (с проверкой)
    try {
        std::cout << "front of b: " << b.front().val << "\n";
    } catch (...) {
        std::cout << "exception in front()\n";
    }*/

    return 0;
}
