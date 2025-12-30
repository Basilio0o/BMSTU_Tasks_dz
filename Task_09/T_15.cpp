#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void BubbleSort(vector<int>& arr, int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SelectionSort(vector<int>& arr, int n)
{
	int temp = 0, max = arr[0], max_index = 0, last = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if(arr[j] > max)
			{
				max = arr[j];
				max_index = j;
			}
			last = j;
		}
		temp = arr[max_index];
		arr[max_index] = arr[last];
		arr[last] = temp;
		max = arr[0];
		max_index = 0;
	}
}

void InsertionSort(vector<int>& arr, int n)
{
    int sorted = 0;
    int temp = 0;
    for (int i = 1; i < n; i++){
        sorted = i;
        while((sorted >= 1) && (arr[sorted-1] > arr[sorted])){
            temp = arr[sorted];
            arr[sorted] = arr[sorted-1];
            arr[sorted-1] = temp;
            sorted--;
        }
    }
}

void ShellSort(vector<int>& arr, int n)
{
	int temp = 0;
    for (int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
        	int sorted = i;
        	while ((sorted >= gap) && (arr[sorted - gap] > arr[sorted])){
				temp = arr[sorted];
				arr[sorted] = arr[sorted - gap];
				arr[sorted - gap] = temp;
				sorted -= gap;
			}
        }
    }
}

void PartOfQuickSort(vector<int>& arr, int left, int right)
{
    int l = left, r = right;
    int temp = 0;
    int pivot = arr[(left + right)/2];
    while(l<=r){
        while(arr[l] < pivot) l++;
        while(arr[r] > pivot) r--;
        if(l<=r){
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
    if (left < l-1) PartOfQuickSort(arr, left, l-1);
    if (l < right) PartOfQuickSort(arr, l, right);
}

void QuickSort(vector<int>& arr, int n){
    PartOfQuickSort(arr, 0, n - 1);
}

void Merge(vector<int>& arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++) L[i] = arr[l + i];
	for(int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	while (j < n2)
	{
		arr[k++] = R[j++];
	}

}

void PartOfMergeSort(vector<int>& arr, int l, int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;

		PartOfMergeSort(arr, l, m);
		PartOfMergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}

void MergeSort(vector<int>& arr, int n)
{
	PartOfMergeSort(arr, 0, n - 1);
}

void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp = 0;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr, n, largest);
    }
}

void HeapSort(vector<int>& arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

	int temp = 0;

	for (int i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n = 100000;
    using namespace std::chrono;
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-2000, 2000);
    for(int i = 0; i < n; i++) arr[i] = dist(gen);
    vector<int> temp = arr;

    auto start = high_resolution_clock::now();
    BubbleSort(temp, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "BubbleSort отсортировала массив за: " << duration.count() << " мс\n";
    temp = arr;

    start = high_resolution_clock::now();
	SelectionSort(temp, n);
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	cout << "SelectionSort отсортировала массив за: " << duration.count() << " мс\n";
	temp = arr;

    start = high_resolution_clock::now();
	InsertionSort(temp, n);
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	cout << "InsertionSort отсортировала массив за: " << duration.count() << " мс\n";
	temp = arr;

    start = high_resolution_clock::now();
	ShellSort(temp, n);
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	cout << "ShellSort отсортировала массив за: " << duration.count() << " мс\n";
	temp = arr;

    start = high_resolution_clock::now();
	QuickSort(temp, n);
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	cout << "QuickSort отсортировала массив за: " << duration.count() << " мс\n";
	temp = arr;

    start = high_resolution_clock::now();
	MergeSort(temp, n);
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	cout << "MergeSort отсортировала массив за: " << duration.count() << " мс\n";
	temp = arr;

    start = high_resolution_clock::now();
	HeapSort(temp, n);
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	cout << "HeapSort отсортировала массив за: " << duration.count() << " мс\n";
	temp = arr;

    start = high_resolution_clock::now();
	sort(temp.begin(), temp.end());
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	cout << "Sort отсортировала массив за: " << duration.count() << " мс\n";
	temp = arr;

    return 0;
}

