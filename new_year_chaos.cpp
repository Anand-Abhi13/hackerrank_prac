
#include <vector>

#include <iostream>

using namespace std;


int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0;q_i < n;q_i++){
           cin >> q[q_i];
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {   cout<<endl<<endl;
            cout<<"i is "<<i<<endl;
            cout<<"time to find i+1"<<endl;
                if (ans == -1)
                break;
            int k = i;
            while (q[k] != i + 1)
                {
                    cout<<"old k is "<<k<<endl;
                    k--;
                    cout<<"new k is "<<k<<endl;
                }
                cout<<"found the object at k="<<k<<endl;
            if (i - k > 2){
                ans = -1;
                break;
            } else {
                cout<<"its a safe move"<<endl;
                while (k != i){
                    cout<<"k is "<<k<<endl;
                    cout<<"q[k] is "<<q[k]<<endl;
                    cout<<"q[k+1] is "<<q[k+1]<<endl;
                    swap(q[k], q[k + 1]);
                    k++;
                    cout<<"now k is "<<k<<endl;
                    ans++;
                    cout<<"ans is "<<ans<<endl;
                }
            }
        }
        if (ans == -1)
            cout<<"Too chaotic";
        else
            cout << ans << "\n";
    }
    return 0;
}
