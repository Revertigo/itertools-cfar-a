//
// Created by osboxes on 6/9/20.
//

#ifndef ITERTOOLS_CFAR_A_ACCUMULATE_HPP
#define ITERTOOLS_CFAR_A_ACCUMULATE_HPP

#include <functional>
#include <iostream>
#include "range.hpp"

namespace itertools {

    //template<typename ...> class accumulate;
    //std::plus<int>()
    static int _sum;
    template<typename Iter>
    class accumulate {
        Iter _iter;
        typename Iter::iterator beg;
        typename Iter::iterator end_iter;

    public:
        accumulate(Iter iter): _iter(iter) {
            beg = _iter.begin(); end_iter = iter.end();
            _sum = *beg;
        }

        class iterator{
            int _value;
            typename Iter::iterator & _iter;
        public:

            /**
             * explict keyword uses for prevent the compiler from using implicit conversation for constructors who
             * accepts 1 primitive type. The compiler as default behivior tries to do implicit conversation of that
             * type to beg members exists within the class, hiding beg bug.
             */
            explicit iterator(int value, typename Iter::iterator & iter) : _value(value), _iter(iter) {}

            //iterator(int value) : _value(value) {}

            //Iterator class must provide overloading of operators *, ++, !=
            int operator*() const { return _sum; }
            bool operator==(const iterator& other) const { return _iter == other._iter; }
            bool operator!=(const iterator& other) const { return !(*this == other); }
            int operator++(int){_sum += _value; return *this;} //postfix ++
            iterator& operator++(){_iter++; _sum += *_iter;  return *this;} //prefix ++
        };

        iterator begin(){ return iterator(*beg, beg);}
        iterator end(){ return iterator(*end_iter, end_iter);}

    };


//    template<typename Iter, typename functor>
//    class accumulate<Iter, functor> {
//        Iter _iter;
//        functor _func;
//    public:
//        accumulate(Iter iter,  functor bin):_iter(iter), _func(bin){}
//        int operator()(int x, int y) {return x+y;}
//        class iterator{
//            int _value;
//
//            class intholder
//            {
//                int internal_val;
//            public:
//                explicit intholder(int value): internal_val(value) {}
//                int operator*() { return internal_val; }
//            };
//
//        public:
//
//            /**
//             * explict keyword uses for prevent the compiler from using implicit conversation for constructors who
//             * accepts 1 primitive type. The compiler as default behivior tries to do implicit conversation of that
//             * type to beg members exists within the class, hiding beg bug.
//             */
//            explicit iterator(int value) : _value(value) {}
//            //Iterator class must provide overloading of operators *, ++, !=
//            int operator*() const { return _value; }
//            bool operator==(const iterator& other) const { return _value == other._value; }
//            bool operator!=(const iterator& other) const { return !(*this == other); }
//            intholder operator++(int){intholder ret(_value);} //postfix ++
//            iterator& operator++(){} //prefix ++
//        };
//
//        iterator begin(){ return _iter;}
//        iterator end(){ return _iter; }
//
//    };
}


#endif //ITERTOOLS_CFAR_A_ACCUMULATE_HPP