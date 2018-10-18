# C-Regex
Wrapped C++ regex for C. Easier interface than the original.

This code was originaly written to work with Fortran. It was remodified without some of the boilerplate variables.

Remember to use the free() function in C to free the strings and structures or else you'll get a memory leak.

## Functions
The numbers after the function indicate what kind of flags it accepts in what order\
0 - no flags\
1 - match flags\
2 - syntax flags then match flags
3 - syntax flags
Flags:
```
    //mflags
    const int r_match_default=0;
    const int r_match_not_bol=1;
    const int r_match_not_eol=2;
    const int r_match_not_bow=3;
    const int r_match_not_eow=4;
    const int r_match_any=5;
    const int r_match_not_null=6;
    const int r_match_continuous=7;
    const int r_match_prev_avail=8;
    const int r_format_default=9;
    const int r_format_sed=10;
    const int r_format_no_copy=11;
    const int r_format_first_only=12;
    
    //sflags
    const int r_icase=0;
    const int r_nosubs=1;
    const int r_optimize=2;
    const int r_collate=3;
    const int r_ECMAScript=4;
    const int r_basic=5;
    const int r_extended=6;
    const int r_awk=7;
    const int r_grep=8;
    const int r_egrep=9;
```

The flags are constants. The functions accept integer arrays of these flags. In the integer arrays you can place the flags in any order
```
    struct regex_str{
        char*str;
        int len;
    };
    struct regex_data{
        char*str;
        int len;
        int start;
        int end;
    };
    struct regex_container{
        struct regex_data *x;
        int len;
    };
    char * regex_replace0(char*str,char *rgx,char *str_replace);
    char * regex_replace1(char*str,char *rgx,char *str_replace,int *mflags,int mflags_size);
    char * regex_replace2(char*str,char *rgx,char *str_replace,int *sflags,int sflags_size,int *mflags,int mflags_size);
    char * regex_replace3(char*str,char *rgx,char *str_replace,int *sflags,int sflags_size);

    bool regex_contains0(char*str,char*rgx);
    bool regex_contains1(char*str,char*rgx,int *mflags,int mflags_size);
    bool regex_contains2(char*str,char*rgx,int *sflags,int sflags_size,int *mflags,int mflags_size);
    bool regex_contains3(char*str,char*rgx,int *sflags,int sflags_size);

    bool regex_match_logical0(char*str,char*rgx);
    bool regex_match_logical1(char*str,char*rgx,int *mflags,int mflags_size);
    bool regex_match_logical2(char*str,char*rgx,int *sflags,int sflags_size,int *mflags,int mflags_size);
    bool regex_match_logical3(char*str,char*rgx,int *sflags,int sflags_size);

    int regex_indexof0(char*str,char*rgx);
    int regex_indexof1(char*str,char*rgx,int *mflags,int mflags_size);
    int regex_indexof2(char*str,char*rgx,int *sflags,int sflags_size,int *mflags,int mflags_size);
    int regex_indexof3(char*str,char*rgx,int *sflags,int sflags_size);

    int regex_lastindexof0(char*str,char*rgx);
    int regex_lastindexof1(char*str,char*rgx,int *mflags,int mflags_size);
    int regex_lastindexof2(char*str,char*rgx,int *sflags,int sflags_size,int *mflags,int mflags_size);
    int regex_lastindexof3(char*str,char*rgx,int *sflags,int sflags_size);

    int regex_indexofend0(char*str,char*rgx);
    int regex_indexofend1(char*str,char*rgx,int *mflags,int mflags_size);
    int regex_indexofend2(char*str,char*rgx,int *sflags,int sflags_size,int *mflags,int mflags_size);
    int regex_indexofend3(char*str,char*rgx,int *sflags,int sflags_size);

    int regex_lastindexofend0(char*str,char*rgx);
    int regex_lastindexofend1(char*str,char*rgx,int *mflags,int mflags_size);
    int regex_lastindexofend2(char*str,char*rgx,int *sflags,int sflags_size,int *mflags,int mflags_size);
    int regex_lastindexofend3(char*str,char*rgx,int *sflags,int sflags_size);

    struct regex_container* regex_search0(char*str,char*rgx,int*max_size);
    struct regex_container* regex_search1(char*str,char*rgx,int *mflags,int mflags_size,int*max_size);
    struct regex_container* regex_search2(char*str,char*rgx,int *sflags,int sflags_size,int *mflags,int mflags_size,int*max_size);
    struct regex_container* regex_search3(char*str,char*rgx,int *sflags,int sflags_size,int*max_size);

    struct regex_str* regex_match0(char*str,char*rgx,int*matchnum);
    struct regex_str* regex_match1(char*str,char*rgx,int *mflags,int mflags_size,int*matchnum);
    struct regex_str* regex_match2(char*str,char*rgx,int *sflags,int sflags_size,int *mflags,int mflags_size,int*matchnum); 
    struct regex_str* regex_match3(char*str,char*rgx,int *sflags,int sflags_size,int*matchnum);
```
### regex_replace
Replaces any regex match with the replacement string\
1st Argument: string\
2nd Argument: regex string\
3rd Argument: replacement string\
Example:
```
char z[]="testing 123 321 123";
char e[]="\d+";
char w[]="number";
char *m=regex_replace0(z,e,w);
```
### regex_contains
It returns true or false if the string matches the regular expression or not\
1st Argument: string\
2nd Argument: regex string\
Example:
```
char z[]="testing 123 321 123";
char e[]="\d+"
bool g=regex_contains0(z,e);
//or 
if(regex_contains0(z,e))
{
  printf("True statement");
}
else
{
  printf("False statement");
}
```
## regex_match_logical
It returns true or false if the regular expression matches the whole string or not\
1st Argument: string\
2nd Argument: regex string\
Example:
```
char z[]="testing 123 321 123";
char e[]="\d+";
bool g=regex_match_logical0(z,e);
//or 
if(regex_match_logical0(z,e))
{
  printf("True statement");
}
else
{
  printf("False statement");
}
```
## regex_indexof,  regex_indexofend,   regex_lastindexof,   regex_lastindexofend
Returns the index of the character array that is matched. If nothing is found then it returns -1\
1st Argument: string\
2nd Argument: regex string\
Example:
```
char z[]="testing 123 321 123";
char e[]="\d+";
int t=regex_indexof0(z,e); //first occurance start index
int t2=regex_indexofend0(z,e); //first occurance ending index
int t3=regex_lastindexof0(z,e); //last occurance start index
int t4=regex_lastindexofend0(z,e); //last occurance ending index
```
## regex_search
If a regex match is found it returns an array of structures with all the captures inside along with the starting and ending indexes.\
The first capture is always the whole match of the regex. After the first capture the rest of the matches are based on the closed parenthesis in the regular expression\
1st Argument: string\
2nd Argument: regex string\
3rd Argument: integer - the size of the result is stored here\
Example:
```
    char z[]="This is a test and only a test :)";
    char e[]="(\\b)(\\w{2,4})(\\b)";
    int size;
    struct regex_container *mz=regex_search0(z,e,&size);
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
```
Result:
```
match#0
capture#0
str:This
start:0  end:3

match#1
capture#0
str:test
start:10  end:13

match#2
capture#0
str:and
start:15  end:17

match#3
capture#0
str:only
start:19  end:22

match#4
capture#0
str:test
start:26  end:29
```
## regex_match
If the regex matches the entire string then it returns an array of structures with all the captures inside.\
The first capture is always the whole match of the regex. After the first capture the rest of the matches are based on the closed parenthesis in the regular expression\
1st Argument: string\
2nd Argument: regex string\
3rd Argument: integer - the size of the result is stored here\
Example:
```
    char s[]="This is a test and only a test :)";
    int size;
    char u[]=".*?(\\w+).*?(\\w+).*?";

    struct regex_str *k=regex_match0(s,u,&size);
    printf("size:%d\n",size);
    for(int x=0;x<size;x++)
    {
        printf("match#%d\nstring: %s\n\n",x,k[x].str);
    }
```
Result:
```
size:3
match#0
string: This is a test and only a test :)

match#1
string: This

match#2
string: is
```
## Compilation
A make file can be made for this. Here is a terminal command you can use if you want. -c is used to compile everything initially separately. Then after we link everything together with the -lstdc++ library.
```
gcc-8 -O3 -c reg.c -o reg.o && g++-8 -O3 -std=c++17 -c regex_master.cpp -o regex_master.o  &&gcc-8 regex_master.o reg.o -O3 -std=c++17 -o test.out -lstdc++ && ./test.out

Used for running also. Take off the last && ./test.out if you don't want to run the program immediately. reg.c is the test program. Replace that with your program.
```

