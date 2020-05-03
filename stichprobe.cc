
#include <iostream>
#include <fstream>
#include <cmath>

double mittelwert (double result, int j){
  
  double mitt = 0;
  
  mitt = result / j;

  return mitt;

}

double varianz (double result,double x, int j) {
  
  double var = 0;
  double mitt = 0;
  
  mitt = result / j;
  var = (x - mitt) * (x - mitt) / j;

  return var;

}

double standardabweichung (double result, double x, int j){

  double d = 0; 
  double var = 0;
  double mitt = 0;
  
  mitt = result / j;
  var = (x - mitt) * (x - mitt) / j;
  
  d = sqrt(var);

  return d;
}

int main() {

std::ifstream eindatei("datensumme.txt");

double x = 0;
double result = 0;
double de = 0 ;
int j = 0;


for (int i=0; i < 234; i++){
  
  eindatei >> x;
  result += x;
  
  j++;

}

std::cout << "Mittelwert: " << mittelwert (result,j) << std::endl;
std::cout << "Varianz: " << varianz (result,x,j) << std::endl;
std::cout << "Standardabweichung: " <<  standardabweichung (result,x,j) << std::endl;

eindatei.close();

}