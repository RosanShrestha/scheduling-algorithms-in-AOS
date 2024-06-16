#include <stdio.h>
// Structure to represent a process
typedef struct {
int processId;
int burstTime;
int arrivalTime;
int waitingTime;
int turnaroundTime;
} Process;
// Function to sort processes by arrival time
void sortProcessesByArrival(Process processes[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
Process temp = processes[j];
processes[j] = processes[j + 1];
processes[j + 1] = temp;
}
}
}
}
// Function to calculate waiting and turnaround times
void calculateTimes(Process processes[], int n) {
int currentTime = 0;

for (int i = 0; i < n; i++) {
if (currentTime < processes[i].arrivalTime)
currentTime = processes[i].arrivalTime;

processes[i].waitingTime = currentTime - processes[i].arrivalTime;

processes[i].turnaroundTime = processes[i].waitingTime +
processes[i].burstTime;
currentTime += processes[i].burstTime;
}
}
// Function to print the processes along with all details
void printProcessDetails(Process processes[], int n) {
double totalWaitingTime = 0, totalTurnaroundTime = 0;
printf("\nProcess ID | Arrival Time | Burst Time | Waiting Time |Turnaround Time\n");
printf("-------------------------------------------------------------------------\n");
for (int i = 0; i < n; i++) {
printf(" %d | %d | %d | %d | %d\n",
processes[i].processId, processes[i].arrivalTime,
processes[i].burstTime,
processes[i].waitingTime, processes[i].turnaroundTime);

totalWaitingTime += processes[i].waitingTime;
totalTurnaroundTime += processes[i].turnaroundTime;
}
printf("-------------------------------------------------------------------------\n");
printf("Average Waiting Time = %.2f\n", totalWaitingTime / n);
printf("Average Turnaround Time = %.2f\n", totalTurnaroundTime / n);
}
// Function to print the Gantt chart
void printGanttChart(Process processes[], int n) {
int currentTime = 0;
printf("\nGantt Chart:\n");
printf("------------\n");

for (int i = 0; i < n; i++) {
if (currentTime < processes[i].arrivalTime)
currentTime = processes[i].arrivalTime;
printf("| P%d (%d to %d) ", processes[i].processId, currentTime,
currentTime + processes[i].burstTime);
currentTime += processes[i].burstTime;
}
printf("|\n");
}
int main() {
int n;
printf("Enter the number of processes: ");
scanf("%d", &n);
Process processes[n];
// Input processes data
printf("Enter Process ID, Arrival Time and Burst Time for each process:\n");
for (int i = 0; i < n; i++) {
printf("Process %d: ", i + 1);
scanf("%d %d %d", &processes[i].processId, &processes[i].arrivalTime,
&processes[i].burstTime);
}
// Sort processes by arrival time
sortProcessesByArrival(processes, n);
// Calculate waiting time and turnaround time
calculateTimes(processes, n);

// Print process details
printProcessDetails(processes, n);
// Print the Gantt chart
printGanttChart(processes, n);
return 0;
}
