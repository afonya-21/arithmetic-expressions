#pragma once
#pragma once


template <class T>
class TStack
{
protected:
    size_t top;
    size_t size;
    T* pMem;
public:
    TStack(int sz);
    TStack(const TStack<T>& p);
    TStack(TStack<T>&& p);
    ~TStack();

    bool isEmpty() const;
    bool isFull() const;

    void Push(const T& val);
    T Pop();

    size_t Number() const;
    T Top_el();
};


template<class T>
inline TStack<T>::TStack(int sz)
{
    if (sz <= 0)
        throw "sz <= 0";
    size = sz;
    top = -1;
    pMem = new T[size];
}


template<class T>
inline TStack<T>::TStack(const TStack<T>& p)
{
    if (p.pMem == nullptr)
    {
        pMem = nullptr;
        size = 0;
        top = -1;
    }
    else
    {
        size = p.size;
        top = p.top;
        pMem = new T[size];
        for (int i = 0; i < top; i++)
        {
            pMem[i] = p.pMem[i];
        }
    }
}


template<class T>
inline TStack<T>::TStack(TStack<T>&& p)
{
    size = p.size;
    top = p.top;
    pMem = p.pMem;

    p.pMem = nullptr;
    p.size = 0;
    p.top = -1;
}


template<class T>
inline TStack<T>::~TStack()
{
    if (pMem != nullptr)
    {
        delete[] pMem;
        pMem = nullptr;
    }
    size = 0;
    top = -1;
}


template<class T>
inline size_t TStack<T>::Number() const
{
    return top + 1;
}


template<class T>
inline bool TStack<T>::isEmpty() const
{
    if (top == -1) return true;
    return false;
}


template<class T>
inline bool TStack<T>::isFull() const
{
    if (top == size - 1) return true;
    return false;
}


template<class T>
inline void TStack<T>::Push(const T& val)
{
    {
        if (isFull() == true) throw "pMem isFull";
        pMem[++top] = val;
    }
}


template<class T>
inline T TStack<T>::Pop()
{
    if (isEmpty() == true) throw "pMem isEmpty";
    return pMem[top--];
}


template<class T>
inline T TStack<T>::Top_el()
{
    return pMem[top];
}
