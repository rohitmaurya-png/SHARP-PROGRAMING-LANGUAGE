//
// Created by Rohit Maurya on 11/5/2020.
//

#ifndef SHARP_REFRENCEPOINTER_H
#define SHARP_REFRENCEPOINTER_H

#include "../../../stdimports.h"
#include "../List.h"

class ReferencePointer {
public:
    ReferencePointer()
    :
        mod("")
    {
        classes.init();
    }

    void free() {
        classes.free();
    }

    string mod;
    List<string> classes;
};

#endif //SHARP_REFRENCEPOINTER_H
