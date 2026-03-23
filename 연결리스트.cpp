#include <iostream>

// 1. 노드 구조체 정의
struct Node {
    int data;
    Node* next;

    // 생성자
    Node(int val) : data(val), next(nullptr) {}
};

// 2. 연결 리스트 클래스
class LinkedList {
private:
    Node* head; // 시작 노드

public:
    LinkedList() : head(nullptr) {}

    // 맨 앞에 노드 삽입
    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 리스트 출력
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // 소멸자 (메모리 해제)
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    list.insertFront(3);
    list.insertFront(2);
    list.insertFront(1);

    list.display(); // 출력: 1 -> 2 -> 3 -> NULL
    return 0;
}