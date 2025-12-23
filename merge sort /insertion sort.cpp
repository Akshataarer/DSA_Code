#include <iostream>
using namespace std;

int main()
{
    int n;
    float yield[20];

    cout << "Enter number of days: ";
    cin >> n;

    cout << "Enter mushroom yield for each day (kg):\n";
    for (int i = 0; i < n; i++)
        cin >> yield[i];

    // Insertion Sort
    for (int i = 1; i < n; i++)
    {
        float key = yield[i];
        int j = i - 1;

        while (j >= 0 && yield[j] > key)
        {
            yield[j + 1] = yield[j];
            j--;
        }
        yield[j + 1] = key;
    }

    cout << "\nSorted Mushroom Yield (Low to High):\n";
    for (int i = 0; i < n; i++)
        cout << yield[i] << " kg\t";

    return 0;
}
