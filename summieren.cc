#include <iostream>
#include <fstream>

double summe (double x, double y){

  double result = 0;

  result = y + x;


  return result;

}

int main() {

std::ifstream eindatei("daten.txt");
std::ofstream ausdatei("datensumme.txt");

double x;
double y;
double result = 0;

for (int i=0; i < 234; i++){
  eindatei >> x;
  eindatei >> y;

  ausdatei << summe (x,y) << std::endl;

  //std::cout << x << std::endl;
}

eindatei.close();
ausdatei.close();

/*for (int i=1; i <=234; i++){
  
  fout << summe << std::endl;
}*/
}