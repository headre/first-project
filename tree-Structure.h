//
//  tree-Structure.h
//  ex-quadtree
//
//  Created by headreaper on 2018/12/10.
//  Copyright © 2018 headreaper. All rights reserved.
//

#ifndef tree_Structure_h
#define tree_Structure_h
#include <stdio.h>
struct qnode {
    int level;
    double xy[2];
    struct qnode *child[4];
};
typedef struct qnode Node;

#endif /* tree_Structure_h */

