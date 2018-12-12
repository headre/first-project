//
//  destroy.c
//  ex-quadtree
//
//  Created by headreaper on 2018/12/11.
//  Copyright © 2018 headreaper. All rights reserved.
//

#include "tree-Structure.h"
#include <stdlib.h>
void destroyTree( Node *parent){
    for (int i=0;i<4;++i){
        if (parent->child[i]!=NULL){
            destroyTree(parent->child[i]);
        }
        if (i==3){
            free(parent);
            parent=NULL;
        }
    }
    return;
}

