#include<iostream>
#include<queue>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node -> left);
        cout << node -> data << " ";
        inOrder(node -> right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

// Fungsi tambahan untuk menampilkan node child
void displayChildNodes(TNode *node) {
    if (node == NULL) return;
    cout << "Child nodes of " << node->data << ": ";
    if (node->left != NULL)
        cout << node->left->data << " ";
    if (node->right != NULL)
        cout << node->right->data << " ";
    cout << endl;
}

// Fungsi untuk menampilkan descendant dari node
void displayDescendants(TNode *node) {
    if (node == NULL) return;
    queue<TNode*> q;
    q.push(node);
    cout << "Descendants of " << node->data << ": ";
    while (!q.empty()) {
        TNode *current = q.front();
        q.pop();
        if (current->left != NULL) {
            cout << current->left->data << " ";
            q.push(current->left);
        }
        if (current->right != NULL) {
            cout << current->right->data << " ";
            q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    // Buat sebuah pohon kosong
    TNode *root = NULL;
    
    int choice, data;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah node" << endl;
        cout << "2. PreOrder traversal" << endl;
        cout << "3. InOrder traversal" << endl;
        cout << "4. PostOrder traversal" << endl;
        cout << "5. Tampilkan child nodes dari sebuah node" << endl;
        cout << "6. Tampilkan descendants dari sebuah node" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Masukkan data untuk node baru: ";
                cin >> data;
                if (root == NULL) {
                    root = new TNode(data);
                } else {
                    // Implementasi tambahan untuk menambahkan node ke pohon
                }
                break;
            case 2:
                cout << "PreOrder traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "InOrder traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "PostOrder traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Masukkan data node yang ingin ditampilkan child nodes-nya: ";
                cin >> data;
                // Implementasi panggilan fungsi untuk menampilkan child nodes
                break;
            case 6:
                cout << "Masukkan data node yang ingin ditampilkan descendants-nya: ";
                cin >> data;
                // Implementasi panggilan fungsi untuk menampilkan descendants
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}