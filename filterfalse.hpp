//
// Created by osboxes on 6/9/20.
//

#ifndef ITERTOOLS_CFAR_A_FILTERFALSE_HPP
#define ITERTOOLS_CFAR_A_FILTERFALSE_HPP

#include <sys/types.h> //uint

namespace itertools {
    template< typename functor, typename Iter>
    class filterfalse {
        Iter & _iter;
        functor _f;
        decltype((_iter.begin())) beg;//decltype uses to deduce runtime type of an object
        decltype((_iter.end())) end_iter;

    public:
        filterfalse(functor f, Iter && iter):  _f(f), _iter(iter), beg(_iter.begin()), end_iter(iter.end()){}
        filterfalse(functor f, Iter & iter):  _f(f), _iter(iter), beg(_iter.begin()), end_iter(iter.end()){}

        class iterator
        {
            functor filter;
            decltype((_iter.begin())) & _inner_iter;
            Iter & _it;
            void normalize()
            {
                for(; _inner_iter != _it.end() && filter(*_inner_iter); ++_inner_iter);//jump who ever not matching the filter
            }

        public:

            /**
             * explict keyword uses for prevent the compiler from using implicit conversation for constructors who
             * accepts 1 primitive type. The compiler as default behavior tries to do implicit conversation of that
             * type to beg members exists within the class, hiding beg bug.
             */
            iterator(functor operation, decltype((_iter.begin())) & inner_iter, Iter & it) : filter(operation), _inner_iter(inner_iter), _it(it)
            {
                normalize();//We have to check the first element inside the ctor
            }

            //Iterator class must provide overloading of operators *, ++, !=
            int operator*() const { return *_inner_iter; }
            bool operator==(const iterator& other) const {return _inner_iter == other._inner_iter;}
            bool operator!=(const iterator& other) const { return !(*this == other); }

            iterator& operator++(){
                ++_inner_iter;
                normalize();
                return *this;
            } //prefix ++
        };

        iterator begin() { return iterator(_f, beg, _iter); }
        iterator end()   { return iterator(_f, end_iter, _iter); }
    };
}

#endif //ITERTOOLS_CFAR_A_FILTERFALSE_HPP
