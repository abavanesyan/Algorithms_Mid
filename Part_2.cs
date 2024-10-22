void merging(int[] arr, int left, int middle, int right) {  
    int size_1 = middle - left + 1; 
    int size_2 = right - middle;
    int[] Left_p = new int[size_1];
    int[] Right_p = new int[size_2];
    int i, j;
    for (i = 0; i < size_1; i++) 
    {
        Left_p[i] = arr[left + i];
    }
    for (j = 0; j < size_2; j++)
    {
        Right_p[j] = arr[middle + 1 + j];
    }
    i = 0; 
    j = 0;
    int k = left;
    while (i < size_1 && j < size_2) 
    { 
        if (Left_p[i] <= Right_p[j]) 
        { 
            arr[k] = Left_p[i]; 
            i++; 
        } else 
        { 
            arr[k] = Right_p[j];
            j++; 
        } 
        k++; 
    }
    while (i < size_1) 
    { 
        arr[k] = Left_p[i];
        i++;
        k++; 
    }
    while (j < size_2) 
    {
        arr[k] = Right_p[j];
        j++;
        k++; 
    } 
}
void mergeSort(int[] arr, int left, int right) { 
    if (left < right) 
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle); 
        mergeSort(arr, middle + 1, right); 
        merging(arr, left, middle, right); 
    } 
} 
void printArray(int[] arr)
{
    for (int i = 0; i < arr.Length; i++)
    {
        Console.Write(arr[i] + " ");
    }
}

int[] arr = { 10, 4, 9, 5, 8, 6, 1, 2 }; 
Console.WriteLine("At first array is"); 
printArray(arr); 
mergeSort(arr, 0, arr.Length - 1); 
Console.WriteLine();
Console.WriteLine("Sorted array is"); 
printArray(arr);