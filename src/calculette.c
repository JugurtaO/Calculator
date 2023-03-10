#include "../headers/analyse_syntaxique.h"
#include "../headers/ast_construction.h"
#include "../headers/ast_parcours.h"
#include <stdlib.h>
 



int main(int argc,char**argv) {

   
    Ast A;

    if (argc!=2)
        printf("USED WITH : ./calculette <txt file name> \n");
        
    
    else{

        int err=analyser(argv[1],&A);
        if(err==1){
            printf("Cannot evaluate expression due to syntactic error !! \n");
            return 0;
        }

        AfficherAST(A);
        int value=evaluation(A);
        printf(" = %d \n",value);
         
        destroy_Tree(A);
      
        
       
        
    }
    return 0;
}




