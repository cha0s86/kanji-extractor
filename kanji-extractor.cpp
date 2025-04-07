#pragma execution_character_set( "utf-8" )
#include <iostream>
#include <windows.h>
#include <string>
#include <fcntl.h>
#include <io.h>
using namespace std;

#define KANJI_MIN   19968
#define KANJI_MAX   40879

union pools {
    struct kanjipool {
        public:
            std::wstring kanjipool[4096];
    };
};

pools::kanjipool kanjilexer(std::wstring kanjitext) {

    pools::kanjipool kanjipool;

    int iterator = 0;
    int kanjiindex = 0;
    int wordindex = 0;
    int comboiterator = 0;

    for (iterator = 0; kanjitext[iterator] != '\0'; iterator++)
    {
        // Check for a kanji, if we get a kaji, store it in charpool.
        if (kanjitext[iterator] > KANJI_MIN && kanjitext[iterator] < KANJI_MAX)
        {
            kanjipool.kanjipool[kanjiindex] += kanjitext[iterator];
            kanjiindex++;
        }
    }

    return kanjipool;
}

void printkanji(pools::kanjipool kanjiobj) {

    int iterator = 0;

    std::wstring ntchar = L"\0";

    for (iterator = 0; kanjiobj.kanjipool[iterator] != ntchar; iterator++)
    {
        std::wcout << iterator+1 << ": " << kanjiobj.kanjipool[iterator] << std::endl;
    }
}

int main() {
    
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stdin), _O_WTEXT);

    std::wstring kanjitext = L"日本語でお願いします、僕は日本人だから";

    std::wcout << L"You entered: " << kanjitext << std::endl;

    pools::kanjipool kanjiobj = kanjilexer(kanjitext);

    printkanji(kanjiobj);

    return 0;
}