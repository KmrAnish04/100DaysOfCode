struct node{
    int key;
    int value;
    
    node *pre;
    node *next;
    node(int keyData, int valData){
        key=keyData;
        value=valData;
    }
};

class LRUCache
{
    private:

    public:
    unordered_map<int, node*> keyMap;
    // queue<node> que;
    node *head=new node(-1, -1);
    node *front=head;
    node *back=head;
    node *tmp=head;
    int cacheSize;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        cacheSize=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if (keyMap.find(key) == keyMap.end()) {
            return -1; //Key is not in the map
        }
        
        node *reqNode=keyMap[key];
        int popedData=reqNode->value;
        
        if(back!=front){
            // pop this node from its origional position and push into the back of LL
            // poping from the front
            if(back!=reqNode){
                
                reqNode->pre->next=reqNode->next;
                reqNode->next->pre=reqNode->pre;
                
                // pushing into the front
                back->next=reqNode;
                reqNode->next=NULL;
                reqNode->pre=back;
                
                tmp=reqNode;
                back=reqNode;
            }
        }
        
        return popedData;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        if(keyMap.find(key)!=keyMap.end()){
            node *nodeRepl = keyMap[key];
            nodeRepl->pre->next = nodeRepl->next;
            nodeRepl->next->pre=nodeRepl->pre;
            
            back->next=nodeRepl;
            nodeRepl->next=NULL;
            nodeRepl->pre=back;
            
            nodeRepl->value=value;
            tmp=nodeRepl;
            back=nodeRepl;
        }
        else{
            
            node *newNode=new node(key, value);
            if(keyMap.size()<cacheSize){
                if(tmp->key==-1){
                    tmp->next=newNode;
                    newNode->pre=tmp;
                    front = newNode;
                    back = newNode;
                }
                else{
                    tmp->next=newNode;
                    newNode->pre=tmp;
                    back = newNode;
                    
                }
                tmp=newNode;
                keyMap[key] = newNode;
                
                
            }
            else{
                //firstly we will pop from front, then push from back
                
                // Poping from front
                node *firstNode=head->next;
                head->next=firstNode->next;
                firstNode->next->pre=head;
                keyMap.erase(firstNode->key);
                // keyMap[firsNode->key]=NULL;
                free(firstNode);
                front= head->next;
                
                // Pushing from back
                back->next=newNode;
                newNode->pre=back;
                
                
                
            }
        }
    }
};