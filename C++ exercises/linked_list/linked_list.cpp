#include <iostream>
#include <string>

using namespace std;

struct Link {
    string value;
    Link* prev;
    Link* succ;
    Link(const string& v, Link* p = nullptr, Link* s = nullptr) : value{v}, prev{p}, succ{s} {}
};


class LinkedList{
    private:
        Link* head;
        Link* tail;
    public:
        LinkedList(){head = new Link(""); tail = new Link("", head, nullptr); head->succ = tail;}
        Link* getFirst() const;
        Link* getLast() const;
        Link* insert(Link* pos, const string& s);
        Link* add(Link* pos, const string& s);
        Link* erase(Link* pos);
        const Link* find(const string& obj) const;
        Link* advance(Link* pos, int n) const;
        ostream& operator<<(ostream& os);
        void push_back(const string& s);
        Link* pop_back();
        void push_front(const string& s);
        Link* pop_front();
};

int main(){
    LinkedList list = LinkedList();
    list.push_back("banane");
    list.push_back("cioccolata");
    list.push_back("caramelle");
    list.push_back("smarties");
    list.push_back("lions");
    list.push_front("coca-cola");
    list.operator<<(cout);
    list.erase(list.advance(list.getFirst(),3)); //elimina caramelle
    list.push_back("banane");
    list.pop_back();
    if(list.find("caramelle"))
        cout << "found\n";
    else
        cout << "not found\n";
    list.operator<<(cout);
    return 0;
}

Link* LinkedList::getFirst() const{
    if(head->succ == tail) 
        return nullptr;
    return head->succ;
}

Link* LinkedList::getLast() const{
    if(tail->prev == head) 
        return nullptr;
    return tail->prev;
}

Link* LinkedList::insert(Link* pos, const string& s){
    if(pos == head) return nullptr;
    Link* elem = new Link(s, pos->prev, pos);
    pos->prev->succ = elem;
    pos->prev = elem;
    return elem; 
}

Link* LinkedList::add(Link* pos, const string& s){
    if(pos == tail) return nullptr;
    Link* elem = new Link(s, pos, pos->succ);
    pos->succ->prev = elem;
    pos->succ = elem;
    return elem;
}

Link* LinkedList::erase(Link* pos){
    if(pos == head || pos == tail)  return nullptr;
    pos->succ->prev = pos->prev;
    pos->prev->succ = pos->succ;
    return pos;
}

const Link* LinkedList::find(const string& obj) const{
    Link* i = head->succ;
    while(i != tail){
        if(i->value == obj)
            return i;
        i = i->succ;
    }
    return nullptr;
}

void LinkedList::push_back(const string& s){
    insert(tail, s);
}

Link* LinkedList::pop_back(){
    return erase(getLast());
}

void LinkedList::push_front(const string& s){
    add(head, s);
}
        

Link* LinkedList::pop_front(){
    return erase(head);
}

Link* LinkedList::advance(Link* pos, int n) const{
    while(n > 0){
        if(pos->succ == tail){
            return nullptr;
        }
        pos = pos->succ;
        n--;
    }

    while(n < 0){
        if(pos->prev == head){
            return nullptr;
        }
        pos = pos->prev;
        n++;
    }

    return pos;
}

ostream& LinkedList::operator<<(ostream& os){
    if(!getFirst()) return os;
    os << "{";
    Link* pos = getFirst();
    while(pos->succ != tail){
        os << pos->value << ", ";
        pos = pos->succ;
    }
    os << pos->value <<"}\n";
    return os;
}