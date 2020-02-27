// Copyright 2020 Merzlov Nikolay merzlovnik@mail.ru
#include "string.hpp"

String::~String() {
    delete[] string;
}

String::String() : size(1) {
    string = new char[size];
    string[0] = '0';
}

String::String(const String &rhs) : size(rhs.size) {
    string = new char[size];
    for (unsigned int i = 0; i < size; ++i) {
        string[0] = rhs[i];
    }
}

String::String(const char *data) {
    for (const char *copy_str = data; *copy_str != 0; ++copy_str)
        ++size;
    string = new char[size];
    for (unsigned int i = 0; i < size; ++i, ++data)
        string[i] = *data;
}

String &String::operator=(const String &rhs) {
    if (&rhs != this) {
        string = new char[rhs.size];
        size = rhs.size;
        for (unsigned int i = 0; i < size; ++i)
            string[i] = rhs[i];
    }
    return *this;
}

class String &String::operator+=(const class String &rhs) {
    size = size + rhs.size;
    for (unsigned int i = size - rhs.size, j = 0; i < size; ++i, ++j)
        string[i] = rhs[j];
    return *this;
}

class String &String::operator*=(unsigned int m) {
    String copy_str(*this);
    for (unsigned int i = 0; i < m; ++i)
        *this += copy_str;
    return *this;
}

bool String::operator==(const class String &rhs) const {
    if (size != rhs.size)
        return false;
    else {
        for (unsigned int i = 0; i < size; ++i) {
            if (string[i] != rhs[i])
                return false;
        }
    }
    return true;
}

bool String::operator<(const class String &rhs) const {
    for (unsigned int i = 0; i < rhs.size && i < size; ++i) {
        if (string[i] > rhs[i])
            return false;
    }
    return size <= rhs.size;
}

size_t String::Find(const class String &substr) const {
    size_t sub_size = 0;
    size_t sub_pos = 0;
    for (unsigned int i = 0; i < size - substr.size; ++i) {
        if (string[i] == substr.string[i]) {
            if (sub_size == 0)
                sub_pos = i;
            ++sub_size;
            if (sub_size == substr.size)
                return sub_pos;
        } else
            sub_size = 0;
    }
    return -1;
}

void String::Replace(char oldSymbol, char newSymbol) {
    for (unsigned int i = 0; i < size; ++i) {
        if (string[i] == oldSymbol)
            string[i] = newSymbol;
    }
}

size_t String::Size() const {
    return size;
}

bool String::Empty() const {
    return (size != 0);
}

char String::operator[](size_t index) const {
    return string[index];
}

char &String::operator[](size_t index) {
    return string[index];
}

void String::RTrim(char symbol) {
    unsigned int pos = 0;
    if (string[size - 1] == symbol) {
        for (unsigned int i = size - 1; i >= 0; ++i) {
            if (string[i] != symbol) {
                pos = i + 1;
                break;
            }
        }
        char *new_string = new char[pos + 1];
        for (unsigned int i = 0; i <= pos; ++i)
            new_string[i] = string[i];
        delete[]string;
        string = new_string;
    }
}

void String::LTrim(char symbol) {
    unsigned int pos = 0;
    if (string[0] == symbol) {
        for (unsigned int i = 0; i < size; ++i) {
            if (string[i] != symbol) {
                pos = i - 1;
                break;
            }
        }
        char *new_string = new char[pos + 1];
        for (unsigned int i = pos, j = 0; i <= size; ++i, ++j)
            new_string[j] = string[i];
        delete[]string;
        string = new_string;
    }
}

void String::swap(String &oth) {
    char *s_str;
    size_t s_size;
    s_str = string;
    s_size = size;
    string = oth.string;
    size = oth.size;
    oth.string = s_str;
    oth.size = s_size;
}