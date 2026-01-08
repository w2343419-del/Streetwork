#include <stdio.h>

struct Package {
    int PkgID;
    char Receiver[20];
    int weight;
};

typedef struct Package a;

int main() {
    a x = {1, "Unknown", 10};
    a* p;
    p = &x;

    printf("PkgID: %d; Receiver: %s; weight: %d", 
            p->PkgID, p->Receiver, p->weight);
    return 0;
}
