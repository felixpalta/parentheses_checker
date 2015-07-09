#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class ParenthesesChecker
{
public:

    void add_brace_pair(char opening, char closing)
    {
        if (is_opening(opening) || is_closing(closing))
            return; // These symbols are already present.
        used_pairs.push_back(BracePair{opening, closing});
    }

    bool check_expression(const string& s)
    {
        char c;
        unsigned i;
        for (i = 0; i < s.length(); ++i)
        {
            c = s[i];
            if (is_opening(c))
                brace_stack.push(c);
            else if (is_closing(c))
            {
                if (brace_stack.empty())
                    break;
                if (!braces_match(brace_stack.top(), c))
                    break;
                brace_stack.pop();
            }
        }

        if (brace_stack.empty() && i == s.length())
            return true;
        return false;
    }
private:

    using BracePair = pair<char, char>;

    bool is_opening(char c) const
    {
        auto f = [=](const BracePair& p) {return c == p.first;};

        auto iter = find_if(begin(used_pairs), end(used_pairs), f);
        return iter != end(used_pairs);
    }
    bool is_closing(char c) const
    {
        auto f = [=](const BracePair& p) {return c == p.second;};

        auto iter = find_if(begin(used_pairs), end(used_pairs), f);
        return iter != end(used_pairs);
    }

    bool braces_match(char opening, char closing) const
    {
        auto iter = find(begin(used_pairs), end(used_pairs), BracePair{opening, closing});
        return iter != end(used_pairs);
    }
    stack<char> brace_stack;
    vector<BracePair> used_pairs;
};



int main()
{
    string s;

    ParenthesesChecker pch{};
    pch.add_brace_pair('(', ')');
    pch.add_brace_pair('{', '}');

    cout << "Enter an expression with parentheses." << endl;
    getline(cin, s);


    cout << boolalpha << pch.check_expression(s) << endl;

    return 0;
}

