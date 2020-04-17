//
//  1799.cpp
//  cpp
//
//  Created by jonghoon han on 2020/04/16.
//  Copyright © 2020 jonghoon. All rights reserve#d.
//

#include<iostream>
#include<vector>
using namespace std;
int n,m;
bool adj[201][201];

vector<int> aMatch,bMatch;
vector<bool> visited;

bool dfs(int a){
    if(visited[a]) return 0;
    
    visited[a] = 1;
    
    for(int b=0; b<m; b++){
        if(adj[a][b]){
            if(bMatch[b] == -1 || dfs(bMatch[b])){
                aMatch[a] = b;
                bMatch[b] = a;
                return 1;
            }
        }
    }
    return 0;
}

int count(){
    aMatch = vector<int>(n,-1);
    bMatch = vector<int>(m,-1);
    int size = 0;
    
    for(int i=0; i<n; i++){
        visited = vector<bool>(n,0);
        if(dfs(i)) size++;
    }
    return size;
    
}

int main(){
    cin >> n >> m;
    int itr,num;
    for(int i=0; i<n; i++){
        cin >> itr;
        while(itr--){
            cin >> num;
            adj[i][num-1] = 1;
        }
    }
    cout << count();
}
