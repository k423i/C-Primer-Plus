#include <bits/stdc++.h>
using namespace std;
int search(char s[],char c){
    int i;
    for(i=0;i<strlen(s);i++){
        if(c>='a'&&c<='z'){
            if((c-32)==s[i]||(c==s[i])) return 1;
            else continue;
        }
        else{
            if(c==s[i]) return 1;
            else continue;
        }
    }
    return 0;//找到返回1，没找到返回0
}
int main(){
    char ini[10000],brk[10000];
    fgets(brk,10000,stdin);
    fgets(ini,10000,stdin);
    int i,j,k,tag=0;
    int vnt=0;
    for(i=0;i<strlen(brk);i++){
        if(brk[i]=='+') {
			tag=1;//上档键坏了
			break;
		}
    }
    for(i=0;i<strlen(ini);i++){
        if(tag==1){
            if(ini[i]>='A'&&ini[i]<='Z') continue;
            else if(!search(brk,ini[i])) {
				printf("%c",ini[i]);vnt++;
			}
        }
        else{
            if(!search(brk,ini[i])){
            	printf("%c",ini[i]);vnt++;
			}
        }
    }
    if(vnt==0) printf("\n");
}

