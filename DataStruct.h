//
// Created by ace89 on 13/07/17.
//

#ifndef OPTIONPRICER_DATASTRUCT_H
#define OPTIONPRICER_DATASTRUCT_H

namespace OptionPricer
{
    template <class T>
    class DataStruct {
    public:
        DataStruct(T _x):x(_x){}
        void SetVariable(T _x);

        T GetVariable();

        void SetHead(DataStruct* _head);

        DataStruct* GetHead();

    private:
        T           x;
        DataStruct* head;
    };

    template <class T>
    void DataStruct<T>::SetVariable(T _x)
    {
        this->x = _x;
    }

    template <class T>
    T DataStruct<T>::GetVariable()
    {
        return this->x;
    }

    template <class T>
    void DataStruct<T>::SetHead(DataStruct* _head)
    {
        this->head = _head;
    }

    template <class T>
    DataStruct<T>* DataStruct<T>::GetHead()
    {
        return this->head;
    }

}

#endif //OPTIONPRICER_DATASTRUCT_H
