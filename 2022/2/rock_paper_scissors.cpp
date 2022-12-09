#include <fstream>
#include <iostream>

int main(){

    int yourScore = 0; 

    char i, j; 

    std::ifstream infile("input.txt");

    while(infile >> i >> j){
        switch(i) {
            case 'A':
            //Opponent has Rock
            if(j == 'X'){
                //You need to Lose - choose scissors.
                yourScore += 3; 
            }
            else if (j == 'Y'){
                //You need to draw - choose rock 
                yourScore += 4;
            }
            else if(j == 'Z'){
                //You need to win - choose paper
                yourScore += 8;
            }
            break;

            case 'B':
            //Opponent has Paper
            if(j == 'X'){
                //You need to Lose - choose rock.
                yourScore += 1;
            }
            else if (j == 'Y'){
                //You need to draw - choose paper.
                yourScore += 5;
            }
            else if(j == 'Z'){
                //You need to win - choose scissors
                yourScore += 9;
            }
            break;

            case 'C':
            //Opponent has Scissors
            if(j == 'X'){
                //You need to Lose - choose paper 
                yourScore += 2;
            }
            else if (j == 'Y'){
                //You need to draw - choose scissors 
                yourScore += 6;
            }
            else if(j == 'Z'){
                //You need to Win - choose Rock 
                yourScore += 7;
            }
            break;
        }

    }
    
    std::cout << yourScore << std::endl;

}