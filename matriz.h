#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
private:
    int nl, nc;
    int **x;
public:
    Matriz(int _nl, int _nc);
    ~Matriz();
    print();
};

#endif // MATRIZ_H
