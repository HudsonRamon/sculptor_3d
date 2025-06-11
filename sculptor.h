#ifndef SCULPTOR_H
#define SCULPTOR_H

<<<<<<< HEAD

// Definição da estrutura Voxel
struct Voxel {
    float r, g, b; // Cores
    float a;       // Transparência
    bool isOn;     // Incluído ou não
};

class Sculptor {
protected:
    Voxel ***v;  // Matriz 3D de voxels
    int nx, ny, nz; // Dimensões
    float r, g, b, a; // Cor atual de desenho

public:
    Sculptor(int _nx, int _ny, int _nz); // Construtor
    ~Sculptor();                         // Destrutor
    void setColor(float r, float g, float b, float a); // Define a cor atual
    void putVoxel(int x, int y, int z); // Ativa um voxel
    void cutVoxel(int x, int y, int z); // Desativa um voxel
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); // Ativa uma caixa
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); // Desativa uma caixa
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); // Ativa uma esfera
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); // Desativa uma esfera
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Ativa um elipsoide
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Desativa um elipsoide
    void writeOFF(const char* filename); // Escreve o arquivo OFF
};

=======
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class sculptor;
}
QT_END_NAMESPACE

class sculptor : public QMainWindow
{
    Q_OBJECT

public:
    sculptor(QWidget *parent = nullptr);
    ~sculptor();

private:
    Ui::sculptor *ui;
};
>>>>>>> f4832bb3c02a95e5043b61f0634fe655a309b44f
#endif // SCULPTOR_H
