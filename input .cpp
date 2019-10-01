#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    float place[100][100],c[100],d[100],r[100];
    float x,y,z,p;
    while(cin>>t){
        if(t==1){
             fstream dis;
    dis.open("input.txt");
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
                dis>>x;
            place[i][j]=x;
        }
    }

    dis.close();


//    for(int i=1;i<=9;i++){
//        for(int j=1;j<=9;j++){
//            cout<<place[i][j]<<" ";
//        }
//        cout<<endl;
//    }

        }
        else if(t==2){
            fstream cost;
            cost.open("cost.txt");
            for(int i=1;i<=9;i++){
                cost>>y;
            c[i]=y;
            }
            cost.close();

        }
        else if(t==3){
            fstream day;
            day.open("day.txt");
            for(int i=1;i<=9;i++){
                day>>z;
            d[i]=z;
            }
            day.close();

        }
        else if(t==4){
            fstream rat;
            rat.open("rating.txt");
            for(int i=1;i<=9;i++){
                rat>>p;
            r[i]=p;
            }
            rat.close();

        }


    }
}
