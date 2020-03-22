#include <vector>
#include <list>
#include <iostream>
#include <sstream>
using namespace std;

struct Client{
    string name;
    int actions;
    int patience;
    Client(string _name, int _actions, int _patience){
        this->name = _name;
        this->actions = _actions;
        this->patience = _patience;
    }
    string toString(){
        return name + ":" + to_string(actions) + ":" + to_string(patience);
    }
};

struct Banco{
    vector<Client*> teller;
    list<Client*> queue_in;
    list<Client*> queue_out;
    int received {0};
    int lost {0};
    int tics {0};

    Banco(int teller_size){
        teller = vector<Client*>(teller_size);
    }

    void insert(Client * client){
        queue_in.push_back(client);
    }

    bool empty(){
        for(auto * client : teller)
            if(client != nullptr)
                return false;
        return queue_in.empty() && queue_out.empty();
    }

    void tic(){
        tics++;
        while(!queue_out.empty()){
            delete queue_out.front();
            queue_out.pop_front();
            this->lost += 1;
        }
        for(int i = 0; i < (int) teller.size(); i++){
            if(teller[i] != nullptr){
                if(teller[i]->actions > 0){
                    teller[i]->actions -= 1;
                    this->received += 1;
                }else{
                    queue_out.push_back(teller[i]);
                    teller[i] = nullptr;
                }
            }else{
                if(queue_in.size() > 0){
                    teller[i] = queue_in.front(); 
                    queue_in.pop_front();
                }
            }
        }
        for(auto it = queue_in.begin(); it != queue_in.end(); ){
            if((*it)->patience > 0){
                (*it)->patience -= 1;
                it++;
            }else{
                queue_out.push_back(*it);
                it = queue_in.erase(it);
            }
        }
        
    }

    void show_all(){
        for(auto client : teller){
            cout << "[" << (client == nullptr ? "" : client->toString()) << "]";
        }
        cout << "\nin :{ ";
        for(auto client : queue_in)
            cout << client->toString() << " ";
        cout << "}\nout:{ ";
        for(auto client : queue_out)
            cout << client->toString() << " ";
        cout << "}\n";
    }
};

int main(){
    Banco banco(3);

    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        if(cmd == "show"){
            banco.show_all();
        }else if(cmd == "in"){
            string name;
            int actions, patience;
            ss >> name >> actions >> patience;
            banco.insert(new Client(name, actions, patience));
        }else if(cmd == "init"){
            int size;
            ss >> size;
            banco = Banco(size);
        }else if(cmd == "tic"){
            banco.tic();
        }else if(cmd == "finish"){
            while(!banco.empty())
                banco.tic();
            cout << "received: " << banco.received << endl;
            cout << "lost: " << banco.lost - 1<< endl;
            cout << "tics: " << banco.lost << endl;
        }else{
            cout << "fail: command not found\n";
        }
    }
}
