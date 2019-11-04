/*
CS3 - Binary Search Tree
Updated by: Allen Harper -- on 10/25/19

Doc: https://docs.google.com/document/d/1YdH5Ky6O3JMnyxvq9duhYZy-sN468DtakS3r2sVJTdI/edit
*/
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cctype>
#include "strip.h"
#include "bst.h"

struct node{
    string word;
    int count;
};

vector<string> readFile(){
    vector<string> words;
    ifstream input;
    input.open("csi.txt");
    
    if(input.is_open()){
        string delimiter = " ";
        string word;
        string line;

        while(getline(input, line)){
            stringstream ss(line);
            while (getline(ss, word, ' '))
            {
                if(word.length() >= 1)
                {
                    int i = 0;
                    string lowerWord = "";
                    word = strip(word);
                    while (word[i])
                    {
                        char c=word[i];
                        string s(1, tolower(c));
                        lowerWord.append(s);
                        i++;
                    }
                    words.push_back(lowerWord);
                }
            }
        }  
    }
    input.close();

    return words;
}

void showTop10Nodes(){
    
}

int main(){
    BST<string> tree;
    vector<string> words = readFile();
    
    for(int i = 0; i <= words.size(); i++)
    {
        // cout << "Inserting:'" << words[i] << "' into database." << endl;
        tree.insert(words[i]);
    }

    int input;
    bool run = true;
    while (run)
    {
        system("CLS");
        cout << "What would you like to do?"
             << "\n1. Show all word in order"
             << "\n2. Show all word in preorder"
             << "\n3. Show all word in postorder"
             << "\n4. Output 10 most frequent words to file"
             << "\n5. Search for specific word"
             << "\n6. Delete word/node"
             << "\n7. Exit Program." 
             << "\n>";
        cin >> input;

        string temp;
        switch (input)
        {
        case 1:
            tree.inorder();
            cout << "\nPress enter to continue." << endl;
            cin.get();
            cin.get();
            break;
        case 2:
            tree.preorder();
            cout << "\nPress enter to continue." << endl;
            cin.get();
            cin.get();
            break;
        case 3:
            tree.postorder();
            cout << "\nPress enter to continue." << endl;
            cin.get();
            cin.get();
            break;
        case 4:
            // open file
            // string file;
            // cout << "\nWhat is the name of the out put file that\n you would like to save the data to?" << endl;
            // cin >> file;

            // ofstream fout;
            // fout.open(file);

            

            cout << "\nPress enter to continue." << endl;
            cin.get();
            cin.get();
            break;
        case 5:
            cout << "Enter the word you would like to search for." << "\n>";
            cin >> temp;
            cout << "Found "<< tree.find(temp)->count << " instances of '" << tree.find(temp)->data << "'" << endl;
            cout << "\nPress enter to continue." << endl;
            cin.get();
            cin.get();
            break;
        case 6:
            cout << "Enter the word you would like to remove." << "\n>";
            cin >> temp;
            tree.remove(temp);
            cout << "\nPress enter to continue." << endl;
            cin.get();
            cin.get();
            break;
        case 7:
            cout << "Closing program. \nPress enter to continue." << endl;
            cin.get();
            cin.get();
            run = false;
            break;
        default:
            cout << "Please enter a integer with in the menu." << endl;
            cin.get();
            cin.get();
            break;
        }
    }

    return 0;
}