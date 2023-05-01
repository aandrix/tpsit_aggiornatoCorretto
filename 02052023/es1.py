from threading import Thread
import random

'''

Giordano Andrea 

esercizio da consegnare su clasroom per il 2 sui thread


Un processo produttore genera in modo casuale (anche con ripetizioni) numeri da 1 a 10 (inclusi)
 e li memorizza in un buffer condiviso che può contenere un solo numero alla volta.
   Due processi consumatori concorrenti tentano di acquisire tali numeri soltanto 
   dopo la loro produzione. Uno dei due consumatori tenta di acquisire solo numeri 
   da 1 a 5, l'altro solo numeri che vanno da 6 a 10. Quando lo prendono
settano il buffer (variabile) a 0 (zero)

'''

prodotto = 0

valoriConsumatore1 = 0
valoriConsumatore2 = 0

bufferConsumatori = [0,0]



class Consumatore (Thread):

    def __init__(self, nome, vMin, vMax, posMem):
        Thread.__init__(self)
        self.vMax = vMax 
        self.vMin = vMin 
        self.pos = posMem #questo serve a identificare a quale posizione del buffer si trova la memoria 
        #del processo 
        self.nome = nome


    def run(self):
        global prodotto
        global bufferConsumatori
        
        if prodotto >= self.vMin and prodotto <= self.vMax:
            bufferConsumatori[self.pos] += prodotto
            prodotto = 0
        print(f"quantita {self.nome} = {bufferConsumatori[self.pos]}")
        

class Produttore(Thread):

    def __init__(self, pMin, pMax):
        Thread.__init__(self)
        self.pMax = pMax
        self.pMin = pMin

    def run(self):
        global prodotto
        
        if prodotto == 0:
            prodotto = random.randint(self.pMin, self.pMax)

        
        




def main():
    for k in range(1,20):
        produttore = Produttore(1,10)
        consumatore1 = Consumatore("processo 1", 1, 5, 0)#nome, vmin, vmax, posBuffer
        consumatore2 = Consumatore("processo 2", 6,10, 1)
        produttore.start()
        consumatore1.start()
        consumatore2.start()  
        produttore.join()
        consumatore1.join()
        consumatore2.join()  
    print(f"il processo 1 ha acquisito: {bufferConsumatori[0]}\nil processo 2 ha acquisito: {bufferConsumatori[1]}")


    

    pass


if __name__ == "__main__":
    main()