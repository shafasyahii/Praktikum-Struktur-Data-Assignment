#include<iostream>
#include<queue>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // Constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Fungsi untuk menambahkan node ke tree
TNode* tambahNode(TNode* root, int data) {
    if (root == NULL) {
        return new TNode(data);
    }
    queue<TNode*> q;
    q.push(root);

    while (!q.empty()) {
        TNode* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new TNode(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new TNode(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder (node -> left);
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

// Fungsi untuk menampilkan child dari node yang diinput
void tampilChild(TNode* node, int value) {
    if (node == NULL) return;
    if (node->data == value) {
        if (node->left != NULL) {
            cout << "Left Child: " << node->left->data << endl;
        } else {
            cout << "Left Child: NULL" << endl;
        }
        if (node->right != NULL) {
            cout << "Right Child: " << node->right->data << endl;
        } else {
            cout << "Right Child: NULL" << endl;
        }
        return;
    }
    tampilChild(node->left, value);
    tampilChild(node->right, value);
}

// Fungsi untuk menampilkan semua descendant dari node yang diinput
void tampilDescendant(TNode* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    tampilDescendant(node->left);
    tampilDescendant(node->right);
}

int main() {
    TNode* root = NULL;
    int pilihan, data, nodeValue;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Node\n";
        cout << "2. Tampilkan Pre-Order\n";
        cout << "3. Tampilkan In-Order\n";
        cout << "4. Tampilkan Post-Order\n";
        cout << "5. Tampilkan Child dari Node\n";
        cout << "6. Tampilkan Descendant dari Node\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                root = tambahNode(root, data);
                break;
            case 2:
                cout << "Pre-Order: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-Order: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-Order: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Masukkan nilai node: ";
                cin >> nodeValue;
                tampilChild(root, nodeValue);
                break;
            case 6:
                cout << "Masukkan nilai node: ";
                cin >> nodeValue;
                cout << "Descendant dari " << nodeValue << ": ";
                tampilChild(root, nodeValue);
                tampilDescendant(root);
                cout << endl;
                break;
            case 7:
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    }
    return 0;
}