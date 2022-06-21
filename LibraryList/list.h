
#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#include <fstream>
#include <queue>
using namespace std;

/*
������������� �������� �������� ���������, ��� �������, ������� �� �����. ������� ���������� ������ �����:
������� ���������� � ����, ����� ����������� ��������, ������� ����������� �� �����, ����������� � ���������
���������� � ����, � ����� ������ ������� ������� ����� �������� ��������� ���������. ����� �������, ����������
�������� ��������� �� �������� ����� ����� ����������� � ������� ��������� ����� � ����� ���� ������� ������.
*/

struct Node {
    string val;
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}
};

class list {
public:
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty();

    // ���������� � ����� ������
    void push_back(string _val);
    // ����������� ������ 
    void print();

    // ������ ������
    int size();

    // ��������� �������
    string back();

    Node* find(string _val);

    void remove_first();

    void remove_last();

    void remove(string _val);

    Node* operator[] (const int index);

    //���������� ��������� ������
    friend ostream& operator<< (ostream& out, const list& l);

    //���������� ��������� �����
    friend istream& operator>> (std::istream& in, list& l);

    // ���������� ��������� ������������
    list& operator= (const list& l);

    //���������� ��������� �������� (����������������)
    void operator()(int i, int j, const list& l);

};
