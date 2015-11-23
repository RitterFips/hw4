#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//Unterprogramm um die Rohdaten in ein Array zu lesen
void read(double* const, const int, const string);
//Unterprogramm um die gefilterten Daten in eine Datei zu schreiben
void write(double* const, const int, const string);
//Unterprogramm um die Daten zu filtern
void filter(double* const, const int);

int main(void){
  const int N = 237;//Anzahl der Daten
  const int M = 10;//Anzahl der Filterschritte
  const string filename = "noisy.txt";//Name der Quelldatei
  const string filename2 = "result.txt";//Name der Zieldatei
  double* A = new double[N];//erzeuge ein flexibles Array zum einlesen der Daten
  
  read(A, N, filename);
  filter(A,N);
  write(A, N, filename2);
  
  delete[] A;
  
  return 0;
}

void read(double* const A, const int N, const string fname){
 ifstream in(fname.c_str());
 for(int i = 0; i < N; i++){
  in >> A[i]; 
 }
 in.close();
}

void filter(double* const A, const int N){
  double b = A[0];//Zwischenspeicher beim überschreiben der Daten
  double A0 = (A[0]+A[1]+A[N-1])/3;//Mittelung des ersten Dateneintrages
  double AN = (A[0]+A[N-1]+A[N-1])/3;//Mittelung des letzen Dateneintrages
  for(int i = 1; i < N-1; i++){//Mittelung der übrigen Dateneinträge
  double a = A[i];//Zwischenspeicher beim überschreiben der Daten
  A[i] =(b+A[i]+A[i+1])/3;
  b = a;
  }
  A[0] = A0;
  A[N-1] = AN;
}

void write(double* const A, const int N, const string fname){
 ofstream out(fname.c_str());
 for(int i = 0; i < N; i++){
  out << A[i] << endl; 
 }
 out.close();
}