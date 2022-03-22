#include <iostream>

typedef struct List{
    int id;
    struct List *next;
}List;

int autoGeneratId(List *mainList);
List* creatingNewList(List *mainList);
List* searchingTheList(List *mainList, int valueSought);
void insertIntoListOfSpecificPlace(List *mainList, int insertBeforeThisNumber);
List* preparingAnIdToBeExclusion(List **mainList, int idToBeDeleted);
void confirmingDeletionOfId(List* mainListPreparedToDelete);
List* minimumIdList(List *mainList);
List* maximumIdList(List *mainList);
List* sucessorThisId(List *mainList, int id);
List* predecessorThisId(List *mainList, int id);
void test(List *mainList); //Here we can test the code, here we just print on screen all the id of the list we have

int main(int argc,  char const* argv[]){

    return 0;
}

int autoGeneratId(List *mainList){

    List *listToBeSearched;

    int newIdTemp = 0;

    for(listToBeSearched = mainList; listToBeSearched != NULL; listToBeSearched = listToBeSearched -> next){
        newIdTemp++;
    }
    return newIdTemp;
}

List* creatingNewList(List *mainList){
    List *newList = (List*)malloc(sizeof(List*));

    int newId = 0;
    newId = autoGeneratId(mainList);

    newList ->id =  newId++;
    newList -> next = mainList;

    return newList;
}

List* searchingTheList(List *mainList, int valueSought){

    List *listToBeSearched;
    for(listToBeSearched = mainList; listToBeSearched != NULL; listToBeSearched = listToBeSearched -> next){
        if(listToBeSearched -> id == valueSought){
            return listToBeSearched;
        }
    }
    return NULL;
}

void insertIntoListOfSpecificPlace(List *mainList, int insertBeforeThisNumber){

    List *specificList = searchingTheList(mainList, insertBeforeThisNumber);
    List *creationOfNewList = (List*)malloc(sizeof(List*));

    creationOfNewList -> id = autoGeneratId(mainList);
    creationOfNewList -> next = specificList -> next;
    specificList -> next = creationOfNewList;
}

List* preparingAnIdToBeExclusion(List **mainList, int idToBeDeleted){

    List* listTemporary, *lixo = NULL;

    if(*mainList)//verificando se o conteudo não é nulo
        if((*mainList) -> id == idToBeDeleted){
            lixo = *mainList;
            *mainList = lixo -> next;
        }else{
            listTemporary = *mainList;

            while(listTemporary -> next != NULL && listTemporary -> next -> id != idToBeDeleted){
                listTemporary = listTemporary -> next;
            }

            if(listTemporary -> next != NULL){
                lixo = listTemporary -> next;
                listTemporary -> next = lixo -> next;
            }

        }
        return lixo;
}

void confirmingDeletionOfId(List* mainListPreparedToDelete){
    if(mainListPreparedToDelete){
        free(mainListPreparedToDelete);
    }
    else{
        std::cout <<"Elemento inexistente";
    }
}

List* minimumIdList(List *mainList){

    List *minimumNumber = mainList;
    int minimumIdTemporary;

    while(minimumNumber != NULL){
        if(minimumNumber -> id <= minimumIdTemporary){
            minimumIdTemporary = minimumNumber -> id;
        }
        minimumNumber = minimumNumber -> next;
    }

    minimumNumber = searchingTheList(mainList, minimumIdTemporary);
    return minimumNumber;
}

List* maximumIdList(List *mainList){
    List *maximumNumber = mainList;
    int maximumIdTemporary = 0;

    while(maximumNumber != NULL){
        if(maximumNumber -> id >= maximumIdTemporary){
            maximumIdTemporary = maximumNumber -> id;
        }
        maximumNumber = maximumNumber -> next;
    }

    maximumNumber = searchingTheList(mainList, maximumIdTemporary);
    return maximumNumber;
}

List* sucessorThisId(List *mainList, int id){
    List *sucessorId = searchingTheList(mainList, ++id);

    if(sucessorId -> next == NULL){
        return NULL;
    }
    return sucessorId;
}

List* predecessorThisId(List *mainList, int id){
    List *predecessorId = searchingTheList(mainList, --id);

    if(predecessorId == NULL){
        return NULL;
    }
    return predecessorId;
}

void test(List *mainList){
    List *testeList;

    for(testeList = mainList; testeList != NULL; testeList = testeList -> next){
        std::cout << testeList -> id <<std::endl;
    }
}
