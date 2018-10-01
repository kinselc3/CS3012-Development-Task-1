#include <stdio.h>
#include <stdlib.h>
#include <cbdd.h>

#include "LowestCommonAncestry.c"


int main()
{
  struct node *root        = newNode(20);
  root->left               = newNode(8);
  root->right              = newNode(22);
  root->left->left         = newNode(4);
  root->left->right        = newNode(12);
  root->left->right->left  = newNode(10);
  root->left->right->right = newNode(14);

  int n1 = 8, n2 = 22;
  struct node *t = lca(root, n1, n2);

  it("testing normal scenario", ^{
        expect_equal(t->data, 20) ;
  });

  n1 = 8, n2 = 4;
  t = lca(root, n1, n2);
  it("testing parent and child", ^{
        expect_equal(t->data, 8) ;
  });

  n1 = 12, n2 = 12;
  t = lca(root, n1, n2);
  it("testing same node", ^{
        expect_equal(t->data, 12) ;
  });

  n1 = 0, n2 = 0;
  t = lca(root, n1, n2);

  it("testing missing node", ^{
        expect_null(t) ;
  });


}
