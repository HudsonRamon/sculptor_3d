#include <iostream>
<<<<<<< HEAD
#include "sculptor.h" // Inclua o cabeçalho da sua classe Sculptor

int main() {
    // Crie uma escultura de 60x60x60 voxels
    Sculptor s(60, 60, 60);

    // Defina a cor para o cubo (por exemplo, vermelho sólido)
    s.setColor(0.0, 1.0, 0.0, 1.0); // R=1.0 (vermelho), G=0.0, B=0.0, A=1.0 (opaco)

    // Crie o cubo usando putBox, abrangendo todas as dimensões da escultura
    // x0=0, x1=59 (60-1), y0=0, y1=59, z0=0, z1=59
    s.putBox(0, 59, 0, 59, 0, 59);

    // Escreva a escultura para um arquivo OFF
    s.writeOFF("cubo_60x60x60.off");

    std::cout << "Cubo 60x60x60 criado e salvo em cubo_60x60x60.off" << std::endl;

=======
#include "sculptor.h"

int main(){
    Sculptor s(10,10,10);
    s.setColor(1,0,0,1);
    s.putVoxel(3,5,8);
    s.writeOFF("alo.off");
>>>>>>> f4832bb3c02a95e5043b61f0634fe655a309b44f
    return 0;
}
