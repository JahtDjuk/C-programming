// file: /data/courses/ece_1111/labs/current/lab_09/myprog.cc
//

// local include files
//
#include "myprog.h"

// function: main
//
// This is a program that allocates an array of float pointers,
// computes sine values to populate the array, and writes the data to a
// binary file.
//
// Usage: myprog.exe <file.txt> num_channels(long) time(float)
// frequency(float) sample frequency(float) phase(float)
// amplitude(float)
//
int main(int argc, const char** argv) {

  // Argc check
  //
  if(argc != 8)
    {
      fprintf(stdout,"Incorrect number of command line arguements\n");
      exit(2);
    }


  // Open file in write mode
  //
  FILE* output = fopen(argv[1],"w");

  // Number of Channels (argv[2])
  //
  long num_channels = atoi(argv[2]) ;
  
  // Number of Seconds of data (argv[3])
  //
  float time = atof(argv[3]);
 
  // Frequency (argv[4])
  //
  float freq = atof(argv[4]);

  // Sample frequency (argv[5])
  //
  float fsamp = atof(argv[5]);

  // Phase angle in degrees (argv[6])
  //
  float phase = atof(argv[6]);

  // Amplitude (argv[7])
  //
  float amp = atof(argv[7]);

  // Number of Samples
  //
  long N = (long)round(fsamp * time);

  // Float** array initialization
  //
  float* array[num_channels];

  // Allocate function call
  //
  ece1111_allocate(array,num_channels,N);
  
  // Sinewave function call (will be in a loop)
  //
  for (int i = 0; i < num_channels; i++)
    {
      ece_1111_compute_sin(array[i],N,freq,fsamp,amp,phase);
    }

  // Write to file using looping structure
  //
  for(int i = 0; i < num_channels; i++) // iterate over the rows
    {
      for(int j = 0; j < N; j++)
	{
	  if(fwrite(&array[i][j],sizeof(float),1,output) != 1)
	    {
	      fprintf(stdout,"Write error");
	    }
	}
    }
 // Deallocate function call
 //
 ece1111_deallocate(array,num_channels,N); 

  // Close the file
  //
 fclose(output);
 
  return(0);
}


