import socket
from threading import Thread

class Ricevitore(Thread):
    def __init__(self,socket):
        Thread.__init__(self)
        self.socket=socket
        self.running=True

    def run(self):
        while self.running:
            dati, indirizzo_client=self.socket.recvfrom(4096)
            while(dati.decode()!="exit"):
                inf=dati.decode()
                print(f"\t{inf}")
                dati, indirizzo_client=self.socket.recvfrom(4096)
            self.stop()

    def stop(self):
        self.running=False

def main():
    s=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind(("0.0.0.0",5000))
    r=Ricevitore(s)
    r.start()
    destinatario=input("Dammi il nome del destinatario: ")
    messaggio=input("Text: ")
    while(destinatario!="exit"):
        server_WhatsApp=("192.168.0.126",5000)
        s.sendto(messaggio.encode(),server_WhatsApp)
        destinatario=input("Dammi il nome del destinatario: ")
        messaggio=input("Text: ")
        messaggio+="|"+destinatario
    r.stop()    
    r.join()

if __name__=="__main__":
    main()

