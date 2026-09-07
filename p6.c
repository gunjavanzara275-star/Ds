#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start=NULL;


/* Insert at Beginning */
void addbeg()
{
    int no;
    struct node *p=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter data of New Node=");
    scanf("%d",&no);

    p->data=no;

    if(start==NULL)
    {
        start=p;
        p->next=NULL;
    }
    else
    {
        p->next=start;
        start=p;
    }

    printf("\n%d inserted successfully at beginning",no);
}


/* Insert at Last */
void addlast()
{
    int no;
    struct node *p=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter data of New Node=");
    scanf("%d",&no);

    p->data=no;
    p->next=NULL;

    if(start==NULL)
    {
        start=p;
    }
    else
    {
        struct node *temp_p=start;

        while(temp_p->next!=NULL)
        {
            temp_p=temp_p->next;
        }

        temp_p->next=p;
    }

    printf("\n%d inserted successfully at last",no);
}


/* Insert After Given Node */
void addafter()
{
    int no,after;
    struct node *p=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter node after which you want to insert=");
    scanf("%d",&after);

    struct node *temp_p=start;

    while(temp_p!=NULL && temp_p->data!=after)
    {
        temp_p=temp_p->next;
    }

    if(temp_p==NULL)
    {
        printf("\nNode %d not found",after);
        free(p);
        return;
    }

    printf("Enter data of New Node=");
    scanf("%d",&no);

    p->data=no;
    p->next=temp_p->next;
    temp_p->next=p;

    printf("\n%d inserted successfully after %d",no,after);
}


/* Delete First Node */
void delbeg()
{
    struct node *temp_p;
    int no;

    if(start==NULL)
    {
        printf("\nSingly linked list is Empty");
        return;
    }

    temp_p=start;
    no=temp_p->data;
    start=start->next;

    free(temp_p);

    printf("\n%d deleted successfully from beginning",no);
}


/* Delete Last Node */
void dellast()
{
    struct node *temp_p,*prev;
    int no;

    if(start==NULL)
    {
        printf("\nSingly linked list is Empty");
        return;
    }

    if(start->next==NULL)
    {
        no=start->data;
        free(start);
        start=NULL;

        printf("\n%d deleted successfully from last",no);
        return;
    }

    temp_p=start;

    while(temp_p->next!=NULL)
    {
        prev=temp_p;
        temp_p=temp_p->next;
    }

    no=temp_p->data;
    prev->next=NULL;

    free(temp_p);

    printf("\n%d deleted successfully from last",no);
}


/* Delete Node After Given Node */
void delafter()
{
    int after,no;
    struct node *temp_p,*delnode;

    if(start==NULL)
    {
        printf("\nSingly linked list is Empty");
        return;
    }

    printf("\nEnter node after which you want to delete=");
    scanf("%d",&after);

    temp_p=start;

    while(temp_p!=NULL && temp_p->data!=after)
    {
        temp_p=temp_p->next;
    }

    if(temp_p==NULL)
    {
        printf("\nNode %d not found",after);
        return;
    }

    if(temp_p->next==NULL)
    {
        printf("\nNo node exists after %d",after);
        return;
    }

    delnode=temp_p->next;
    no=delnode->data;

    temp_p->next=delnode->next;

    free(delnode);

    printf("\n%d deleted successfully after %d",no,after);
}


/* Display Linked List */
void display()
{
    if(start==NULL)
    {
        printf("\nSingly linked list is Empty");
    }
    else
    {
        struct node *temp_p=start;

        printf("\nLinked List = ");

        while(temp_p->next!=NULL)
        {
            printf("%d\t",temp_p->data);
            temp_p=temp_p->next;
        }

        printf("%d\n",temp_p->data);
    }
}


/* Main Function */
void main()
{
    int i;

    do
    {
        printf("\n\n1. INSERT A NEW NODE AT BEGINNING");
        printf("\n2. INSERT A NEW NODE AT LAST");
        printf("\n3. INSERT A NEW NODE AFTER GIVEN NODE");
        printf("\n4. DELETE FIRST NODE");
        printf("\n5. DELETE LAST NODE");
        printf("\n6. DELETE NODE AFTER GIVEN NODE");
        printf("\n7. DISPLAY LINKED LIST");
        printf("\n8. EXIT");

        printf("\n\nPLEASE, ENTER THE CHOICE:");
        scanf("%d",&i);

        switch(i)
        {
            case 1:
                addbeg();
                break;

            case 2:
                addlast();
                break;

            case 3:
                addafter();
                break;

            case 4:
                delbeg();
                break;

            case 5:
                dellast();
                break;

            case 6:
                delafter();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("\nProgram Ended");
                break;

            default:
                printf("\nInvalid Choice");
        }

    }while(i<8);
}

