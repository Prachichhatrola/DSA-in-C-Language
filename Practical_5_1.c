#include <stdio.h>
#include <stdlib.h>
int l = 0;
int i = 0;
// create structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// to creat a new node
struct node *create(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// function to insert he data in the bst
struct node *insert(struct node *root, int data)
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        temp = create(data);
        return temp;
    }

    if (data < temp->data)
    {
        temp->left = insert(temp->left, data);
    }
    else if (data > temp->data)
    {
        temp->right = insert(temp->right, data);
    }
    return temp;
}
// function to print the data in inorder format
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // left -> root-> right
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}
// function to print the data in preorder format
void preorder(struct node *root)
{
    if (root != NULL)
    {
        // root -> left -> right
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// functio to print the data in postorder format
void postorder(struct node *root)
{
    if (root != NULL)
    {
        // left -> right -> root
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}
// function to search the specific data
struct node *search(struct node *root, int value)
{
    struct node *temp;
    temp = root;
    if (value == root->data)
    {
        return temp;
    }
    else if (value < temp->data)
    {
        return search(temp->left, value);
    }
    else if (value > temp->data)
    {
        return search(temp->right, value);
    }
    else
    {
        return NULL;
    }
}
// function to find the minimum value in the bst
struct node *min(struct node *root)
{
    struct node *temp;
    temp = root;
    // to find the minimum value we will traverse until the leaf node
    // the condition is that the root and its left child are both null
    while (temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
// function to find specific data
struct node *delete(struct node *root, int data)
{
    struct node *temp, *ptr;
    temp = root;
    if (temp == NULL)
    {
        return temp;
    }
    // to treavesr the tree in left direction
    else if (data < temp->data)
    {
        temp->left = delete (temp->left, data);
    }
    // to traverse in the right direction
    else if (data > temp->data)
    {
        temp->right = delete (temp->right, data);
    }
    // after finding the data ,it has two child or one child
    else
    {
        // if after traversing the root node has right child then the root will be replaced by it
        if (temp->left == NULL)
        {
            ptr = temp->right;
            free(temp);
            return ptr;
        }
        // if after travesing the root node has left child then the root will be replaced by it
        else if (temp->right == NULL)
        {
            ptr = temp->left;
            free(temp);
            return ptr;
        }
        ptr = min(temp->right);
        // if the root node have two child then we find the minimum element from the right child tree
        temp->data = ptr->data;
        // then copy the data in another pointer data
        // after than delete the data from the right child tree using recursice call of right child tree
        temp->right = delete (temp->right, ptr->data);
    }
    return temp;
}
// function to find the height of the tree
int height(struct node *root)
{
    struct node *temp;
    temp = root;
    // for leaf node we will return 1
    if (temp == NULL)
    {
        return 0;
    }
    int lheight, rheight;
    lheight = height(temp->left);
    rheight = height(temp->right);
    // using travesal we will reach at leaf node
    // using below condition we will do +1
    if (lheight > rheight)
    {
        return lheight + 1;
    }
    else
    {
        return rheight + 1;
    }
}
// function to fin the number of child node that mens leaf nodes
void leaf(struct node *root)
{
    struct node *temp;
    temp = root;
    if (temp != NULL)
    {
        // leaf node means the node which have no child
        // we traverse in the whole tree and using the bellow condition we increment the value of l
        leaf(temp->left);
        if (temp->left == NULL && temp->right == NULL)
        {
            l = l + 1;
        }
        leaf(temp->right);
    }
    // return l;
}
// functiion to find the number of internal nodes
void internal(struct node *root)
{
    struct node *temp;
    temp = root;
    if (temp != NULL)
    {
        // internal node means the node which have one child or two child excluding root node
        internal(temp->left);
        if (temp->left != NULL || temp->right != NULL)
        {
            i = i + 1;
        }
        internal(temp->right);
    }
}
int main()
{
    printf("\nName : Prachi Chhatrola\n");
    printf("Enrollment No. : 210210116030\n");
    int data;
    int high;
    struct node *root, *ptr;
    root = NULL;
    root = insert(root, 50);
    // insert(root,30);
    // insert(root,20);
    // insert(root,40);
    // insert(root,70);
    // insert(root,60);
    // insert(root,80);
    int ch;
    while (1)
    {
        printf("\n1.Insert\n2.Search the specific element\n3.To find the Minimum element From the tree\n4.To delete a specific data\n5.Print the Tree in inorder\n6.Print the tree in preorder\n7.Print the tree in postorder\n8.To find the height of a Tree\n9.To find the number of leaf node\n10.To find the number of internal node\n11.To find the Total number of nodes\n12.Exit");
        printf("\n Enter the choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the data = ");
            scanf("%d", &data);
            insert(root, data);
            inorder(root);
            break;
        case 2:
            printf("\n Enter the element which you to search = ");
            scanf("%d", &data);
            ptr = search(root, data);
            if (ptr == NULL)
            {
                printf("\n There is not such an element");
            }
            else
            {
                printf("\n the searched element is = %d", ptr->data);
            }
            break;
        case 3:
            ptr = min(root);
            printf("\nThe minimum element is = %d", ptr->data);
            break;
        case 4:
            printf("\n Enter the element which you want to delete = ");
            scanf("%d", &data);
            root = delete (root, data);
            printf("\n After deleting the specific data from the tree = ");
            inorder(root);
            break;
        case 5:
            printf("\n Tree in inorder : ");
            inorder(root);
            break;
        case 6:
            printf("\n Tree in preorder : ");
            preorder(root);
            break;
        case 7:
            printf("\n Tree in postorder : ");
            postorder(root);
            break;
        case 8:
            high = height(root);
            printf("\n The height of Tree : %d", high);
            break;
        case 9:
            leaf(root);
            printf("\n The number of leaf node : %d", l);
            break;
        case 10:
            internal(root);
            printf("\n The number of internal node : %d", i - 1);
            break;
        case 11:
            internal(root);
            leaf(root);
            printf("\n The Total number of nodes : %d", l + i);
            break;
        case 12:
            exit(1);
            break;
        }
    }
}