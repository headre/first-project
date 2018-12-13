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
#include <math.h>
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
double value( double x, double y, double time ) {
    
    return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

double nodeValue( Node *node, double time ) {
    
    int level = node->level;
    double x = node->xy[0];
    double y = node->xy[1];
    
    double h = pow(2.0,-level);
    
    return( value( x+0.5*h, y+0.5*h, time ) );
}

#endif /* buildTree_h */

