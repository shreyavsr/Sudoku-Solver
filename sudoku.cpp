#include<iostream>
#include<vector>
using namespace std;
bool possible_num(int row,int col,vector<vector<int>>v,int num){
    for(int i=0;i<9;i++){
        if(v[row][i]==num){
            return false;
        }
        if(v[i][col]==num){
            return false;
        }
        if(v[3*(row/3)+i/3][3*(col/3)+i%3]==num){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&v){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(v[i][j]==0){
                for(int val=1;val<=9;val++){
                    if(possible_num(i,j,v,val)==true){
                        v[i][j]=val;
                        if(solve(v)==true){
                            return true;
                        }
                        else{
                            v[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<vector<int>>v;
    int i,j,x;
    for(i=0;i<9;i++){
        vector<int>v1;
        for(j=0;j<9;j++){
            cin>>x;
            v1.push_back(x);
        }
        v.push_back(v1);
    }
    cout<<"ans"<<endl;
    if(solve(v)==true){
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"not possible";
    }
    return 0;
}
