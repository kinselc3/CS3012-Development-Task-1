#include <stdio.h>
#include <stdlib.h>
#include <cbdd.h>

#include "DAG.c"


int main()
{
  struct node *src        = newNode(20);
  src->left               = newNode(8);
  src->right              = newNode(22);
  src->left->left         = newNode(4);
  src->left->right        = newNode(12);
  src->left->right->left  = newNode(10);
  src->left->right->right = newNode(14);
  linkNodes(src->left->right->right,src,0);
  int n1 = 8, n2 = 22;
  struct node *t = lca(src, n1, n2);

  it("testing normal scenario", ^{
        expect_equal(t->data, 20) ;
  });

  n1 = 8, n2 = 4;
  t = lca(src, n1, n2);
  it("testing parent and child", ^{
        expect_equal(t->data, 8) ;
  });

  n1 = 12, n2 = 12;
  t = lca(src, n1, n2);
  it("testing same node", ^{
        expect_equal(t->data, 12) ;
  });

  n1 = 0, n2 = 0;
  t = lca(src, n1, n2);

  it("testing missing node", ^{
        expect_null(t) ;
  });


}
