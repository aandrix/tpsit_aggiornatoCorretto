import threading

mutex = threading.Lock()

saldo = 100 

class Deposita(threading.Thread):
    def __init__(self):
        super().__init__()

    def run(self):
        global saldo #saldo è gia globale ma adesso è modificabile 
        for _ in range(100000000):
            mutex.acquire()
            saldo += 20
            mutex.release()



class Preleva(threading.Thread):
    def __init__(self):
        super().__init__()

    def run(self):
        global saldo #saldo è gia globale ma adesso è modificabile 
        for _ in range(100000000):
            saldo -= 10

def main():
    alice = Deposita()
    dario = Preleva()
    alice.start()
    dario.start()
    print("aspetto la fine dei thread")
    print(threading.enumerate())
    alice.join()
    dario.join()
    print(saldo)



if __name__ == "__main__":
    main()


'''
questo programma non è tread safe perche abbiamo due tread che accedono in maniera concorrente 
a volte le istruzioni si accavallano, si può evitare con la lock per far si che la risorsa in comune venga bloccata

.aquire --> acquisire una risorsa sul thread 



paradigma produttore consumatore, 
ad esempio nei video giochi con un controller, si deve utilizzare un tread per far si che l'istruzione 
non sia bloccante 2





'''