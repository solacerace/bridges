#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

/*

Problem Statement:
There are n people standing in line to buy show tickets.Due to high demand, the venue sells tickets according to the following rules:

The person at the head of the line can buy exactly one ticket and must then exit the line.
if a person needs to purchase additional tickets,they must re-enter the end of the line and wait to be sold their next ticket(assume exit and re-entry takes zero seconds).
Each ticket sale takes exactly one second.
We express initial line of n people as an array, tickets = [tickets0, tickets1 ... ticketsN-1], where ticketsi denotes the number of tickets person i wishes to buy. If Jesse is standing at a position p in this line, find out how much time it would take for him to buy all tickets. Complete the waiting time function in the editor below. It has two parameters:

An array, tickets, of n positive integers describing initial sequence of people standing in line. Each ticketsi describes number of tickets that a person waiting at initial place.
An integer p, denoting Jesse's position in tickets.

Sample Input 5 2 6 3 4 5 2 Sample Output 12 
Sample Input 4 5 5 2 3 3 Sample Output 11



Solution:
https://stackoverflow.com/questions/43950000/hackerrank-buying-show-tickets-optimization

*/


int waitingTime(const vector<int> arr, int p)
{

    int N = arr.size();
    int total = 0;
    // 
    for (int i = 0; i < N; ++i)
    {
        total += min(arr[i], arr[p] - int(i > p));
    }

    return total;
}


int main(int argc, char* argv[])
{
    std::vector<int> tickets{ 2, 6, 3, 4, 5 };
    for (int p = 0, n = tickets.size(); p < n; ++p) {
        std::cout << "tickets{ 2, 6, 3, 4, 5 }, p = " << p << std::endl;
        int t = waitingTime(tickets, p);
        std::cout << "computed t:  " << t << std::endl;
    }

    return 0;
}

