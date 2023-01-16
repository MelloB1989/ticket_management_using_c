#include<string.h>
#include<stdio.h>

int main(){
    char s1[][5] = {"dfs", "fdsf", "dfsd"};
    char temp[5];
    int book[5][5][5] = {};
    printf("%s", s1[3]);
    //printf("%ld", sizeof(s1[2]));
    printf("\n\nInput: ");
    fgets(temp, 5, stdin);
    strcpy(s1[3], temp);
    //s1[3][5] = "tree";
    printf("\n%s", s1[3]);
}