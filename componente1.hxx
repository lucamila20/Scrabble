#ifndef __COMPONENTE1_HXX__
#define __COMPONENTE1_HXX__

template <typename K, typename V>
struct  keyValue
{
    K key;
    V value;

    keyValue(K key, V value): key(key) , value(value) {}
};

#endif