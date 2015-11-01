/*************************************************************************
    > File Name: strcmp.h
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 23/10/2015 - 09:39:31
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
