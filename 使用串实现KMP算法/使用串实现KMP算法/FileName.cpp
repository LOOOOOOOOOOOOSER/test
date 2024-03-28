#include <iostream>
using namespace std;

void get_next(string a, int next[])
{
    next[0] = -1;
    for (int i = 0, j = -1; i < a.length();)
    {
        if (j == -1 || a[i] == a[j])
        {
            i++;
            j++;
            next[i] = j;
            if (a[i] != a[j])
            {
                next[i] = j;
            }
            else
            {
                next[i] = next[j];
            }
        }
        else
        {
            j = next[j];
        }
    }
}
void KMP(string a, string b, int next[], int result[])
{
    result[0] = 0;
    result[2] = 0;
    for (int i = 0, j = 0; i < a.length() && (j < b.length() || j == -1);)//-1与string的length()比较结果为-1>b.length(),考虑补码比较，b.length()为无符号整数小于-1的补码
    {
        if (j == -1 || a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j > result[2])
            {
                result[2] = j;
                result[1] = i - j;
            }
            j = next[j];
        }
        if (j == b.length())
        {
            result[0] = 1;
            result[1] = i - j;
            result[2] = j;
        }
    }
}
int main()
{
    string a = "abedabcdabcee";
    string b = "abcdabcf";
    int next[256];
    int result[20];
    get_next(b, next);
    KMP(a, b, next, result);
    cout << result[1] << result[2] << endl;
    return 0;
}