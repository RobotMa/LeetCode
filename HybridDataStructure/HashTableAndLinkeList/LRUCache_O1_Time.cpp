#include <iostream>
#include <unordered_map>
#include <list>
#include <limits>

/*
p : put
g : get
p-1 -> p-2 -> p-3 -> g-1 -> p-4 -> p-5 -> p-6

1
2 -> 1 
3 -> 2 -> 1
1 -> 3 -> 2
4 -> 1 -> 3 -> 2
5 -> 4 -> 1 -> 3 -> 2
6 -> 5 -> 4 -> 1 -> 3
 
*/

/* Single Linked List 
*/
struct Node
{
    Node(const int value_input, const int key_input) : value(value_input), key(key_input) {}
    Node* next;
    Node* prev;
    int key;
    int value;    
};

class LRUCache {
    public:
        LRUCache(std::size_t capacity) : capacity_(capacity)
        {
            head_ = new Node(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
            tail_ = new Node(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
            head_->next = tail_;
            tail_->prev = head_;
        }

        int get(const int key)
        {
            auto result = cacheMap_.find(key);
            
            if (result != cacheMap_.end())
            {
                return result->second->value;
            }

            return -1;
        }

        void put(const int key, const int value)
        {
            if(get(key) != -1)
            {
                cacheMap_[key]->value = value;
            }
            else
            {
                Node* node = new Node(value, key);

                if ( size_ == capacity_)
                {
                   evict(); 
                }
                addHead(node);
                cacheMap_.insert({key, node});
            }
        }

        size_t size() { return size_; }

    private:
        /**
            remove the least recently used element - at the tail of the single linked list
        */
        void evict()
        {
            Node* tmpNode = tail_->prev;
            delete tail_->prev;
            cacheMap_.erase(tmpNode->key);
            tail_->prev = tmpNode->prev;
            --size_;
        }

        void addHead(Node* node)
        {
            node->next = head_->next;
            head_->next->prev = node;
            head_->next = node;
            ++size_;
        }


    private:
        std::unordered_map<int, Node*> cacheMap_;
        size_t size_ = 0;
        size_t capacity_;
        Node* head_;
        Node* tail_;
};

int main()
{
   LRUCache cache(5);

   cache.put(1, 1);
   std::cout << " size is " << cache.size() << '\n';
   cache.put(2, 2);
   std::cout << " size is " << cache.size() << '\n';
   cache.put(3, 3);
   std::cout << " size is " << cache.size() << '\n';
   cache.put(4, 4);
   std::cout << " size is " << cache.size() << '\n';
   cache.put(5, 5);
   std::cout << " size is " << cache.size() << '\n';
   cache.put(6, 6);
   std::cout << " size is " << cache.size() << '\n';
   
   std::cout << cache.get(7) << '\n';
   std::cout << cache.get(6) << '\n';
   std::cout << cache.get(5) << '\n';
   std::cout << cache.get(4) << '\n';
   std::cout << cache.get(3) << '\n';
   std::cout << cache.get(2) << '\n';
   std::cout << cache.get(1) << '\n';
   
   return 0; 
}