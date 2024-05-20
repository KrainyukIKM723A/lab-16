#include <iostream> 

#include <string> 

using namespace std;



const int MAX_PAGES = 10;



class Word {

private:

    string word;

    int pageNumbers[MAX_PAGES];

    int pageCount;



public:

    Word() {

        word = "";

        pageCount = 0;

        for (int i = 0; i < MAX_PAGES; ++i) {

            pageNumbers[i] = -1;

        }

    }



    Word(string w, int pages[], int count) {

        word = w;

        pageCount = count;

        for (int i = 0; i < MAX_PAGES; ++i) {

            if (i < count) {

                pageNumbers[i] = pages[i];

            }

            else {

                pageNumbers[i] = -1;

            }

        }

    }



    void setWord(string w) {

        word = w;

    }



    void setPageNumbers(int pages[], int count) {

        pageCount = count;

        for (int i = 0; i < MAX_PAGES; ++i) {

            if (i < count) {

                pageNumbers[i] = pages[i];

            }

            else {

                pageNumbers[i] = -1;

            }

        }

    }



    string getWord() {

        return word;

    }



    void getPageNumbers(int pages[], int& count) {

        count = pageCount;

        for (int i = 0; i < pageCount; ++i) {

            pages[i] = pageNumbers[i];

        }

    }



    int getPageCount() {

        return pageCount;

    }



    void show() {

        cout << "Word: " << word << ", Page numbers: ";

        for (int i = 0; i < pageCount; ++i) {

            cout << pageNumbers[i] << " ";

        }

        cout << endl;

    }



    bool appearsOnMoreThanNPages(int N) {

        return pageCount > N;

    }



    void printPageNumbers() {

        cout << "Pages for word '" << word << "': ";

        for (int i = 0; i < pageCount; ++i) {

            cout << pageNumbers[i] << " ";

        }

        cout << endl;

    }

};



void sortWordsAlphabetically(Word words[], int size) {

    for (int i = 0; i < size - 1; ++i) {

        for (int j = 0; j < size - i - 1; ++j) {

            if (words[j].getWord() > words[j + 1].getWord()) {

                Word temp = words[j];

                words[j] = words[j + 1];

                words[j + 1] = temp;

            }

        }

    }

}



int main() {

    const int WORD_COUNT = 3;

    Word words[WORD_COUNT];

    int pages1[] = { 1, 2, 3, 4 };

    words[0] = Word("apple", pages1, 4);

    int pages2[] = { 3, 5, 7, 9 };

    words[1] = Word("cherry", pages2, 4);

    int pages3[] = { 2, 4, 6, 8, 10 };

    words[2] = Word("banana", pages3, 5);



    int N = 3;

    cout << "Words that appear on more than " << N << " pages:" << endl;

    for (int i = 0; i < WORD_COUNT; ++i) {

        if (words[i].appearsOnMoreThanNPages(N)) {

            words[i].show();

        }

    }



    sortWordsAlphabetically(words, WORD_COUNT);

    cout << "\nWords in alphabetical order:" << endl;

    for (int i = 0; i < WORD_COUNT; ++i) {

        words[i].show();

    }



    string searchWord = "banana";

    cout << "\nPages for the word '" << searchWord << "': ";

    for (int i = 0; i < WORD_COUNT; ++i) {

        if (words[i].getWord() == searchWord) {

            words[i].printPageNumbers();

        }

    }



    return 0;

}