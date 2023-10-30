// file: lab_09/myfuncts_00.cc
//
// a simple function that doesn't do much
//

// system include files
//
#include "myprog.h"


//----------------------------------------------------------------->
// function: ece1111_allocate
//
//
// Description: This function will allocate memory for a float** array
// this array will contain the samples of a sinewive.
//
// arguments:
//  float** array: will constain one array for each channel
//  long num_channels: Sets the number of channels
//        -> this will set the number of float* arrays in array
//  long N: The number of samples
//        -> this will set the number of elements in a channel
//
// return: None
//
bool ece1111_allocate(float** array, long num_channels, long N) {
 /home/tun88825/useful_code_1111/
  // Allocate memory for each channel
  //
  for(int i = 0; i < num_channels; i++)
    {
    array[i] = new float[N];
      // Check for allocation
      if(array[i] == NULL)
      {
	fprintf(stdout,"Allocation failed for row %d.\n",i);
	return(false);
      }
    }

  // Success
  //
  fprintf(stdout,"Allocation was a success\n");

  // exit gracefully
  //
  return (true);
}


//----------------------------------------------------------------->
// function: ece1111_deallocate
//
//
// Description: This function will deallocate a float** array
// 
//
// arguments:
//  float** array:Array to be deallocated
//  long num_channels: Basically the number of float*'s to be freed
//  long N: the number of elements per float* to be freed
//
// return: None
//
bool ece1111_deallocate(float** array, long num_channels, long N) {

  // Deallocate rows of array(each row is it's own pointer)
  //
  for(int i = 0; i < num_channels; i++)
    {
      // deallocate each row of array
      delete[] array[i];

      // set each row to NULL
      array[i] = NULL;
    }
  // exit gracefully
  //
  return (true);
}
  

//----------------------------------------------------------------->
// function: ece_1111_compute_sin
//
//
// Description: This function computes a sinewave
// 
//
// arguments:
//  float* array: Channel to contain the samples
//  long N: the number of samples
//  float freq: The frequency of the sinewave
//  float fsamp: Sample Frequency
//  float amp: amplitude of the sinewave
//  float phase: phase angle of sin wave
//
// return: array
//
bool ece_1111_compute_sin(float* array,long N,float freq,float fsamp,float amp,float phase) {

  // sine calculation to implement
  // y = A * sin((2*pi*f)t + phase)
  // A -> amplitude
  // (2*pi*f) -> angular frequency
  // t -> time

  // Convert phase from degrees to radians
  //
  float phase_rad = phase*(M_PI/(float)180);
  
  // Looping strucuture to compute sine values
  //

  for (int i = 0; i < N; i++) 
    {
      // calculate time stamp for each sample      
      float t_samp = (float)i/fsamp;

      // Calculate each value and add it to the channel(float* array)
      array[i] = amp * sin((2*M_PI*freq)*t_samp + phase);
      
    }
  // exit gracefully
  //
  return (true);
}

