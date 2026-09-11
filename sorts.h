#ifndef SORTS_H
#define SORTS_H

#include <vector>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
	public:
    void ordenaSeleccion(std::vector<T>&);
    void ordenaBurbuja(std::vector<T>&);
    void ordenaMerge(std::vector<T>&);
    int busqSecuencial(const std::vector<T>& v, T val);
    int busqBinaria(const std::vector<T>& v, T val);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v) {
    int indx;

    for (int i = v.size() - 1; i > 0; i--) {
        indx = 0;

        for (int j = 1; j <= i; j++) {
            if (v[j] > v[indx]) {
                indx = j;
            }
        }

        if (indx != i) { 
            swap(v, i, indx);
        }
    }
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &v) {
    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
            }
        }
    }
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &original, std::vector<T> &result, int low, int high) {
    for (int i = low; i <= high; i++) {
        original[i] = result[i];
    }
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &original, std::vector<T> &result, int low, int mid, int high) {
	int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (original[i] < original[j]) {
            result[k] = original[i];
            i++;
        } else {
            result[k] = original[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (; j <= high; j++) {
            result[k++] = original[j];
        }
    } else {
        for (; i <= mid; i++) {
            result[k++] = original[i];
        }
    }
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &original, std::vector<T> &result, int low, int high) {
	int mid;

	if ((high - low) < 1) {
		return;
    }
	mid = (high + low) / 2;
	mergeSplit(original, result, low, mid);
	mergeSplit(original, result, mid + 1, high);
	mergeArray(original, result, low, mid, high);
	copyArray(original, result, low, high);
}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &v) {
    std::vector<T> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
}

template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T> &v, T val) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == val) {
            return i;
        }
    }
    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(const std::vector<T> &v, T val) {
    int low = 0;
    int high = v.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (v[mid] == val) {
            return mid;
        } else if (val < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
#endif /* SORTS_H */
