
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left, *right;
};

struct node *lca(struct node* n0, int n1, int n2)
{
    if (n0 == NULL) return NULL;

    // If both n1 and n2 are smaller than n0, then LCA lies in left
    if (n0->data > n1 && n0->data > n2)
        return lca(n0->left, n1, n2);

    // If both n1 and n2 are greater than n0, then LCA lies in right
    if (n0->data < n1 && n0->data < n2)
        return lca(n0->right, n1, n2);

    return n0;
}


struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = node->right = NULL;
    return(node);
}
//link 2 nodes, direction is determined by dir (left dir = 1, right dir = 0)
void linkNodes(struct node* src, struct node* dest, int dir) {
  if(src != NULL && dest !=NULL)
  {
    if(dir == 0 && src->left != NULL)
      src->left = dest;
    else if(dir == 1 && src->right != NULL)
      src->right = dest;
  }
  return;
};
