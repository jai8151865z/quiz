/* FIXME: Implement! */

#include<stdio.h>
#include<stdlib.h>

char smallest_character(char str[],char c,int left,int right,char ret);

int main()
{
    char str[]={'c','f','j','p','v'};
    char c[]={'a','c','z','f'};
    int left=0,right=(sizeof(str)/sizeof(str[0]))-1; 
    char ret=str[0];
    for(int i=0;i<(sizeof(c)/sizeof(c[0]));i++)
   {
         printf("output is %c\n",smallest_character(str,c[i],left,right,ret));
    }

    return 0;
}

char smallest_character(char str[],char c,int left,int right,char ret)
{
    if(left<=right)
    {
         int m=left+((right-left)/2);
         if(str[m]>c)
         {
              ret=str[m];
              smallest_character(str,c,left,m-1,ret);
          }
         else
              smallest_character(str,c,m+1,right,ret);
     }
     else
           return ret;
}
