#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void){
    setlocale(LC_ALL, "");
    wchar_t co[3] = {L'\u250C', L'\u251C', L'\u252C'};
    for(int i=0;i<3;i++){
        wprintf(L"%lc\n",co[i]);
    }
    return 0;
}