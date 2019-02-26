//
//  MMULT2.h
//  sysc-4001-assignment-1
//
//  Created by Kyle Horne on 2019-02-25.
//  Copyright © 2019 Kyle Horne. All rights reserved.
//

#ifndef MMULT2_h
#define MMULT2_h

#define ROWS 4
#define COLS 4
typedef int matrix[ROWS][COLS];

struct shared_matrices {
    matrix m;
    matrix n;
    matrix q;
};

#endif /* MMULT2_h */
