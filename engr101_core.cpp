#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
 
using namespace std; 
 
int main(){ 
   WavSound sound1; // helper 
   int sample_rate = 41400; // samples per second  
   double duration = 5.0;
   int n_samples = (int)(sample_rate * duration); 
   int* waveform = new int[n_samples]; // creates the array 
   int A = 20000;
   double dt = 1.0/(double)(sample_rate);
   double freq = 1000.0;
   
   for ( int i_sample = 0; i_sample < n_samples ; i_sample++){  
       waveform[i_sample]= A*sin(2.0*M_PI*freq*i_sample*dt);
   } 
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   sound1.MakeWavFromInt("tone6.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav 
   delete(waveform); 
   return 0; 
} 
