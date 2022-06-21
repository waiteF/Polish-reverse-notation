#include "..\LibraryList\list.h"

/*
Интерпретатор обратных польских выражений, как правило, основан на стеке. Процесс объяснения обычно таков:
операнд помещается в стек, когда встречается оператор, операнд извлекается из стека, оценивается и результат
помещается в стек, а после одного прохода вершина стека является значением выражения. Таким образом, вычисление
обратных выражений на польском языке легко реализовать с помощью структуры стека и может быть оценено быстро.
*/
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// В польскую обратную запись
string infixToPostfix(string s)
{

    stack<char> st;

    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;


        else if (c == '(')
            st.push('(');


        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }


        else {
            while (!st.empty()
                && prec(s[i]) <= prec(st.top())) {
                if (c == '^' && st.top() == '^')
                    break;
                else {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }


    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

// Проверка на переменную
bool isOperand(char x)
{
    return (x >= 'a' && x <= 'z') ||
        (x >= 'A' && x <= 'Z');
}

// Из польской обратной записи
void getInfix(string exp, list& l)
{
    stack<string> s;

    for (int i = 0; exp[i] != '\0'; i++)
    {

        if (isOperand(exp[i]))
        {
            string op(1, exp[i]);
            s.push(op);
        }

        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                op1 + ")");
            l.push_back("(" + op2 + exp[i] +
                op1 + ")");
        }
    }
}

void readFromFile(string path, string& line) {
    ifstream in;
    in.open(path);

    if (in.is_open()) {
        in >> line;
    }
    in.close();
}

void writeToFile(string path, list& l) {
    ofstream out;
    out.open(path);

    if (out.is_open()) {
        Node* p = l.first;
        while (p) {
            out << p->val << " ";
            p = p->next;
        }
    }
    out.close();
}


// (5*3)+(5-3) a*(b+d*c)
int main(int argc, char* argv[]){
    list l;
    string expression; 
    string path;
   
        cout << "U want enter expression - 1" << endl;
        cout << "U want enter path where program find expression - 2" << endl;
        cout << "You input: ";
        int a;
        cin >> a;
        cout << endl;

        switch (a) {
        case 1:
            cout << "Enter expression: ";
            cin >> expression;
            cout << endl;
            break;
        case 2:
            cout << "Enter path of file: ";
            cin >> path;
            cout << endl;
            readFromFile(path, expression);
            break;
        default:
            cout << "Choice 1 or 2. ERROR." << endl;
        }
        
    

    string str = infixToPostfix(expression);
    getInfix(str, l);
    cout << "\nExpression: " << expression << endl;
    cout << "\nPolish reverse notation: " << str << endl;
    cout << "\nList decomposed algebraic expression: " << l;
    cout << "\nLast elements, main expression: " << l.back();
}