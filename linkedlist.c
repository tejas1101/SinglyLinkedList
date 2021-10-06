#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;

void display()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("No nodes\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d -- >", temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}

int length()
{
    int count = 0;
    struct node *temp;
    temp = root;
    if (root == NULL)
    {

    }
    else
    {
        while (temp != NULL)
        {
            count += 1;
            temp = temp->link;
        }
    }
    return count;
}

void DelAtBeg()
{
    if (root == NULL)
    {
        printf("There are no nodes to delete\n");
        return;
    }
    if (length() == 1)
    {
        struct node *temp = root;
        root = NULL;
        free(temp);
    }
    else
    {
        struct node *temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    display();
}

void DelAtEnd()
{
    if (root == NULL)
        printf("There are no nodes to delete\n");
    else
    {
        struct node *temp, *p;
        int i = 1;
        temp = root;
        while (i < length() - 1)
        {
            temp = temp->link;
            i++;
        }
        p = temp->link;
        temp->link = NULL;
        free(p);
    }
    display();
}

void DelAt()
{
    int n, i = 1;
    printf("Enter the location where you want to delete: ");
    scanf("%d", &n);
    if (n == 1)
        DelAtBeg();
    else if (n == length())
        DelAtEnd();
    else if (n <= 0 || n > length())
        printf("There are only %d nodes in the list\n", length());
    else
    {
        struct node *temp, *p;
        temp = root;
        while (i < n - 1)
        {
            temp = temp->link;
            i++;
        }
        p = temp->link;
        temp->link = p->link;
        p->link = NULL;
        free(p);
        display();
    }
}

void deleteNode()
{
    int ch;
    while (1)
    {
        printf("1.At Beg\n2.At End\n3.At Position\n4.Move to parent menu\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            DelAtBeg();
            break;
        }
        case 2:
        {
            DelAtEnd();
            break;
        }
        case 3:
        {
            DelAt();
            break;
        }
        case 4:
        {
            return;
        }
        }
    }
}

void InsertAtBeg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter node date: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        newnode->link = root;
        root = newnode;
    }
    display();
}

void InsertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        struct node *temp;
        temp = root;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    display();
}

void InsertAfter()
{
    int len, n, i = 1;
    len = length();
    printf("Enter the position: ");
    scanf("%d", &n);
    if (n == 0)
        InsertAtBeg();
    else if (n == len)
        InsertAtEnd();
    else if (n < 0 || n > len)
    {
        printf("There are only %d node in the list\n", len);
    }
    else
    {
        struct node *temp;
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &newnode->data);
        newnode->link = NULL;
        temp = root;
        while (i < n)
        {
            temp = temp->link;
            i++;
        }
        newnode->link = temp->link;
        temp->link = newnode;
        display();
    }
}

void insertNode()
{
    int ch;
    while (1)
    {
        printf("1.At beg\n2.At End\n3.Insert After\n4.Move to parent menu\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            InsertAtBeg();
            break;
        }
        case 2:
        {
            InsertAtEnd();
            break;
        }
        case 3:
        {
            InsertAfter();
            break;
        }
        case 4:
        {
            return;
        }
        }
    }
}

void createList()
{
    int i, n;
    printf("Size of LinkedList: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("%d. Enter the data\n", i + 1);
        scanf("%d", &newnode->data);
        newnode->link = NULL;
        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            struct node *temp;
            temp = root;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = newnode;
        }
    }
    display();
}

void reverseList()
{
    if (length() == 0)
    {
        printf("No nodes to reverse");
    }
    else
    {

        struct node *prev = NULL, *next = root, *current = root;
        printf("Before reversing : ");
        display();
        printf("\n");

        while(next != NULL)
        {
            next = current->link;
            current->link = prev;
            prev = current;
            current = next; 
        }
        root = prev;

        printf("After reversing : ");
        display();
    }
}

int main()
{
    int ch, len = 0;
    printf("Creating Linked List...\n");
    createList();
    while (1)
    {
        printf("1.insert\n2.delete\n3.display\n4.length\n5.Reverse the data\n6.exit\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            insertNode();
            break;
        }
        case 2:
        {
            deleteNode();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            len = length();
            printf("Length is %d\n", len);
            break;
        }
        case 5:
        {
            reverseList();
            break;
        }
        case 6:
        {
            exit(0);
        }
        }
    }
}
