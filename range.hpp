//
// Created by osboxes on 6/9/20.
//

#ifndef ITERTOOLS_CFAR_A_RANGE_HPP
#define ITERTOOLS_CFAR_A_RANGE_HPP

#include <sys/types.h>

namespace itertools {
    class range {
        uint _start;
        uint _end;

    public:
        range(uint start, uint end): _start(start), _end(end){};

        class iterator
        {
            int _value;

            class intholder
            {
                int internal_val;
            public:
                explicit  intholder(int value): internal_val(value) {}
                int operator*() { return internal_val; }
            };

        public:

            /**
             * explict keyword uses for prevent the compiler from using implicit conversation for constructors who
             * accepts 1 primitive type. The compiler as default behivior tries to do implicit conversation of that
             * type to a members exists within the class, hiding a bug.
             */
            explicit iterator(int value) : _value(value) {}
            //Iterator class must provide overloading of operators *, ++, !=
            int operator*() const { return _value; }
            bool operator==(const iterator& other) const { return _value == other._value; }
            bool operator!=(const iterator& other) const { return !(*this == other); }
            intholder operator++(int){intholder ret(_value);} //postfix ++
            iterator& operator++(){} //prefix ++
        };

        iterator begin() { return iterator(_start); }
        iterator end()   { return iterator(_end); }
    };

}


#endif //ITERTOOLS_CFAR_A_RANGE_HPP
