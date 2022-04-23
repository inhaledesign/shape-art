#pragma once

#include "CoreMinimal.h"
#include <stdexcept>

template <class T>
class THistory {
public:
    class THistoryNode {
    public:
        friend class THistory;
        THistoryNode(const T& Value) : Value(Value), Previous(nullptr), Next(nullptr) {}
        const T& GetValue() const { return Value; }

    protected:
        // this constructor is used for the Head node, where calling GetValue() is an exception
        THistoryNode() : Previous(nullptr), Next(nullptr) {}
        T Value;
        THistoryNode* Previous;
        THistoryNode* Next;
    };

private:
    THistoryNode* Head = new THistoryNode();
    THistoryNode* Current { Head };

public:
    THistory() {}
    ~THistory() {         
        THistoryNode* Next { Head->Next };
        THistoryNode* Tmp { nullptr };

        while(Next != nullptr) {
            Tmp = Next->Next;
            delete Next;
            Next = Tmp;
        }

        delete Head;
        Head = nullptr;
        Current = nullptr;
    }

    THistoryNode* GetCurrent() { 
        if(IsHead()) {
            throw std::out_of_range("Head node value is meaningless and should not be accessed.");
        }
        return Current; 
    }
    
    THistoryNode* GetHead() { return Head; };

    void Post(const T& Value) {
        if(Current->Next != nullptr) {
            EmptyFuture();
        }

        THistoryNode* NewElement = new THistoryNode(Value);
        Current->Next = NewElement;
        NewElement->Previous = Current;
        Current = NewElement;
    }

    void StepPrevious() {
        if(IsHead()) {
            throw std::out_of_range("Cannot StepPrevious() on the Head node.");
        }
        Current = Current->Previous;
    }

    void StepNext() {
        if(IsTail()) {
            throw std::out_of_range("Cannot StepNext() on the Tail node.");
        }
        Current = Current->Next;
    }

    bool IsHead() { return Current == Head; }

    bool IsTail() { return Current->Next == nullptr; }

private:

    void EmptyFuture() {
        THistoryNode* Next { Current->Next };
        THistoryNode* Tmp { nullptr };

        while(Next != nullptr) {
            Tmp = Next->Next;
            delete Next;
            Next = Tmp;
        }

        Current->Next = nullptr;
    }

};