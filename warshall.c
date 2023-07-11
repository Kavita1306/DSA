#include<stdio.h>
int max=4;
void transitive_closure(int adj_mat[][max], int n){ int i ,j ,k;
for(k=0;k<n;k++){ for(i=0;i<n;i++){
for(j=0;j<n;j++){
adj_mat[i][j] =adj_mat[i][j] || (adj_mat[i][k]&& adj_mat[k][j]);
}}}}

void main(){
int adj_mat[max][max], t[max][max],i,k,j;
printf("Enter the adjacency matrix: ");

for(i=0;i<max;i++){ for(j=0; j<max;j++){
scanf("%d", &adj_mat[i][j]);
}}
transitive_closure(adj_mat,max);
printf("\t 1\t2 \t 3 \t 4 \n");
for(i=0;i<max;i++)
{ printf("%d:",i+1); for(j=0;j<max;j++){
printf("\t %d", adj_mat[i][j]);
}printf("\n");
}}
