//
//  writeTree.h
//  ex-quadtree
//
//  Created by headreaper on 2018/12/10.
//  Copyright © 2018 headreaper. All rights reserved.
//

#ifndef writeTree_h
#define writeTree_h

#include <stdio.h>
#include <math.h>
#include "tree-Structure.h"// recursively visit the leaf nodes
void printOut( FILE *fp, Node *node);
void writeNode( FILE *fp, Node *node ) {
    
    int i;
    
    if( node->child[0] == NULL )
        printOut( fp, node );
    else {
        for ( i=0; i<4; ++i ) {
            writeNode( fp, node->child[i] );
        }
    }
    return;
}

// write out the (x,y) corners of the node

void printOut( FILE *fp, Node *node ) {
    double x = node->xy[0];
    double y = node->xy[1];
    int level = node->level;
    double h = pow(2.0,-level);
    
    fprintf(fp, " %g %g\n",x,y);
    fprintf(fp, " %g %g\n",x+h,y);
    fprintf(fp, " %g %g\n",x+h,y+h);
    fprintf(fp, " %g %g\n",x,y+h);
    fprintf(fp, " %g %g\n\n",x,y);
    
    return;
}

#endif /* writeTree_h */
