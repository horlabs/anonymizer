#ifndef LIBTOOLINGAST_HOOKS_H
#define LIBTOOLINGAST_HOOKS_H

#include <iostream>

extern "C"
void _ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode(
        std::basic_ifstream<char, std::char_traits<char>> *self,
        const char *__s,
        std::ios_base::openmode __mode);

extern "C"
void _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode(
        std::basic_ofstream<char, std::char_traits<char>> *self,
        const char *__s,
        std::ios_base::openmode __mode);

extern "C"
void _ZNSt14basic_ofstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode(
        std::basic_ofstream<char, std::char_traits<char>> *self,
        const char *filename,
        std::ios_base::openmode mode);

extern "C"
void _ZNSt14basic_ifstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode(
        std::basic_ifstream<char, std::char_traits<char>> *self, const char *__s, std::ios_base::openmode __mode);

template<class RandomAccessIterator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last);


#endif //LIBTOOLINGAST_HOOKS_H
