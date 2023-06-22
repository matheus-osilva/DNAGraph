#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int lowerSize(string one, string two);
bool match(string one, string two, int edgeParam);
bool match2(string one, string two, int edgeParam);
string removeSuffixIfMatched(string one, const string& two, int edgeParam);
void createfile(vector<string> pieces, int edgeParam, int mode);