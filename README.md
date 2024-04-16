# Problem Statement:
    This is program that simulates the Monty Hall Problem with variable number of doors and
    host opening variable number of doors.The output of the code is the simulated 
    probabilities of winnning in sticking to intial choice and switching to another door.

# Code Description:

The program runs simulations for Montyhall problem with n doors out of which only k are revealed. 
In every simulation when host offers to pick a door out of n we always choose door 1 (since all has equal
probability at start) to make things easy we assume that is the first door. Now the host assigns the car to a      random door. If the assigned door is car door then the player wins in a non switching strategy. After that the       
host reveals the first k non car door( this doesn't include the door which the player chooses that is door 1)        
the order in which the host reveals doesn't matter. So we choose to reveal first k non car doors (from door 2       
to door n). Now if the player switches from door 0 to some door among n-k-1 , if the car is present in that door     
the player wins in switching strategy. The code will  run for many simulations and find the percentage for each      
strategy given the car door.
    

# How to run the code:
    The code takes 3 command line arguments, Total number of doors, 
    doors revealed by host and the number of iterations to simulate.

# Compiling and Running the code
```
    g++ -o Montyhall_simulator Montyhall_simulator.cpp
    ./Montyhall_simulator num_doors num_doors_opened_by_host num_simulations
```
# Results of the program
    The prababilities produced by the program is closely matches to the actual probabilities for
    sufficient iterations for given n and k. The mathematical formuala is derived in Montyhall.pdf
