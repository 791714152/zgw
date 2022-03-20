#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

struct Node{
    string name, id;
};

int main(int array, char* team[]){
    if(array < 3){
        cout << "输入文件名" << endl;
        return 0;
    }
    
    ifstream infile;
    infile.open(team[1]);
    if(!infile){
        cout << "打开失败" << endl;
        return 0;
    }

    
    ofstream outfile;
    outfile.open(team[2]);
    if(!outfile){
        cout << "打开失败" << endl;
        return 0;
    }

    
    string s;
    vector<string>vec, pro;
    while(infile >> s){
        vec.push_back(s);
    }

    
    map<string, vector<Node> >mp;
    int cnt = vec.size();
    for(int i = 0; i < cnt; i += 3){
        if(mp[vec[i]].size() == 0) pro.push_back(vec[i]);
        mp[vec[i]].push_back({vec[i+1], vec[i+2]});
    }

   
    if(array == 4){ 
        string t;
        int len = strlen(team[3]);
        for(int i = 0; i < len; i++) t.push_back(team[3][i]);
        outfile << t << endl;
        for(Node i : mp[t]) outfile << i.name << " " << i.id << endl;
    }
    else{ 
        for(string i : pro){
            outfile << i << endl;
            for(Node j : mp[i]){
                outfile << j.name << " " << j.id << endl;
            }
            outfile << endl;
        }
    }
    infile.close();
    outfile.close();
    cout << "成功！" << endl;
    return 0;
}


