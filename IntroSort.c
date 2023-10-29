void InsertionSort(int* data, int count) {
  for (int i = 1; i < count; ++i)
  {
    int j = i;

    while (j > 0)
    {
      if (data[j - 1] > data[j])
      {
        data[j - 1] ^= data[j];
        data[j] ^= data[j - 1];
        data[j - 1] ^= data[j];

        --j;
      }
      else
      {
        break;
      }
    }
  }
}

void MaxHeapify(int* data, int heapSize, int index) {
  int left = (index + 1) * 2 - 1;
  int right = (index + 1) * 2;
  int largest = 0;

  if (left < heapSize && data[left] > data[index])
    largest = left;
  else
    largest = index;

  if (right < heapSize && data[right] > data[largest])
    largest = right;

  if (largest != index)
  {
    int temp = data[index];
    data[index] = data[largest];
    data[largest] = temp;

    MaxHeapify(data, heapSize, largest);
  }
}

void HeapSort(int* data, int count) {
  int heapSize = count;

  for (int p = (heapSize - 1) / 2; p >= 0; --p)
    MaxHeapify(data, heapSize, p);

  for (int i = count - 1; i > 0; --i)
  {
    int temp = data[i];
    data[i] = data[0];
    data[0] = temp;

    --heapSize;
    MaxHeapify(data, heapSize, 0);
  }
}

int Partition(int* data, int left, int right) {
  int pivot = data[right];
  int temp;
  int i = left;

  for (int j = left; j < right; ++j)
  {
    if (data[j] <= pivot)
    {
      temp = data[j];
      data[j] = data[i];
      data[i] = temp;
      i++;
    }
  }

  data[right] = data[i];
  data[i] = pivot;

  return i;
}

void QuickSortRecursive(int* data, int left, int right) {
  if (left < right)
  {
    int q = Partition(data, left, right);
    QuickSortRecursive(data, left, q - 1);
    QuickSortRecursive(data, q + 1, right);
  }
}

void IntroSort(int* data, int count) {
  int partitionSize = Partition(data, 0, count - 1);

  if (partitionSize < 16)
  {
    InsertionSort(data, count);
  }
  else if (partitionSize >(2 * log(count)))
  {
    HeapSort(data, count);
  }
  else
  {
    QuickSortRecursive(data, 0, count - 1);
  }
}


int main() {
  int data[] = {5, 2, 9, 3, 6, 1, 8, 7, 4};
  int count = sizeof(data) / sizeof(data[0]);

  printf("Array original: ");
  for (int i = 0; i < count; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");
  IntroSort(data, count);

  printf("Array ordenado: ");
  for (int i = 0; i < count; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");

  return 0;
}