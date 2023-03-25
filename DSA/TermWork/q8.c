Program to create a binary search tree and perform following operations.
#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    struct BST *Left;
    struct BST *Right;
    int data;
} treetype;

treetype *insert(treetype *R, int X)
{
    treetype *p = NULL;
    if (R == NULL)
    {
        p = (treetype *)malloc(sizeof(treetype));
        p->data = X;
        p->Left = p->Right = NULL;
        R = p;
        return R;
    }
    else if (R->data > X)
        R->Left = insert(R->Left, X);
    else
        R->Right = insert(R->Right, X);
    return R;
}

int search_key(treetype *R, int X)
{
    if (R != NULL)
    {
        if (R->data == X)
            return 1;
        search_key(R->Left, X);
        search_key(R->Right, X);
    }
    return 0;
}

treetype *inOrderPredecessor(treetype *R)
{
    R = R->Left;
    while (R->Right != NULL)
        R = R->Right;
    return R;
}

treetype *delete_Node(treetype *R, int X)
{
    treetype *iPre = NULL;
    if (R == NULL)
    {
        printf("Node not found!!");
        return NULL;
    }
    if (R->Left == NULL && R->Right == NULL && R->data == X)
    {
        printf("Node is deleted");
        free(R);
        return NULL;
    }
    if (X < R->data)
        R->Left = delete_Node(R->Left, X);
    else if (X > R->data)
        R->Right = delete_Node(R->Right, X);
    else
    {
        iPre = inOrderPredecessor(R);
        R->data = iPre->data;
        R->Left = delete_Node(R->Left, iPre->data);
    }
    return R;
}

void total_leaf_node(treetype *R, int *c)
{
    if (R != NULL)
    {
        if (R->Left == NULL && R->Right == NULL)
            (*c)++;
        total_leaf_node(R->Left, c);
        total_leaf_node(R->Right, c);
    }
}

int height_tree(treetype *R)
{
    if (R == NULL)
        return 0;
    else
    {
        int left_Height = height_tree(R->Left);
        int right_Height = height_tree(R->Right);
        if (left_Height > right_Height)
            return left_Height + 1;
        else
            return right_Height + 1;
    }
}

void total_Right_Node(treetype *R, int *c)
{
    if (R != NULL)
    {
        (*c)++;
        total_Right_Node(R->Left, c);
        total_Right_Node(R->Right, c);
    }
}

void main()
{
    treetype *Root = NULL;
    int X, ch;
    int c = 0, d = 0;
    do
    {
        printf("\nEnter 1 to insert\nEnter 2 to find a key\nEnter 3 to delete a node\nEnter 4 to find total leaf Node\nEnter 5 to find height of tree\nEnter 6 to find total nodes at right side\nEnter 7 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Number: ");
            scanf("%d", &X);
            Root = insert(Root, X);
            break;

        case 2:
            printf("Enter Key: ");
            scanf("%d", &X);
            if (search_key(Root, X))
                printf("Find the key\n");
            else
                printf("Didn't find the key\n");
            break;

        case 3:
            printf("Enter Node to delete: ");
            scanf("%d", &X);
            Root = delete_Node(Root, X);
            break;

        case 4:
            total_leaf_node(Root, &c);
            printf("Total Leaf Nodes: %d\n", c);
            break;

        case 5:
            printf("Height of tree: %d", height_tree(Root));
            break;

        case 6:
            total_Right_Node(Root->Right, &d);
            printf("Total Nodes at right side: %d\n", d);
            break;
        }
    } while (ch <= 6);
}
