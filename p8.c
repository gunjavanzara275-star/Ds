#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};


/* Create a new node */
struct node *create_node(int x)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


/* Insert node in BST */
struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        return create_node(x);
    }

    if (x < root->info)
    {
        root->left = insert(root->left, x);
    }
    else if (x > root->info)
    {
        root->right = insert(root->right, x);
    }
    else
    {
        printf("%d already exists in the BST.\n", x);
    }

    return root;
}


/* Inorder Traversal */
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}


/* Preorder Traversal */
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}


/* Postorder Traversal */
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}


/* Display all traversals */
void display(struct node *root)
{
    if (root == NULL)
    {
        printf("BST is empty.\n");
        return;
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");
}


/* Main function */
int main()
{
    struct node *root = NULL;

    int choice;
    int x;

    do
    {
        printf("\n====================================\n");
        printf("       BINARY SEARCH TREE\n");
        printf("====================================\n");

        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Display All Traversals\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            /* Insert */
            case 1:

                printf("Enter value: ");
                scanf("%d", &x);

                root = insert(root, x);

                printf("\nAfter inserting %d:", x);

                display(root);

                break;


            /* Inorder */
            case 2:

                printf("\nInorder Traversal: ");

                if (root == NULL)
                {
                    printf("BST is empty");
                }
                else
                {
                    inorder(root);
                }

                printf("\n");

                break;


            /* Preorder */
            case 3:

                printf("\nPreorder Traversal: ");

                if (root == NULL)
                {
                    printf("BST is empty");
                }
                else
                {
                    preorder(root);
                }

                printf("\n");

                break;


            /* Postorder */
            case 4:

                printf("\nPostorder Traversal: ");

                if (root == NULL)
                {
                    printf("BST is empty");
                }
                else
                {
                    postorder(root);
                }

                printf("\n");

                break;


            /* Display all */
            case 5:

                display(root);

                break;


            /* Exit */
            case 6:

                printf("\nProgram ended.\n");

                break;


            default:

                printf("Invalid choice!\n");
        }

    } while (choice != 6);


    return 0;
}