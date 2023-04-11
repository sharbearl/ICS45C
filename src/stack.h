using namespace std;
constexpr int STK_MAX = 1000;

class Stack
{
	int _top;
    char buf[STK_MAX] = {};
public:
	Stack()
    {
    	_top = 0;
    }

    void push(char c)
    {
    	if (!isFull())
        {
            buf[_top] = c;
            _top++;
        }

    char pop()
    {
        char last = top();
        if (_top == 0 && isEmpty())
        {
            return '@';
        }
        if (_top == STK_MAX)
        {
            buf[_top] = {};
            _top--;
        }
        buf[_top] = {};
        if (_top != 0)
        {
            _top--;
        }
        return last;
    }

    char top()
    {
        if (_top == STK_MAX)
        {
            return buf[_top - 1];
        }
        else
        {
        return buf[_top];
        }
    }

    bool isEmpty()
    {
        for (int i = 0; i < STK_MAX; i++)
        {
            if buf[i] != '\0'
            {
                return false;
            }
        }
        return true;
    }

    bool isFull()
    {
        return (_top == STK_MAX);
    }

};

void push_all(Stack & stk, string line)
{
    for (int i = 0; i < line.length(); i++)
    {
        stk.push(line[i]);
    }
}
void pop_all(Stack & stk)
{
    for (int i = 0; i < STK_MAX; i++)
    {
        char cur = stk.pop();
        if (cur == '@')
        {
            cout << cur;
            break;
        }
        if (cur != '\0')
        {
            cout << cur;
        }
        if (stk.isEmpty())
        {
            break;
        }
    }
    cout << endl;
}
