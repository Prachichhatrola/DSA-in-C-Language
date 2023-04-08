#include<stdio.h>
int sum(Node node)
{
    if (node == NULL)
    {
        return 0;
    }
    return sum(node.left)+node.value+sum(node.right);
}