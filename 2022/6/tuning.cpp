#include <iostream> 
#include <fstream>
#include <streambuf>
#include <deque>
#include <set>

using namespace std;

int main() {
    ifstream infile("input.txt");
    string str((istreambuf_iterator<char>(infile)), 
    istreambuf_iterator<char>());

    deque<char> possible_combo {};
    set<char> seen_chars {};
    int count = 0;

    for(char& c : str){
        //First we check, is the char already in our set of seen chars?
        if(seen_chars.find(c) != seen_chars.end()){
            //If it is, we remove every character from the deque and set up to our current char.
            while(possible_combo.front() != c){
                seen_chars.erase(possible_combo.front());
                possible_combo.pop_front();
            }

            //Then we move the current (repeated) char to the front of the queue.
            possible_combo.push_back(possible_combo.front());
            possible_combo.pop_front();
        
            count++;
        }
        else {
            //If not, we add. 
            possible_combo.push_back(c);
            seen_chars.insert(c);
            count++;
            if(possible_combo.size() == 4){
                break;
            }
        }
    }

    cout << count << endl;
}