#include <iostream>
class ListNode {
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

class ListNode_doubly :public ListNode {
public:
	ListNode_doubly(ListNode* m) {
		this->setData(m->getData());
		this->setNext(m->getNext());
		this->previous = NULL;
	};

	ListNode_doubly* getNext() {
		return this->next;
	}
	void setNext_doubly(ListNode_doubly* p) {
		this->next = p;
	}
	ListNode_doubly* getPrevious() {
		return this->previous;
	}
	void setPrevious(ListNode_doubly* p) {
		this->previous = p;
	}
private:
	ListNode_doubly* previous;
	ListNode_doubly* next;
};

class Linked_list_singly {
public:
	friend class Linked_list_doubly;
	Linked_list_singly();
	Linked_list_singly(ListNode* head) {
		this->head = head;
	}
	ListNode* getHead() {
		return this->head;
	}
	void setHead(ListNode* new_head) {
		this->head = new_head;
	}
	void insert_by_order(ListNode* newnode) {//按顺序插入
		if (this->head == NULL)
			this->head = newnode;
		else if (newnode->getData() < head->getData()) {
			newnode->setNext(head->getNext());
			this->head = newnode;
		}
		else {
			ListNode* p = head;
			while (p->getNext()!=NULL&&p->getNext()->getData() < newnode->getData()) {
				p = p->getNext();
			}
			newnode->setNext(p->getNext());
			p->setNext(newnode);
		}
	}
	void insert(ListNode* after_which, ListNode* newnode) {
		newnode->setNext(after_which->getNext());
		after_which->setNext(newnode);
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

	ListNode* remove(ListNode*  deleted_node) {
		ListNode* current = getHead();
		if (current) {
			while (current->getNext() != NULL && current->getNext() != deleted_node) {
				current = current->getNext();
			}
			if (current->getNext()) {
				current->setNext(deleted_node->getNext());
				return deleted_node;
			}
		}
		return NULL;
	}
private:
	ListNode* head;

};

class Linked_list_doubly :public Linked_list_singly {
public:
	Linked_list_doubly(Linked_list_singly* source_list) {
		ListNode* p = source_list->getHead();
	};
	void remove(ListNode_doubly*  deleted_node) {
		deleted_node->getPrevious()->setNext(deleted_node->getNext());
		deleted_node->getNext()->setPrevious(deleted_node->getPrevious());
	}
	void insert_by_order(ListNode_doubly* newnode) {//按顺序插入
		if (this->head == NULL)
			this->head = newnode;
		else if (newnode->getData() < head->getData()) {
			newnode->setNext(head->getNext());
			this->head = newnode;
		}
		else {
			ListNode_doubly* p = head;
			while (p->getNext() != NULL && p->getNext()->getData() < newnode->getData()) {
				p = p->getNext();
			}
			newnode->setNext(p->getNext());
			newnode->setPrevious(p);
			p->setNext(newnode);
			if (newnode->getNext() != NULL)
				newnode->getNext()->setPrevious(newnode);
		}
	}
	void insert(ListNode_doubly* after_which, ListNode_doubly* newnode) {
	  //if (after_which){
		newnode->setPrevious(after_which);
		newnode->setNext(after_which->getNext());
		after_which->setNext(newnode);
		if (newnode->getNext() != NULL)
			newnode->getNext()->setPrevious(newnode);
	  //}
	}
private:
	ListNode_doubly* head;
};
