# SEOApplication
Search Engine Optimization project using a Binary Search Tree
The Search Engine Optimization (SEO) application uses URL addresses and keywords to improve a site’s search visibility. 
The keywords will act as an index to access the URL’s. The application will store the URL’s and associated keywords, allowing up to 4 keywords to be provided for each URL. 
The keywords will be stored as nodes in a Binary Search Tree (BST). 
A BST is a linked structure where each node in the tree has the property that the value of the root node is greater than the value of its left child and less than the value of its right child. 
The nodes will be stored alphabetically using the keywords as the nodes value. 
Each node will contain its keyword, a vector array to store each of the URL’s linked to the keyword, a pointer to the nodes left child, a pointer to its right child and a pointer to its parent node. 
Each nodes vector list will store up to a maximum of 5 URL addresses. A menu will be displayed to the user allowing the user access to the operations provided by the application.
The operations will  allow the user to;
- Insert a new URL – the user enters a URL to be added into the application. They are given the option of inserting up to 4 keywords to be associated with the URL. The application first checks if an entered keyword already exists in the BST. If it does not exist, new node is created containing the keyword and it is added to the BST. The URL is stored in the nodes vector array. If the keyword already exists, the URL is added to the URL list of the existing keyword (once the vector size is <=5).
- Retrieve a keywords associated URLS – the user enters in a keyword. The application returns the list of the URLs associated with that keyword.
- Output all keywords – an in order search of the BST is carried out. The application outputs each keyword from the BST in alphabetical order.
- Delete a URL – the user enters in a keyword. The application displays the list of URLs associated with the keyword. The user selects which URL they would like to remove from the list. The URL is removed from the list.
- Count a keywords associated URLS – the user enters in a keyword . A count of the number of URLs currently stored in the entered keywords URL list is returned.
- Retrieve a URLs associated keywords – the user enters in a URL. The application will return the list of the keywords from the BST that currently store that URL in the keywords URL vector list.
- Delete a keyword – the user enters in a keyword. The keyword is removed from the BST while the properties of the BST are maintained. 
All operations are provided as options from a menu displayed at the user interface. Each operation has clear instructions provided on the user interface as to how they should be used. The application was developed using the C++ programming language.
