#include "list.h"

bool list::is_empty() {
    return first == nullptr;
}

// добавление в хвост списка
void list::push_back(string _val) {
    Node* p = new Node(_val);
    if (is_empty()) {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}
// отображение списка 
void list::print() {
    if (is_empty()) return;
    Node* p = first;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

// размер списка
int list::size() {
    Node* p = first;
    int cnt = 0;
    while (p) {
        p = p->next;
        cnt++;
    }
    return cnt;
}

// последний элемент
string list::back() {
    return last->val;
}

Node* list::find(string _val) {
    Node* p = first;
    while (p && p->val != _val) p = p->next;
    return (p && p->val == _val) ? p : nullptr;
}

void list::remove_first() {
    if (is_empty()) return;
    Node* p = first;
    first = p->next;
    delete p;
}

void list::remove_last() {
    if (is_empty()) return;
    if (first == last) {
        remove_first();
        return;
    }
    Node* p = first;
    while (p->next != last) p = p->next;
    p->next = nullptr;
    delete last;
    last = p;
}

void list::remove(string _val) {
    if (is_empty()) return;
    if (first->val == _val) {
        remove_first();
        return;
    }
    else if (last->val == _val) {
        remove_last();
        return;
    }
    Node* slow = first;
    Node* fast = first->next;
    while (fast && fast->val != _val) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        cout << "This element does not exist" << endl;
        return;
    }
    slow->next = fast->next;
    delete fast;
}

Node* list::operator[] (const int index) {
    if (is_empty()) return nullptr;
    Node* p = first;
    for (int i = 0; i < index; i++) {
        p = p->next;
        if (!p) return nullptr;
    }
    return p;
}

//перегрузка оператора вывода
 ostream& operator<< (ostream& out, const list& l) {
    Node* p = l.first;
    while (p) {
        out << p->val << " ";
        p = p->next;
    }
    return out;
}

//перегрузка оператора ввода
 istream& operator>> (std::istream& in, list& l) {
    string str;
    in >> str;
    Node* p = new Node(str);

    l.last->next = p;
    l.last = p;
    return in;
}

// перегрузка оператора присваивание
list& list::operator= (const list& l) {
    Node* p = l.first;
    Node* k = first;
    while (p) {
        k = p;
        p = p->next;
        k = k->next;
    }
    return *this;
}

//перегрузка оператора функтора (псевдопеременная)
void list::operator()(int i, int j, const list& l) {
    Node* p = l.first;
    Node* m = first;

    if (is_empty()) return;
    for (int k = 0; k < i; k++) {
        p = p->next;
        m = m->next;
    }

    for (int k = 0; k < j; k++) {
        m = p;
        p = p->next;
        m = m->next;
    }
}
