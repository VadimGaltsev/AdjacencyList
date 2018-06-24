//
// Created by vadik on 18.06.2018.
//

#ifndef GRAPHS_ITERATABLE_H
#define GRAPHS_ITERATABLE_H


class Iteratable {
public:
    Iteratable() {}
    virtual ~Iteratable() {}
    virtual bool next() = 0;
};


#endif //GRAPHS_ITERATABLE_H
