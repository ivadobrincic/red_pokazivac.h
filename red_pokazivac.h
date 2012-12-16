struct klijent {
    int ulazak, trajanje, c, transakcija;
    string ime;
    long int datum;
    float tekuci, devizni;
};

struct qu {
    klijent k;
    qu *next;
};

struct que {
    qu *front;
    qu *rear;
};

typedef qu *element;
typedef que queue;


klijent FrontQ(queue *q) {
    return q->front->next->k;
}

void InitQ(queue *q) {
    element novi = new qu;
    novi->next = NULL;
    q->front = q->rear = novi;
}

bool IsEmptyQ(queue *q) {
    return q->front == q->rear;
}

/*
void EnQueueQ(klijent x, queue *q) {
    element novi = new qu;
    novi->k = x;
    q->rear->next = novi;
    q->rear = novi;
}
*/

void EnQueueQ(klijent x, queue *q) {
    element novi = new qu;
    novi->k = x;    
    novi->next = NULL;
    element tekuci = q->front;
    if (IsEmptyQ(q) == true) {
        q->front->next = novi;
        q->rear = novi;
        return;
    }
    while (tekuci->next != NULL && x.c <= tekuci->next->k.c) {
        if (tekuci->next == NULL) {
            break;
        }
        tekuci = tekuci->next;

    }

    novi->next = tekuci->next;
    tekuci->next = novi;

    if (tekuci == q->rear) {
        q->rear = novi;
    }

}

void DeQueueQ(queue *q) {
    element brisi = q->front;
    q->front = brisi->next;
    delete brisi;
}

void PrintQ(queue *q) {
    if (IsEmptyQ(q) == true) {
        cout << "Red je prazan." << endl;
        return;
    }
    qu *tekuci = q->front;
    cout << "U redu cekaju: " << endl;
    do {
        tekuci = tekuci->next;
        cout << tekuci->k.ime << endl;
    } while (tekuci != q->rear);
    cout << "--------------------------" << endl;

}

