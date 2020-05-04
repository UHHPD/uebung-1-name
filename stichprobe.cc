#include <iostream>
#include <fstream>
#include <cmath>

double mittelwert (double result, int j){
  
  double mitt = 0;
  
  mitt = result / j;

  return mitt;

}

double varianz (double result, int j) {
  
  std::ifstream eindatei("datensumme.txt");
  double var = 0;
  double mitt = 0;
  double x = 0;
  
  mitt = result / j;
  
  for (double i = 0; i < 234; i++){
    
    eindatei >> x;
    var += ((x - mitt)*(x - mitt)) / j;
    
  }
  
  eindatei.close();
  
  return var;

}

double standardabweichung (double result, int j){

  std::ifstream eindatei("datensumme.txt");
  
  double d = 0; 
  double var = 0;
  double mitt = 0;
  double x = 0;
  
  mitt = result / j;
  
  for (double i = 0; i < 234; i++){
    
    eindatei >> x;
    var += ((x - mitt)*(x - mitt)) / j;
    
  }
  
  eindatei.close();
  
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

std::cout << mittelwert (result,j) << std::endl;
std::cout << varianz (result,j) << std::endl;
std::cout << standardabweichung (result,j) << std::endl;

eindatei.close();

}
