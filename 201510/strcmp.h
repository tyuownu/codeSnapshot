/*************************************************************************
    > File Name: strcmp.h
    > Author: 
    > Mail: 
    > Created Time: 2015年10月23日 星期五 09时39分31秒
 ************************************************************************/

#ifndef _STRCMP_H
#define _STRCMP_H
int strcmp(const char *dest, const char *source)
{
    assert((NULL != dest) && (NULL != source));
    while(*dest && *source && (*dest == *source))
    {
        dest++; source++;
    }
    return *dest - *source;
}
#endif
