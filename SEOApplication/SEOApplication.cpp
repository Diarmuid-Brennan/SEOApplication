// SEOApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Diarmuid Brennan c00133947
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class node
{
public:
    std::string data = "";
    std::vector<std::string> urls;
    node* lchild;
    node* rchild;
    node* parent;
    node(std::string input) {
        data = input;
        lchild = NULL;
        rchild = NULL;
        parent = NULL;
    }
    void print()
    {
        for (int i = 0; i < urls.size(); i++)
        {
            std::cout << i + 1 << ".	" << urls[i] << "\n";
        }
    }
};

node* CreateNode(std::string, std::string);
node* Insert(node*, node*);
node* exists(node*, std::string);
node* put(node*);
node* get(node*);
void printOrder(node*);
void printPreOrder(node*);
void deleteURL(node*);
int count(node*, std::string); 
void existsURL(node*);
std::vector<std::string> searchForUrls(node*, std::vector<std::string>, std::string);
node* removeKeyword(node*);
void parentNode(node*);
node* findPredecessor(node*);


int main()
{
    node* head = NULL;
    node* getKeyword;
    std::string checkWord;

    int response = -1;
    while (response != 0)
    {
        std::cout << "\n********MENU********\n";
        std::cout << "1. Add a url to the application\n";
        std::cout << "2. Return a keywords associated urls\n";
        std::cout << "3. Output all currently stored keywords\n";
        std::cout << "4. Delete an url from a keywords associated list\n";
        std::cout << "5. Return a count of the current urls assocaited with a keword\n";
        std::cout << "6. Return all keywords associated with a url\n";
        std::cout << "7. Remove a keyword from the application\n";
        std::cout << "8. Return a childs parent\n";
        std::cout << "0. Exit\n";
        std::cout << "*********************\n\n";

        std::cout << "Enter a value to select a operation from the menu :  ";
        std::cin >> response;

        switch (response)
        {
        case 1:
            std::cout << "1. Add a url/keywords to the application.\n";
            head = put(head);
            std::cout << "KEYWORDS(inorder) :    ";
            printOrder(head);
            std::cout << "\n";
            break;
        case 2:
            std::cout << "2. Return a keywords associated urls.\n";
            std::cout << "KEYWORDS :    ";
            printOrder(head);
            std::cout << "\n";
            getKeyword = get(head);
            if (getKeyword == NULL)
            {
                std::cout << "The entered keyword does not exist in the tree\n";
            }
            else 
            {
                
                std::cout << "The associated urls are :\n";
                getKeyword->print();
            }
            break;
        case 3:
            std::cout << "3. Output all currently stored keywords.\n";
            std::cout << "KEYWORDS(inorder)  :    ";
            printOrder(head);
            std::cout << "\n";
            std::cout << "KEYWORDS(preorder) :    ";
            printPreOrder(head);
            std::cout << "\n";
            break;
        case 4:
            std::cout << "4. Delete an url from a keywords associated list.\n";
            deleteURL(head);
            break;
        case 5:
            std::cout << "5. Return a count of the current urls assocaited with a keword.\n";
            std::cout << "KEYWORDS :    ";
            printOrder(head);
            std::cout << "\n";
            std::cout << "Enter the keyword you would like the url count for :  ";
            std::cin >> checkWord;
            std::cout << "The number of urls associated with " << checkWord << " is " << count(head, checkWord);
            std::cout << "\n";
            break;
        case 6:
            std::cout << "6. Return all keywords associated with a url.\n";
            existsURL(head);
            break;
        case 7:
            std::cout << "7. Remove a keyword from the application.\n";
            std::cout << "KEYWORDS(inorder)  :    ";
            printOrder(head);
            std::cout << "\n";
            std::cout << "KEYWORDS(preorder) :    ";
            printPreOrder(head);
            std::cout << "\n";
            head = removeKeyword(head);
            std::cout << "KEYWORDS(inorder)  :    ";
            printOrder(head);
            std::cout << "\n";
            std::cout << "KEYWORDS(preorder) :    ";
            printPreOrder(head);
            std::cout << "\n";
            break;
        case 8:
            std::cout << "8. Retrn nodes parent.\n";
            std::cout << "KEYWORDS(inorder)  :    ";
            printOrder(head);
            std::cout << "\n";
            std::cout << "KEYWORDS(preorder) :    ";
            printPreOrder(head);
            std::cout << "\n";
            parentNode(head);
            break;
        case 0:
            std::cout << "You have exited the application\n";
            break;
        default:
            std::cout << "That is not an option\n";
        }
    }
    return 0;
}

node* CreateNode(std::string url, std::string keyword)
{

    node* newnode = new node(keyword);
    newnode->urls.push_back(url);
    return newnode;

}

void parentNode(node* root)
{
    std::string word;
    std::cout << "Enter a keyword to search for :   ";
    std::cin >> word;

    node* searchForKeyword = exists(root, word);
    if (searchForKeyword == NULL)
    {
        std::cout << "keyword dos not exist\n  ";
    }
    else
    {
        if (searchForKeyword->parent == NULL)
        {
            std::cout << "keyword is the root node\n  ";
        }
        else
        {
            std::cout << "THe parent node is " << searchForKeyword->parent->data << "\n";
        }
        
    }
    

}

node* Insert(node* root, node* newnode) {
    if (!root) {
        root = newnode;
        
    }
    else if (newnode->data.compare(root->data) < 0)
    {
        node* leftchild = Insert(root->lchild, newnode);
        root->lchild = leftchild;

        // Set parent of root of left subtree 
        leftchild->parent = root;

        /*root->lchild = Insert(root->lchild, newnode); 
        newnode->parent = root;*/
    }  
    else if (newnode->data.compare(root->data) > 0)
    {
        node* rightchild = Insert(root->rchild, newnode);
        root->rchild = rightchild;

        // Set parent of root of left subtree 
        rightchild->parent = root;

        /*root->rchild = Insert(root->rchild, newnode);
        newnode->parent = root;*/
    }      
    return root;
}

node* exists(node* root, std::string keyword)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (root->data.compare(keyword) == 0)
            return root;
        else if (root->data.compare(keyword) > 0)
        {
            root = exists(root->lchild, keyword);
            return root;
        }
        else
        {
            root = exists(root->rchild, keyword);
            return root;
        }
    }
}

node* get(node* root)
{
    std::string word;
    std::cout << "Enter a keyword to search for :   ";
    std::cin >> word;

    node* searchForKeyword = exists(root, word);
    return searchForKeyword;
}


node* put(node* root) {
    std::string url;
    std::cout << "Enter the url to enter into the tree :    ";
    
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore();
    std::getline(std::cin, url);


    int maxKeywords = 0;
    bool inRange = false;
    while (!inRange)
    {
        std::cout << "Enter the number of keywords (1-4) :    ";
        std::cin >> maxKeywords;
        if (maxKeywords > 0 && maxKeywords <= 4)
        {
            inRange = true;
        }
        else
        {
            std::cout << "The option selected is not valid\n";
        }
    }

    while (maxKeywords > 0)
    {
        std::string word;
        std::cout << "Enter a keyword for the url : ";
        std::cin >> word;

        node* searchForKeyword = exists(root, word);
        if (searchForKeyword == NULL)//if the keyword doesnt exist already
        {
            node* newNode = CreateNode(url, word);//create a new keyword node
            root = Insert(root, newNode);//insert it to the BST
            maxKeywords--;
        }
        else//if the keyword already exists
        {
            if (searchForKeyword->urls.size() == 5)//if keyword already has 4 urls attached to it
            {
                std::cout << "This keyword already has the maximun number of urls assigned. ";
                std::cout << "Please select another keyword \n";
            }
            else//if < 4 assign the url to the keyword
            {
                searchForKeyword->urls.push_back(url);
                maxKeywords--;
            }
        }
    }
    std::cout << "\n";
    return root;
}

void printOrder(node* root)
{
    if (root == NULL)
        return;
    else
    {
        printOrder(root->lchild);
        std::cout << root->data << ", ";
        printOrder(root->rchild);
    }
    
}

void printPreOrder(node* root)
{
    if (root == NULL)
        return;
    else
    {
        std::cout << root->data << ", ";
        printPreOrder(root->lchild);
        printPreOrder(root->rchild);
    }

}

void deleteURL(node* root)
{
    std::cout << "KEYWORDS :    ";
    printOrder(root);
    std::cout << "\n";
    node* deleteUrl = get(root);
    if (deleteUrl == NULL)
    {
        std::cout << "The keyword does not exist\n";
    }
    else
    {
        std::cout << "The associated urls are :\n";
        deleteUrl->print();
        int deleteIndex = 0;
        bool inRange = false;
        while (!inRange)
        {
            std::cout << "Enter the number of the URL you would like to delete: ";
            std::cin >> deleteIndex;
            if (deleteIndex > 0 && deleteIndex <= deleteUrl->urls.size())
            {
                inRange = true;
            }
            else
            {
                std::cout << "The option selected is not valid\n";
            }
        }

        std::vector<std::string>::iterator it;
        it = deleteUrl->urls.begin();
        it += (deleteIndex - 1);
        deleteUrl->urls.erase(it);

        std::cout << "The associated urls are now:\n";
        deleteUrl->print();
    }
    

    
}

int count(node* root, std::string word)
{
    node* searchForKeyword = exists(root, word);
    if (searchForKeyword == NULL)
    {
        std::cout << "The entered keyword does not exist :\n";
        return 0;
    }
    return searchForKeyword->urls.size();
}

void existsURL(node* root)
{
    std::string searchUrl;
    std::cout << "Enter the url to search for any keywords :    ";
    std::cin >> searchUrl;

    std::vector<std::string> urls;
    urls = searchForUrls(root, urls, searchUrl);

    if (urls.size() == 0)
    {
        std::cout << "The url has not been entered previously\n";
    }
    else
    {
        std::cout << "The keywords associated are :  ";
        for (int i = 0; i < urls.size(); i++)
        {
            std::cout << urls[i] << ", ";
        }

    }
    std::cout << "\n";
}

std::vector<std::string> searchForUrls(node* root, std::vector<std::string> foundUrls, std::string url)
{
    if (root == NULL)
        return foundUrls;
    else
    {
        foundUrls = searchForUrls(root->lchild, foundUrls, url);
        for (int i = 0; i < root->urls.size(); i++)
        {
            if (root->urls[i].compare(url) == 0)
            {
                foundUrls.push_back(root->data);
            }
        }
        foundUrls = searchForUrls(root->rchild, foundUrls, url);
        return foundUrls;
    }
}

node* removeKeyword(node* root)
{
    std::string word;
    std::cout << "Enter a keyword to remove from the tree :   ";
    std::cin >> word;

    node* searchForKeyword = exists(root, word);
    if (searchForKeyword == NULL)
    {
        std::cout << "The keyword does not exist in the tree.\n";
    }
    //if the node is a leaf
    else if (searchForKeyword->lchild == NULL && searchForKeyword->rchild == NULL)
    {
        if (searchForKeyword->parent == NULL)
        {
            root = NULL;
        }
        else if (searchForKeyword->parent->data > searchForKeyword->data)
        {
            searchForKeyword->parent->lchild = NULL;
        }
        else
        {
            searchForKeyword->parent->rchild = NULL;
        } 
        std::cout << "The keyword was successfully removed.\n";
    }
    //if the node has 2 children, find its predecessor
    else if (searchForKeyword->lchild != NULL && searchForKeyword->rchild != NULL)
    {
        node* predecessor = findPredecessor(searchForKeyword);
        if (predecessor == searchForKeyword->lchild)
        {
            searchForKeyword->lchild = predecessor->lchild;
            searchForKeyword->data = predecessor->data;
            searchForKeyword->urls = predecessor->urls;
        }
        else
        {
            predecessor->parent->rchild = predecessor->lchild;
            searchForKeyword->data = predecessor->data;
            searchForKeyword->urls = predecessor->urls;
        }
        std::cout << "The keyword was successfully removed.\n";
    }
    //if the node has one child
    else
    {
        
        if (searchForKeyword->lchild != NULL)
        {
            if (searchForKeyword->parent == NULL)
            {
                root = searchForKeyword->lchild;
                searchForKeyword->lchild->parent = NULL;
            }
            else if (searchForKeyword->parent->data > searchForKeyword->data)
            {
                searchForKeyword->parent->lchild = searchForKeyword->lchild;
                searchForKeyword->lchild->parent = searchForKeyword->parent;
            }
            else
            {
                searchForKeyword->parent->rchild = searchForKeyword->lchild;
                searchForKeyword->lchild->parent = searchForKeyword->parent;
            }
        }
        else
        {
            if (searchForKeyword->parent == NULL)
            {
                root = searchForKeyword->rchild;
                searchForKeyword->rchild->parent = NULL;
            }
            else if (searchForKeyword->parent->data > searchForKeyword->data)
            {
                searchForKeyword->parent->lchild = searchForKeyword->rchild;
                searchForKeyword->rchild->parent = searchForKeyword->parent;
            }
            else
            {
                searchForKeyword->parent->rchild = searchForKeyword->rchild;
                searchForKeyword->rchild->parent = searchForKeyword->parent;
            }
        }
        std::cout << "The keyword was successfully removed.\n";
    }
    return root;
}

node* findPredecessor(node* root)
{
    node* currentNode = root->lchild;
    while (currentNode->rchild != NULL)
    {
        currentNode = currentNode->rchild;
    }
    return currentNode;
}