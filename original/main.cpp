
#include "funcionesAES.h"


int main () {

  std::cout << "Bienvenido al programa de cifrado AES" << std::endl;

  std::vector<std::vector<std::string>> key = {
    {"00", "04", "08", "0c"},
    {"01", "05", "09", "0d"},
    {"02", "06", "0a", "0e"},
    {"03", "07", "0b", "0f"}
  };
  int bloque = 1;
  std::cout << "Introduzca la clave de cifrado(0): o use la por defecto " << std::endl;

  std::cin >> bloque;
  if (bloque == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> key[j][i];
      }
    }
  }

  

  std::cout << "La clave de cifrado es: " << std::endl;

  printMatrix(key);

  int clave = 1;

  std::cout << "Introduzca el bloque de texto(0): o use la por defecto" << std::endl;

  std::cin >> clave;
  
  std::vector<std::vector<std::string>> state = {
    {"00", "44", "88", "cc"},
    {"11", "55", "99", "dd"},
    {"22", "66", "aa", "ee"},
    {"33", "77", "bb", "ff"}
  };
  if (clave == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> state[j][i];
      }
    }
  }

  std::cout << "El bloque de texto es: " << std::endl;

  printMatrix(state);

  std::vector<std::vector<std::vector<std::string>>> keySchedule = KeySchedules(key);

  std::cout << "El bloque de texto cifrado es: " << std::endl;

  std::vector<std::vector<std::string>> stateCifrado = AES(state, keySchedule);

  printMatrix(stateCifrado);

  std::cout << "Las claves son: " << std::endl;

  for (int i = 0; i < keySchedule.size(); i++) {
    std::cout << "Clave " << i << std::endl;
    printMatrix(keySchedule[i]);
  }
  

  







  return 0;


}