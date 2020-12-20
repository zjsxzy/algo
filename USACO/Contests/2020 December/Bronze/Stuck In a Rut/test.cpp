#include <bits/stdc++.h>
int n;
using namespace std;
struct stuff{
    int x;
    int y;
    int i;
};
bool cmp(stuff a, stuff b)
{
    return a.y<b.y;
}
bool cmp2(stuff a, stuff b)
{
    return a.x<b.x;
}
int main()
{
    cin>>n;
    int cows[51] ={0};
    vector<stuff> e;
    vector<stuff> no;
    for(int i  =0;i<n;i++){
        char d;
        int x, y;
        cin>>d>>x>>y;
        stuff temp;
        temp.x = x; temp.y = y; temp.i = i;
        if(d == 'E') e.push_back(temp);
        else no.push_back(temp);
    }
    sort(e.begin(), e.end(), cmp);
    sort(no.begin(), no.end(), cmp2);
/*
    for(auto it: e){
        cout<<it.x<<  " "<<it.y<<endl;;
    }
    cout<<endl;
    for(auto it: no){
        cout<<it.x<< " "<<it.y<<endl;
    }
*/
    for(auto it: e)
    {
        for(int i  =0;i<no.size();i++){
            if(no[i].y > it.y) continue;
            if(no[i].x < it.x) continue;
            int t = no[i].x - it.x;
            int ny = no[i].y  +t;
            if(ny == it.y)continue;   /// if they touch at the same time, continue
            if(ny > it.y) {
                cout<<"E BREAKS"<<endl;
                cows[it.i] = t;
                break;
            }
            else {
                cout<<"DOWN BREAKS";
                cows[no[i].i] = it.y - no[i].y;
                no.erase(no.begin()  +i);
                i--;
            }
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i  =0;i<n;i++){
        if(cows[i] == 0) cout<<"IMPOSSIBLE"<<endl;
        else cout<<cows[i]<<endl;
    }


}
