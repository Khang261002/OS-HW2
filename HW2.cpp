#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

class Process {
private:
    int id;
    std::vector<int> lottery_tickets;

public:
    Process(int id) : id(id) {};

    void add_ticket(int ticket) {
        lottery_tickets.push_back(ticket);
    }

    // Check if Process has the ticket input
    bool check_ticket(int ticket_to_check) const {
        for (int const & ticket : lottery_tickets) {
            if (ticket == ticket_to_check) {
                return true;
            }
        }
        return false;
    }

    // Print Process with all tickets
    void print() const {
        std::cout << "Process " << id << ": ";
        for (int const & ticket : lottery_tickets) {
            std::cout << ticket << ", ";
        }
        std::cout << std::endl;
    }

    // Print the Process when winning ticket
    void winner_print() const {
        std::cout << "Process " << id << " wins the lottery!" << std::endl;
    }
};

class Scheduler {
private:
    std::vector<Process> processes;
    std::vector<int> tickets;               // To store all the tickets numbers

public:
    // Add processes to the scheduler list
    void add_process(Process p) {
        processes.push_back(p);
    }

    // Allocate ticket to process
    bool allocate_ticket(Process &p, int ticket) {
        if (std::find(tickets.begin(), tickets.end(), ticket) != tickets.end()) {
            std::cout << "A process has this ticket number already! Please try again." << std::endl;
            return false;
        } else {
            tickets.push_back(ticket);
            p.add_ticket(ticket);
            return true;
        }
    }

    // Print all Processes with all tickets to see to see
    void print_processes() const {
        for (Process const & p : processes) {
            p.print();
        }
    }

    // Find and print the winner process
    void select_winner() const {
        int n = tickets.size();

        // This is to generate random number to choose a random index for tickets
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distribution(0, n - 1);
        int idx = distribution(gen);

        int winning_ticket = tickets[idx];
        std::cout << "The winning ticket for this time is " << winning_ticket << std::endl;
        for (Process const & p : processes) {
            if (p.check_ticket(winning_ticket)) {
                p.winner_print();
            }
        }
    }
};

int main() {
    Scheduler scheduler;
    int num;

    std::cout << "Enter the number of processes: ";
    std::cin >> num;

    // Loop to enter all the processes
    for (int i = 0; i < num; i++) {
        int num_ticket;
        Process p(i + 1);

        std::cout << "Number of tickets for Process " << i + 1 << ": ";
        std::cin >> num_ticket;

        // Loop to enter all the tickets fo the process
        for (int j = 0; j < num_ticket; j++) {
            int ticket;

            while (true) {
                std::cout << "Ticket: ";
                std::cin >> ticket;
                if (scheduler.allocate_ticket(p, ticket)) {
                    // Break out of the loop if the ticket is valid
                    break;
                }
            }
        }
        // Add the process to the scheduler after allocating tickets
        scheduler.add_process(p);
    }

    scheduler.print_processes();
    scheduler.select_winner();

    return 0;
}
