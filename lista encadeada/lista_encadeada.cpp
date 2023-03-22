#include <iostream>

class Node {
public:
int aux;
Node *prox;

Node(int aux) : aux(aux), prox(nullptr) {}
};

class LinkedList {
public:
LinkedList() : head(nullptr), size(0) {}

~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *prox = current->prox;
        delete current;
        current = prox;
    }
}

bool isEmpty() {
    return size == 0;
}

int getSize() {
    return size;
}

int get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node *current = head;
    for (int i = 0; i < index; ++i) {
        current = current->prox;
    }

    return current->aux;
}

void set(int index, int value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node *current = head;
    for (int i = 0; i < index; ++i) {
        current = current->prox;
    }

    current->aux = value;
}

void insert(int index, int value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }

    Node *newNode = new Node(value);

    if (index == 0) {
        newNode->prox = head;
        head = newNode;
    } else {
        Node *prev = head;
        for (int i = 1; i < index; ++i) {
            prev = prev->prox;
        }
        newNode->prox = prev->prox;
        prev->prox = newNode;
    }

    size++;
}

void remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node *toDelete;

    if (index == 0) {
        toDelete = head;
        head = head->prox;
    } else {
        Node *prev = head;
        for (int i = 1; i < index; ++i) {
            prev = prev->prox;
        }
        toDelete = prev->prox;
        prev->prox = toDelete->prox;
    }

    delete toDelete;
    size--;
}

void print() {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->aux << " ";
        current = current->prox;
    }
    std::cout << std::endl;
}
private:
Node *head;
int size;
};

int main() {
LinkedList list;

list.insert(0, 1);
list.insert(1, 2);
list.insert(2, 3);

list.print(); // output: 1 2 3

list.set(1, 4);

list.print(); // output: 1 4 3

list.remove(2);

list.print(); // output: 1 4

std::cout << "Size: " << list.getSize() << std::endl; // output: Size: 2

return 0;
}