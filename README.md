Sumario do codigo

mainList == lista aonde está sendo salvo todos os nós

int autoGeneratId(List *mainList);
O ID é gerado automaticamente sem precisar de nenhuma ação humana
_____________________________________________________________________________________________________________________________________________________________
List* creatingNewList(List *mainList);
Cria uma nova lista em nosso nó
_____________________________________________________________________________________________________________________________________________________________
List* searchingTheList(List *mainList, int valueSought);
Procura na lista por um valor especifico passado pelo programador em valueSought
_____________________________________________________________________________________________________________________________________________________________

void insertIntoListOfSpecificPlace(List *mainList, int insertBeforeThisNumber);
Insere uma nova lista em um lugar especifico. 
EX: Se o programador quer uma nova lista entre o ID 5 e 6, o programador passa o numero 6 como valor em insertBeforeThisNumber e é acrescentada a lista
_____________________________________________________________________________________________________________________________________________________________

List* preparingAnIdToBeExclusion(List **mainList, int idToBeDeleted);
O programa prera a exclusão de uma lista de acordo com o ID passado em idToBeDeleted.

(SEMPRE que se usa essa função é necessario em seguida usar o *confirmingDeletionOfId*).

void confirmingDeletionOfId(List* mainListPreparedToDelete);

Você confirma a exclusão do id que foi recebido em uma lista na função *preparingAnIdToBeExclusion*
_____________________________________________________________________________________________________________________________________________________________
List* minimumIdList(List *mainList);
Recebe o menor ID da lista
_____________________________________________________________________________________________________________________________________________________________
List* maximumIdList(List *mainList);
Recebe o maior id da lista
_____________________________________________________________________________________________________________________________________________________________
List* sucessorThisId(List *mainList, int id);
Recebe o sucessor do ID passado
_____________________________________________________________________________________________________________________________________________________________
List* predecessorThisId(List *mainList, int id);
Recebe o antecessor do ID passado
_____________________________________________________________________________________________________________________________________________________________
void test(List *mainList);
Um teste criado que printa na tela os ID de todas as listas
