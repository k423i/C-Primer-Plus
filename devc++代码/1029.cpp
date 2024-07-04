#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],b[100];
    int i,j,flag=0;
    int k=0;
    char str[100];
    int y;int tag=0;
    scanf("%s %s",a,b);
    for(i=0;i<strlen(a);i++)
    {
        flag=0;tag=0;
        for(j=0;j<strlen(b);j++)
        {
            if(a[i]==b[j])
            {
                flag=1;
            }
           
        }
        if(flag==0)
        {

            str[k++]=a[i];
        }
        
    }
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='0'&&str[i]<=9)
            continue;
        else
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                str[i]=str[i]-32;
            }
        }
    }
    char qwe[100];
    int u=0;
    flag=0;
    tag=0;
    int c=0;
    int key=0;
    int len=strlen(str);
    for(i=0;i<len-1;i++)
    for(j=i+1;j<len;j++){
		if(str[j]==str[i])
    		str[j]='*';
	}
    for(i=0,j=0;i<len;i++)
    if(str[i]!='*'){
   		str[j]=str[i];
    	j++;
    }
    str[j]='\0';
    puts(str);

}

