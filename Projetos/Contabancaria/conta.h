typedef struct{
    int numero;
    double saldo;
} conta;

conta inicializa(int, double);
void deposito(conta*, double);
void saque(conta*, double);
void imprime(conta);
