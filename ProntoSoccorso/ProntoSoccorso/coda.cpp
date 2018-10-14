#include "coda.h"
#define add1 ((miaCoda.iRear+1)%DIM)

template <class generico>
void Init(coda<generico> & miaCoda) {
	miaCoda.iFront = miaCoda.iRear = 0;
}

template <class generico>
void Enqueue(coda<generico> &miaCoda, generico x) {
	miaCoda.elem[miaCoda.iRear] = x;
	miaCoda.iRear = add1;
}

template <class generico>
void Dequeue(coda<generico> &miaCoda) {
	miaCoda.iFront = (miaCoda.iFront + 1) % DIM;
}

template <class generico>
generico Front(coda<generico> miaCoda) {
	return(miaCoda.elem[miaCoda.iFront]);
}

template <class generico>
bool Full(coda<generico> miaCoda) {
	return(miaCoda.iFront == ((miaCoda.iRear + 1) % DIM));
}

template <class generico>
bool Empty(coda<generico> miaCoda) {
	return(miaCoda.iFront == miaCoda.iRear);
}