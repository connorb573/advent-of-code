#include <fstream> 
#include <string> 
#include <iostream>

int main(){

    std::ifstream file("input.txt");
    std::string line;
    int priorityTotal = 0;

    while(std::getline(file, line)){
        //Split string in half to get both compartment's contents
        std::string line2;
        std::string line3;

        std::getline(file, line2);
        std::getline(file, line3);

        //Check for repeating character
        char repeatingChar;
        for(int i = 0; i<line.length(); i++){
            if(line2.find(line.at(i)) != std::string::npos && line3.find(line.at(i)) != std::string::npos){
                repeatingChar = line.at(i);
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