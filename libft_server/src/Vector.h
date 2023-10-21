
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <vector>

template <class T>
class Vector: public std::vector<T>
{
    static T _default;
public:

    T& at(int i)
    {
        if(i >= (int)std::vector<T>::size()) return _default;
        return std::vector<T>::at(i);
    }

    T& operator [](int i)
    {
        return Vector<T>::at(i);
    }

    T& set(int i, const T & t)
    {
        if(i >= (int)std::vector<T>::size()){
            std::vector<T>::resize(i+1);
        }

        return std::vector<T>::at(i) = t;
    }

};

template<class T>
T Vector<T>::_default = T();


#endif
