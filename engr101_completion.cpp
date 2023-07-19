#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
 
using namespace std; 
 
int main(){ 
   WavSound sound1; // helper 
   int sample_rate = 41400; // samples per second  
   double duration = 5.0; // length of my sound
   int n_samples = (int)(sample_rate * duration); // number of samples is sample rate times duration
   int* waveform = new int[n_samples]; // creates the array 
   int A = 20000; // amplitude (loudness)
   double dt = 1.0/(double)(sample_rate);
   double freq = 1000.0;
   
   for (int i_sample = 0; i_sample < n_samples ; i_sample++){  // making an i_sample, if it's less than n_samples, then plus one
	   for (int slot = 0; slot<(duration*2); slot++) // making a time slot, if slot is less than 10 secs, then plus one
	   if (i_sample % sample_rate == 0){ // if i_sample fits into sample_rate with no remainder,
		   freq = 1000.0;} // then freq is set to 1000
		   else if (i_sample % (sample_rate/2)==0){ // if i_sample fits into half of sample_rate with no remainder,
			freq = 2000.0;} // then freq is set to 2000
       waveform[i_sample]= A*sin(2.0*M_PI*freq*i_sample*dt);
   } 

   sound1.MakeWavFromInt("tone5.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav 
   delete(waveform); 
   return 0; 
} 
