#include <stdio.h>
#include <stdlib.h>
int top=-1;
int main()
{
    int ch1=0;
    int ch,item,a[50],i;
    while(ch1==0)
    {
         printf("Press 1 to push\n");
    printf("Press 2 to pop\n");
    printf("press 3 to display\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);


    switch(ch)
    {
    case 1:
        {
            printf("Enter item to be pushed\n");
            scanf("%d",&item);
            top++;
            a[top]=item;
            break;

        }
    case 2:
        {
            if(top==-1)
               printf("Stack is empty\n");
            else
            printf("popped item=",a[top]);
            printf("\n");
            top--;
            break;

        }
    case 3:
        {
            printf("stack:\n");
            if(top==-1)
                printf("Stack is empty\n");
            else
            {


            for(i=0;i<=top;i++)
            printf("%d\t",a[i]);
            }
            printf("\n");
            break;
        }
    default:
        {

        printf("Wrong choice");
        break;
        }
    }
    printf("Press 0 to continue \n");
    scanf("%d",&ch1);
    }


    return 0;
}
