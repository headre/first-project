//
//  writeTree.c
//  ex-quadtree
//
//  Created by headreaper on 2018/12/10.
//  Copyright © 2018 headreaper. All rights reserved.
//

#include "writeTree.h"
#include "tree-Structure.h"
void writeTree( Node *head ) {
    
    FILE *fp = fopen("quad.out","w");
    
    writeNode(fp,head);
    
    fclose(fp);
    
    return;
}
