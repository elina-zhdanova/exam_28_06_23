#pragma once
//#ifndef Det_H//#ifndef ƒиректива провер€ет наличие противоположного услови€, установленного #ifdef
//≈сли идентификатор не был определен или его определение было удалено с помощью, условие имеет значение true (отличное от #undef нул€)
//¬ противном случае условие не выполн€етс€ (false, значение равно 0).
#define Det_H
//#define в данном случае определ€ет содержимое, если файл определ€етс€ впервые.
#define elem(t, x, y, n) t[(x)*(n)+(y)]

void free_memory(double* matr);

double* create(double* matr, int n, int iskI, int iskJ);

double det_Minors(double* matr, int n);

//#endif
//ƒирективы #ifndef ... #endif созданы дл€ того, что бы предотвратить многократное включение заголовочного файла