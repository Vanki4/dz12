#pragma once

#include <iostream>
#include <cstdlib>

class DFlist {
	public:
		struct Node {
                         double val;
                         Node* nval;
                         Node* pval;
                };
		DFlist();
		DFlist(const DFlist& other);
		DFlist& operator=(const DFlist& other);
		DFlist(DFlist&& other);
		DFlist& operator=(DFlist&& other);
		~DFlist() = default;
		void tobreak();
		void push_front(double v);
		void pop_front();
		Node& front() const;
		int size() const;
		bool empty() const;
		void erase(double v);
		void clear();
		void push_back(double v);
		void pop_back();
		void insert(int index,double value);
		Node& back() const;
		double operator[](int index) const;
		DFlist operator+(const DFlist& other);
		friend std::pair<Node*,size_t> findcic(const DFlist& a);
		friend std::ostream& operator<<(std::ostream &out,const DFlist &ob);
	private:
		Node* head = nullptr;
                Node* tail = nullptr;
};

std::ostream& operator<<(std::ostream &out,const DFlist &ob);
