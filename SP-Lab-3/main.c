#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float * createArray(char* inputFile, int* xp, int* yp); 
void display(float array[], int count, int totalSize);
void swapNumbers(float* addr1, float* addr2);
void sortNumbers(float array[], int n);
double mean(float array[], int size);
float median(float array[], int size);
double stddev(float array[], int size);

// The below function loads in the data from the data file and creates the DB
float * createArray(char* inputFile, int* dataCount, int* arraySize)
{
    int allocatedSize = 20;
    // Allocating memory dynamically using malloc()
    float* dataset = (float*)malloc(allocatedSize * sizeof(float));     

    // checking if memory is allocated
    if (dataset == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    
    // Reading the data from the input file
    FILE *filePointer;
    filePointer = fopen(inputFile, "r");
    int counter = 0;
    float data = 0;
    char buffer[100];   
    while (fgets(buffer, sizeof(buffer), filePointer))  
    {
        data = strtof(buffer, NULL);
        dataset[counter] = data;
        counter++; 
        if (counter == allocatedSize)
        {
            //  allocating twice the size of current
            allocatedSize = allocatedSize*2; 
            float* temp = (float*)malloc(allocatedSize * sizeof(float)); 
            if (temp == NULL) { 
                printf("Memory not allocated.\n"); 
                exit(0); 
            }

/*Copying values from old to new 
               and  free the space allocated*/ 
            memcpy(temp, dataset, allocatedSize * sizeof(float));
            free(dataset);
            dataset = (float*)malloc(allocatedSize * sizeof(float)); 
            memcpy(dataset, temp, allocatedSize * sizeof(float));
            free(temp);
        }
    }

//  if at end of file closing the file
    if (feof(filePointer))
    {
        fclose(filePointer);
    } 
    *dataCount = counter;
    *arraySize = allocatedSize;

    return dataset;
}

// The below function is used to print out the DB        
void display (float array[], int usedCapacity, int totalSize)
{
    printf("\nResults:\n");
    printf("-----------\n");
    printf("Num Values:\t\t%d\n", usedCapacity);
    printf("mean\t\t\t%lf\n", mean(array, usedCapacity));
    printf("median:\t\t\t%f\n", median(array, usedCapacity));
    printf("stddev:\t\t\t%lf\n", stddev(array, usedCapacity));
    printf("Unused Array Capacity:\t%d\n\n", (totalSize-usedCapacity));
}

// swap function 
void swapNumbers(float* num1Address, float* num2Address) 
{ 
    float temp = *num1Address; 
    *num1Address = *num2Address; 
    *num2Address = temp; 
} 
  
// Functipn to sort (insertion sort) numbers of the array
void sortNumbers(float values[], int size) 
{ 
    for(int i=0; i<size; i++){
 
    for(int j=i-1; j<size; j--){
 
        if(values[j+1]<values[j]){
            swapNumbers(&values[j+1], &values[j]);
        }else{
            break;
        }
 
    }
    }

     
} 

//  Function to calculate mean

double mean(float values[], int size)
{
 double sum, average =0;

  for( int i=0; i<size; i++){
    sum+= values[i];
  }

  average = sum/size;
  return average;
}

//  Function to calculate median

float median(float sortedValues[], int size)
{
  float median=0;

  if ( size % 2 == 0){
   median = (sortedValues[size/2] + sortedValues[size/2+1])/2.0 ;
  }else{
   median = sortedValues[size/2 + 1];
  }

  return median;
}

//  Function to calculate standard deviation from the formula given  stddev = sqrt((sum((xi - mean)^2))/N)

double stddev(float values[], int size)
{
  double stddev = 0;
  double meanValue = mean( values, size);
  double sum= 0;

  for(int i=0; i<size; i++){
   sum+= (values[i] - meanValue) * (values[i] - meanValue);
  }

  stddev = sqrt(sum/ size);
  return stddev;

}


// Main function
int main(int argc, char *argv[])
{
        int arraySize = 20;
        int count = 0;
        float* dataset = createArray(argv[1], &count, &arraySize);
        sortNumbers(dataset, count);
        display(dataset, count, arraySize);      
}