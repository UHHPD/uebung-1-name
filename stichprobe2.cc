
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

/*double standardabweichung (double result, double x, int j){

  double d = 0; 
  double var = 0;
  double mitt = 0;
  
  mitt = result / j;
  var = (x - mitt) * (x - mitt) / j;
  
  d = sqrt(var);

  return d;
}*/

int main() {

std::ifstream eindatei("datensumme.txt");
std::ifstream eindatei2("datensumme.txt");
std::ifstream eindatei3("mittelwert.txt");
std::ifstream eindatei4("varianz.txt");
std::ofstream ausdatei("mittelwert.txt");
std::ofstream ausdatei2("varianz.txt");

double x = 0;
double y = 0;
double result = 0;
double mittwmitt = 0;
double mittvarianz = 0;
int j = 0;
int f = 0;

for (int h=0; h < 26; h++){

  for (int i=0; i < 9; i++){
  
    eindatei >> x;
    result += x;
  
    j++;

    
  }
  
  ausdatei << mittelwert (result,j) << std::endl;
  ausdatei2 << varianz (result,x,j) << std::endl;
  
}

for (int i =0 ; i< 26; i++){

  
  eindatei3 >> x;
  eindatei4 >> y;

  mittwmitt += x;
  mittvarianz += y;

  f++;
}

std::cout <<"Mittelwert von Mittelwert: "<< mittwmitt/f << " Mittelwetrt von stichprobe.cc war: 3.11538 "<<std::endl;
std::cout <<"Mittelwert von Varianz: " << mittvarianz/f <<" Varianz aus stichprobe.cc war: 0.0355599 "<<std::endl;


eindatei.close();
eindatei2.close();
ausdatei.close();
ausdatei2.close();

}