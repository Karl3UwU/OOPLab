#include <iostream>
#include <functional>

template<typename T>
class TreeNode {
public:
    T value;
    TreeNode* nextSibling;
    TreeNode* firstChild;
    TreeNode* parentNode;

    TreeNode(T val) {
        value = val;
        nextSibling = firstChild = parentNode = nullptr;
    }

    ~TreeNode() {
        while (firstChild != nullptr) {
            TreeNode* temp = firstChild;
            firstChild = firstChild->nextSibling;
            delete temp;
        }
    }

    void add_node(TreeNode<T>* node) {
        if (!firstChild) {
            firstChild = node;
        }
        else {
            TreeNode<T>* current = firstChild;
            while (current->nextSibling) {
                current = current->nextSibling;
            }
            current->nextSibling = node;
        }
        node->parentNode = this;
    }


    void sort_children(std::function<bool(const T&, const T&)> compare = nullptr) {
        if (!firstChild) return;

        bool swapped;
        TreeNode<T>* current;
        TreeNode<T>* lastPtr = nullptr;

        if (compare == nullptr) {
            compare = [](const T& a, const T& b) -> bool { return a < b; };
        }

        do {
            swapped = false;
            current = firstChild;

            while (current->nextSibling != lastPtr) {
                if (compare(current->nextSibling->value, current->value)) {
                    std::swap(current->value, current->nextSibling->value);
                    swapped = true;
                }
                current = current->nextSibling;
            }
            lastPtr = current;

        } while (swapped);
    }

    static int count(TreeNode<T>* node) {
        if (!node) return 0;
        int counter = 0;
        for (TreeNode<T>* child = node->firstChild; child != nullptr; child = child->nextSibling) {
            counter += 1 + TreeNode<T>::count(child);
        }
        return counter;
    }

    static TreeNode<T>* get_node(TreeNode<T>* node, int index) {
        if (!node) return nullptr;
        TreeNode<T>* current = node->firstChild;
        for (int i = 0; current != nullptr && i < index; i++) {
            current = current->nextSibling;
        }
        return current;
    }

    static TreeNode<T>* find(TreeNode<T>* root, std::function<bool(const T&)> compare) {
        if (!root) return nullptr;
        if (compare(root->value)) return root;

        TreeNode<T>* result = nullptr;
        for (TreeNode<T>* child = root->firstChild; child != nullptr && result == nullptr; child = child->nextSibling) {
            result = TreeNode<T>::find(child, compare);
        }
        return result;
    }

    static void delete_node(TreeNode<T>*& node) {
        if (!node) return;

        // check if node is first child
        if (node->parentNode && node->parentNode->firstChild == node) {
            node->parentNode->firstChild = node->nextSibling;
        }
        else if (node->parentNode){
            // node not first child, get previous sibling
            TreeNode<T>* prev = node->parentNode->firstChild;
            while (prev && prev->nextSibling != node) {
                prev = prev->nextSibling;
            }
            // update previous sibling
            if (prev) {
                prev->nextSibling = node->nextSibling;
            }
        }
        // delete node
        delete node;
        node = nullptr;
    }

    static void insert(TreeNode<T>* parent, TreeNode<T>* newNode, int index) {
        // xd
        if (!parent || index < 0) return;

        if (index == 0) { // special needs for first place
            newNode->nextSibling = parent->firstChild;
            parent->firstChild = newNode;
        }
        else {
            TreeNode<T>* current = parent->firstChild;
            for (int i = 1; current && i < index; ++i) {
                current = current->nextSibling;
            }
            if (current) {
                newNode->nextSibling = current->nextSibling;
                current->nextSibling = newNode;
            }
        }
    }
};

int main() {
    TreeNode<int>* root = new TreeNode<int>(0);
    // Add child nodes
    TreeNode<int>* child1 = new TreeNode<int>(1);
    TreeNode<int>* child2 = new TreeNode<int>(2);
    root->add_node(child1);
    root->add_node(child2);
    // Fetch a child node by index
    TreeNode<int>* selectedChild = TreeNode<int>::get_node(root, 1); // Should return child2
    // Delete a node
    TreeNode<int>::delete_node(child1);

    // Cleanup
    TreeNode<int>::delete_node(root);
    return 0;
}