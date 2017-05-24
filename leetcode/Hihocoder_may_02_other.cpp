#include <stdio.h>  
#include <string.h>  
int left[1000000+10];  
int right[1000000+10];  
int main()  
{  
    char ch;  
    int t=1;  
    left[0]=right[0]=0;  
    while(~scanf("%c",&ch))  
    {  
        if(ch=='(')  
        left[t]=left[t-1]+1,right[t]=right[t-1];  
        else if(ch==')')  
        right[t]=right[t-1]+1,left[t]=left[t-1];  
        else if(ch=='\n')  
        {  
            int result=0;  
            for(int i=1;i<t;i++)  
            {  
                for(int j=i;j<t;j++)  
                {  
                    int left_count=left[j]-left[i-1];  
                    int right_count=right[j]-right[i-1];  
                    if(left_count<right_count)  
                    break;  
                    if(left_count==right_count)  
                    {  
                    //  printf("%d %d\n",i,j);  
                        result++;  
                    }  
                }  
            }  
            printf("%d\n",result);  
            memset(left,0,sizeof(left));  
            memset(right,0,sizeof(right));  
            t=1;  
        }  
        t++;  
    }  
    return 0;  
}  
