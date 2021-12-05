#include<bits/stdc++.h>
using namespace std;

#define MX 1000

int ara[MX][3];
double cost[MX][5];
double nt[MX][4];

int main(){
int i,j,n,m;
freopen("Input_Path.txt", "r", stdin);
scanf("%d %d",&n, &m);
for(i = 1; i <= n; i++)
{
scanf("%d %d %d %lf", &ara[i][0], &ara[i][1], &ara[i][2], &cost[i][0]);
}
nt[1][1] = 0;
for(i = 1; i <= n; i++)
{
cost[i][1] = nt[ara[i][1]][1];
cost[i][2] = cost[i][1] + cost[i][0];
nt[ara[i][2]][1] = max(nt[ara[i][2]][1], cost[i][2]);
}
for(i = 0; i <= m ;i++)
{
nt[i][2] = INT_MAX;
}
nt[m][2] = nt[m][1];
for(i = n; i >= 1; i--){
cost[i][4] = nt[ara[i][2]][2];
cost[i][3] = cost[i][4] - cost[i][0];
nt[ara[i][1]][2] = min(nt[ara[i][1]][2], cost[i][3]);
}
puts(" ");
puts("  Activity        S(k)        F(k)          T(k)         EST(k)         EFT(k)         LST(k)         LFT(k)");
puts(" ");
for(i = 1; i <= n ; i++){
printf("  %3d             %3d         %3d          %5.2lf        %6.3lf         %6.3lf         %6.3lf         %6.3lf \n",
ara[i][0],ara[i][1],ara[i][2],cost[i][0],cost[i][1],cost[i][2],cost[i][3],cost[i][4]);
}
puts(" \n\n\n");
puts("  Nodes   ENT(k)   LNT(k)    Slack  ");
puts(" ");
for(i = 1; i <= m; i++)
{
nt[i][3] = abs(nt[i][2] - nt[i][1]);
printf("  %3d     %6.3lf   %6.3lf   %6.3lf  \n",i, nt[i][1],abs(nt[i][2]),nt[i][3]);
}

return 0;
}
