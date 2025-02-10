#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef enum{
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    PUNCTUATION,
    END,
    INVALID
} Tokentype;
typedef struct{
    TokenTypetype;
    char value[100];

}Token;
typedef struct{
    char*input;
    size_tpos;
}Lexer;
typedef enum{
    ASSIGNMENT,
    BINARY_OP,
    LITERAL,
    IDENTIFIER,
    IF_STATEMENT
}NodeType;
typedef struct Node{
    NodeType type;
    char value[100];
    struct Node*left;
    struct Node*right;
}Node;
Lexer*lexer_create(const char*input){
    Lexer*lexer=(Lexer*)malloc(sizeof(Lexer));
    lexer->input=strdup(input);
    lexer->pos=0;
    return lexer;
}
void lexer_destroy(Lexer*lexer){
    free(lexer->input);
    free(lexer);
}
void lexer_skip_whitespace(Lexer*lexer){
    while(lexer->pos<strlen(lexer->input)&&isspace(lexer->input[lexer->pos])){
        lexer->pos++;
    }
}
Token lexer_next_token(Lexer*lexer){
    lexer_skip_whitespace(lexer);
    if (lexer->pos>=strln(lexer->input)){
        Token token={END,""""};
        return token;
    }
    char current_char=lexer->input[lexer->pos];
    Token token;
    if(isdigit(current_char))
    {
        size_t start=lexer->pos;
        while(lexer->pos<strln(lexer->input)&&isdigit(lexer->input[lexer->pos])){
    
    lexer->pos++;
}
strncpy(token.value,&lexer->input[start],lexer->pos-start);
token.value[lexer->pos-start]='\0';
token.type=NUMBER;
return token;
    }
    if (isalfa(current_char)){
        size_t start=lexer->pos;
        while(lexer->pos<strlen(lexer->input)&&(isalnum(lexer->input[lexer->pos])||lexer->input[lexer->pos]=='_')){
            lexer->pos++;
        }
      strncpy(token.value,&lexer->input[start],lexer->pos-start);
      token.value[lexer->pos-start]='\0';
      if(strcmp(token.value,"int")==0||strcmp(token.value,"if")==0)||strcmp(token.value,"else")==0){
        toklen.type=KEYWORD;
      }else{
        token.type=IDENTIFIER;
      }
      return token;
    }
    if(current_char=='+'||current_char=='-'||current_char=='*'||current_char=='/'){
        token.value[0]=current_char;
        token.value[1]='\0';
        lexer->pos++;
        token.type=OPERATOR;
        return token;    }
        if(current_char=='='||current_char==';'||current_char=='('||current_char==')'){
            token.value[0]=current_char;
            token.value[1]='\0';
            lexer->pos++;
            token.type=PUNCTUATION;
            return token;
        }
        token.type=INVALID;
        return token;}
        Node*node_create(NodeType type,const char*value){
            Node*node=(Node*)malloc(sizeof(Node));
            node->type=type;
            strncpy(node->value,value,100);
            node->left=NULL;
            node->right=NULL;
            returnb node;
        }
        void node_destroy(Node*node){
            if(node){
                node_destroy(node->left);
                node_destroy(node->right);
                free(node);
            }
        }
        Node*parse_assignment(Lexer*lexer)
        {
            Token token=lexer_next_token(lexer);
            token=lexer_next_token(lexer);
            variable name char var_name[100];
            strcpy(var_name,token.value);
            lexer_naxt_token(lexer);
            token=lexer_next_token(lexer);
            Node*expr=node_create(LITERAL,token.value);
            Node*assignment_node=node_create(ASSIGNMENT,var_name);
            assignment_node->left=expr;
            return assignment_node;
        }
        Node*parse_expression(Lexer*lexer){
            Token token=lexer_next_token(lexer);
            if(token.type==NUMBER){
                return node_create(LITERAL,token.value);
            }
            return NULL;
        }
        Node*parse_ifstatement(Lexer*lexer){
            lexer_next_token(lexer);
            lexer_next_token(lexer);
            Node*condition=parse_expression(lexer);
            lexer_next_token(lexer);
            lexer_next_token(lexer);
            lexer_next_token(lexer);
            Node*if_node=node_create(IF_STATEMENT,"if");
            if_node->left=condition;
            return if_node;
        }
        Node*parser_parse(Lexer*lexer)
        {
            Token token=lexer_next_token(lexer);
            if(token.type==KEYWORD && strcmp(token.value,"int")==0){
                return parse_assignment(lexer);
            }
            if(token.type==KEYWORD && strcmp(token.value,"if")==0){
                return parse_if_statement(lexer);
            }
            return NULL;
        }
        void code_generator_generate(Node*node){
            if(node->type==ASSIGNMENT){
                printf("MOV R0,%\n",node->left->value);
                printf("MOV %s,R0\n",node->value)
            }
            if(node->type==IF_STATEMENT){
                printf("CMP %s,5\n",node->left->value);
                printf("JGT label_1\n");
                printf("label_1:\n");
                printf("label_1:\n");
            }
            if(node->type==LITERAL){
                printf("MOV R0,%s\n",node->value);
            }
        }
        int main()
        {
            "int x=10;if(x>5){x=x+1;}"
            const char*code="int x=10;if(x>5){x=x+1;}";
            Node*ast=parser_parse(lexer);
            printf("Assembly code:\n");
            code_generator_generator(ast);
            node_destroy(ast);
            lexer_destroy(lexer);
            return 0;
        }