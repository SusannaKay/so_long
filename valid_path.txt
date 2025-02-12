nodo iniziale P ( scan per posizione P)
aggiungere P a visited
passare alla prossima posizione
e un muro?
si --> passare a posizione adiacente (LOOP finche non e un muro)
la queue finisce senza trovare altri nodi --> mappa non valida

no --> aggiungere a visited
e il goal? 

aggiorna queue con prossime posizione
controlla in ordine le altre posizioni, aggiunge in queue


1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111


3,1

VISITED     QUEUE
(3,2) -> (3,3) (2,3)
(2,1) ->  (2,2) (1,1)

(3,3) -> (3,4) (2,4) ---> (2,3)(2,2)(1,1)(3,4)(2,4)
(2,3) ->