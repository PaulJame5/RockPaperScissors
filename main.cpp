/// Rock Paper Scissors Game (For when you're bored in work like me when I made this).
/// Made by Paul O'Callaghan
/// CC0 Public Domain License since it's simply the power chords of music in terms of programming.
/// Known Issues: No validator for checking if user input a char but maybe you can make this as an exercise for yourself

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>


void compareSelection(int t_playerChoice, int t_cpuChoice);
void displaySelection(int t_playerChoice, int t_cpuChoice);

// Global constant values to be used, we'll make them static as we only need one of each to exist
const static int ROCK = 0, PAPER = 1, SCISSORS = 2;
int main()
{
    
    // Declare values and variables to be used in game
    bool exitGame = false;
    int cpuChoice = 0, playerChoice = 0, playerScore = 0, cpuScore = 0; 
    
    // Set up seed of the game
    std::time_t result = std::time(nullptr);
    srand(result);
    
    // Game loop
    while(!exitGame)
    {
        std::cout <<"Make your choice(Rock: 0, Paper: 1, Scissors: 2): ";
        std::cin >> playerChoice;
        std::cout << "" << std::endl;
        
        // Catch invalid choices
        while(playerChoice != 0 && playerChoice != 1 && playerChoice != 2)
        {
            std::cout<< "ERROR: Invalid choice!!!" << std::endl;
            std::cout <<"Make your choice(Rock: 0, Paper: 1, Scissors: 2): ";
            std::cin >> playerChoice;
            std::cout << "" << std::endl;
        } // End invalid choice
        
        // cpu choice decided by seed time
        cpuChoice = rand() % 3;
        
        displaySelection(playerChoice,cpuChoice);
        compareSelection(playerChoice,cpuChoice);
        
        // Continue playing
        int keepPlaying;
        std::cout <<"Would you like to keep playing? (0: NO, 1: YES): ";
        std::cin >> keepPlaying;
        std::cout << "" << std::endl;
        
        // ERROR Catch
        while(keepPlaying != 0 && keepPlaying != 1)
        {
            std::cout<< "ERROR: Invalid choice!!!" << std::endl;
            std::cout <<"Would you like to keep playing? (0: NO, 1: YES): ";
            std::cin >> keepPlaying;
            std::cout << "" << std::endl;
        }
        
        if(keepPlaying == 0)
        {
            exitGame = true;
        }
        // End continue playing
        
    } // end game loop
  std::cout << "Thanks for playing!!!";
  //system("pause");
}


void displaySelection(int t_playerChoice, int t_cpuChoice)
{
    // Player Choice Display
    std::cout << "Player choice: ";
    
    if(t_playerChoice == SCISSORS)
    {
        std::cout << "SCISSORS, ";
    }
    else if(t_playerChoice == ROCK)
    {
        std::cout << "ROCK, ";
    }
    else
    {
        std::cout << "PAPER, ";
    } // End Player Choice Display
    
    // CPU Choice Display
    std::cout << "CPU choice: ";
    
    if(t_cpuChoice == SCISSORS)
    {
        std::cout << "SCISSORS, ";
    }
    else if(t_cpuChoice == ROCK)
    {
        std::cout << "ROCK, ";
    }
    else
    {
        std::cout << "PAPER, ";
    } // End CPU Choice Display
    
} // End displaySelection() 

void compareSelection(int t_playerChoice, int t_cpuChoice)
{
    if(t_playerChoice != t_cpuChoice)
    {
        if(t_playerChoice == ROCK)
        {
            if(t_cpuChoice == SCISSORS)
            {
                std::cout << "You win!!!" << std::endl;  
            }
            else
            {
                std::cout << "You Lose!!!" << std::endl;   
            }
        } // end player choice ROCK
        
        else if(t_playerChoice == PAPER)
        {
            if(t_cpuChoice == ROCK)
            {
                std::cout << "You win!!!" << std::endl;  
            }
            else
            {
                std::cout << "You Lose!!!" << std::endl;   
            }
        } // End player choice PAPER
        
        // Player Choice is SCISSORS
        else
        {
            if(t_cpuChoice == PAPER)
            {
                std::cout << "You win!!!" << std::endl; 
            }
            else
            {
                std::cout << "You Lose!!!" << std::endl;  
            }
            
        } // End player choice PAPER
    } // end choices not the same
    
    else // Draw
    {
        std::cout << "It's a draw!!!" << std::endl;
    }
    
} // End compare compareSelection()


