#include "analyse_syntaxique.h"
// #include "ast_construction.h"
#include "ast_parcours.h"
#include <stdlib.h>




int main(int argc,char**argv) {

   
    Ast A;

    if (argc!=2)
        printf("USED WITH : ./calculette <txt file name> \n");
        
    
    else{

        int err=analyser(argv[1],&A);
        if(err==1){
            printf("Cannot give value due to error in your expression \n");
            return 0;
        }
        AfficherAST(A);
        int value=evaluation(A);
        printf(" = %d \n",value);
    

      
        
       
        
    }
    return 0;
}




