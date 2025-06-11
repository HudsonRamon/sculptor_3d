#include "sculptor.h"
#include <fstream>
<<<<<<< HEAD
#include <iostream> // Para std::cout e std::cerr


Sculptor::Sculptor(int _nx, int _ny, int _nz) : nx(_nx), ny(_ny), nz(_nz) {
    // Aloca a matriz 3D de voxels
    v = new Voxel**[nx];
    for (int i = 0; i < nx; ++i) {
        v[i] = new Voxel*[ny];
        for (int j = 0; j < ny; ++j) {
            v[i][j] = new Voxel[nz];
            for (int k = 0; k < nz; ++k) {
                v[i][j][k].isOn = false; // Inicializa todos os voxels como desligados
            }
        }
    }
}

Sculptor::~Sculptor() {
    // Libera a memória alocada para a matriz de voxels
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    // Verifica se as coordenadas estão dentro dos limites
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].isOn = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    // Verifica se as coordenadas estão dentro dos limites
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].isOn = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    // Garante que os limites sejam válidos
    x0 = std::max(0, x0);
    x1 = std::min(nx - 1, x1);
    y0 = std::max(0, y0);
    y1 = std::min(ny - 1, y1);
    z0 = std::max(0, z0);
    z1 = std::min(nz - 1, z1);

    for (int i = x0; i <= x1; ++i) {
        for (int j = y0; j <= y1; ++j) {
            for (int k = z0; k <= z1; ++k) {
                putVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    // Garante que os limites sejam válidos
    x0 = std::max(0, x0);
    x1 = std::min(nx - 1, x1);
    y0 = std::max(0, y0);
    y1 = std::min(ny - 1, y1);
    z0 = std::max(0, z0);
    z1 = std::min(nz - 1, z1);

    for (int i = x0; i <= x1; ++i) {
        for (int j = y0; j <= y1; ++j) {
            for (int k = z0; k <= z1; ++k) {
                cutVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for (int i = xcenter - radius; i <= xcenter + radius; ++i) {
        for (int j = ycenter - radius; j <= ycenter + radius; ++j) {
            for (int k = zcenter - radius; k <= zcenter + radius; ++k) {
                // Equação da esfera: (x-x0)^2 + (y-y0)^2 + (z-z0)^2 <= r^2
                if ((i - xcenter) * (i - xcenter) +
                        (j - ycenter) * (j - ycenter) +
                        (k - zcenter) * (k - zcenter) <= radius * radius) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for (int i = xcenter - radius; i <= xcenter + radius; ++i) {
        for (int j = ycenter - radius; j <= ycenter + radius; ++j) {
            for (int k = zcenter - radius; k <= zcenter + radius; ++k) {
                // Equação da esfera: (x-x0)^2 + (y-y0)^2 + (z-z0)^2 <= r^2
                if ((i - xcenter) * (i - xcenter) +
                        (j - ycenter) * (j - ycenter) +
                        (k - zcenter) * (k - zcenter) <= radius * radius) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int i = xcenter - rx; i <= xcenter + rx; ++i) {
        for (int j = ycenter - ry; j <= ycenter + ry; ++j) {
            for (int k = zcenter - rz; k <= zcenter + rz; ++k) {
                // Equação do elipsoide: ((x-x0)/rx)^2 + ((y-y0)/ry)^2 + ((z-z0)/rz)^2 <= 1
                if (((float)(i - xcenter) * (i - xcenter)) / (rx * rx) +
                        ((float)(j - ycenter) * (j - ycenter)) / (ry * ry) +
                        ((float)(k - zcenter) * (k - zcenter)) / (rz * rz) <= 1.0f) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int i = xcenter - rx; i <= xcenter + rx; ++i) {
        for (int j = ycenter - ry; j <= ycenter + ry; ++j) {
            for (int k = zcenter - rz; k <= zcenter + rz; ++k) {
                // Equação do elipsoide: ((x-x0)/rx)^2 + ((y-y0)/ry)^2 + ((z-z0)/rz)^2 <= 1
                if (((float)(i - xcenter) * (i - xcenter)) / (rx * rx) +
                        ((float)(j - ycenter) * (j - ycenter)) / (ry * ry) +
                        ((float)(k - zcenter) * (k - zcenter)) / (rz * rz) <= 1.0f) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream fout;
    int totalVoxels = 0;

    fout.open(filename);
    if (!fout.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        exit(1);
    }

    fout << "OFF\n";

    // Conta quantos voxels estão marcados com show == true
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].isOn) {
                    totalVoxels++;
                }
            }
        }
    }

    fout << totalVoxels * 8 << " " << totalVoxels * 6 << " 0\n"; // Vértices, Faces, Arestas

    // Escreve os vértices de cada voxel ativo
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].isOn) {
                    // Os 8 vértices do cubo (voxel)
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                }
            }
        }
    }

    int currentVoxel = 0;
    // Escreve as faces de cada voxel ativo
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].isOn) {
                    int offset = currentVoxel * 8;
                    // 6 faces do cubo, cada uma com 4 vértices (índices relativos ao voxel)
                    fout << "4 " << 0 + offset << " " << 3 + offset << " " << 2 + offset << " " << 1 + offset << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 " << 4 + offset << " " << 5 + offset << " " << 6 + offset << " " << 7 + offset << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 " << 0 + offset << " " << 1 + offset << " " << 5 + offset << " " << 4 + offset << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 " << 0 + offset << " " << 4 + offset << " " << 7 + offset << " " << 3 + offset << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 " << 3 + offset << " " << 7 + offset << " " << 6 + offset << " " << 2 + offset << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 " << 1 + offset << " " << 2 + offset << " " << 6 + offset << " " << 5 + offset << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    currentVoxel++;
                }
            }
        }
    }

    fout.close();
=======

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    // aloca a matriz de voxels v
}

Sculptor::~Sculptor(){

}

void Sculptor::setColor(float r, float g, float b, float a){
    this->r = r;
    this->g = g;
    this->b = b;
}
void Sculptor::putVoxel(int x, int y, int z){

}
void Sculptor::cutVoxel(int x, int y, int z){

}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

}
void Sculptor::writeOFF(const char* filename){
    std::ofstream fout;
    int nvoxels;

    fout.open(filename);
    if (!fout.is_open()) {
        exit(1);
    }
    fout << "OFF\n";
    // conta quantos voxels estao marcados com show == true
    // lasso aninhado

    fout << nvoxels * 8 << " " << nvoxels * 6 << " 0\n";
    // escrever os vertices

    // escrever as faces
    fout.close();

>>>>>>> f4832bb3c02a95e5043b61f0634fe655a309b44f
}
