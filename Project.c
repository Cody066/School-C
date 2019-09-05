#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

struct Patient{
    char HospName [50];
    char Triage [50];
    char PatName [50];
    char NurseName [50];
    char InsurName [50];
    char Policy [50];
    char DocName [50];
    char Diagnosis [100];
    char Cost [50];
    struct Patient *next;  
};

struct Patient *first;
struct Patient *current;
struct Patient *new;
struct Patient *last ;
struct Patient *Create(void);
struct Patient *FileLoad(void);

void FileSave(void);
void Display(void);
void Add(void);
void Delete(void);
void Edit(void);
void Sort(void);
void TotalCost(void);
void Swap(struct Patient *a, struct Patient *b); 
int Count();

int main () {
    FILE *fp;
    char filename[100];
    char writestr[100];
    char readstr[100];
    char sentinel[2];
    char ch;
    char newData [20];
    int valid = 0;



while (valid == 0) {    

        puts("What would you like to do ? \n [1]Enter new patient\n [2]Load from file\n [3]Display current patients\n [4]Edit patients\n [5]Save to file\n [6]Delete a patient\n [7]Sort by Triage\n [8]Total Cost\n");
        fgets(newData,20,stdin);
        strtok(newData, "\n");
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (*newData == '1') {
            //create list
            //Add to list
            //no touch
           Add();
        
        } else if (*newData == '2'){    
           //kinda works come back to it 
            FileLoad();

        }else if (*newData == '3'){
            //it works dont touch
            Display();
            puts("End"); 

        } else if (*newData == '4'){

            //it works dont touch 
            Edit();


        } else if (*newData == '5'){
            //save to file
            FileSave();

        } else if (*newData == '6'){
            //delete a patient
            Delete();

        } else if (*newData == '7'){

            Sort();

        } else if (*newData == '8'){

            TotalCost();

        } else {
            valid =1;
        }

        
    }
    return 0;
}


struct Patient *FileLoad(void){

    FILE *fp;
    char fileName[100];
    int count = 0;

    printf("Enter a file name:");
    //gets keyboard input
    fgets(fileName, 100, stdin);
    strtok(fileName, "\n");

    fp = fopen(fileName, "r");
        if (fp == NULL) {
            puts ("No such file");
            exit(1);
        }

    while (!feof(fp)) {

        if(first==NULL){
            first=Create();
            current=first;
        } else {
            current=first;
            while(current->next) 
            current=current->next;
            new = Create();
            current->next=new;
            current=new;
        }

        fscanf(fp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];\n", &current->HospName, &current->Triage, &current->NurseName, &current->InsurName, &current->Policy, &current->DocName, &current->Diagnosis, &current->Cost);
        current->next = 0;
       
    }
    
    return first;

}


void FileSave(void){

    //it works dont touch

    FILE *fp;
    char filename[100];
    printf("Enter a file name:");
    //gets keyboard input
    fgets(filename, 100, stdin);
    strtok(filename, "\n");
    int Trilvl = 0;
    float MedCost = 0;
    current = first;
    
    
    //opens the file
    fp = fopen(filename, "a");

    if(fp){
            fputs(current->HospName, fp);
            fputs(";", fp);
            fputs(current->Triage,fp);
            fputs(";", fp);
            fputs(current->NurseName, fp);
            fputs(";", fp);
            fputs(current->InsurName, fp);
            fputs(";", fp);
            fputs(current->Policy, fp);
            fputs(";", fp);
            fputs(current->DocName, fp);
            fputs(";", fp);
            fputs(current->Diagnosis, fp);
            fputs(";", fp);
            fputs(current->Cost,fp);
            fputs("\n", fp);
    }
    fclose(fp);

        while (current->next != 0){
            
            
            fp = fopen(filename, "a");

            if (fp) {

            current = current->next;
            fputs(current->HospName, fp);
            fputs(";", fp);
            fputs(current->Triage,fp);
            fputs(";", fp);
            fputs(current->NurseName, fp);
            fputs(";", fp);
            fputs(current->InsurName, fp);
            fputs(";", fp);
            fputs(current->Policy, fp);
            fputs(";", fp);
            fputs(current->DocName, fp);
            fputs(";", fp);
            fputs(current->Diagnosis, fp);
            fputs(";", fp);
            fputs(current->Cost,fp);
            fputs("\n", fp);

            
            }
            fclose(fp);
        }    
        
}

void Display(void){
    //working, dont touch

    int count=1;
    if(first==NULL){
        puts("Nothing to show");
        return;
    }
    puts("Showing all records:");
    current=first;
    while(current){
        printf("Hospital: %s Triage: %s Nurse: %s Insurance: %s Policy #: %s Doctor: %s Diagnosis: %s Cost: %s \n",current->HospName, current->Triage, current->NurseName,
                current->InsurName, current->Policy, current->DocName, current->Diagnosis, current->Cost);
        current=current->next;
        count++;
    }

}

void Add(void) {
    //working, don't touch
    int ch;

    if(first==NULL){
        first=Create();
        current=first;
    } else {
        current=first;
        while(current->next) 
        current=current->next;
        new = Create();
        current->next=new;
        current=new;
    }
    puts("Enter Hospital : \n");
    scanf("%s", &current->HospName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Triage Level : \n");
    scanf("%s", &current->Triage);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Patient Name : \n");
    scanf("%s", &current->PatName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Nurse : \n");
    scanf("%s", &current->NurseName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Insurance Prov : \n");
    scanf("%s", &current->InsurName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Policy : \n");
    scanf("%s", &current->Policy);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Doc Name : \n");
    scanf("%s", &current->DocName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Diagnosis : \n");
    scanf("%s", &current->Diagnosis);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Cost : \n");
    scanf("%s", &current->Cost);
    while ((ch = getchar()) != '\n' && ch != EOF);
    current->next = NULL;
 

}

struct Patient *Create(void){
    //working, don't touch
    //create a blank structure and return it to add to fill
    struct Patient *a;
    a = (struct Patient *)malloc(sizeof(struct Patient));
    if(a==NULL){
        puts("Some kind of malloc() error");
        exit(1);
    }


    return(a);
}

void Delete(void){
    //working dont touch
    struct Patient *previous; 
    int r,c;
    if(first==NULL) {
        puts("No records to remove");
        return;
    } else {
    puts("Choose a record to remove:");
    Display();
    }

    scanf("%d",&r);
    while(getchar()!='\n'); //pressing enter ends the prompt
    c=1;
    current=first;
    previous=NULL; /* first record has no previous */
    while(c!=r) {
        if(current==NULL) {
        puts("Record not found");
        return;
        } else {   
        previous=current;
        current=current->next;
        c++;
        }
    }
    
    if(previous==NULL){ /* special case for first record */
    first=current->next;
    
    } else { /* point previous record at next */
    previous->next=current->next;
    printf("Record %d removed.n",r);
    free(current);
    } 
}

void Edit(void){

    struct Patient *previous; 
    int c;
    int input;
    int ch;
    if(first==NULL) {
        puts("No records to edit");
        return;
    } else {
    puts("Choose a record to edit:");
    Display();
    }

    scanf("%d",&input);
    while(getchar()!='\n'); //pressing enter ends the prompt
    c=1;

    int count = 0; 
    current = first;

    while (count < (input-1)){   

        count++; 
        current = current->next; 
        
    } 

    printf("Record %d being modified \n",input);
    
    puts("Enter Hospital : \n");
    scanf("%s", &current->HospName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Triage Level : \n");
    scanf("%s", &current->Triage);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Patient Name : \n");
    scanf("%s", &current->PatName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Nurse : \n");
    scanf("%s", &current->NurseName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Insurance Prov : \n");
    scanf("%s", &current->InsurName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Policy : \n");
    scanf("%s", &current->Policy);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Doc Name : \n");
    scanf("%s", &current->DocName);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Diagnosis : \n");
    scanf("%s", &current->Diagnosis);
    while ((ch = getchar()) != '\n' && ch != EOF);
    puts("Enter Cost : \n");
    scanf("%s", &current->Cost);
    while ((ch = getchar()) != '\n' && ch != EOF);

    
}


void Sort(void){

    int swapped, i; 
    int j;
    int Tri1;
    int Tri2;
    int count;
    char tempVar[50];
    
    /* Checking for empty list */
    if(first==NULL) {
        puts("No records to edit");
        return;
    }
    current = first;
    count = Count();

    while(current != NULL) {
        printf("Here");
        while (current->next !=NULL )//travel till the second last element 
        {
            Tri1 = atof(current->Triage);
            Tri2 = atof(current->next->Triage);
            printf("Tri1 : %d Tri2 : %d", Tri1, Tri2);
           if(Tri1 > Tri2) {
                strcpy(tempVar ,current->Triage);
                strcpy(current->Triage, current->next->Triage);
                strcpy(current->next->Triage, tempVar);
            }
         current = current->next;    // move to the next element 
        }
        current = current->next;    // move to the next node
    }
    
    
    if(first==NULL){
        puts("Nothing to show");
        return;
    }
    puts("Showing all records:");
    current=first;
    while(current){
        printf("Hospital: %s Triage: %s Nurse: %s Insurance: %s Policy #: %s Doctor: %s Diagnosis: %s Cost: %s \n",current->HospName, current->Triage, current->NurseName,
                current->InsurName, current->Policy, current->DocName, current->Diagnosis, current->Cost);
        current=current->next;
       
    }
    
}

void Swap(struct Patient *a, struct Patient *b) { 
    printf("got to swap");
    char temp = a->HospName; 
    strcpy(a->HospName, b->HospName);
    strcpy(b->HospName, temp);
    
} 

int Count(){

    
    int count = 0; // Initialize count  
    current = first; // Initialize current  
    while (current != NULL) {  

        count++;  
        current = current->next;  
    }  
    printf("Total records : %d\n", count);
    return count;  
} 



void TotalCost(void){

    int count = 0; // Initialize count  
    float TotalCost = 0;
    float cost;
    current = first; // Initialize current  
    while (current != NULL) {  
        cost = atof(current->Cost);
        TotalCost = TotalCost + cost;
          
        current = current->next;  
    }  
    printf("Total cost : %0.2f $ \n", TotalCost);
      

}