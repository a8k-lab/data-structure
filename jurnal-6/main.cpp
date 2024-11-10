#include "DLL.h"

int main() {
    List L;
    infotype H;
    address Elm;

    createList(L);
    printList(L);

    H.title = "example";
    H.url = "https://www.example.com";
    H.timestamp = "2024-10-18/10:00:00";
    H.visitcount = 1;
    Elm = createElemen(H);
    insertLast(L, Elm);
    printList(L);

    H.title = "OpenAI";
    H.url = "https://www.openai.com";
    H.timestamp = "2024-10-18/10:15:00";
    H.visitcount = 9;
    Elm = createElemen(H);
    insertLast(L, Elm);
    printList(L);

    H.title = "GitHub";
    H.url = "https://www.github.com";
    H.timestamp = "2024-10-18/10:19:53";
    H.visitcount = 17;
    Elm = createElemen(H);
    insertLast(L, Elm);
    printList(L);

    // deleteFirst(L, Elm);
    // printList(L);

    // deleteLast(L, Elm);
    // printList(L);

    // deleteLast(L, Elm);
    // printList(L);

    cout << findElemen(L, "OpenAI") << endl;
    cout << moreThanOnce(L) << endl;

    return 0;
}
