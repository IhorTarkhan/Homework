#ifndef HOMEWORK_INTERFACE_LAB_6_H
#define HOMEWORK_INTERFACE_LAB_6_H

#include "DataStructure.h"
#include "OrderedLists/LinkedList.h"
#include "OrderedLists/VectorList.h"
#include "OrderedLists/NotBalancedBinaryTree.h"
#include "OrderedLists/AVL_Tree.h"
#include "OrderedLists/Tree_2_3.h"

class Interface_lab_6 {
private:
    AVL_Tree *avlTree = new AVL_Tree();
    LinkedList *linkedList = new LinkedList();
    NotBalancedBinaryTree *binaryTree = new NotBalancedBinaryTree();
    Tree_2_3 *tree23 = new Tree_2_3();
    VectorList *vectorList = new VectorList();
public:
    void dialog() {
        cout << "Available options:" << endl;
        cout << "Choice 1 : append new Position(x, y, z) to AVL Tree" << endl;
        cout << "Choice 2 : remove all Position from AVL Tree" << endl;
        cout << "Choice 3 : search all Positions with parameters" << endl;
        cout << "Choice 4 : search all Positions in range" << endl;
        cout << "Choice 5 : print AVL Tree" << endl;
        cout << endl;
        cout << "Available options:" << endl;
        cout << "Choice 6 : append new Position(x, y, z) to Linked List" << endl;
        cout << "Choice 7 : remove all Position from Linked List" << endl;
        cout << "Choice 8 : search all Positions with parameters" << endl;
        cout << "Choice 9 : search all Positions in range" << endl;
        cout << "Choice 10: print Linked List" << endl;
        cout << endl;
        cout << "Available options:" << endl;
        cout << "Choice 11: append new Position(x, y, z) to Not Balanced Binary Tree" << endl;
        cout << "Choice 12: remove all Position from Not Balanced Binary Tree" << endl;
        cout << "Choice 13: search all Positions with parameters" << endl;
        cout << "Choice 14: search all Positions in range" << endl;
        cout << "Choice 15: print Not Balanced Binary Tree" << endl;
        cout << endl;
        cout << "Available options:" << endl;
        cout << "Choice 16: append new Position(x, y, z) to 2-3 Tree" << endl;
        cout << "Choice 17: remove all Position from 2-3 Tree" << endl;
        cout << "Choice 18: search all Positions with parameters" << endl;
        cout << "Choice 19: search all Positions in range" << endl;
        cout << "Choice 20: print 2-3 Tree" << endl;
        cout << endl;
        cout << "Available options:" << endl;
        cout << "Choice 21: append new Position(x, y, z) to Vector List" << endl;
        cout << "Choice 22: remove all Position from Vector List" << endl;
        cout << "Choice 23: search all Positions with parameters" << endl;
        cout << "Choice 24: search all Positions in range" << endl;
        cout << "Choice 25: print Vector List" << endl;
        cout << endl;
        cout << "Your choice: ";
        int n;
        cin >> n;
        double x;
        double y;
        double z;
        vector<DataStructure> list;
        switch (n) {
            case 1:
                cout << "Enter X of new Position: ";
                cin >> x;
                cout << "Enter Y of new Position: ";
                cin >> y;
                cout << "Enter Z of new Position: ";
                cin >> z;
                avlTree->append(DataStructure(x, y, z));
                cout << "Added!" << endl;
                break;
            case 2:
                cout << "Enter X of Positions witch you want to delete: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to delete: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to delete: ";
                cin >> z;
                avlTree->removeAll(DataStructure(x, y, z));
                cout << "Removed!" << endl;
                break;
            case 3:
                cout << "Enter X of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to search: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to search: ";
                cin >> z;
                list = avlTree->search(DataStructure(x, y, z));
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 4:
                cout << "Enter first limit of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter second limit of of Positions witch you want to search: ";
                cin >> y;
                avlTree->search(x, y);
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 5:
                cout << avlTree->toString();
                break;
            case 6:
                cout << "Enter X of new Position: ";
                cin >> x;
                cout << "Enter Y of new Position: ";
                cin >> y;
                cout << "Enter Z of new Position: ";
                cin >> z;
                linkedList->append(DataStructure(x, y, z));
                cout << "Added!" << endl;
                break;
            case 7:
                cout << "Enter X of Positions witch you want to delete: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to delete: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to delete: ";
                cin >> z;
                linkedList->removeAll(DataStructure(x, y, z));
                cout << "Removed!" << endl;
                break;
            case 8:
                cout << "Enter X of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to search: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to search: ";
                cin >> z;
                list = linkedList->search(DataStructure(x, y, z));
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 9:
                cout << "Enter first limit of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter second limit of of Positions witch you want to search: ";
                cin >> y;
                linkedList->search(x, y);
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 10:
                cout << linkedList->toString();
                break;
            case 11:
                cout << "Enter X of new Position: ";
                cin >> x;
                cout << "Enter Y of new Position: ";
                cin >> y;
                cout << "Enter Z of new Position: ";
                cin >> z;
                binaryTree->append(DataStructure(x, y, z));
                cout << "Added!" << endl;
                break;
            case 12:
                cout << "Enter X of Positions witch you want to delete: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to delete: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to delete: ";
                cin >> z;
                binaryTree->removeAll(DataStructure(x, y, z));
                cout << "Removed!" << endl;
                break;
            case 13:
                cout << "Enter X of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to search: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to search: ";
                cin >> z;
                list = binaryTree->search(DataStructure(x, y, z));
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 14:
                cout << "Enter first limit of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter second limit of of Positions witch you want to search: ";
                cin >> y;
                binaryTree->search(x, y);
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 15:
                cout << binaryTree->toString();
                break;
            case 16:
                cout << "Enter X of new Position: ";
                cin >> x;
                cout << "Enter Y of new Position: ";
                cin >> y;
                cout << "Enter Z of new Position: ";
                cin >> z;
                tree23->append(DataStructure(x, y, z));
                cout << "Added!" << endl;
                break;
            case 17:
                cout << "Enter X of Positions witch you want to delete: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to delete: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to delete: ";
                cin >> z;
                tree23->removeAll(DataStructure(x, y, z));
                cout << "Removed!" << endl;
                break;
            case 18:
                cout << "Enter X of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to search: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to search: ";
                cin >> z;
                list = tree23->search(DataStructure(x, y, z));
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 19:
                cout << "Enter first limit of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter second limit of of Positions witch you want to search: ";
                cin >> y;
                tree23->search(x, y);
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 20:
                cout << tree23->toString();
                break;
            case 21:
                cout << "Enter X of new Position: ";
                cin >> x;
                cout << "Enter Y of new Position: ";
                cin >> y;
                cout << "Enter Z of new Position: ";
                cin >> z;
                vectorList->append(DataStructure(x, y, z));
                cout << "Added!" << endl;
                break;
            case 22:
                cout << "Enter X of Positions witch you want to delete: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to delete: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to delete: ";
                cin >> z;
                vectorList->removeAll(DataStructure(x, y, z));
                cout << "Removed!" << endl;
                break;
            case 23:
                cout << "Enter X of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter Y of Positions witch you want to search: ";
                cin >> y;
                cout << "Enter Z of Positions witch you want to search: ";
                cin >> z;
                list = vectorList->search(DataStructure(x, y, z));
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 24:
                cout << "Enter first limit of Positions witch you want to search: ";
                cin >> x;
                cout << "Enter second limit of of Positions witch you want to search: ";
                cin >> y;
                vectorList->search(x, y);
                for (int i = 0; i < list.size(); ++i) {
                    cout << list[i].toString() << endl;
                }
                break;
            case 25:
                cout << vectorList->toString();
                break;
            default:
                cout << "Error case" << endl;
                break;
        }
    }

    string demon() {
        const string BlueInConsole = "\u001B[34m";
        const string YellowInConsole = "\u001B[33m";
        const string StandardConsole = "\u001B[30m";

        AVL_Tree avlTree = AVL_Tree();
        LinkedList linkedList = LinkedList();
        NotBalancedBinaryTree binaryTree = NotBalancedBinaryTree();
        Tree_2_3 tree23 = Tree_2_3();
        VectorList vectorList = VectorList();
        vector<DataStructure> list;
        string demoResult;

        demoResult += "---------AVL Tree---------\n";
        demoResult += "Add Position (10, 10, 10)\n";
        avlTree.append(DataStructure(10, 10, 10));
        demoResult += "Added!\n";

        demoResult += "Printing:\n";
        demoResult += avlTree.toString();

        demoResult += "Searching Position (10, 10, 10):\n";
        list = avlTree.search(DataStructure(10, 10, 10));
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }

        demoResult += "Removing Position (10, 10, 10)\n";
        avlTree.removeAll(DataStructure(10, 10, 10));
        demoResult += "Removed!\n";

        demoResult += "Printing:\n";
        demoResult += avlTree.toString();

        demoResult += "Rewrite on random List (size = 10)\n";
        avlTree = AVL_Tree::createRandomListWithSize(10);
        demoResult += "Done!\n";

        demoResult += "Printing:\n";
        demoResult += avlTree.toString();

        demoResult += "Searching Position between distance to (0, 0, 0): 40 - 100 :\n";
        list = avlTree.search(100, 40);
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }
        demoResult += "\n";

        demoResult += "---------Linked List---------\n";
        demoResult += "Add Position (10, 10, 10)\n";
        linkedList.append(DataStructure(10, 10, 10));
        demoResult += "Added!\n";

        demoResult += "Printing:\n";
        demoResult += linkedList.toString();

        demoResult += "Searching Position (10, 10, 10):\n";
        list = linkedList.search(DataStructure(10, 10, 10));
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }

        demoResult += "Removing Position (10, 10, 10)\n";
        linkedList.removeAll(DataStructure(10, 10, 10));
        demoResult += "Removed!\n";

        demoResult += "Printing:\n";
        demoResult += linkedList.toString();

        demoResult += "Rewrite on random List (size = 10)\n";
        linkedList = LinkedList::createRandomListWithSize(10);
        demoResult += "Done!\n";

        demoResult += "Printing:\n";
        demoResult += linkedList.toString();

        demoResult += "Searching Position between distance to (0, 0, 0): 40 - 100 :\n";
        list = linkedList.search(100, 40);
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }
        demoResult += "\n";

        demoResult += "---------Binary Tree---------\n";
        demoResult += "Add Position (10, 10, 10)\n";
        binaryTree.append(DataStructure(10, 10, 10));
        demoResult += "Added!\n";

        demoResult += "Printing:\n";
        demoResult += binaryTree.toString();

        demoResult += "Searching Position (10, 10, 10):\n";
        list = binaryTree.search(DataStructure(10, 10, 10));
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }

        demoResult += "Removing Position (10, 10, 10)\n";
        binaryTree.removeAll(DataStructure(10, 10, 10));
        demoResult += "Removed!\n";

        demoResult += "Printing:\n";
        demoResult += binaryTree.toString();

        demoResult += "Rewrite on random List (size = 10)\n";
        binaryTree = NotBalancedBinaryTree::createRandomListWithSize(10);
        demoResult += "Done!\n";

        demoResult += "Printing:\n";
        demoResult += binaryTree.toString();

        demoResult += "Searching Position between distance to (0, 0, 0): 40 - 100 :\n";
        list = binaryTree.search(100, 40);
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }
        demoResult += "\n";

        demoResult += "-------- 2-3 Tree --------\n";
        demoResult += "Add Position (10, 10, 10)\n";
        tree23.append(DataStructure(10, 10, 10));
        demoResult += "Added!\n";

        demoResult += "Printing:\n";
        demoResult += tree23.toString();

        demoResult += "Searching Position (10, 10, 10):\n";
        list = tree23.search(DataStructure(10, 10, 10));
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }

        demoResult += "Removing Position (10, 10, 10)\n";
        tree23.removeAll(DataStructure(10, 10, 10));
        demoResult += "Removed!\n";

        demoResult += "Printing:\n";
        demoResult += tree23.toString();

        demoResult += "Rewrite on random List (size = 10)\n";
        tree23 = Tree_2_3::createRandomListWithSize(10);
        demoResult += "Done!\n";

        demoResult += "Printing:\n";
        demoResult += tree23.toString();

        demoResult += "Searching Position between distance to (0, 0, 0): 40 - 100 :\n";
        list = tree23.search(100, 40);
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }
        demoResult += "\n";

        demoResult += "---------AVL Tree---------\n";
        demoResult += "Add Position (10, 10, 10)\n";
        vectorList.append(DataStructure(10, 10, 10));
        demoResult += "Added!\n";

        demoResult += "Printing:\n";
        demoResult += vectorList.toString();

        demoResult += "Searching Position (10, 10, 10):\n";
        list = vectorList.search(DataStructure(10, 10, 10));
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }

        demoResult += "Removing Position (10, 10, 10)\n";
        vectorList.removeAll(DataStructure(10, 10, 10));
        demoResult += "Removed!\n";

        demoResult += "Printing:\n";
        demoResult += vectorList.toString();

        demoResult += "Rewrite on random List (size = 10)\n";
        vectorList = VectorList::createRandomListWithSize(10);
        demoResult += "Done!\n";

        demoResult += "Printing:\n";
        demoResult += vectorList.toString();

        demoResult += "Searching Position between distance to (0, 0, 0): 40 - 100 :\n";
        list = vectorList.search(100, 40);
        for (int i = 0; i < list.size(); ++i) {
            demoResult += list[i].toString() + "\n";
        }
        demoResult += "\n";


        return demoResult;
    }

    void benchmark() {
        cout << "Enter the time in milliseconds"
                " that you want to increase the planingDuration of the demonstration iterations (without display) - ";
        long planingDuration;
        cin >> planingDuration;
        long numberOfIterations = 1;

        auto fullStart = high_resolution_clock::now();

        auto start = high_resolution_clock::now();
        auto stop = high_resolution_clock::now();
        auto realDuration = duration_cast<milliseconds>(stop - start);
        while (realDuration.count() < planingDuration) {
            start = high_resolution_clock::now();
            for (long i = 0; i < numberOfIterations; ++i) {
                demon();
            }
            stop = high_resolution_clock::now();
            realDuration = duration_cast<milliseconds>(stop - start);
            cout << numberOfIterations << " iterations - " << realDuration.count() << " milliseconds" << endl;
            numberOfIterations *= 2;
        }

        auto fullStop = high_resolution_clock::now();
        cout << "Full time is "
             << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " milliseconds" << endl;

    }
};

#endif
