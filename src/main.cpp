#include "../inc/bst.hpp"

using namespace std;

void readInputFile();

void printErrors();

BST myBST;
ifstream inFile;
string Line, CMD, Title, Day, Hour, Output;
bool cmdFlag = false;
bool titleFlag = false;
bool dayFlag = false;
bool hourFlag = false;
bool argFlag = false;
bool tempFlag = false;

int main(int argc, char* argv[]) {

    if (argc != 2){
        cout << "Invalid arguments" << endl;
        return 0;
    }
    
    inFile.open(argv[1], std::ifstream::in);
    if (inFile.is_open()) {
        readInputFile();
    }
    else cout << "File Not Found" << endl;

    return 0;
}

void readInputFile() {
    while (getline(inFile, Line)) {

        istringstream stream(Line);
        stream >> CMD;
        if (CMD == "ADD" || CMD == "MOD") {
            int firstQuoteIdx = Line.find("\"");
            int secondQuoteIdx = Line.rfind("\"");
            if (firstQuoteIdx != (int)string::npos) {
                firstQuoteIdx++;
                if (secondQuoteIdx != (int)string::npos)
                    Title = Line.substr(firstQuoteIdx, secondQuoteIdx - firstQuoteIdx);
            }
            else {
                stream >> Title;
                tempFlag = true;
                titleFlag = true;
            }

            int counter = 0;
            for (int Idx = 0; Idx < (int)Title.size(); Idx++) {
                if (Title[Idx] == '"') counter++;
            }
            if (counter != 0) titleFlag = true;

            if ((firstQuoteIdx == (int)string::npos && secondQuoteIdx == (int)string::npos) || (firstQuoteIdx - 1 == secondQuoteIdx)) {
                if (!tempFlag) {
                    stream >> Day;
                    tempFlag = false;
                }
                stream >> Day;
                stream >> Hour;
                titleFlag = true;
            }
            else {
                Day = Line.substr(secondQuoteIdx + 1, Line.size() - secondQuoteIdx);
                istringstream stream2(Day);
                stream2 >> Day;
                stream2 >> Hour;
            }

            for (int Idx = 0; Idx < (int)Day.size(); Idx++) {
                if (!(isdigit(Day[Idx])))
                    dayFlag = true;
            }
            for (int Idx = 0; Idx < (int)Hour.size(); Idx++) {
                if (!(isdigit(Hour[Idx])))
                    hourFlag = true;
            }

            int counter2 = 0;
            if (Title != "") counter2++;
            if (Day != "") counter2++;
            if (Hour != "") counter2++;
            if (counter2 != 3) {
                argFlag = true;
                counter2 = 0;
                printErrors();
                continue;
            }

            if (!(argFlag) && !(dayFlag) && (stoi(Day) < 1 || stoi(Day) > 365)) dayFlag = true;
            if (!(argFlag) && !(hourFlag) && (stoi(Hour) < 0 || stoi(Hour) > 23)) hourFlag = true;

            if (dayFlag || hourFlag || titleFlag || argFlag) {
                printErrors();
                continue;
            }

            if (CMD == "ADD") {
                Output = myBST.Insert(Title, stoi(Day), stoi(Hour));
                if (Output != "") cout << Output << endl;
            }
            else if (CMD == "MOD") {
                Output = myBST.Modify(Title, stoi(Day), stoi(Hour));
                if (Output != "") cout << Output << endl;
            }
        }
        else if (CMD == "DEL" || CMD == "Find" || CMD == "Print") {

            if (CMD == "Print") {
                myBST.Print();
                continue;
            }
            else {
                stream >> Day;
                stream >> Hour;

                for (int Idx = 0; Idx < (int)Day.size(); Idx++) {
                    if (!(isdigit(Day[Idx])))
                        dayFlag = true;
                }
                for (int Idx = 0; Idx < (int)Hour.size(); Idx++) {
                    if (!(isdigit(Hour[Idx])))
                        hourFlag = true;
                }

                if (Day == "" || Hour == "") argFlag = true;

                if (!(argFlag) && !(dayFlag) && (stoi(Day) < 1 || stoi(Day) > 365)) dayFlag = true;

                if (!(argFlag) && !(hourFlag) && (stoi(Hour) < 0 || stoi(Hour) > 23)) hourFlag = true;

                if (dayFlag || hourFlag || argFlag) {
                    printErrors();
                    continue;
                }

                if (CMD == "DEL") {
                    Output = myBST.Delete(stoi(Day), stoi(Hour));
                    if (Output != "") cout << Output << endl;
                }
                else if (CMD == "Find") {
                    Output = myBST.Search(stoi(Day), stoi(Hour));
                    cout << Output << endl;
                }
            }
        }
        else {
            if (CMD == "") continue;
            else{
                cmdFlag = true;
                printErrors();
                continue;
            }
        }

        CMD = "";
        Title = "";
        Day = "";
        Hour = "";
    }
    return;
}

void printErrors() {

    if (argFlag)
        cout << "Invalid arguments" << endl;
    if (cmdFlag)
        cout << "Invalid command" << endl;
    if (!argFlag && titleFlag)
        cout << "Invalid title" << endl;
    if (!(argFlag) && dayFlag)
        cout << "Invalid day" << endl;
    if (!(argFlag) && hourFlag)
        cout << "Invalid hour" << endl;

    cmdFlag = false;
    titleFlag = false;
    dayFlag = false;
    hourFlag = false;
    argFlag = false;
    tempFlag = false;
    CMD = "";
    Title = "";
    Day = "";
    Hour = "";
}