#include<iostream>

using namespace std;

int i,j,k,a,b,u,v,n,ne=1;
int min_val,min_valcost=0,cost[9][9],parent[9];

int find(int);
int uni(int,int);

int main() {
    cout << "\nImplementation of Kruskal's algorithm\n\n";
    cout << "Enter the no. of vertices: ";
    cin >> n;
    cout << "Enter the cost adjacency matrix: \n";
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            cin >> cost[i][j];

            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    cout << "\nThe edges of minimum Cost Spanning Tree are\n\n";
    while(ne<n) {
        for(i=1,min_val=999;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(cost[i][j]<min_val) {
                    min_val=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        u=find(a);
        v=find(b);
        if(uni(u,v)) {
            cout << ne++ << " edge (" << a << "," << b << ") =" << min_val << "\n";
            min_valcost +=min_val;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout << "\n\tminimum cost = " << min_valcost << "\n";
}

int find(int i) {
    while(parent[i])
        i=parent[i];
    return i;
}

int uni(int i,int j){
    if(i!=j) {
        parent[j]=i;
        return 1;
    }
    return 0;
}
