#include <iostream>
using namespace std;

// Bottom-Up Max Heap construction for gym equipment usage
void buildMaxHeap(int usage[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        int k = i;
        int value = usage[k];
        bool isHeap = false;

        while (!isHeap && 2 * k <= n) {
            int j = 2 * k;   // left child

            // Check right child for higher usage
            if (j < n && usage[j] < usage[j + 1]) {
                j = j + 1;   // choose equipment with higher usage
            }

            // Heap condition
            if (value >= usage[j]) {
                isHeap = true;
            } else {
                usage[k] = usage[j];
                k = j;
            }
        }
        usage[k] = value;
    }
}

int main() {
    // Equipment usage count (index starts from 1)
    // Example: Treadmill, Cycle, Bench Press, Lat Pulldown, Rowing Machine
    int equipmentUsage[20] = {0, 45, 30, 60, 25, 40};
    int equipmentCount = 5;

    buildMaxHeap(equipmentUsage, equipmentCount);

    cout << "Gym Equipment Usage Max Heap (Most used at top):\n";
    for (int i = 1; i <= equipmentCount; i++) {
        cout << equipmentUsage[i] << " ";
    }

    cout << "\n\nMost frequently used equipment count: "
         << equipmentUsage[1];

    return 0;
}
