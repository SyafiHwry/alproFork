#include <iostream>
using namespace std;

struct ListNode {
    char val;
    ListNode* prev;  // anak kiri
    ListNode* next;  // anak kanan

    ListNode(char x) : val(x), prev(nullptr), next(nullptr) {}
};

// ─── QUEUE sederhana tanpa library ────────────────────────────────────────
// BFS butuh queue, tapi kita buat manual pakai array
struct Queue {
    ListNode* data[100];
    int front;
    int rear;

    Queue() : front(0), rear(0) {}

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

    ListNode* head       = new ListNode('H');
    head->prev           = new ListNode('A');
    head->next           = new ListNode('K');
    head->prev->next     = new ListNode('C');

    cout << "=== Struktur Tree ===" << endl;
    cout << "Root            : " << head->val             << endl;
    cout << "Child kiri  (A) : " << head->prev->val       << endl;
    cout << "Child kanan (K) : " << head->next->val       << endl;
    cout << "Leaf        (C) : " << head->prev->next->val << endl;

    cout << "\n=== Traversal ===" << endl;

    cout << "Preorder  (Root-L-R) : ";
    preorder(head);   // H A C K
    cout << endl;

    cout << "Inorder   (L-Root-R) : ";
    inorder(head);    // A C H K
    cout << endl;

    cout << "Postorder (L-R-Root) : ";
    postorder(head);  // C A K H
    cout << endl;

    cout << "\n=== BFS / Level Order ===" << endl;
    bfs(head);
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