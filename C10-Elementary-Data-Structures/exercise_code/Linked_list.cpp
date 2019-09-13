#include <iostream>
class ListNode{
public:
	ListNode() {
		data = 0;
		next = NULL;
	}
	ListNode(int data, ListNode* next) {
		this->data = data;
		this->next = next;
	
	};
	ListNode* getNext() {
		return this->next;
	}
	void setNext(ListNode* p) {
		this->next = p;
	}
	int getData() {
		return this->data;
	}
	void setData(int data) {
		this->data = data;
	}

private:
	int data;
	ListNode* next;
};
class ListNode_doubly:public ListNode {
public:
	ListNode_doubly(ListNode* m) {
		this->setData(m->getData());
		this->setNext(m->getNext());
		this->previous = NULL;
	};
	ListNode_doubly* getPrevious() {
		return this->previous;
	}
	void setPrevious(ListNode_doubly* p) {
		this->previous = p;
	}
	ListNode_doubly* getNext() {
		return this->next;
	}
	void setNext(ListNode_doubly* p) {
		this->next = p;
	}
	

private:
	ListNode_doubly* previous;
	ListNode_doubly* next;
};

class Linked_list {
public:
	Linked_list();
	Linked_list(ListNode* head) {
		this->head = head;
	}
	ListNode* getHead() {
		return this->head;
	}
	void setHead(ListNode* new_head) {
		this->head = new_head;
	}
	void insert_as_head(ListNode* a) {
		a->setNext(this->head);
		this->setHead(a);
	}
	void insert(ListNode* a,int before_which_data) {
		ListNode* current = getHead();
		if (current == NULL)
			return;
		while (current->getNext() != NULL&& current->getNext()->getData() != before_which_data) {
			current = current->getNext();
		}
		if (current->getNext()) {
			a->setNext(current->getNext());
			current->setNext(a);
		}
	}
	ListNode* search(int data) {
		ListNode* current = getHead();
		if (current == NULL)
			return NULL;
		while (current->getNext() != NULL && current->getNext()->getData() != data) {
			current = current->getNext();
		}
		return  current->getNext();
	}
	void remove(ListNode*  deleted_node) {
		ListNode* current = getHead();
		if (current) {
			while (current->getNext() != NULL && current->getNext()!= deleted_node) {
				current = current->getNext();
			}
			if (current->getNext()) {
				current->setNext(deleted_node->getNext());
			}
		}
	}
private:
	ListNode* head;

};
class Doubly_linked_list :public Linked_list {
public:
	void setHead(ListNode_doubly* new_head) {
		this->head = new_head;
	}
	ListNode_doubly* getHead() {
		return this->head;
	}
	void remove(ListNode_doubly*  deleted_node) {
		deleted_node->getPrevious()->setNext(deleted_node->getNext());
		deleted_node->getNext()->setPrevious(deleted_node->getPrevious());
	}
	void insert(ListNode_doubly* a, int before_which_data) {
		ListNode_doubly* current = getHead();
		if (current == NULL)
			return;
		while (current->getNext() != NULL && current->getNext()->getData() != before_which_data) {
			current = current->getNext();
		}
		if (current->getNext()) {
			a->setNext(current->getNext());
			a -> setPrevious(current->getPrevious());
			a->getPrevious()->setNext(a);
			a->getNext()->setPrevious(a);
		}
	}
private:
	ListNode_doubly* head;
};




int main() {
	ListNode n0;
	ListNode n1;
	n0.setNext(&n1);
	ListNode_doubly n2(&n0);
	std::cout<<n2.getNext();
	return 0;
}