/* FIXME: Implement! */
#include<stdio.h>
#include<stdlib.h>

char smallest_character(char str[],char c,int left,int right);

int main()
{
    char str[]={'c','f','j','p','v'};
    char c[]={'a','c','z','f'};
    int left=0,right=(sizeof(str)/sizeof(str[0]))-1;
    for(int i=0;i<(sizeof(c)/sizeof(c[0]));i++)
    {
         printf("output is %c\n",smallest_character(str,c[i],left,right));
     }

    return 0;
}

char smallest_character(char str[],char c,int left,int right)
{
    char ret=str[0];

    while(left<=right)
    {
         int m=left+((right-left)/2);
         if(str[m]>c)
        {
             ret=str[m];
             right=m-1;
         }
          else
         {
             left=m+1;
          }
     }
     return ret;
}
