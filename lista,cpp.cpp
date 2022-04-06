#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;


struct node
{
    node *para;
    char emri;
    int paga;
    node *pas;
};

void last(struct node *head,struct node *fund){
	while(head->pas != NULL){
		if(fund->pas==NULL){
			head->pas = NULL;
		}
		else{
			head = head->pas;
			fund = fund->pas;
		}
		
	}
	
}
	

	

void same(struct node *a, struct node *b)
{
    while (a != NULL)
    {
    	
		
        if (a->paga == b->paga){
		
		cout<<"\n";
		cout<<"Lista ka dy punojes me page te barabarte";
		cout<<"\n";
		cout << a->emri <<  "  "  << a->paga <<" " <<"leke";
        cout<<"\n";
        cout << b->emri <<  "  "  << b->paga <<" " <<"leke";
		break;
            
 
        /* If we reach here, then a and b are not NULL and
           their data is same, so move to next nodes in both
           lists */
    }
        else{
        
        b = b->pas;
        
        }
        
        a = a->pas;
    }
 
}


// Funksioni për të futur një nyje të re në mënyrë të renditur
// një listë dydrejtimore renditur
void sort2(struct node **head_ref, struct node *newNode)
{
    struct node *current;
 
    // nqs lista eshte bosh
    if (*head_ref == NULL)
        *head_ref = newNode;
 
    // nqs nyja duhet te vendoset ne fillim
    // te listes dydrejtimore
    else if ((*head_ref)->paga >= newNode->paga) {
        newNode->pas = *head_ref;
        newNode->pas->para = newNode;
        *head_ref = newNode;
    }
 
    else {
        current = *head_ref;
 
        // gjejme nyjen pas së cilës nyja e re duhet të futet
        while (current->pas != NULL &&
               current->pas->paga < newNode->paga)
            current = current->pas;
 
        /*Bejme lidhjet e duhura */
 
        newNode->pas = current->pas;
 
        // nëse nyja e re nuk futet
        // në fund të listës
        if (current->pas != NULL)
            newNode->pas->para = newNode;
 
        current->pas = newNode;
        newNode->para = current;
    }
}
 
// funksioni për të renditur një listë dydrejtimore duke përdorur insertion sort(renditjen e futjes)
void sort(struct node **head_ref)
{
    // Inicializojme 'sorted' - nje liste dydrejtimore e renditur
    struct node *sorted = NULL;
 
    // Përshkojme listën dydrejtimore te dhene dhe
// fusim çdo nyje në "sorted"
    struct node *current = *head_ref;
    while (current != NULL) {
 
        // Ruajm next per iteracionin e rradhes
        struct node *next = current->pas;
 
        // heqim te gjitha lidhjet per te krijuar 'current'
        // nje nyje e re per futje ne iteracion
        current->para = current->pas = NULL;
 
        // fusim current ne 'sorted' liste dydrejtimore
        sort2(&sorted, current);
 
        // Update current
        current = next;
    }
 
    // Update head_ref
    *head_ref = sorted;
}

// funksioni per te printuar listen
void print(struct node *head)
{
    while (head != NULL) {
        cout << head->emri <<  "  "  << head->paga <<" " <<"leke";
        cout<<"\n";
        head = head->pas;
    }
}

// funksioni per te printuar listen pas fshirjes se elementit te fundit
void print2(struct node *head)
{
	cout<<"\n";
	cout<<"\n";
	cout<<"Lista pas fshirjes se elementit te fundit";
    while (head != NULL) {
    	cout<<"\n";
        cout << head->emri <<  "  "  << head->paga <<" " <<"leke";
        head = head->pas;
    }
}

//funksion per fshirjen e elementit te pare, paga me e vogel
void paga1(struct node *head){
head = head->pas;
cout<<"\n";
cout << "Lista pas fshirjes se pages minimale";
cout<<"\n";
while(head != NULL){

cout << head->emri<< "  "<<head->paga<< "  "<<"leke";
cout<<"\n";
head = head->pas;
}
}


int main(){

// krijojme nyjen e pare head
struct node *head;
head = (struct node *)malloc(sizeof(struct node));

// plotesojme parametrat e saj
head -> para = NULL;
head -> emri = 'a';
head -> paga = 600;
head -> pas = NULL;

// krijojme nyjen e rradhes
struct node *current1;
current1 = (struct node *)malloc(sizeof(struct node));

// plotesojme parametrat e saj
current1 -> para = head;
current1 -> emri = 'b';
current1 -> paga = 200;
current1 -> pas = NULL;

head -> pas = current1;

// krijojme nyjen e rradhes
struct node *current2;
current2 = (struct node *)malloc(sizeof(struct node));

// plotesojme parametrat e saj
current2 -> para = current1;
current2 -> emri = 'c';
current2 -> paga = 100;
current2 -> pas = NULL;

current1 -> pas = current2;

// krijojme nyjen e rradhes
struct node *current3;
current3 = (struct node *)malloc(sizeof(struct node));

// plotesojme parametrat e saj
current3 -> para = current2;
current3 -> emri = 'd';
current3 -> paga = 600;
current3 -> pas = NULL;

current2 -> pas = current3;

// krijojme nyjen e rradhes
struct node *current4;
current4 = (struct node *)malloc(sizeof(struct node));

// plotesojme parametrat e saj
current4 -> para = current3;
current4 -> emri = 'e';
current4 -> paga = 500;
current4 -> pas = NULL;

current3 -> pas = current4;


cout << "Lista para renditjes se pagave";
cout<<"\n";
cout<<"\n";
print(head);
 
sort(&head);
 
cout<<"\n";
cout << "Lista pas renditjes se pagave";
cout<<"\n";
cout<<"\n";
print(head);

paga1(&*head);

same(head, current1);

last(head,current1);

print2(head);

return 0;

}

