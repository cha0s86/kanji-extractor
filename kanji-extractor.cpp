#include <iostream>
#include <string>
using namespace std;

#define KANJI_MIN 19968
#define KANJI_MAX 40879

union pools {
    struct kanjipool {
        public:
            std::wstring kanjipool[256];
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

int main() {

    std::wstring kanjitext = L"日本語でお願いします、僕は日本人だから";

    kanjilexer(kanjitext);

    return 0;
}