import threading

posti = 200


class CassaCinema(threading.Thread):
    def __init__(self, nome, lock):
        threading.Thread.__init__(self)
        self.nome = nome
    
        self.lock = lock
    
    def run(self):

        global posti

        while True:
            self.lock.acquire()  
            if posti > 0:
                posti -= 1
                print(f"Cassa {self.nome}: Venduto un biglietto. Posti disponibili: {posti}")
                self.lock.release() 
            else:
                self.lock.release()  
                break


lock = threading.Lock()

cassa1 = CassaCinema("Cassa 1", lock)
cassa2 = CassaCinema("Cassa 2", lock)
cassa3 = CassaCinema("Cassa 3", lock)
cassa4 = CassaCinema("Cassa 4", lock)
cassa5 = CassaCinema("Cassa 5", lock)
cassa6 = CassaCinema("Cassa 6", lock)

cassa1.start()
cassa2.start()
cassa3.start()
cassa4.start()
cassa5.start()
cassa6.start()

cassa1.join()
cassa2.join()
cassa3.join()
cassa4.join()
cassa5.join()
cassa6.join()

print("Tutte le casse hanno terminato la vendita dei biglietti.")
