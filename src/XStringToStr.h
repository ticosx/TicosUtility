#ifndef __XSTRING_TO_STR__
#define __XSTRING_TO_STR__

#include <string>

static std::string XStringToStr(ticos::XString s) {
    std::string str;
    int len = ticos::length<char>(s);
    str.resize(len);
    ticos::dump<char>(s, (char *)str.data());
    return str;
}

static const char *XStringToCstr(ticos::XString s) {
    static char buf[128];
    int len = ticos::length<char>(s);
    ticos::dump<char>(s, buf);
    int end = (len > sizeof(buf)) ? (sizeof(buf) - 1) : len;
    buf[end] = 0;
    return buf;
}

#endif
