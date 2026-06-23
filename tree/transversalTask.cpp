#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* prev;  // anak kiri
    ListNode* next;  // anak kanan
};

// ─── QUEUE sederhana tanpa library ────────────────────────────────────────
// BFS butuh queue, tapi kita buat manual pakai array
struct Queue {
    ListNode* data[100];
    int front;
    int rear;

    Queue() : front(0), rear(0) {} //kenapa 0 bukan null

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(ListNode* node) {
        data[rear++] = node;
    }

    ListNode* dequeue() {
        return data[front++];
    }
};


// ─── BFS / LEVEL ORDER : Level 0 → Level 1 → Level 2 → ... ──────────────
// Kunjungi node per level dari atas ke bawah, kiri ke kanan
// Pakai Queue: masukkan root, lalu tiap node dikeluarkan → masukkan anak-anaknya
class Tree{
private:
    ListNode* createNode(int val) {
        ListNode* newNode = new ListNode;
        newNode->val = val;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

    void bfs(ListNode* root) {
        if (root == nullptr) return;
    
        Queue q;
        q.enqueue(root);           // mulai dari root
    
        int level = 0;
    
        while (!q.isEmpty()) {
            // hitung berapa node di level sekarang
            int nodeCount = q.rear - q.front;
    
            cout << "Level " << level << " : ";
    
            // proses semua node di level ini
            for (int i = 0; i < nodeCount; i++) {
                ListNode* current = q.dequeue();
                cout << current->val << " ";
    
                // masukkan anak-anak ke queue untuk level berikutnya
                if (current->prev != nullptr) q.enqueue(current->prev);
                if (current->next != nullptr) q.enqueue(current->next);
            }
    
            cout << endl;
            level++;
        }
    }
    
    // ─── PREORDER : Root → Kiri → Kanan ──────────────────────────────────────
    void preorder(ListNode* node) {
        if (node == nullptr) return;    
        cout << node->val << " ";
        preorder(node->prev);
        preorder(node->next);
    }
    
    // ─── INORDER : Kiri → Root → Kanan ───────────────────────────────────────
    void inorder(ListNode* node) {
        if (node == nullptr) return;
        inorder(node->prev);
        cout << node->val << " ";
        inorder(node->next);
    }
    
    // ─── POSTORDER : Kiri → Kanan → Root ─────────────────────────────────────
    void postorder(ListNode* node) {
        if (node == nullptr) return;
        postorder(node->prev);
        postorder(node->next);
        cout << node->val << " ";
    }

    void insertFirst(ListNode*& head, int val) {
        ListNode* newNode = createNode(val);
        if(head == nullptr) {
            head = newNode;
        } else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

public:
    int intData, pilihan, jumlah;
    char charData;
    string strData;
    ListNode* head = nullptr;
    void inputUser() {
        cout << "Jumlah yang akan anda input: ";
        cin >> jumlah;

        cout << "Masukkan data: ";
        cin >> intData;
        createNode(intData);
        while(intData < jumlah) {
            cout << "Masukkan data: ";
            cin >> intData;
            insertFirst(head, intData);
        }
        cout << "------------------------" <<endl;
        displayList(head);
    }

    void binaryTree(ListNode* node) {
        bfs(node);
    }
    void preOrder(ListNode* node) {
        preorder(node);
    }
    void inOrder(ListNode* node) {
        inorder(node);
    }
    void postOrder(ListNode* node) {
        postorder(node);
    }

    void displayList(ListNode* head) {
        ListNode* current = head;
        cout << "Informasi tentang setiap node:" << endl;
        while (current != nullptr) {
            cout << current->val << " " <<endl;
            // cout << "Alamat: " << current << endl;
            // cout << "Nilai: " << current->val << endl;
            // cout << "Alamat prev: " << current->prev << endl;
            // cout << "Alamat next: " << current->next << endl << endl;
            current = current->next;
        }
    cout << "---------------------------------------" <<endl;
}

};


int main() {
    /*
     * Struktur tree yang dibangun manual:
     *
     *         H              <- Level 0 (root)
     *        / \
     *       A   K            <- Level 1
     *        \
     *         C              <- Level 2 (leaf)
     */
    Tree obj;
    ListNode* head = nullptr;
    // head->prev           = new ListNode('A');
    // head->next           = new ListNode('K');
    // head->prev->next     = new ListNode('C');

    obj.inputUser();

    cout << "=== Struktur Tree ===" << endl;
    // obj.displayList(head);
    // cout << "Root            : " << head->val             << endl;
    // cout << "Child kiri  (A) : " << head->prev->val       << endl;
    // cout << "Child kanan (K) : " << head->next->val       << endl;
    // cout << "Leaf        (C) : " << head->prev->next->val << endl;

    cout << "\n=== Traversal ===" << endl;

    cout << "Preorder  (Root-L-R) : ";
    obj.preOrder(head);   // H A C K
    cout << endl;

    cout << "Inorder   (L-Root-R) : ";
    obj.inOrder(head);    // A C H K
    cout << endl;

    cout << "Postorder (L-R-Root) : ";
    obj.postOrder(head);  // C A K H
    cout << endl;

    cout << "\n=== BFS / Level Order ===" << endl;
    obj.binaryTree(head);
    /*
     * Level 0 : H
     * Level 1 : A K
     * Level 2 : C
     */

    // Bebaskan memori
    delete head->prev->next;
    delete head->prev;
    delete head->next;
    delete head;

    return 0;
}