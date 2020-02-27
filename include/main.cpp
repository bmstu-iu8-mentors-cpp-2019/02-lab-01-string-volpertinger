// Copyright 2020 Merzlov Nikolay merzlovnik@mail.ru
#include"string.hpp"

using std::cout;
using std::endl;

int main() {
//Constructors
    cout << "constructors" << endl;
    String str_base, str_user("Abcde"), str_copy(str_user);
    std::cout << "str_base" << endl << str_base << endl;
    std::cout << "str_user" << endl << str_user << endl;
    std::cout << "str_copy" << endl << str_copy << endl;
//operator=
    cout << "operator=" << endl;
    String new_str("Datan");
    str_base = new_str;
    cout << str_user << endl;
//operator <<
    cout << "operator<<" << endl;
    cout << str_user << endl;
//operator+=
    cout << "operator+=" << endl;
    str_user += str_base;
    cout << str_user << endl;
//operator*=
    cout << "operator*=" << endl;
    str_base *= 8;
    cout << str_base << endl;

//operator==
    cout << "operator==" << endl;
    cout << (str_base == str_user) << endl << (str_user == str_user) << endl;
//operator<
    cout << "operator<" << endl;
    cout << (str_user < str_base) << endl << (str_user < str_user) << endl;
//Find
    cout << "Find" << endl;
    String substr("cd");
    cout << "str=" << str_user << endl << "find=" << substr << endl;
    cout << str_user.Find(substr) << endl;
//Replace
    cout << "replace a to - in " << str_user << endl;
    str_user.Replace('a', '-');
    cout << str_user << endl;
//size
    cout << "size of " << str_user << endl;
    cout << str_user.Size() << endl;
//empty
    cout << "empty of " << str_user << endl;
    cout << str_user.Empty() << endl;
//operator[]
    cout << "operator[]" << endl;
    cout << str_user << endl;
    cout << "str_user[2]=" << str_user[2] << endl;
    str_user[2] = '+';
    cout << "[2]=+" << endl;
    cout << str_user << endl;
//RTim
    cout << "RTim" << endl;
    String strrt("___RTTHG++++");
    cout << strrt << endl;
    strrt.RTrim('+');
    cout << strrt << endl;
//LTim
    cout << "LTim" << endl;
    strrt.LTrim('_');
    cout << strrt << endl;
//Swap
    cout << "Swap" << endl;
    String s1("aaa"), s2("bbb");
    cout << "s1=" << s1 << endl << "s2=" << s2 << endl;
    s1.Swap(s2);
    cout << "Swap" << endl << "s1=" << s1 << endl << "s2=" << s2 << endl;
//operator+
    cout << "operator+" << endl;
    cout << "bbb+aaa" << endl << s1 + s2 << endl;
//operator*
    cout << "operator*" << endl;
    cout << "bbb*3" << endl << s1 * 3 << endl;
//operator!=
    cout << "operator!=" << endl;
    cout << "bbb!=aaa?" << endl << (s1 != s2) << endl;
    cout << "bbb!=bbb?" << endl << (s1 != s1) << endl;
//operator>
    cout << "operator>" << endl;
    cout << "bbb>aaa?" << endl << (s1 > s2) << endl;
    cout << "bbb>bbb?" << endl << (s1 > s1) << endl;
    return 0;
}
