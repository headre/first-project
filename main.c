//
//  main.c
//  ex-quadtree
//
//  Created by headreaper on 2018/12/10.
//  Copyright © 2018 headreaper. All rights reserved.
//

#include <stdio.h>
#include "tree-Structure.h"
Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );
void growTree( Node *parent);
void destroyTree( Node *parent);

int main() {
    
    Node *head;
    head = makeNode( 0.0,0.0, 0 );
    makeChildren(head);
    makeChildren(head->child[0]);
    growTree(head);
    destroyTree(head);
    writeTree( head );
    
    return 0;
}
