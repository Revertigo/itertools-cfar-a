//
// Created by osboxes on 6/9/20.
//

#ifndef ITERTOOLS_CFAR_A_ACCUMULATE_HPP
#define ITERTOOLS_CFAR_A_ACCUMULATE_HPP

#include <functional>
#include "range.hpp"
#include <iostream>
using namespace std;
namespace itertools {

    //template<typename ...> class accumulate;
    //std::plus<int>()
    template<typename Iter>
    class accumulate {
        Iter & _iter; //We don't want to duplicate the container.
        decltype((_iter.begin())) beg;//decltype uses to deduce runtime type of an object
        decltype((_iter.begin())) end_iter;
        inline static decltype(*(_iter.begin())) _sum; //type is string/int in this case

    public:
        /**
         * explict keyword uses for prevent the compiler from using implicit conversation for constructors who
         * accepts 1 primitive type. The compiler as default behivior tries to do implicit conversation of that
         * type to beg members exists within the class, hiding beg bug.
         */
        explicit accumulate(Iter iter): _iter(iter) {
            beg = _iter.begin();
            end_iter = iter.end();
            //cout << *beg << endl;
            _sum = *beg;
        }

        class iterator{
            decltype(*(_iter.begin())) _value;
            decltype((_iter.begin())) & _inner_iter;
        public:

            iterator(decltype(*(_iter.begin())) value, decltype((_iter.begin())) & inner_iter) : _value(value), _inner_iter(inner_iter) {}

            //Iterator class must provide overloading of operators *, ++, !=
            decltype(*(_iter.begin())) operator*() const { return _sum; }
            bool operator==(const iterator& other) const { return _inner_iter == other._inner_iter; }
            bool operator!=(const iterator& other) const { return !(*this == other); }
            iterator& operator++(){
                _inner_iter++;
                _sum += *_inner_iter;
                return *this;} //prefix ++
            };

        iterator begin(){ return iterator(*beg, beg);}
        iterator end(){ return iterator(*end_iter, end_iter);}

    };
    //Declaration on type _sum
//    template<typename Iter>
//    typename Iter::value_type accumulate<Iter>:: _sum;


    /**
     * Lambda expression:
     * [](int x, int y){return x*y;}
     */

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