#include <iostream>
#include<bits/stdc++.h>
#include <stdio.h>
#include <queue>

using namespace std;

float v, adj[100][100], clr[100] , prev[100];
vector <int> comb;
float maxx=0;
void input();
struct place
{
    string name;
    float cost;
    float popularity;
    vector <int> combination;
    float distance;
    int day;
    float totalpopularity;
    float totalcost;
    float totalday;
};
struct place place[100];
void DFS(int s);
void DFS_visit(int s);
float budget=500;
int l=1;

int main()
{
    v=9;


    for(int i=1; i<=20; i++)
    {
        place[i].distance=0;
        place[i].cost=0;
        place[i].popularity=0;
        place[i].day=0;
        place[i].totalpopularity=0;
        place[i].totalcost=0;
        place[i].totalday=0;
        place[i].combination.push_back(1);
    }
    place[1].combination.erase(place[1].combination.begin(),place[1].combination.end());
    input();
    place[1].totalcost=300;
    //cout<<place[2].popularity;

//    DFS(1);
    cout<<place[4].day<<endl<<endl;

    cout<<maxx<<endl;
    for(int i=0;i<comb.size();i++)
        cout<<comb[i]<<" ";
    cout<<endl;
}

void DFS(int s)
{
    int i;

    for(i=1 ; i<=v ; i++)
    {
        clr[i]=0;
        prev[i]=-1;
    }

    DFS_visit(s);
//    cout<<maxx;

}

void DFS_visit(int s)
{
    for(int i=1 ; i<=v ; i++)
    {
        bool m=false;
        for(int k=0; k<place[s].combination.size(); k++)
        {
            if(place[s].combination[k]==i)
            {
                m=true;
                break;
            }
        }
        if(adj[s][i]!=0 && m==false)
        {
            float t;
            cout<<i<<endl;
            t=place[s].distance+adj[s][i];
            t=t*3;
            cout<<"distance cost: "<<t<<endl;
            t=t+place[i].cost+place[s].totalcost;
            cout<<"total cost: "<<t<<endl;
            float d=place[s].totalday+place[i].day;
            cout<<"place day: "<<place[i].day<<endl;
            cout<<"d: "<<d<<endl;
            d=floor(d);
            cout<<"d(floor): "<<d<<endl;
            if(d<1)
            {
                t=t+200;
                cout<<"d1=200"<<endl;
            }
            else if(d==1)
            {
                cout<<"d2=200"<<endl;
                t=t+200;
            }
            else t=t+(d*450);

//            cout<<adj[s][i]+place[s].distance<<endl;
            cout<<t<<endl;
            if(t<=budget)
            {
//                cout<<t<<endl;
                place[i].totalpopularity=place[s].totalpopularity+place[i].popularity;
                place[i].totalday=place[i].day+place[s].totalday;
                place[i].distance=adj[s][i]+place[s].distance;
                prev[i]=s;
                for(int k=0; k<place[s].combination.size(); k++)
                {
                    place[i].combination.push_back(place[s].combination[k]);
                }
                place[i].combination.push_back(s);
                if(maxx<place[i].totalpopularity)
                {
                    comb.erase (comb.begin(),comb.end());
                    maxx=place[i].totalpopularity;
                    for(int k=0; k<place[s].combination.size(); k++)
                    {
                        comb.push_back(place[s].combination[k]);
                    }
                    comb.push_back(s);
                    comb.push_back(i);
                }

                DFS_visit(i);

            }


        }
    }
}
void input()
{
    float x,y,z,p;
    fstream dis;
    dis.open("input.txt");
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            dis>>x;
            adj[i][j]=x;
        }
    }

    dis.close();

    fstream cost;
    cost.open("cost.txt");
    for(int i=1; i<=9; i++)
    {
        cost>>y;
        place[i].cost=y;
    }
    cost.close();

    fstream day;
    day.open("day.txt");
    for(int i=1; i<=9; i++)
    {
        day>>z;
        place[i].day=z;
    }
    day.close();

    fstream rat;
    rat.open("rating.txt");
    for(int i=1; i<=9; i++)
    {
        rat>>p;
        place[i].popularity=p;
    }
    rat.close();

}
