#include <iostream>
#define INT_MAX 2147483647
using namespace std;

int main() {
    string line;
    cout << "Enter String : ";
    getline(cin, line);

    int s = line.size();
    cout << "Lengeth of string : " << s << "\n";

    string currWord = "";
    string smallest = "";
    int minSize = INT_MAX;
    string largest = "";
    int maxSize = -1;

    // O(n)
    for(int i = 0; i < s; i++) {
        if(line[i] != ' ') {
            currWord += line[i];
        }
        else {
            if((int) currWord.size() < minSize) {
                minSize = currWord.size();
                smallest = currWord;
                // cout << "smallest found" << endl;
            }
            if((int) currWord.size() > maxSize) {
                maxSize = currWord.size();
                largest = currWord;
                // cout << "largest found" << endl;
            }
            currWord = "";
        }
    }

    if(currWord != "") {
        if(currWord.size() < minSize) {
            minSize = currWord.size();
            smallest = currWord;
        }
        if(currWord.size() > maxSize) {
            maxSize = currWord.size();
            largest = currWord;
        }
        currWord = "";
    }

    cout << "Smallest word : " << smallest << "\n";
    cout << "Largest Word : " << largest << "\n";

    return 0;
}