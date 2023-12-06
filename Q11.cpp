#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

// Structure to store information for each thread
struct ThreadInfo {
  vector<int>& numbers;
  int start_index;
  int end_index;
  int sum;
};

// Thread function to calculate the sum of a sublist
void* sum_sublist(void* arg) {
  ThreadInfo* info = (ThreadInfo*)arg;
  int local_sum = 0;
  for (int i = info->start_index; i <= info->end_index; ++i) {
    local_sum += info->numbers[i];
  }
  info->sum = local_sum;
  return nullptr;
}

int main() {
  // Get the number of numbers
  int n;
  cout << "Enter the number of numbers: ";
  cin >> n;

  // Get the list of numbers
  vector<int> numbers(n);
  cout << "Enter the numbers: ";
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  // Create two threads
  pthread_t thread1, thread2;

  // Calculate the size of each sublist
  int sublist_size = n / 2;

  // Create thread information for each thread
  ThreadInfo info1 = {numbers, 0, sublist_size - 1, 0};
  ThreadInfo info2 = {numbers, sublist_size, n - 1, 0};

  // Create the threads
  pthread_create(&thread1, nullptr, sum_sublist, &info1);
  pthread_create(&thread2, nullptr, sum_sublist, &info2);

  // Wait for both threads to finish
  pthread_join(thread1, nullptr);
  pthread_join(thread2, nullptr);

  // Add the local sums of each thread to get the total sum
  int total_sum = info1.sum + info2.sum;

  // Print the total sum
  cout << "The sum of the numbers is: " << total_sum << endl;

  return 0;
}
