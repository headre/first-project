//
//  buildTree.h
//  ex-quadtree
//
//  Created by headreaper on 2018/12/10.
//  Copyright © 2018 headreaper. All rights reserved.
//

#ifndef buildTree_h
#define buildTree_h

#include <stdio.h>
#include "tree-Structure.h"
#include <stdlib.h>
Node *makeNode( double x, double y, int level ) {
    
    int i;
    
    Node *node = (Node *)malloc(sizeof(Node));
    
    node->level = level;
    
    node->xy[0] = x;
    node->xy[1] = y;
    
    for( i=0;i<4;++i )
        node->child[i] = NULL;
    
    return node;
}
#endif /* buildTree_h */

