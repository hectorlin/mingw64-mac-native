#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <chrono>

// Global variables for thread communication
int counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function
void* thread_function(void* arg) {
    int thread_id = *(int*)arg;

    for (int i = 0; i < 5; i++) {
        // Lock the mutex before accessing shared variable
        pthread_mutex_lock(&mutex);

        counter++;
        std::cout << "Thread " << thread_id << ": Counter = " << counter
                  << " (iteration " << (i + 1) << ")" << std::endl;

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Sleep for a short time
        usleep(100000); // 100ms
    }

    return nullptr;
}

int main() {
    std::cout << "Hello, MinGW64 with pthread!" << std::endl;
    std::cout << "This is a multi-threaded C++ program using pthread." << std::endl;

    // Get user input
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    if (!name.empty()) {
        std::cout << "Nice to meet you, " << name << "!" << std::endl;
    }

    // Create multiple threads
    const int num_threads = 3;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    std::cout << "\nCreating " << num_threads << " threads..." << std::endl;

    // Record start time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], nullptr, thread_function, &thread_ids[i]) != 0) {
            std::cerr << "Error creating thread " << (i + 1) << std::endl;
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], nullptr) != 0) {
            std::cerr << "Error joining thread " << (i + 1) << std::endl;
            return 1;
        }
    }

    // Record end time
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << "\nAll threads completed!" << std::endl;
    std::cout << "Final counter value: " << counter << std::endl;
    std::cout << "Total execution time: " << duration.count() << " ms" << std::endl;

    // Clean up mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
