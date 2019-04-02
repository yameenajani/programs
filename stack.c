// Program to implement stack
// Input format is:
// 1 x         -----       Push int x to stack
// 2           -----       Pop top element
// 3           -----       Print the maximum element in the stack

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
    int *array;
}stack;
int main() {
    int n,t,top=-1,max,temp=0;
    scanf("%d",&n);
   stack *s=malloc(sizeof(stack));
    s->array=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        {
      scanf("%d",&t);  
    switch(t)
        {
        case 1:
        scanf("%d",&t);
        s->array[++top]=t;
        if(top==-1)
        max=t;
        else
        {
          if(max<t)
            max=t;
        }
        break;
        case 2:
         top--;
        temp=1;
         break;
        case 3:
        if(temp==1)
            {
        max=s->array[0];
        for(int i=0;i<=top;i++)
            {
            if(max<s->array[i])
                max=s->array[i];
        }
        }
        printf("%d\n",max);
        break;
    }
    }
    free(s);
    return 0;
}