#include <iostream> // input-output library 
#include <fstream>
#include <math.h>  // library for sin function 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 

using namespace std;

double* read_file_array(string file_name, int &count){
	
	string line;
	ifstream file(file_name);
	while (getline(file, line)){
		count++;
	}
	file.close();
	cout<<"Number of lines/freqencies in file : "<<count<<endl;



	double* frequencies = new double[count];
	int repeat = 0;
	string line2;
	ifstream file2(file_name);
	while (getline(file2, line2)){
		frequencies[repeat] = stod(line2); //puts notes in array
		repeat++;
		}
		file2.close();
		return frequencies;
}


int main(){ 
	WavSound sound1;
	int count = 0;
	double *frequencies = read_file_array("odetojoy.txt", count);

	double play_freq = 0.0;
	int counter = 0;
	double duration = 10.0; 
	
	int A = 4000; // amplitude (loudness)
	int sample_rate = 41400;
	int n_samples = sample_rate * duration;
	double dt = 1.0/(double)(sample_rate);
	int* tune = new int[n_samples]; // creates the array, length being all the samples

	for (int i_sample = 0; i_sample < n_samples ; i_sample++){ 
		if (i_sample % (sample_rate / 3) == 0){
			play_freq = frequencies[counter] * 3;
			counter = counter + 1;
		}

       tune[i_sample]= A*sin(2.0*M_PI*play_freq*i_sample*dt);
   }
    sound1.MakeWavFromInt("challenge3.wav", sample_rate, tune, n_samples); //file name can be changed but keep extension .wav 
    delete(tune); 
    return 0; 

}

