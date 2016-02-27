//
//  targetFound.cpp
//  northgroup
//
//  Created by David Mongiello on 2/14/16.
//  Copyright © 2016 David Mongiello. All rights reserved.
//

#include "main.hpp"
#include <iostream>
using namespace std;

// Had to edit preprocessor definitions to get timeStamp to work (Error C4996). properties> config>prop. > C/C++> preprocessor> prepross. def.> Edit
// Type in "_CRT_SECURE_NO_WARNINGS" and save



void targetFound()
{
    
cout << "Target Found" << endl;
time_t ltime; /* calendar time */
ltime = time(NULL); /* get current cal time */
printf("%s", asctime(localtime(&ltime)));
}
