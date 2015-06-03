#include <iostream>
#include <list>


using namespace std;



/** \class Node - класс описания и методов поля
 */
class Node{
    list<Node> nodes; /**< список дочерних полей */
    int serialNum; /**< содержимое поля */
 public:
     /** \brief Конструктор без параметров
      */

     Node();
     /** \brief Конструктор с заданием содержимого поля
      *
      * \param [in] serial - содержимое для ноды
      *
      */

     Node(int);
     /** \brief Метод добавления дочерних полей
      *
      * \param [in] node - ссылка на объект новой ноды
      *
      */

     void add(const Node&);
     /** \brief Метод поиска по дереву
      *
      * \param [in] serial - содержимое ноды для поиска
      * \return ссылку на ноду
      *
      */

     Node& search(int);
     /** \brief Метод получения содержимого ноды
      *
      * \return значение ноды
      *
      */

     int  getSerial();
     /** \brief Метод распечатывает список в обратном порядке
      *
      */

     void printForward();
     /** \brief Метод распечатывает список в прямом порядке
      *
      */

     void printBack();
     /** \brief Метод распечатывает список в симметричном порядке
      *
      */

     void printSymetric();
};
Node * node; /**< глобальная переменная для указателя на искомый элементы списка */
Node::Node(){
    count = 0;
}
void Node::printForward(){

    if(serialNum != 0){
    cout<<serialNum<<" ";
    }
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printForward();
    }

}
void Node::printBack(){

    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printBack();
    }
    if(serialNum != 0){
    cout<<serialNum<<" ";
    }
}

void Node::printSymetric(){
    bool flag = true;
    if(nodes.size() == 0){
        if(serialNum != 0){
            cout<<serialNum<<" ";
        }
    }
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printSymetric();
        if(flag){
            if(serialNum != 0){
                cout<<serialNum<<" ";
            }
            flag = false;
        }
    }
}
Node::Node(int serial){
    serialNum = serial;
}
int Node::getSerial() {
    return serialNum;
}

Node& Node::search(int num){
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        if((*it).getSerial() == num){
            node = &(*it);
        } else {
            (*it).search(num);
        }
    }
    return (*node);
}

void Node::add(const Node& node){
    nodes.push_back(node);
}

/** \brief Метод main основной метод программы
 *
 * \return код ошибки
 *
 */

int main()
{
    /** \brief Заполнение списка и распечатка
     */

    int serialCounter = 0;
    Node * baseNode = new Node(serialCounter);
    int countOfNodes = 0;
    int nextSerial = 0;
    cin>>countOfNodes;

    for(int i = 0;i < countOfNodes; i ++){
        cin>>nextSerial;
        if(nextSerial ==  0){
            ++serialCounter;
            baseNode->add(*(new Node(serialCounter)));
        } else {
            ++serialCounter;
            baseNode->search(nextSerial).add(*(new Node(serialCounter)));
        }

    }
    baseNode->printForward();
    cout<<"\n";
    baseNode->printBack();
    cout<<"\n";
    baseNode->printSymetric();



    return 0;
}
