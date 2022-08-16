#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
 {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    char s[1024];
    int len,c;
    gets(s);
    
    for(int i=0;s[i] !='\0';i++)
    {	c=0;
        for(int j=i;s[j] != '\0';j++)
        {
            if(s[j] == s[i])
            c++;
        }
        printf("%d ",c);
    }    
    return 0;
}
*/

char s[100]; scanf("%[^/n]",s); int i = 0, b[10], k, c, j, d;
for (k = 0; k < 10; i++)
  b[k] = 0;

while (s[i] != '\0')
 {

  for (d = 0; d < 10; d++) 
  {
    if (s[i] == d) 
    {
      b[d]++;
    }
  }

  i++;
}
for (j = 0; j < i; j++)
  printf("%d", b[j]);
return 0;
}

