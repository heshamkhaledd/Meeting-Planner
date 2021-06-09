#include "../inc/bst.hpp"

using namespace std;

void readInputFile();

void printErrors ();

BST myBST;
ifstream inFile;
string Line,CMD,Title,Day,Hour,Output;
bool cmdFlag = false;
bool titleFlag = false;
bool dayFlag = false; 
bool hourFlag = false;

int main(int argc, char *argv[])
{

    inFile.open(argv[1],std::ifstream::in);
    if(inFile.is_open()){
        readInputFile();
    }
    else cout<<"File Not Found"<<endl;
    
    return 0;
}

void readInputFile (){
        while (getline(inFile, Line)) {

            istringstream stream(Line);
            stream>>CMD;
            if (CMD == "ADD" || CMD == "MOD"){
                    int firstQuoteIdx = Line.find("\"");
                    int secondQuoteIdx = Line.rfind("\"");
                if (firstQuoteIdx != (int)string::npos) {
                    firstQuoteIdx++;
                    if (secondQuoteIdx != (int)string::npos)
                    Title = Line.substr(firstQuoteIdx,secondQuoteIdx-firstQuoteIdx);
                    else titleFlag = true;
                }
                else titleFlag = true;
                    Day = Line.substr(secondQuoteIdx+1,Line.size()-secondQuoteIdx);
                    istringstream stream2(Day);
                    stream2>>Day;
                    stream2>>Hour;

                if (stoi(Day) < 1 || stoi(Day) > 365) dayFlag = true;
                if (stoi(Hour) < 0 || stoi(Hour) > 23) hourFlag = true;
                
                if (dayFlag || hourFlag){
                    printErrors();
                    continue;
                }

                if (CMD == "ADD") {
                    Output = myBST.Insert(Title, stoi(Day), stoi(Hour));
                    if (Output == "") continue;
                    else cout<< Output <<endl;
                }
                else if (CMD == "MOD") {
                    Output = myBST.Modify(Title,stoi(Day),stoi(Hour));
                    if (Output == "") continue;
                    else cout<< Output <<endl;
                }       
            }
            else if (CMD == "DEL" || CMD == "Find" || CMD == "Print") {

                if (CMD == "Print") {
                    myBST.Print();
                    continue;
                }
                else{
                    stream>>Day;
                    stream>>Hour;
                    if (stoi(Day) < 1 || stoi(Day) > 365) dayFlag = true;
                        
                    if (stoi(Hour) < 0 || stoi(Hour) > 23) hourFlag = true;

                    if (dayFlag || hourFlag){
                        printErrors();
                        continue;
                    }
                        
                    if (CMD == "DEL") {
                        Output = myBST.Delete(stoi(Day),stoi(Hour));
                        if (Output == "") continue;
                        else cout<< Output <<endl;
                    }
                    else if (CMD == "Find"){
                    Output =  myBST.Search(stoi(Day),stoi(Hour));
                    cout<< Output <<endl;
                    }
                }
            }

            else {
                cmdFlag = true;
                printErrors();
            }

            Title = "";
            Day = "";
            Hour = "";
        }
        return;
}

void printErrors() {
    if (cmdFlag)
        cout<<"Invalid command"<<endl;
    if (titleFlag)
        cout<<"Invalid title"<<endl;
    if (dayFlag)
        cout<<"Invalid day"<<endl;
    if (hourFlag)
        cout<<"Invalid hour"<<endl;

    cmdFlag = false;
    titleFlag = false;
    dayFlag = false; 
    hourFlag = false;
}