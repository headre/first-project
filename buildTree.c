//
//  buildTree.c
//  ex-quadtree
//
//  Created by headreaper on 2018/12/10.
//  Copyright © 2018 headreaper. All rights reserved.
//

#include "buildTree.h"
#include "tree-Structure.h"
#include <math.h>

void makeChildren( Node *parent ) {
    
    double x = parent->xy[0];
    double y = parent->xy[1];
    
    int level = parent->level;
    
    double hChild = pow(2.0,-(level+1));
    
    parent->child[0] = makeNode( x,y, level+1 );
    parent->child[1] = makeNode( x+hChild,y, level+1 );
    parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
    parent->child[3] = makeNode( x,y+hChild, level+1 );
    
    return;
}
void growTree( Node *parent ){
        if (parent->child[0]==NULL){
            makeChildren(parent);
        }
        else{
            for (int j=0;j<4;j++){
                growTree(parent->child[j]);
            }
        }
    return;
}
