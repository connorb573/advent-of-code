#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

int main() {
    std::ifstream infile("input.txt");

    std::string line;
    std::vector<std::deque<char>> queues{};
    int numberOfQueues = 9;


    for(int i = 0; i < numberOfQueues; i++){
            queues.push_back(std::deque<char> {});
    }

    while(std::getline(infile, line)){
        if(line[1] == '1'){
            break;
        }

        int queueCount = 0;
        int charCount = 0;

        while(charCount < line.size()){

            if(line[charCount] == '['){
                queues.at(queueCount).push_back(line[charCount + 1]);
            }
            
            charCount += 4;
            queueCount++;
        }
    }    


    //Process movement - retaining order.
    while(std::getline(infile, line)){
        if(line[0] == 'm'){
            int amount = stoi(line.substr(4, line.find('f')));
            int from = stoi(line.substr(line.find('f') + 4, line.find('t')));
            int to = stoi(line.substr(line.find('t') + 2));

            std::deque<char> chunk_moved {};
            for(int i = 0; i < amount; i++){
                char val = queues.at(from - 1).front();
                queues.at(from - 1).pop_front();
                chunk_moved.push_back(val);
            }

            std::cout << "chunk" << std::endl;
            for(char x : chunk_moved){
                std::cout << x << std::endl;
            }

            for(int i = 0; i < amount; i++){
                queues.at(to -1).push_front(chunk_moved.back());
                chunk_moved.pop_back();
            }
        }
    }

    //Get top values
    std::string final_tops = "";

    for(int i = 0; i < queues.size(); i ++){
        final_tops += queues.at(i).front();
    }

    for(int i = 0; i<numberOfQueues; i++){
        std::cout << "Queue " << i << std::endl;
        for(int j = 0; j < queues.at(i).size(); j++){
            std::cout << queues.at(i).at(j) << std::endl;
        }
    }

    std::cout << final_tops << std::endl;

}