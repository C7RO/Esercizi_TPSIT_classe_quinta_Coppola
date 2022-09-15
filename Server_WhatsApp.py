import socket

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("0.0.0.0",5000))

rubrica = {}
f = open("rubrica.csv","r")

righe = f.readlines()

for riga in righe:
    ls = riga.split(",")
    rubrica[ls[0]]=ls[1][:-1]
rubricaContrario = {v: k for k, v in rubrica.items()}
print(rubrica)
print(rubricaContrario)

while True:
    msg,ind_client = s.recvfrom(4096)
    msg = msg.decode()
    print(msg)
    ls = msg.split("|")
    print(ls)
    if ls[1] not in rubrica:
        msg = ("Non ci sono destinatari con questo nome")
        s.sendto(msg.encode(),(ind_client,5000))
    else:
        ind_mittente = rubricaContrario[ind_client[0]]
        ind_client = rubrica[ls[1]] 
        msg = ind_mittente + "> " + ls[0]
        s.sendto(msg.encode(),(ind_client,5000))
        print("Inviato")