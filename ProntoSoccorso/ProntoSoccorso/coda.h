#pragma once
#define DIM 15
template <class generico>
struct coda {
	generico elem[DIM];
	int iRear, iFront;
};

template <class generico> //da aggiungere prima di OGNI funzione
void Init(coda<generico> &); //da mettere prima di ogni "coda", per distinguere coda int o string

template <class generico>
void Enqueue(coda<generico> &, generico);

template <class generico>
void Dequeue(coda<generico> &);

template <class generico>
generico Front(coda<generico>);

template <class generico>
bool Full(coda<generico>);

template <class generico>
bool Empty(coda<generico>);