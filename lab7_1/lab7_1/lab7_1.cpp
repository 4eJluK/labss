#include <iostream>
#include <list>

using namespace std;

struct Lection
{
    int begin;
    int end;
};



int main()
{
    list<Lection> lections;
    int n;
    cin >> n;

    Lection inputLection;
    for (int i = 0; i < n; ++i)
    {
        cin >> inputLection.begin >> inputLection.end;
        lections.push_back(inputLection);
    }

    lections.sort([](const Lection lec1, const Lection lec2)
        {
            return lec1.end < lec2.end;
        });

    int count = 1;
    Lection curLection = lections.front();
    for (auto it = ++lections.cbegin(); it != lections.cend(); ++it)
    {
        if (curLection.end <= it->begin)
        {
            curLection = *it;
            ++count;
        }
    }

    cout << count;

}