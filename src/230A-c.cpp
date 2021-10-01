#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    pair<int, int> dragons[1000];
    for (int i = 0;i < n;i++)
    {
        dragons[i].first = 10001;
    }

    for (int i = 0;i < n;i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = 0;j < n;j++)
        {
            if (x < dragons[j].first)
            {
                for (int k = n-1;k > j;k--)
                {
                    dragons[k] = dragons[k-1];
                }

                dragons[j].first = x;
                dragons[j].second = y;
                break;
            }
        }
    }

    for (int i = 0;i < n;i++)
    {
        if (dragons[i].first >= s)
        {
            cout << "NO";
            return 0;
        }

        s += dragons[i].second;
    }

    cout << "YES";
    return 0;
}