#include <iostream>
#include <fstream>
#include <cmath>

double mittelwert (double result, int j){
  
  double mitt = 0;
  
  mitt = result / j;

  return mitt;

}

/*double varianz (double result, int j) {
  
  std::ifstream eindatei("datensumme.txt");
  double var = 0;
  double mitt = 0;
  double x = 0;
  
  mitt = result / j;
  
  for (double i = 0; i < 9; i++){
    
    eindatei >> x;
    var += ((x - mitt)*(x - mitt)) / j;
  }
  
  eindatei.close();
  
  return var;

}*/

double standardabweichung (double result, int j){

  std::ifstream eindatei("datensumme.txt");
  
  double d = 0; 
  double var = 0;
  double mitt = 0;
  double x = 0;
  
  mitt = result / j;
  
  for (double i = 0; i < 9; i++){
    
    eindatei >> x;
    var += ((x - mitt)*(x - mitt)) / j;
    
  }
  
  eindatei.close();
  
  d = sqrt(var);

  return d;
}

int main() {

std::ifstream eindatei("datensumme.txt");
std::ifstream eindatei2("datensumme.txt");
std::ifstream eindatei3("mittelwerte.txt");
std::ifstream eindatei4("varianzen.txt");
std::ofstream ausdatei("mittelwerte.txt");
std::ofstream ausdatei2("varianzen.txt");

double x = 0;
double y = 0;
double mittwmitt = 0;
double mittvarianz = 0;
int f = 0;


for (int h=0; h < 26; h++){
  
  int j = 0;
  double result = 0;
  double mitt = 0;
  double var = 0;
  double z = 0;
  
  for (int i=0; i < 9; i++){
  
    eindatei >> x;
    result += x;
  
    j++;
    
  }
  
  mitt = result / j;
  
  for (int i=0; i < 9; i++){

  eindatei2 >> z;
  
  var += ((z - mitt)*(z - mitt)) / j;
  
  }
  
  ausdatei << mittelwert (result,j) << std::endl;
  ausdatei2 << var << std::endl;
  
}

for (int i =0 ; i< 26; i++){

  
  eindatei3 >> x;
  eindatei4 >> y;

  mittwmitt += x;
  mittvarianz += y;

  f++;
}

std::cout <<"Mittelwert von Mittelwert: "<< mittwmitt/f << " Mittelwetrt von stichprobe.cc war: 3.11538 "<<std::endl;
std::cout <<"Mittelwert von Varianz: " << mittvarianz/f <<" Varianz aus stichprobe.cc war: 1.65365 "<<std::endl;


eindatei.close();
eindatei2.close();
ausdatei.close();
ausdatei2.close();

}