#include "src/Interface.h"

int main_Lab_2_4() {
    Tree *root = new Tree(-1);
    BinaryTree *binaryRoot = new BinaryTree(-1);
    const string RedInConsole = "\u001B[31m";
    const string BlueInConsole = "\u001B[34m";
    const string PurpleInConsole = "\u001B[35m";
    const string StandardConsole = "\u001B[0m";
    while (true) {
        cout << RedInConsole << "Menu:" << endl;
        cout << BlueInConsole << "1" << StandardConsole << " - dialog." << endl;
        cout << BlueInConsole << "2" << StandardConsole << " - demon;" << endl;
        cout << PurpleInConsole << "Your choice: " << StandardConsole;
        int choiceValue;
        cin >> choiceValue;
        switch (choiceValue) {
            case 1:
                Interface::dialog(root, binaryRoot);
                break;
            case 2:
                Interface::demon();
                break;
            default:
                cout << "Incorrect option selected!" << endl;
        }
    }
    return 0;
}
