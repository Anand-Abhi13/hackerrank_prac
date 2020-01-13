#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

int D=0,mount=0, i;
int l = s.length();

    // declaring character array
    char char_array[l + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());

for(i=0;i<l+1;i++)
    {
        if(char_array[i]=='D')
        {
            D++;

        }
        if(char_array[i]=='U')
        {
            D--;
            if(D==0)
            {
               mount++;
            }
        }
    }
    return mount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;

}
