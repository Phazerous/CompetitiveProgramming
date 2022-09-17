#include "split.h"

vector<string> split(string str, string delimeter) {
    vector<string> sublines;
    size_t pos;

    while ((pos = str.find(delimeter)) != string::npos) {
        sublines.push_back(str.substr(0, pos));
        str.erase(0, pos + delimeter.length());
    }

    sublines.push_back(str);

    return sublines;
}