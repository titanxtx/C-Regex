/*
MIT License

Copyright (c) 2018 Joshua Oliva

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stdio.h>
#include "regex_master.h"

int main(){
    char s[]="This is a test and only a test :)"; //string
    char reg[]="(\\b)(\\w{2,4})(\\b)"; //regex string, you need to escape your backslashes
    char rep[]="$1TEST$3"; //replacement string
    
    char *z=regex_replace2(s,reg,rep,(int[]){r_icase},1,(int[]){r_format_first_only},1);
    char *m=regex_replace1(s,reg,rep,(int[]){r_format_first_only},1);
    char *n=regex_replace0(s,reg,rep);

    printf("z string:%s\n",z);
    printf("m string:%s\n",m);
    printf("n string:%s\n",n);
    printf("logical match: %s\n",(regex_match_logical0(s,reg)?"true":"false"));
    printf("contains: %s\n",(regex_contains0(s,reg)?"true":"false"));
    printf("indexof: %d\n",regex_indexof0(s,reg));
    printf("indexofend: %d\n",regex_indexofend0(s,reg));
    printf("lastindexof: %d\n",regex_lastindexof0(s,reg));
    printf("lastindexofend: %d\n\n",regex_lastindexofend0(s,reg));
    
    char rep2[]="\\w{3,}";
    int size;
    struct regex_container *mz=regex_search0(s,rep2,&size);
    for(int w=0;w<size;w++)
    {
        printf("match#%d\n",w);
        for(int w2=0;w2<mz[w].len;w2++)
        {
            printf("capture#%d\n",w2);
            printf("str:%s\n",mz[w].x[w2].str);
            printf("start:%d  end:%d\n\n",mz[w].x[w2].start,mz[w].x[w2].end);
        }
    }
    
    int sizex;
    char u[]=".*?(\\w+).*?(\\w+).*?";

    struct regex_str *k=regex_match0(s,u,&sizex);
    printf("sizex:%d\n",sizex);
    for(int x=0;x<sizex;x++)
    {
        printf("match#%d\nstring: %s\n\n",x,k[x].str);
    }
    
    if(regex_contains0(s,reg))
    {
        printf("TRUE: Contains the regex\n");
    }
    else{
        printf("FALSE: Does not contain the regex\n");
    }
    return 0;
}
