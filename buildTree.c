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
void RemoveChildren( Node *node){
    for (int i=0;i<4;i++){
        free(node->child[i]);
        node->child[i]=NULL;
    }
    return;
}

int getFlag(Node *node,double time){
    int flag;
    double value;
    value=nodeValue(node, time);
    if (value>0.5){
        flag=1;
    }
    else if (value<-0.5){
        flag=-1;
    }
    else{
        flag=0;
    }
    return flag;
}
void addOrRemove( Node *node, double time){
    for (int i=0;i<4;i++){
        int f=getFlag(node->child[i], time);
        if (f==1){
            makeChildren(node->child[i]);
        }
        if (f==-1){
            RemoveChildren(node);
            break;
        }
    }
    
    return;
}
void adapt( Node *head){
    if (head->child[0]!=NULL&&head->child[0]->child[0]==NULL){
        addOrRemove(head, 0.0);
    }
    else if (head->child[0]!=NULL&&head->child[0]->child[0]!=NULL){
        for (int i=0;i<4;i++){
            adapt(head->child[i]);
        }
        
    }
    
    return;
}

