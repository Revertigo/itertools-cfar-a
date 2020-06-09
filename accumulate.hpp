//
// Created by osboxes on 6/9/20.
//

#ifndef ITERTOOLS_CFAR_A_ACCUMULATE_HPP
#define ITERTOOLS_CFAR_A_ACCUMULATE_HPP

#include "range.hpp"
namespace itertools {
    template<class T>
    class accumulate {
        T _iter;
    public:
        accumulate(T iter): _iter(iter){}
        T begin(){ return _iter; }
        T end(){ return _iter; }

    };
}

#endif //ITERTOOLS_CFAR_A_ACCUMULATE_HPP
