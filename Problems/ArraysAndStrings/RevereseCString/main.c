#include <stdio.h>
#include <string.h>

int main()
{
   char s[256];
   scanf("%s", &s);
   char *end = s;
   char *str = s;
   char tmp;
   if(str) {
       while(*end) {
           end++;
       }
       end--;
       while(str < end) {
           tmp = *str;
           *str = *end;
           str++;
           *end = tmp;
           end--;
       }
   }
   printf("%s", &s);
   
   return 0;
}