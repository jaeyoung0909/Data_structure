#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> ex;
    vector<int>::iterator it;
    it = ex.begin();
    ex.push_back(1);
    ex.push_back(2);
    ex.push_back(3);
    ex[0] = 4;
    it = ex.begin();
    it = ex.insert(it,10);
	cout << ex.at(3) << endl;
}

