// Copyright 2020 Merzlov Nikolay merzlovnik@mail.ru
#include "string.hpp"

String::~String() {
    delete[] Data;
}

String::String() : size(0) {
    Data = new char[size];
}

String::String(const String &rhs) : size(rhs.size) {
    Data = new char[size];
    for (size_t i = 0; i < size; ++i) {
        Data[i] = rhs[i];
    }
}

String::String(const char *data) : size(0) {
    const char *copy_str = data;
    for (unsigned int i = 0; copy_str[i] != '\000'; ++copy_str)
        ++size;
    Data = new char[size];
    for (unsigned int i = 0; i < size; ++i)
        Data[i] = data[i];
}

void String::Resize(size_t new_size) {
    if (new_size > size) {
        auto new_Data = new char[new_size];
        for (unsigned int i = 0; i < size; ++i)
            new_Data[i] = Data[i];
        delete[]Data;
        Data = new_Data;
    }
    if (new_size < size) {
        auto new_Data = new char[new_size];
        for (unsigned int i = 0; i < new_size; ++i)
            new_Data[i] = Data[i];
        delete[]Data;
        Data = new_Data;
    }
}

String &String::operator=(const String &rhs) {
    if (&rhs != this) {
        Data = new char[rhs.size];
        size = rhs.size;
        for (unsigned int i = 0; i < size; ++i)
            Data[i] = rhs[i];
    }
    return *this;
}

class String &String::operator+=(const class String &rhs) {
    size = size + rhs.size;
    Resize(size);
    for (unsigned int i = size - rhs.size, j = 0; i < size + 1; ++i, ++j)
        Data[i] = rhs.Data[j];
    return *this;
}

class String &String::operator+=(const char *rhs) {
    String str(rhs);
    size = size + str.size;
    Resize(size);
    for (unsigned int i = size - str.size, j = 0; i < size; ++i, ++j)
        Data[i] = str.Data[j];
    return *this;
}

class String &String::operator*=(unsigned int m) {
    String copy_str(*this);
    for (unsigned int i = 1; i < m; ++i)
        *this += copy_str;
    return *this;
}

bool String::operator==(const class String &rhs) const {
    if (size != rhs.size)
        return false;
    if (size == rhs.size) {
        for (unsigned int i = 0; i < size; ++i) {
            if (Data[i] != rhs.Data[i])
                return false;
        }
    }
    return true;
}

bool operator==(const char *ch, const String &str) {
    String rhs(ch);
    if (str.Size() != rhs.Size())
        return false;
    if (str.Size() == rhs.Size()) {
        for (unsigned int i = 0; i < str.Size(); ++i) {
            if (str[i] != rhs[i])
                return false;
        }
    }
    return true;
}

bool String::operator<(const class String &rhs) const {
    for (unsigned int i = 0; i < rhs.size && i < size; ++i) {
        if (Data[i] > rhs.Data[i])
            return false;
        if (Data[i] < rhs.Data[i])
            return true;
    }
    return size < rhs.size;
}

size_t String::Find(const class String &substr) const {
    unsigned int j = 0;
    size_t sub_size = 0, sub_pos = 0, last_pos = -1;
    for (unsigned int i = 0; i < size; ++i) {
        if (Data[i] == substr.Data[j]) {
            ++j;
            if (sub_size == 0)
                sub_pos = i;
            ++sub_size;
            if (sub_size == substr.size)
                last_pos = sub_pos;
        } else {
            sub_size = 0;
            j = 0;
        }
    }
    return last_pos;
}

void String::Replace(char oldSymbol, char newSymbol) {
    for (unsigned int i = 0; i < size; ++i) {
        if (Data[i] == oldSymbol)
            Data[i] = newSymbol;
    }
}

size_t String::Size() const {
    return size;
}

bool String::Empty() const {
    return (size == 0);
}

char String::operator[](size_t index) const {
    return this->Data[index];
}

char &String::operator[](size_t index) {
    return this->Data[index];
}

void String::RTrim(char symbol) {
    unsigned int del_num = 0;
    if (Data[size - 1] == symbol) {
        for (unsigned int i = size - 1; Data[i] == symbol; --i)
            ++del_num;
        size -= del_num;
        Resize(size);
    }
}

void String::LTrim(char symbol) {
    unsigned int del_num = 0;
    if (Data[0] == symbol) {
        for (unsigned int i = 0; Data[i] == symbol; ++i) {
            ++del_num;
        }
        size -= del_num;
        char *new_string = new char[size];
        for (unsigned int i = del_num, j = 0; i < size + del_num; ++i, ++j)
            new_string[j] = Data[i];
        Resize(size);
        for (unsigned int i = 0; i < size; ++i)
            Data[i] = new_string[i];
    }
}

void String::Swap(String &oth) {
    char *s_str;
    size_t s_size;
    s_str = Data;
    s_size = size;
    Data = oth.Data;
    size = oth.size;
    oth.Data = s_str;
    oth.size = s_size;
}

std::ostream &operator<<(std::ostream &out, const String &str) {
    for (unsigned int i = 0; i < str.size; ++i)
        out << str[i];
    return out;
}

String operator+(const String &a, const String &b) {
    String str(a);
    str += b;
    return str;
}

String operator*(const String &a, unsigned int b) {
    String str(a);
    str *= b;
    return str;
}

bool operator!=(const String &a, const String &b) {
    if (a.Size() != b.Size()) {
        return true;
    }
    if (a.Size() == b.Size()) {
        for (unsigned int i = 0; i < a.Size(); ++i) {
            if (a[i] == b[i])
                return false;
        }
    }
    return true;
}

bool operator>(const String &a, const String &b) {
    for (unsigned int i = 0; i < a.Size() && i < b.Size(); ++i) {
        if (a[i] <= b[i])
            return false;
        if (a[i] > b[i])
            return true;
    }
    return a.Size() >= b.Size();
}
