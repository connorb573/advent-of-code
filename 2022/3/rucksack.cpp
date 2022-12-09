#include <fstream> 
#include <string> 
#include <iostream>

int main(){

    std::ifstream file("input.txt");
    std::string line;
    int priorityTotal = 0;

    while(std::getline(file, line)){
        //Split string in half to get both compartment's contents
        std::string compartment1 = line.substr(0, line.length()/2);
        std::string compartment2 = line.substr(line.length()/2);

        //Check for repeating character
        char repeatingChar;
        for(int i = 0; i<compartment1.length(); i++){
            if(compartment2.find(compartment1.at(i)) != std::string::npos){
                repeatingChar = compartment1.at(i);
            }
        }

        //Get priority of repeating character.
        int priority = 0;
        //Lowercase first
        if(islower(repeatingChar)){
            priority = repeatingChar - 'a' + 1;
        }
        else {
            priority = repeatingChar - 'A' + 27;
        }

        priorityTotal += priority;
    }

    std::cout << priorityTotal << std::endl;
}