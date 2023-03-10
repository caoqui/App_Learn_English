#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <locale>
#include <io.h>
#include <fcntl.h>
#include <locale.h>
#include <wchar.h>
#include <codecvt>

using namespace std;


int lengOfList() {
    int leng;

    //ifile.open("lengthOfList.txt", ios_base::in);

    wifstream ifile("lengthOfList.txt", ios::in);

    //Thiết lập tiếng việt
    ifile.imbue(locale("vi_VN.UTF-8"));

    ifile >> leng;

    ifile.close();

    return leng;
}

void setLengOfList(int newleng) {
    //ofile.open("lengthOfList.txt", ios_base::out);
    wofstream ofile("lengthOfList.txt", ios::out);

    //Thiết lập tiếng việt
    ofile.imbue(locale("vi_VN.UTF-8"));

    ofile << newleng;

    ofile.close();
}

void rewriteFile(vector<wstring> wordlist, vector<wstring> meanlist) {
    //ofstream f;
    //f.open("wordList.txt", ios_base::out);

    wofstream outfile("wordList.txt", ios::out);

    //Thiết lập tiếng việt
    outfile.imbue(locale("vi_VN.UTF-8"));

    for (int i = 0; i < wordlist.size(); i++) {
        outfile << wordlist[i] << " : " << meanlist[i] << " #\n";
    }

    outfile.close();
}

void writeWord(vector<wstring> wordlist, vector<wstring> meanlist, int length) {
    wstring word;
    vector<wstring> wordlistToday, meanlistToday;

    //copy wordList to temp array
    for (int i = 0; i < length; i++) {
        wordlistToday.push_back(wordlist[i]);
    }
    //copy meanList to temp array
    for (int i = 0; i < length; i++) {
        meanlistToday.push_back(meanlist[i]);
    }

    wcin.clear();
    wcin.ignore();


    while (1) {

        for (int i = 0; i < wordlistToday.size(); i++) {
            int random_number = rand() % wordlistToday.size() + 1;
            wcout << L"Random_number: " << random_number << endl;
            wcout << L"SIZE: " << wordlistToday.size() << endl;

            wcout << L"-----------Welcome to word list----------\n";
            //cout << random_number << ". " << meanlistToday[random_number] << "\n";
            wcout << L"--> " << meanlistToday[random_number - 1] << "\n";
            wcout << L"Input this word: ";
            getline(wcin, word);


            if (word == wordlistToday[random_number - 1]) {
                wordlistToday.erase(wordlistToday.begin() + random_number - 1);
                meanlistToday.erase(meanlistToday.begin() + random_number - 1);
                wcout << L"----->Correct!!!\n";
                system("pause");
                system("cls");
            }
            else {
                wcout << L"----->Oh no, That is incorrect.\n";
                wcout << L"\n~The result: " << wordlistToday[random_number - 1] << "\n";
                system("pause");
                system("cls");
            }
        }
        if (wordlistToday.begin() == wordlistToday.end()) {
            wcout << L"\nThat at all. Thank you!\n";
            system("pause");
            break;
        }
        system("cls");

    }
}

void learnByOptions(vector<wstring> wordlist, vector<wstring> meanlist, int length) {
    int option;
    vector<wstring> wordlistToday, meanlistToday;

    //copy wordList to temp array
    for (int i = 0; i < length; i++) {
        wordlistToday.push_back(wordlist[i]);
    }
    //copy meanList to temp array
    for (int i = 0; i < length; i++) {
        meanlistToday.push_back(meanlist[i]);
    }

    while (1) {

        for (int i = 0; i < wordlistToday.size(); i++) {
            wcout << L"-----------Learn by options----------\n";
            wcout << L"0. Exit                              \n";
            wcout << L"1. Answer by Vietnames               \n";
            wcout << L"2. Answer by English                 \n";
            wcout << L"-------------------------------------\n";
            wcout << L"Input your option: ";
            wcin >> option;

            switch (option)
            {
            case 0:
                return;
            case 1:
                wcout << L"-----------Learn by options Vietnames----------\n";
                wcout << L"\n" << i + 1 << L". " << wordlistToday[i] << L"\n";
                //chon vi tri cau tra loi chinh xac
                //int poscor;

                break;
            case 2:
                break;
            default:
                wcout << "Please input correct option, thank.\n";
                system("pause");
                break;
            }
            system("cls");
        }


    }
}

void guessMean(vector<wstring> wordlist, vector<wstring> meanlist, int length) {
    int option;
    vector<wstring> wordlistToday, meanlistToday;

    //copy wordList to temp array
    for (int i = 0; i < length; i++) {
        wordlistToday.push_back(wordlist[i]);
    }
    //copy meanList to temp array
    for (int i = 0; i < length; i++) {
        meanlistToday.push_back(meanlist[i]);
    }

    while (1) {

        for (int i = 0; i < wordlistToday.size(); i++) {
            wcout << L"-----------Guess mean of word----------\n";
            wcout << i + 1 << L". " << wordlistToday[i] << "\n";
            wcout << L"---Guess mean of word, right now---\n";
            system("pause");
            wcout << L"-----------------------------------------\n";
            wcout << L"~The result: " << meanlistToday[i] << "\n";
            wcout << L"1. Yeah, That's true!!!\n";
            wcout << L"2. No, let me retry.\n";
            wcout << L"--> Input your choice: ";
            wcin >> option;

            switch (option)
            {
            case 1:
                wordlistToday.erase(wordlistToday.begin() + i);
                meanlistToday.erase(meanlistToday.begin() + i);
                break;
            case 2:
                break;
            default:
                wcout << L"Please input correct option, thank.\n";
                system("pause");
                break;
            }
            system("cls");
        }
        if (wordlistToday.begin() == wordlistToday.end()) {
            wcout << L"\nThat at all. Thank you!\n";
            system("pause");
            break;
        }

    }
}

void addWordToList(vector<wstring>& wordlist, vector<wstring>& meanlist) {
    wcout << L"--------ADD WORD TO LIST--------\n";
    int length = lengOfList();
    wstring word, mean;

    //f.open("wordList.txt", ios_base::app);
    //wofstream f("wordList.txt", ios::app);
    ofstream file("wordList.txt", ios::app);

    //Thiết lập tiếng việt
    //f.imbue(locale("vi_VN.UTF-8"));

    wcout << L"Input word : ";
    wcin.clear();
    wcin.ignore();
    getline(wcin, word);

    wcout << L"Mean word : ";
    wcin.clear();
    getline(wcin, mean);

    setLengOfList(length + 1);

    // Chuyển đổi chuỗi Unicode sang UTF-8
    wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    string cvt_word = converter.to_bytes(word);

    wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter2;
    string cvt_mean = converter2.to_bytes(mean);

    file << " " << cvt_word << " : " << cvt_mean << " #\n";

    file.close();

    //add to vector wordlist, meanlist
    wordlist.push_back(word);
    meanlist.push_back(mean);
}

void viewWordList(vector<wstring> wordlist, vector<wstring> meanlist, int leng) {
    wcout << L"\n------------WELCOM TO WORD LIST------------\n";
    wcout << L"Size: " << leng << "\n";
    for (int i = 0; i < leng; i++) {
        wcout << i + 1 << L". " << wordlist[i] << L" : " << meanlist[i] << L"\n";
    }
}

void deleteWord(vector<wstring>& wordlist, vector<wstring>& meanlist) {
    while (1) {
        wcout << L"|---------------DELETE SOME WORDS---------------|\n";
        wcout << L"|0. Exit                                        |\n";
        wcout << L"|1.  Delete word at position                    |\n";
        wcout << L"|---------------------------------------------- |\n";

        int leng = lengOfList();
        int choice;
        wcout << L"--> input your choice: ";
        wcin >> choice;

        switch (choice) {
        case 0:
            return;
        case 1:
            viewWordList(wordlist, meanlist, leng);
            int pos;
            wcout << L"\nInput position which you want to delete : ";
            wcin >> pos;

            //delete word out wordlist, meanlist.
            wordlist.erase(wordlist.begin() + pos - 1);
            meanlist.erase(meanlist.begin() + pos - 1);
            setLengOfList(leng - 1);

            //delete word out file wordlist | re-write words to file word list
            rewriteFile(wordlist, meanlist);

            wcout << L"Delete successfully!!!\n";
            break;
        default:
            wcout << L"Wrong option, please retry.\n";
            break;
        }

        system("pause");
        system("cls");
    }

}

void menu(vector<wstring>& wordlist, vector<wstring>& meanlist) {
    while (1) {
        wcout << L"|------------------CHOICE OPTION------------------|\n";
        wcout << L"|0. EXIT                                          |\n";
        wcout << L"|1. WRITE WORD                                    |\n";
        wcout << L"|2. LEARN BY OPTIONS                              |\n";
        wcout << L"|3. GUESS MEAN OF WORD                            |\n";
        wcout << L"|4. ADD SOME WORDS TO WORD LIST                   |\n";
        wcout << L"|5. VIEW WORD LIST                                |\n";
        wcout << L"|6. DELETE A WORD                                 |\n";
        wcout << L"|-------------------------------------------------|\n";

        int leng = lengOfList();

        int choice;
        wcout << L"->Input your choice: ";
        wcin >> choice;

        system("cls");

        switch (choice) {

        case 0: return;
        case 1:
            writeWord(wordlist, meanlist, leng);
            break;
        case 2:
            wcout << L"comming soon\n";
            break;
        case 3:
            guessMean(wordlist, meanlist, leng);
            break;
        case 4:
            addWordToList(wordlist, meanlist);
            break;
        case 5:
            viewWordList(wordlist, meanlist, leng);
            break;
        case 6:
            deleteWord(wordlist, meanlist);
            break;
        default:
            wcout << L"You entered wrong option, please retry.\n";
        }
        system("pause");
        system("cls");
    }


}

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    //ifstream ifile;
    wifstream ifile("wordList.txt", ios::in);

    //Thiết lập tiếng việt
    ifile.imbue(locale("vi_VN.UTF-8"));

    int leng = lengOfList();

    srand(time(0));

    vector<wstring> wordList;
    vector<wstring> meanList;
    wstring word, next;

    for (int i = 0; i < int(leng); i++) {
        //Key word
        ifile >> word;

        ifile >> next;

        while (next != L":") {
            word += L" " + next;
            ifile >> next;
        }
        wordList.push_back(word);
        //Mean word
        ifile >> word;
        ifile >> next;
        while (next != L"#") {
            word += L" " + next;
            ifile >> next;

        }
        meanList.push_back(word);

    }

    ifile.close();

    menu(wordList, meanList);

    wordList.clear();
    meanList.clear();

    return 0;
}
