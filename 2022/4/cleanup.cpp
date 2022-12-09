#include <iostream> 
#include <fstream>
#include <string>

int main(){

std::ifstream infile("input.txt");

    std::string ranges, range1, range2;
    int overlap_count = 0;
    
    while(infile >> ranges){
        range1 = ranges.substr(0, ranges.find(","));
        range2 = ranges.substr(ranges.find(",") + 1);

        //Calculate the values for each range. 
        auto range1_min = stoi(range1.substr(0, range1.find("-")));
        auto range1_max = stoi(range1.substr(range1.find("-") + 1));

        auto range2_min = stoi(range2.substr(0, range2.find("-")));
        auto range2_max = stoi(range2.substr(range2.find("-") + 1));


        if(range1_min >= range2_min && range1_min <= range2_max){
            overlap_count++;
        }
        else if(range1_max >= range2_min && range1_max <= range2_max){
            overlap_count++;
        }
        else if(range2_min >= range1_min && range2_min <= range1_max) {
            overlap_count++;
        }
        else if(range2_max >= range1_min && range2_max <= range1_max) {
            overlap_count++;
        }
    }

    std::cout << overlap_count << std::endl;

}
