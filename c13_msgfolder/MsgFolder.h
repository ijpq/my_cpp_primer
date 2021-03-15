#ifndef MSGFOLDER_H
#define MSGFOLDER_H
#include<string>
#include<vector>
#include<memory>
#include<iostream>
#include<utility>
#include<set>
using namespace std;

class Folder; // forward declariation

class Message{
    friend class Folder;
public:
    // default constructor
    Message(const string& s);
    // copy constructor
    Message(const Message& Msg);
    // copy overload
    Message& operator=(const Message&);
    // move constructor
    Message(Message&&);
    // move overload
    Message& operator=(Message&&);
    // deconstructor
    ~Message();
    void save(Folder&); // put one message into folder indicated.
    void remove(Folder&); // delete one message from folder indicated.
    void swap(Message&, Message&);
private:
    std::set<Folder*> FolderPtrs; // what folders this message saved 
    string MsgInfo;
};

class Folder{
    // friend class Message;
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void rmMsg(Message*);
    void addMsg(Message*);
private:
    std::set<Message*> MessagePtr;
};

inline
void Folder::rmMsg(Message* MsgPtr){
    MessagePtr.erase(MsgPtr);
}

inline
void Folder::addMsg(Message* MsgPtr){
    MessagePtr.emplace(MsgPtr);
}


inline
void Message::save (Folder& folder){
    // put this message in folder.
    folder.addMsg(this);
    FolderPtrs.emplace(&folder);
    return ;
}

inline
void Message::remove(Folder& folder){
    folder.rmMsg(this); // remove this msg from folder.
    FolderPtrs.erase(&folder);
}

inline
Message::~Message(){
    for (auto Fptr:this->FolderPtrs){
        Fptr->rmMsg(this);
    }
};

inline
Message::Message(const string& s){
    MsgInfo = s;
    cout<<"MSG:"<<MsgInfo<<endl;
    }

inline
Message::Message(const Message& Msg):MsgInfo(Msg.MsgInfo),FolderPtrs(Msg.FolderPtrs){
// two different msg obj has diff ptrs
    for (auto Fptr:Msg.FolderPtrs){
        Fptr->addMsg(this); // put this mgs into folder.
    }
}

inline
Message& Message::operator=(const Message& Msg){

        for (auto f:this->FolderPtrs){
            f->rmMsg(this);
        }
        this->FolderPtrs = Msg.FolderPtrs;
        for (auto ff:Msg.FolderPtrs){
            ff->addMsg(this);
        }
        this->MsgInfo = Msg.MsgInfo;
        return *this;
    }
    
inline
Message::Message(Message&& Msg) noexcept{
        this->MsgInfo = Msg.MsgInfo;
        this->FolderPtrs = Msg.FolderPtrs;
        for (auto Fptr:Msg.FolderPtrs){
            Fptr->rmMsg(&Msg);
            Fptr->addMsg(this);
        }
        Msg.FolderPtrs.clear();
    }
inline
Message& Message::operator=(Message&& Msg) noexcept{

    this->MsgInfo = Msg.MsgInfo;
    for (auto Fptr: this->FolderPtrs){
        Fptr->rmMsg(this);
    }
    this->FolderPtrs = Msg.FolderPtrs;
    for (auto Fptr: Msg.FolderPtrs){
        Fptr->rmMsg(&Msg);
        Fptr->addMsg(this);
    }
    Msg.FolderPtrs.clear();
}

inline
void Message::swap(Message& lhs, Message& rhs){
        using std::swap;
        for (auto f:lhs.FolderPtrs){
            f->rmMsg(&lhs);
        }
        for (auto f:rhs.FolderPtrs){
            f->rmMsg(&rhs);
        }

        swap(lhs.MsgInfo, rhs.MsgInfo);

        swap(lhs.FolderPtrs, rhs.FolderPtrs);

        for (auto f:rhs.FolderPtrs){
            f->addMsg(&rhs);
        }
        for (auto f:lhs.FolderPtrs){
            f->addMsg(&lhs);
        }
    }



inline
Folder::Folder(const Folder& Fref):MessagePtr(Fref.MessagePtr){
    for (auto Mptr:Fref.MessagePtr){
        Mptr->FolderPtrs.insert(this);
    }
}

inline
Folder::~Folder(){
    for (auto Mptr:this->MessagePtr){
        Mptr->FolderPtrs.erase(this);
    }
    // this->MessagePtr.clear();
}

inline
Folder& Folder::operator=(const Folder& Fref){ // non const!!!
    if (this != &Fref){
        for (auto Mptr: MessagePtr){
            Mptr->FolderPtrs.erase(this);
        }
        this->MessagePtr = Fref.MessagePtr;
        for (auto Mptr:Fref.MessagePtr){
            Mptr->FolderPtrs.insert(this);
        }
    }
    return *this;
}
#endif