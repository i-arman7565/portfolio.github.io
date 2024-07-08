#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> // Include this header to use INT_MAX & INT_MIN
#include <time.h>
#include <math.h>


// Structure to represent a page
typedef struct {
    int page_number;
    int reference_bit;  // Used in LRU algorithms
    int frequency;      // Used in LFU and MFU algorithms
    int timestamp;      // Used for FIFO
} Page;

typedef struct {
    int totalFaults;
    int leastFaults;
} PageFaultData;


// Function to initialize a page
Page initializePage(int page_number) {
    Page page;
    page.page_number = page_number;
    page.reference_bit = 0;
    page.frequency = 0;
    page.timestamp = -1;
    return page;
}

// Function to find the index of a page in the frame array
int findPageIndex(Page frames[], int page_number, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i].page_number == page_number) {
            return i;
        }
    }
    return -1;
}

// Function to display the current state of frames
void displayFrames(Page frames[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i].page_number != -1) {
            printf("%d ", frames[i].page_number);
        } else {
            printf("-- ");
        }
    }
    printf("\n");
}



// Function to perform FIFO page replacement
int fifoPageReplacement(int reference_string[], int num_references, int num_frames) {
    printf("FIFO Implementation :\n");
    Page frames[num_frames];

    // Initialize frames with sentinel value
    for (int i = 0; i < num_frames; i++) {
        frames[i] = initializePage(-1);
    }

    int page_faults = 0;
    int frame_index = 0;

    for (int i = 0; i < num_references; i++) {
        int page_number = reference_string[i];

        if (findPageIndex(frames, page_number, num_frames) == -1) {
            if (frame_index < num_frames) {
                frames[frame_index] = initializePage(page_number);
                frame_index++;
            } else {
                int replace_index = page_faults % num_frames;
                frames[replace_index] = initializePage(page_number);
            }
            page_faults++;
        }

        displayFrames(frames, num_frames);
    }

    printf("FIFO Page Faults: %d\n", page_faults);
    return page_faults;
}

// Function to perform Optimal page replacement
int optimalPageReplacement(int reference_string[], int num_references, int num_frames) {
    printf("Optimal Implementation :\n");
    Page frames[num_frames];

    // Initialize frames with sentinel value
    for (int i = 0; i < num_frames; i++) {
        frames[i] = initializePage(-1);
    }

    int page_faults = 0;

    for (int i = 0; i < num_references; i++) {
        int page_number = reference_string[i];

        if (findPageIndex(frames, page_number, num_frames) == -1) {
            // Page is not found in the current frames
            int max_distance = -1;
            int replace_index = -1;

            // First, check if there is an empty frame to use
            for (int j = 0; j < num_frames; j++) {
                if (frames[j].page_number == -1) {
                    replace_index = j;
                    break;
                }
            }

            // If no empty frame, then find the page to replace based on optimal algorithm
            if (replace_index == -1) {
                for (int j = 0; j < num_frames; j++) {
                    int future_distance = 0;
                    int k = i + 1;

                    while (k < num_references && reference_string[k] != frames[j].page_number) {
                        future_distance++;
                        k++;
                    }

                    if (future_distance > max_distance) {
                        max_distance = future_distance;
                        replace_index = j;
                    }
                }
            }

            // Replace the page
            frames[replace_index] = initializePage(page_number);
            page_faults++;
        }

        // Display the current state of frames after every page reference
        displayFrames(frames, num_frames);
    }

    printf("Optimal Page Faults: %d\n", page_faults);
    return page_faults;
}

// Function to perform LRU page replacement using Additional-Reference-Bits Algorithm
int lruAdditionalReferenceBits(int reference_string[], int num_references, int num_frames) {
    printf("LRU (Additional-Reference-Bits) Implementation :\n");
    Page frames[num_frames];
    int page_faults = 0;
    unsigned char reference_counter = 0; // Use an 8-bit counter for the reference bits

    // Initialize frames with sentinel value
    for (int i = 0; i < num_frames; i++) {
        frames[i] = initializePage(-1);
    }

    for (int i = 0; i < num_references; i++) {
        int page_number = reference_string[i];
        int page_index = findPageIndex(frames, page_number, num_frames);

        if (page_index == -1) { // Page fault
            int replace_index = -1;
            int min_reference_bit = 0xFF; // Start with the max possible value for an 8-bit number

            // Find the frame with the minimum reference bit
            for (int j = 0; j < num_frames; j++) {
                if (frames[j].page_number == -1 || frames[j].reference_bit < min_reference_bit) {
                    min_reference_bit = frames[j].reference_bit;
                    replace_index = j;
                }
            }

            frames[replace_index] = initializePage(page_number);
            frames[replace_index].reference_bit = (1 << 7); // Set the MSB as it's the most recently used
            page_faults++;
        } else { // Page hit
            frames[page_index].reference_bit |= (1 << 7); // Set the MSB as it's the most recently used
        }

        // Age the reference bits for all frames
        for (int j = 0; j < num_frames; j++) {
            frames[j].reference_bit >>= 1;
        }

        displayFrames(frames, num_frames);
    }

    printf("LRU (Additional-Reference-Bits) Page Faults: %d\n", page_faults);
    return page_faults;
}

// Function to perform LRU page replacement using Second Chance Algorithm
int lruSecondChance(int reference_string[], int num_references, int num_frames) {
    printf("LRU (Second Chance) Implementation :\n");
    Page frames[num_frames];

    // Initialize frames with sentinel value
    for (int i = 0; i < num_frames; i++) {
        frames[i] = initializePage(-1);
    }

    int page_faults = 0;
    int pointer = 0; // Added pointer to keep track of the next frame to consider for replacement

    for (int i = 0; i < num_references; i++) {
        int page_number = reference_string[i];
        int page_index = findPageIndex(frames, page_number, num_frames);

        if (page_index == -1) { // Page fault
            while (frames[pointer].reference_bit != 0) {
                frames[pointer].reference_bit = 0;
                pointer = (pointer + 1) % num_frames;
            }
            frames[pointer] = initializePage(page_number);
            pointer = (pointer + 1) % num_frames; // Move to the next frame for the next replacement
            page_faults++;
        } else {
            frames[page_index].reference_bit = 1; // Page hit, set reference bit
        }

        displayFrames(frames, num_frames);
    }

    printf("LRU (Second Chance) Page Faults: %d\n", page_faults);
    return page_faults;
}

// Function to perform LRU page replacement using Enhanced Second Chance Algorithm
int lruEnhancedSecondChance(int reference_string[], int num_references, int num_frames) {
    printf("LRU (Enhanced Second Chance) Implementation :\n");
    Page frames[num_frames];

    // Initialize frames with sentinel value
    for (int i = 0; i < num_frames; i++) {
        frames[i] = initializePage(-1);
    }

    int page_faults = 0;
    int pointer = 0; // Added pointer to keep track of the next frame to consider for replacement

    for (int i = 0; i < num_references; i++) {
        int page_number = reference_string[i];
        int page_index = findPageIndex(frames, page_number, num_frames);

        if (page_index == -1) { // Page fault
            while (true) {
                if (frames[pointer].reference_bit == 0) {
                    frames[pointer] = initializePage(page_number);
                    page_faults++;
                    pointer = (pointer + 1) % num_frames; // Move to the next frame for the next replacement
                    break;
                }
                frames[pointer].reference_bit >>= 1;
                pointer = (pointer + 1) % num_frames;
            }
        } else {
            frames[page_index].reference_bit = 0x80; // Page hit, set MSB of reference bit
        }

        displayFrames(frames, num_frames);
    }

    printf("LRU (Enhanced Second Chance) Page Faults: %d\n", page_faults);
    return page_faults;
}

// Function to perform LFU page replacement
int lfuPageReplacement(int reference_string[], int num_references, int num_frames) {
    printf("LFU Implementation :\n");
    Page frames[num_frames];
    int page_faults = 0;
    int current_time = 0; // Use this as a timestamp for LFU tie-breaking

    // Initialize frames with sentinel value and set frequency and timestamp to -1
    for (int i = 0; i < num_frames; i++) {
        frames[i] = initializePage(-1);
        frames[i].frequency = 0;
        frames[i].timestamp = -1;
    }

    for (int i = 0; i < num_references; i++) {
        int page_number = reference_string[i];

        int page_index = findPageIndex(frames, page_number, num_frames);
        if (page_index == -1) { // Page fault
            int replace_index = -1;
            int min_frequency = INT_MAX;
            int oldest_time = INT_MAX;

            // Find the frame with the minimum frequency or the oldest frame in case of a tie
            for (int j = 0; j < num_frames; j++) {
                if (frames[j].frequency < min_frequency ||
                    (frames[j].frequency == min_frequency && frames[j].timestamp < oldest_time)) {
                    min_frequency = frames[j].frequency;
                    oldest_time = frames[j].timestamp;
                    replace_index = j;
                }
            }

            frames[replace_index] = initializePage(page_number);
            frames[replace_index].frequency = 1; // Initialize the frequency for the new page
            frames[replace_index].timestamp = current_time; // Set the timestamp for the new page
            page_faults++;
        } else {
            frames[page_index].frequency++; // Increment the frequency for the page
        }

        current_time++; // Increment the timestamp after each reference

        displayFrames(frames, num_frames);
    }

    printf("LFU Page Faults: %d\n", page_faults);
    return page_faults;
}

int mfuPageReplacement(int reference_string[], int num_references, int num_frames) {
    printf("MFU Implementation :\n");
    Page frames[num_frames];
    int page_faults = 0;
    int current_time = 0;

    // Initialize the frames
    for (int i = 0; i < num_frames; i++) {
        frames[i] = initializePage(-1);
    }

    for (int i = 0; i < num_references; i++) {
        int page_number = reference_string[i];

        // Find the page index, if it exists
        int page_index = findPageIndex(frames, page_number, num_frames);

        if (page_index == -1) { // Page fault
            int replace_index = -1;
            int max_frequency = -1;
            int oldest_time = INT_MAX;

            // First, check if there is any empty frame
            for (int j = 0; j < num_frames; j++) {
                if (frames[j].page_number == -1) {
                    replace_index = j;
                    break; // If an empty frame is found, break the loop
                }
            }

            // If no empty frame is found, then find the frame with the highest frequency to replace
            if (replace_index == -1) {
                for (int j = 0; j < num_frames; j++) {
                    if (frames[j].frequency > max_frequency ||
                        (frames[j].frequency == max_frequency && frames[j].timestamp < oldest_time)) {
                        max_frequency = frames[j].frequency;
                        oldest_time = frames[j].timestamp;
                        replace_index = j;
                    }
                }
            }

            // Replace the page in the chosen frame
            frames[replace_index] = initializePage(page_number);
            frames[replace_index].frequency = 1; // Reset frequency for the new page
            frames[replace_index].timestamp = current_time; // Set timestamp for the new page
            page_faults++;
        } else { // Page hit
            frames[page_index].frequency++; // Increment frequency, do not update timestamp
        }

        // Increment time after processing each page reference
        current_time++;

        displayFrames(frames, num_frames);
    }

    // Display total page faults after processing all references
    printf("Total MFU Page Faults: %d\n", page_faults);
    return page_faults;
}


// Function to compare page fault counts for different page replacement algorithms
PageFaultData comparePageFaults(int reference_string[], int num_references, int num_frames) {
    // Arrays to store page fault counts and corresponding algorithm names
    int page_faults[7] = {0};
    int total_page_faults = 0;
    int least_page_faults = INT_MAX;
    const char *algorithm_names[] = {
        "FIFO", "Optimal", "LRU (ARB)", "LRU (SC)", "LRU (ESC)", "LFU", "MFU"
    };

    // Test FIFO Page Replacement
    page_faults[0] = fifoPageReplacement(reference_string, num_references, num_frames);
    printf("\n");

    // Test Optimal Page Replacement
    page_faults[1] = optimalPageReplacement(reference_string, num_references, num_frames);
    printf("\n");

    // Test LRU Page Replacement (Additional-Reference-Bits Algorithm)
    page_faults[2] = lruAdditionalReferenceBits(reference_string, num_references, num_frames);
    printf("\n");

    // Test LRU Page Replacement (Second Chance Algorithm)
    page_faults[3] = lruSecondChance(reference_string, num_references, num_frames);
    printf("\n");

    // Test LRU Page Replacement (Enhanced Second Chance Algorithm)
    page_faults[4] = lruEnhancedSecondChance(reference_string, num_references, num_frames);
    printf("\n");

    // Test LFU Page Replacement
    page_faults[5] = lfuPageReplacement(reference_string, num_references, num_frames);
    printf("\n");

    // Test MFU Page Replacement
    page_faults[6] = mfuPageReplacement(reference_string, num_references, num_frames);

    // Display page fault counts and algorithm names in ascending order
    printf("\nComparison of Page Faults (Ascending Order):\n");

    bool allEqual = true;  // Flag to check if all page fault counts are equal
    int first_page_fault_count = page_faults[0];

    // Bubble sort the arrays in ascending order
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6 - i; j++) {
            if (page_faults[j] > page_faults[j + 1]) {
                // Swap page fault counts
                int temp_faults = page_faults[j];
                page_faults[j] = page_faults[j + 1];
                page_faults[j + 1] = temp_faults;

                // Swap algorithm names
                const char *temp_name = algorithm_names[j];
                algorithm_names[j] = algorithm_names[j + 1];
                algorithm_names[j + 1] = temp_name;

                allEqual = false;  // Different page fault counts found
            }
        }
    }

    // Print all page faults
    for (int i = 0; i < 7; i++) {
            printf("%s Page Faults: %d\n", algorithm_names[i], page_faults[i]);
        }

    // Calculate total page faults and find the least page faults
    for (int i = 0; i < 7; i++) {
        total_page_faults += page_faults[i];
        if (page_faults[i] < least_page_faults) {
            least_page_faults = page_faults[i];
        }
    }

    // Print the sorted results or a message if all counts are equal
    if (allEqual) {
        printf("All algorithms result with the same number of page faults: %d\n\n", first_page_fault_count);
    } else {
        int least_page_faults = page_faults[0];
        printf("\nAlgorithms with the Least Page Faults as %d are : \n", least_page_faults);
        for (int i = 0; i < 7; i++) {
            if (page_faults[i] == least_page_faults) {
                printf("%s \n", algorithm_names[i]);
            } 
        }
        printf("\n\n");
    }

    // Set the values in the PageFaultData struct
    PageFaultData data;
    data.totalFaults = total_page_faults;
    data.leastFaults = least_page_faults;

    // Return the total number of page faults
    return data;
}

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void calculateStatistics(int *data, int num_tests, double *average, double *median, double *std_dev) {
    double sum = 0.0;
    for (int i = 0; i < num_tests; i++) {
        sum += data[i];
    }
    *average = sum / num_tests;

    // Sort the array to calculate median
    qsort(data, num_tests, sizeof(int), compareIntegers);
    if (num_tests % 2 == 0) {
        *median = (data[num_tests / 2 - 1] + data[num_tests / 2]) / 2.0;
    } else {
        *median = data[num_tests / 2];
    }

    double var_sum = 0.0;
    for (int i = 0; i < num_tests; i++) {
        var_sum += pow(data[i] - *average, 2);
    }
    *std_dev = sqrt(var_sum / num_tests);
}

// Function to calculate the sum of an array
int sumOfArray(int *data, int num_tests) {
    int sum = 0;
    for (int i = 0; i < num_tests; i++) {
        sum += data[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num_page_numbers>\n", argv[0]);
        return 1;
    }

    int num_references = atoi(argv[1]); // Convert the argument to an integer

    // Check if the number of references is within a valid range
    if (num_references < 1 || num_references > 100) {
        printf("Invalid number of references. Please enter a number between 1 and 100.\n");
        return 1;
    }

    int test_frame_sizes[] = {5, 10, 15, 20, 25}; // Test categories for the number of frames
    int num_tests_per_category = 5; // Number of tests per category
    int num_categories = sizeof(test_frame_sizes) / sizeof(test_frame_sizes[0]);

    // Allocate memory for reference strings for the smallest frame size
    int **reference_strings = malloc(num_tests_per_category * sizeof(int*));
    for (int i = 0; i < num_tests_per_category; i++) {
        reference_strings[i] = malloc(num_references * sizeof(int));
    }

    int **total_fault_results = malloc(num_categories * sizeof(int*));
    int **least_fault_results = malloc(num_categories * sizeof(int*));
    for (int i = 0; i < num_categories; i++) {
        total_fault_results[i] = malloc(num_tests_per_category * sizeof(int));
        least_fault_results[i] = malloc(num_tests_per_category * sizeof(int));
    }

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Open a file to write the reference strings
    FILE *file = fopen("reference_strings.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Generate reference strings only for the first (smallest) frame size
    for (int t = 0; t < num_tests_per_category; t++) {
        for (int i = 0; i < num_references; i++) {
            reference_strings[t][i] = rand() % 10; // Assuming page numbers range from 0 to 9
            fprintf(file, "%d ", reference_strings[t][i]); // Write to file
        }
        fprintf(file, "\n\n\n"); // Newline at the end of each reference string
    }
    fclose(file); // Close the file after writing

    // Now, reopen the file to read the reference strings back into the array
    file = fopen("reference_strings.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Read the reference strings from the file into the reference_strings array
    for (int t = 0; t < num_tests_per_category; t++) {
        for (int i = 0; i < num_references; i++) {
            fscanf(file, "%d", &reference_strings[t][i]);
        }
    }
    fclose(file); // Close the file after reading

    // Loop over each category of frame sizes and store results
    for (int c = 0; c < num_categories; c++) {
        int num_frames = test_frame_sizes[c];

        // Run tests for each category
        for (int t = 0; t < num_tests_per_category; t++) {
            printf("Testing with %d frames...\n", num_frames);
            printf("Number of page numbers in a reference string: %d\n", num_references);

            // Use the generated reference string
            int *reference_string = reference_strings[t];

            // Initialize frames with sentinel value
            Page frames[num_frames];
            for (int i = 0; i < num_frames; i++) {
                frames[i] = initializePage(-1);
            }

            // Display the generated reference string
            printf("Generated Reference String: ");
            for (int i = 0; i < num_references; i++) {
                printf("%d ", reference_string[i]);
            }
            printf("\n\n");

            // Compare page fault counts for different page replacement algorithms
            PageFaultData result = comparePageFaults(reference_strings[t], num_references, num_frames);
            total_fault_results[c][t] = result.totalFaults;
            least_fault_results[c][t] = result.leastFaults;
            printf("*************************************************************************\n\n");
        }
        printf("\n");
        printf("==========================================================================\n");
    }

    printf("\n");

    // Free the dynamically allocated reference strings
    for (int i = 0; i < num_tests_per_category; i++) {
        free(reference_strings[i]);
    }
    free(reference_strings);

    // Calculate statistics and display the results
    printf("\nStatistics for Total Page Faults\n");
    printf("Frame Size | Total Faults | Average | Median | Standard Deviation\n");
    printf("---------------------------------------------------------------\n");
    for (int c = 0; c < num_categories; c++) {
        double average, median, std_dev;
        int total_faults = sumOfArray(total_fault_results[c], num_tests_per_category);
        calculateStatistics(total_fault_results[c], num_tests_per_category, &average, &median, &std_dev);
        printf("%10d | %12d | %7.2f | %6.2f | %17.2f\n", test_frame_sizes[c], total_faults, average, median, std_dev);
    }

    printf("\nStatistics for Least Page Faults\n");
    printf("Frame Size | Least Faults | Average | Median | Standard Deviation\n");
    printf("----------------------------------------------------------------\n");
    for (int c = 0; c < num_categories; c++) {
        double average, median, std_dev;
        int least_faults = sumOfArray(least_fault_results[c], num_tests_per_category) / num_tests_per_category; // Assuming you want the average least faults
        calculateStatistics(least_fault_results[c], num_tests_per_category, &average, &median, &std_dev);
        printf("%10d | %12d | %7.2f | %6.2f | %17.2f\n", test_frame_sizes[c], least_faults, average, median, std_dev);
    }

    // Free the results arrays
    for (int i = 0; i < num_categories; i++) {
        free(total_fault_results[i]);  // Free each sub-array in total_fault_results
        free(least_fault_results[i]);  // Free each sub-array in least_fault_results
    }
    free(total_fault_results);  // Finally, free the main array for total_fault_results
    free(least_fault_results);  // Finally, free the main array for least_fault_results
    
    return 0;
}