#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    cout << "Enter an expression with parentheses." << endl;
    getline(cin, s);

    class Stub
    {
    };
    stack<Stub> st;

    unsigned i = 0;

    for (auto& c : s)
    {
        if (c == '(')
            st.push(Stub{});
        else if (c == ')')
        {
            if (st.empty())
                break;
            else
                st.pop();
        }
        ++i;
    }

    if (st.empty() && i == s.length())
        cout << "Expression is valid" << endl;
    else
        cout << "Expression is invalid" << endl;

    return 0;
}

