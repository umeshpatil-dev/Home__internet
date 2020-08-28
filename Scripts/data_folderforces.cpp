#include<bits/stdc++.h>

using namespace std;

void solve(){
    string str;
    int x;
    cin>>str;
    cin>>x;

    int n = str.length();
    int a[n] = {-1};
    int s[n];
    for(int i=0; i<n; i++){
        s[i] = (int)(str[i]-'0');
        a[i] = -1;
    }
    //for(int i=0; i<n; i++) cout<<a[i];cout<<endl;
    bool possible = true;
    for(int i=0; i<n; i++){
        if(s[i] == 0){
            if(i-x >=0){
                if(a[i-x] == 1) possible = false;
                //cout<<i<<" "<<x<<endl;
                a[i-x] = 0;
            }
            if(i+x<n){
                if(a[i+x] == 1) possible = false;
                //cout<<i<<" "<<x<<endl;
                a[i+x] = 0;
            }
        }
    }
    for(int i =0; i<n; i++){
        if(a[i] == -1){
            a[i] = 1;
        }
    }


    for(int i=0; i<n; i++){
        if(i-x>=0 && i+x<n){
            if(s[i] != (a[i-x]|a[i+x])) possible = false;
        }
        if(i-x <0){
                if(i+x<n)
            if(s[i] != a[i+x]) possible = false;
        }
        if(i+x>=n){
            if(i-x>=0)
            if(s[i] != a[i-x]) possible = false;
        }
    }
    if(possible){
        for(int i=0; i<n; i++) cout<<a[i];

    }else{
        cout<<-1;
    }

    cout<<endl;


}
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){

        solve();
    }
    return 0;
}
