
#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#include <fstream>
#include <queue>
using namespace std;

/*
Интерпретатор обратных польских выражений, как правило, основан на стеке. Процесс объяснения обычно таков:
операнд помещается в стек, когда встречается оператор, операнд извлекается из стека, оценивается и результат
помещается в стек, а после одного прохода вершина стека является значением выражения. Таким образом, вычисление
обратных выражений на польском языке легко реализовать с помощью структуры стека и может быть оценено быстро.
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

    // добавление в хвост списка
    void push_back(string _val);
    // отображение списка 
    void print();

    // размер списка
    int size();

    // последний элемент
    string back();

    Node* find(string _val);

    void remove_first();

    void remove_last();

    void remove(string _val);

    Node* operator[] (const int index);

    //перегрузка оператора вывода
    friend ostream& operator<< (ostream& out, const list& l);

    //перегрузка оператора ввода
    friend istream& operator>> (std::istream& in, list& l);

    // перегрузка оператора присваивание
    list& operator= (const list& l);

    //перегрузка оператора функтора (псевдопеременная)
    void operator()(int i, int j, const list& l);

};
