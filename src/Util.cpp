#include "Util.h"

/*!
 *    @brief  从路径中获得文件名
 *    @param  path 路径
 */
const char * getFilename(const char * path)
{
    size_t i = 0;
    size_t pos = 0;
    char * p = (char *)path;
    while(*p){
        i++;
        if(*p == '/' || *p == '\\'){
            pos = i;
        }
        p++;
    }
    return path+pos;
}