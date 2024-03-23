class Cuenta_Banco:
    def __init__(self, nombre, saldo):
        self.nombre = nombre
        self.saldo = saldo

    def transferir(self, destino, cantidad):
        if self.saldo >= cantidad:
            self.saldo -= cantidad
            destino.saldo += cantidad
            print("Transferencia realizada con éxito")
        else:
            print("Fondos insuficientes")

C1 = Cuenta_Banco("Grossman", 1000)
C2 = Cuenta_Banco("Yhosfer", 500)
#Fallo
C1.transferir(C2, 10000)
#Resultado
C2.transferir(C1,300)
print(C1.saldo)