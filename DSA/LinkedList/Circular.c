#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *tail=NULL;

void create_list()
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    int i, n, item;
    printf("\nEnter the number of nodes of the linked list: ");
    scanf("%d", &n);
    if(n==0)
    {
        printf("\nNothing to insert\n",n);
        return;
    }
    printf("\nEnter the element 1: ");
    scanf("%d", &item);
    newnode->data=item;
    tail=newnode;
    tail->next=tail;


    for(i=1; i<n; i++)
    {
        newnode=malloc(sizeof(struct node*));
        printf("\nEnter the element %d: ", i+1);
        scanf("%d", &item);
        newnode->data=item;
        newnode->next=tail->next;
        tail->next=newnode;
        tail=tail->next;
    }

}

void insert_beg()
{
    struct node *newnode;
    int item;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the number which you want to insert at beginning: ");
    scanf("%d",&item);
    newnode->data=item;
    if(tail==NULL)
    {
        tail=newnode;
        newnode->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }
    printf("%d inserted successfully at the beginning of the list\n",item);
}

void last_insert()
{
    struct node *newnode;
    int item;
    newnode=malloc(sizeof(struct node*));
    printf("\nEnter the element which you want to insert at last of the list: ");
    scanf("%d", &item);
    newnode->data=item;
    if(tail==NULL)
    {
        tail=newnode;
        newnode->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=tail->next;
    }
    printf("%d inserted successfully at the last of the list\n", item);
}

void random_insert()
{
    struct node *newnode, *temp;
    int item, pos, loc;
    temp=tail->next;
    newnode=malloc(sizeof(struct node*));
    printf("\nEnter the position after which you want to insert the data: ");
    scanf("%d",&pos);

    printf("\nEnter the data which you want to insert after %d position: ",pos);
    scanf("%d",&item);
    newnode->data=item;
    loc=pos;

    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    if(temp==tail)
    {
        tail=tail->next;
    }
    printf("\nNode inserted successfully after position %d\n",loc);
}

void del_first()
{
    if(tail==NULL)
    {
        printf("\nLinked list is already empty\n");
        return;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        printf("\nFirst node deleted successfully\n");
        return;
    }
    struct node *temp;
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    printf("\nFirst node deleted successfully\n");
}

void del_last()
{
    if(tail==NULL)
    {
        printf("\nLinked list is already empty\n");
        return;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        printf("\nLast node deleted successfully\n");
    }
    struct node *temp=tail->next;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    printf("\nLast node deleted successfully\n");


}

void del_random()
{
    struct node *temp, *temp2, *countPlease;
    int pos, count=0;
    if(tail==NULL)
    {
        printf("\nLinked list is already empty\n");
        return;
    }

    printf("\nEnter the position of the node which you want delete: ");
    scanf("%d",&pos);

    countPlease=temp=tail->next;
    do
    {
        count++;
        countPlease=countPlease->next;

    }while(countPlease!=tail->next);


    if(pos>count)
    {
        printf("\nCan't delete - there are only %d elements in the list\n",count);
    }

    else if(count==1)
    {
        free(tail);
        tail=NULL;
    }

    else if(pos==1)
    {
        tail->next=temp->next;
        free(temp);
        temp=NULL;
    }

    else
    {
        while(pos>2)
        {
            temp=temp->next;
            pos--;
        }
        temp2=temp->next;
        temp->next=temp2->next;
        if(temp2==tail)
        {
            tail=temp;
        }
        free(temp2);
        temp2=NULL;
    }




}


void search()
{
    struct node *temp;
    int element, position=1, flag=0;
    if(tail==NULL)
    {
        printf("\nLinked list is already empty\n");
        return;
    }
    temp=tail->next;
    printf("\nEnter the element which you want to search: ");
    scanf("%d",&element);
    do
    {
        if(temp->data==element)
        {
            printf("\nElement found at position %d\n", position);
            flag=1;
        }
        temp=temp->next;
        position++;
    }while(temp!=tail->next);
    if(flag==0)
    {
        printf("\n%d does not exist in the list\n", element);
    }

}


void count()
{
    struct node *temp;
    int count=0;
    if(tail==NULL)
    {
        printf("\nThere are zero node in the linked list\n");
        return;
    }
    temp=tail->next;
    do
    {
        count++;
        temp=temp->next;

    }while(temp!=tail->next);
    printf("\nTotal number of nodes in the list are %d.\n", count);
}


void display()
{
    struct node *temp;
    if(tail==NULL)
    {
        printf("\nNothing to print- Linked list is empty\n");
        return;
    }

    printf("\n---------Printing the data of the singly circular linked list---------\n");
    temp=tail->next;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }while(temp!=tail->next);
    printf("\n");
}

void main()
{
    int choice=0;
    while(choice!=11)
    {
        printf("\n===============================================\n");
        printf("\n------Main Menu-----\n");
        printf("\n1. Create a singly circular linked list\n2. Insert an element at first position\n3. Insert an element at last position\n4. Insert an element in between the nodes\n5. Delete first element\n6. Delete last element\n7. Delete a intermediate node\n8. Count the number of elements\n9. Display the elements of the linked list\n10. Search a element of the linked list\n11. Exit\n");
        printf("\n===============================================\n");
        printf("\nSelect an option from the above menu: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            create_list();
            break;

        case 2:
            insert_beg();
            break;

        case 3:
            last_insert();
            break;

        case 4:
            random_insert();
            break;

        case 5:
            del_first();
            break;

        case 6:
            del_last();
            break;

        case 7:
            del_random();
            break;

        case 8:
            count();
            break;

        case 9:
            display();
            break;

        case 10:
            search();
            break;

        case 11:
            printf("\nThank You\n");
            exit(0);
            break;

        default:
            printf("\nPlease enter a valid choice\n");

        }
    }
}
