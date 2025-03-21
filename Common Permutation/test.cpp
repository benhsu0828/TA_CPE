#include <iostream>
#include <map>
using namespace std;

int main()
{
    string a, b;
    while ( cin >> a  >>b)
    {
       
        map<char, int>A;
        map<char , int> AandB;
        for ( int i = 0;i<a.length(); i++)
        {
            A[a[i]] ++; //注意不能寫成A[i]++ ，因為key是char
        }
        for ( int i=0; i<b.length(); i++)
        {
            if (A[b[i]] > 0)
            {
                AandB[b[i]] ++;
                A[b[i]] --;
            }
        }

        for (auto it:AandB)
        {
           for(int i=0; i<it.second; i++)
           {
            cout << it.first;
           }
        }
        cout << endl;
    }

}