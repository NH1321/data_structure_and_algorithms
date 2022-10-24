// kiểm tra dãy ngoặc hợp lệ
#include <iostream>
using namespace std;

int top;
void check(char str[], int n, char stack[])
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            top = top + 1;
            stack[top] = '(';
        }
        if (str[i] == ')')
        {
            if (top == -1)
            {
                top = top - 1;
                break;
            }
            else
            {
                top = top - 1;
            }
        }
    }
    if (top == -1)
        cout << "Day hop le"
             << "\n";
    else
        cout << "Day khong hop le"
             << "\n";
}

int main()
{
    char str[] = "(())()";

    char str1[] = "((()";
    char stack[15];
    top = -1;
    check(str, 9, stack);
    top = -1;
    check(str1, 5, stack);
    return 0;
}
