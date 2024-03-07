# OS-HW2

## Objective

This program implements a basic lottery scheduling algorithm, simulating the assignment of lottery tickets to processes and randomly selecting a ticket to determine the next process to run.

## Implementation

The program consists of two classes:

1. **Process Class:**
   - Represents a process with a unique identifier, several lottery tickets, and any other relevant attributes.
   - Provides methods to add lottery tickets, check if the process has a specific ticket, and print process details.

2. **Scheduler Class:**
   - Manages the lottery scheduling algorithm.
   - Allows adding processes, allocating lottery tickets, and selecting the next process to run.
   - Uses a random number generator to simulate the lottery ticket selection process.

## Usage

1. **Compile the Code:**
```g++ HW2.cpp -o HW2```

2. **Run the Program:**
```./HW2```

3. **Follow the Prompts:**
   - Enter the number of processes.
   - For each process, enter the number of tickets and individual ticket numbers.

4. **Output:**
   - The program will print the details of all processes and announce the winner based on the randomly selected ticket.

## Grading Criteria

1. **Functionality:**
   - Proper implementation of the Process class with a unique identifier and lottery ticket management.
   - Correct allocation and management of lottery tickets for each process.
   - Implementation of the Scheduler class with necessary methods.
   - Proper handling of the lottery scheduling algorithm using a random number generator.

2. **Script Submission:**
   - Ensure proper submission of the script via the designated platform.
   - Provide adequate documentation or comments explaining the implementation choices.

## Author

Khang Duong

