//
//  main.cpp
//  exo_iterator
//
//  Created by François Bélanger on 17-09-26.
//  Copyright © 2017 François Bélanger. All rights reserved.
//

#include <iostream>
#include "TableauWrapper.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Tableau tab;
    
    for(int i = 0; i < 5; ++i)
        tab.add(i);
    
    for(auto iter=tab.begin(); iter != tab.end(); ++iter)
        cout << *iter << endl;
    
    system("pause");
    return 0;
}
