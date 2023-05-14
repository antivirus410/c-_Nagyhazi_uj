#include <iostream>
#include <cstring>

#include "string5.h"

using std::cin;
using std::ios_base;

String::String(char ch) {
    len = 1;
    pData = new char[len+1];
    pData[0] = ch;
    pData[1] = '\0';
}

            ///Nullával lezárt soroztból
String::String(const char *p) {
    len = strlen(p);
    pData = new char[len+1];
    strcpy(pData, p);
}

String::String(const String& s1) {
    len = s1.len;
    if ((pData = s1.pData) == NULL) return;
    pData = new char[len+1];
    strcpy(pData, s1.pData);
}

String& String::operator=(const String& rhs_s) {
    if (this != &rhs_s) {
        delete[] pData;
        len = rhs_s.len;
        if ((pData = rhs_s.pData) == NULL) return *this;
        pData = new char[len+1];
        strcpy(pData, rhs_s.pData);
    }
    return *this;
}

bool String::operator==(const String &rhs) {
    return strcmp(pData, rhs.pData);
}

char& String::operator[](unsigned int idx) {
    if (idx >= len) throw "String: indexelesi hiba";
    return pData[idx];
}

const char& String::operator[](unsigned int idx) const {
    if (idx >= len) throw "String: indexelesi hiba";
    return pData[idx];
}

String String::operator+(const String& rhs_s) const {
    String temp;
    temp.len = len + rhs_s.len;
    delete []temp.pData;
    if (temp.len == 0) {
        temp.pData = NULL;
        return temp;
    }
    temp.pData = new char[temp.len+1];
    if (pData == NULL)
        temp.pData[0] = '\0';
    else
        strcpy(temp.pData, pData);
    if (rhs_s.pData != NULL)
        strcat(temp.pData, rhs_s.pData);

    return temp;

}
std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}

std::istream& operator>>(std::istream& is, String& s0) {
    unsigned char ch;
    s0 = String("");
	std::ios_base::fmtflags fl = is.flags();
	is.setf(ios_base::skipws);
    while (is >> ch) {
	    is.unsetf(ios_base::skipws);
        if (isspace(ch)) {
            is.putback(ch);
            break;
        } else {
            s0 = s0 + ch;
        }
    }
	is.setf(fl);
    return is;
}

