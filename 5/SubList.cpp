#include <iostream>

using namespace std;

class listt {
private:
    struct uzzel {
        int data;
        uzzel *next;

        uzzel(int d) {
            data = d;
            next = NULL;
        }
    };

    uzzel *start;

    void clear_work(uzzel **sfl) {
        if (*sfl == NULL) return;
        clear_work(&((*sfl)->next));
        delete *sfl;
        *sfl = NULL;
        return;
    }


public:
    listt() {
        start = NULL;
    }

    bool push_back(int d) {
        uzzel **sfl = &(this->start);
        uzzel *tmp = new uzzel(d);
        while (*sfl != NULL) {
            sfl = &((*sfl)->next);
        }
        *sfl = tmp;
        return true;
    }

    int pop_back() {
        if (start == NULL) return false;

        uzzel **sfl = &(this->start);
        while ((*sfl)->next != NULL) {
            sfl = &((*sfl)->next);
        }
        int e = (*sfl)->data;
        delete *sfl;
        *sfl = NULL;
        return e;
    }

    bool push_forward(int d) {
        uzzel **sfl = &(this->start);
        uzzel *tmp = new uzzel(d);
        tmp->next = (*sfl);
        tmp->data = d;
        *sfl = tmp;
        return true;
    } //add element (d) to the beginning of the list

    int pop_forward() {
        if (start == NULL) return false;

        uzzel **sfl = &(this->start);
        uzzel *tmp = (*sfl)->next;
        int e = (*sfl)->data;
        delete *sfl;
        *sfl = tmp;
        return e;
    }//erase element from the beginning of the list + return it's data

    bool push_where(unsigned int where, int d) {
        uzzel **sfl = &(this->start);
        uzzel *tmp = new uzzel(d);
        for (int i = 1; i < where; i++) {
            if (*sfl == NULL) return false;
            sfl = &((*sfl)->next);
        }
        tmp->next = (*sfl);
        (*sfl) = tmp;
        return true;
    } //add element (d) to (where)th position of the list

    bool erase_where(unsigned int where) {
        uzzel **sfl = &(this->start);
        for (int i = 1; i < where; i++) {
            if (*sfl == NULL) return false;
            sfl = &((*sfl)->next);
        }
        uzzel *tmp = (*sfl)->next;
        delete (*sfl);
        (*sfl) = tmp;
        return true;
    } //erase element from (where)th position of the list

    unsigned int size() {
        uzzel *sfl = this->start;
        unsigned int size = 0;
        while (sfl != NULL) {
            sfl = (sfl)->next;
            size++;
        }
        return size;
    } //check size of list

    void clear() {

        uzzel **sfl = &(this->start);
        this->clear_work(sfl);
    } //delete all elements (interface function, work function is private)

    void print() {
        uzzel *tmp = start;
        if (!tmp) cout << "empty list";
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = (tmp)->next;
        }
        cout << endl << endl;
        return;
    }

    ~listt() {
        this->clear();
    }
};
