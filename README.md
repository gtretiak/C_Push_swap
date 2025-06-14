# C_Push_swap
Optimized sorting algorithm using two stacks.

## Project Overview
Push_swap is an algorithmic project. The task is to sort a set of integers, using just two stacks and a very limited set of operations, with a focus on achieving the minimal number of actions possible. 
To demonstrates algorithmic efficiency, understanding of sorting complexities, and optimization skills are required.

## Project Purpose & Objectives
The goal is to implement as efficient as possible sorting algorithm in the given constraints (e.g. two stacks with limited operations).

## Key Concepts & Functionality
The project uses two stacks (a and b):

Initially, stack a contains a random set of unique integers (positive and negative)
Stack b starts empty
All numbers should be sorted in stack a in ascending order

## Only Available Operations
sa: Swap the top two elements of stack a
sb: Swap the top two elements of stack b
ss: Perform sa and sb simultaneously
pa: Push the top element from stack b to stack a
pb: Push the top element from stack a to stack b
ra: Rotate stack a (shift all elements up by 1, first becomes last)
rb: Rotate stack b (shift all elements up by 1)
rr: Perform ra and rb simultaneously
rra: Reverse rotate stack a (shift all elements down by 1, last becomes first)
rrb: Reverse rotate stack b
rrr: Perform rra and rrb simultaneously

## Program Components
1. push_swap program: Takes a list of integers as arguments and outputs the optimal sequence of operations needed to sort them in ascending order.
2. checker program (bonus): Validates if a sequence of sorting operations correctly sorts a given stack of integers.

## Algorithmic Approaches
Depending on the number of elements different strategy might be optimal
1. Small Set Sorting
For 2-3 elements: Direct comparison and swapping
For 5 elements: Simple algorithms with predefined operation sequences
2. Large Set Sorting
Here might be used many sorting algorithms:
Chunk Sorting: Divide the numbers into chunks based on their values, then methodically transfer and sort them
Radix Sort Adaptation: Implement a binary radix sort
Quicksort Adaptation: Adapt quicksort to work with the constraints of the two stacks
I deployed Turk algorithm. Before actually making decision on what step to perform next, it calculates "the cost" of every possible number to be moved from one stack to another.
By "the cost" number of operations is meant.
So, I used double linked lists containing neccessary information.

## How to test it?
1. Clone the repository, cd
2. Clone the Libft repository https://github.com/gtretiak/C_libft
3. Compile with 'make' and 'make_bonus' commands
4. Run the program with unsorted numeric arguments
5. Run the program alongside the checker (or checker_linux, but first run chmod u+x checker_linux)
6. Run bash another_test.sh (but first run chmod u+x another_test.sh)
7. cd push_swap_tester and run bash basic_test.sh or bash loop.sh with the stack size and the loop times
8. Run Visualizer: https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker
## Usage Examples

### Basic Usage
./push_swap 3 1 2
sa
ra

### Piping with the Checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK

### Counting Operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6

### Real-World Applications
1. Financial Systems: Optimizing transaction processing algorithms where efficiency is critical - similar to how push_swap requires finding the most efficient sequence of operations.
2. Database Query Optimization: The techniques used to minimize operations in push_swap parallel the optimization of database queries to improve performance.
3. Network Packet Routing: Efficience of moving and sorting data between different locations helpful for the same operations in network with minimal overhead.
4. Memory Management Systems: The constraint-based problem-solving approach is similar to optimizing memory allocation and garbage collection in low-level systems.
5. Logistics and Supply Chain Management: The algorithmic thinking required to efficiently sort with minimal operations is directly applicable to optimizing product movement in warehouses or transportation systems.

### Performance Benchmarks
A successful push_swap implementation should achieve:
Sorting 100 random integers in fewer than 700 operations (on average)
Sorting 500 random integers in fewer than 5500 operations (on average)

### Conclusion
The Push_swap project goes beyond simply implementing a sorting algorithm - it's about efficiency optimization under constraints. It requires understanding algorithmic complexity aka Big O notation, and clear vision of abstractive concepts in a practical context. Transferable skills: algorithmic thinking, optimization capability, low-level programming proficiency, problem-solving under constraints, and attention to performance details.
