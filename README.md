# Problem Statement:
    This is program that simulates the Monty Hall Problem with variable number of doors and host opening variable number of doors.The output of the code is the simulated probabilities of winnning in sticking to intial choice and switching to another door.

# How to run the code:
    The code takes 3 command line arguments, Total number of doors, doors revealed by host and the number of iterations to simulate.

# Compiling and Running the code
```
    g++ -o Montyhall_simulator Montyhall_simulator.cpp
    ./Montyhall_simulator num_doors num_doors_opened_by_host num_simulations
