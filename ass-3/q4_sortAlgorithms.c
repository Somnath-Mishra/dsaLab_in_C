#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("Pass %d: ", i);
        printArray(arr, n);
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
                min_ind = j;
        }
        int temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

void bubbleSort(int arr[], int n)
{
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
        if (!swapped)
            break;
    }
}

int hoarePartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void qSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = hoarePartition(arr, low, high);
        qSort(arr, low, p);
        qSort(arr, p + 1, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];
    }
    for (int i = 0; i < n2; i++)
        right[i] = a[mid + 1 + i];
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
        printf("Pass %d: ", n - i);
        printArray(arr, n);
    }
}

int main()
{
    int  n;
    char choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\nMenu:\n");
        printf("a. Insertion Sort\n");
        printf("b. Selection Sort\n");
        printf("c. Bubble Sort\n");
        printf("d. Quick Sort\n");
        printf("e. Merge Sort\n");
        printf("f. Heap Sort\n");
        printf("g. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        int sortedArr[n];

        switch (choice)
        {
        case 'a':
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            insertionSort(sortedArr, n);
            break;
        case 'b':
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            selectionSort(sortedArr, n);
            break;
        case 'c':
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            bubbleSort(sortedArr, n);
            break;
        case 'd':
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            qSort(sortedArr, 0, n - 1);
            break;
        case 'e':
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            mergeSort(sortedArr, 0, n - 1);
            break;
        case 'f':
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            heapSort(sortedArr, n);
            break;
        case 'g':
            printf("Exiting Program!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            continue; 
        }
        printf("Sorted array: ");
        printArray(sortedArr, n);
    }

    return 0;
}
