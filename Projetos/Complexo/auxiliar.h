typedef struct{
    double real;
    double imag;
} complexo;

complexo inicio(double, double);
void copia(complexo*, complexo);
complexo soma(complexo, complexo);
bool ehreal(complexo);
void imprime(complexo);
