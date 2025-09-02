#include <stdio.h>

void getAline(char *);
void clear_comments(char *);

int main(){
    char s[1000];
    getAline(s);

    printf("\n----------------------------\n");

    clear_comments(s);

    return 0;
}

void getAline(char *s){
    int length = 0;

    int c;
    while ((c = getchar()) != EOF){
        s[length++] = c;
    }
    s[length] = '\0';
}

void clear_comments(char *s){

    enum { NORMAL, STRING, CHAR, SL_COMMENT, ML_COMMENT } state;
    state = NORMAL;

    for (int i = 0; s[i] != '\0'; ++i){
        if (state == NORMAL){
            if (s[i] == '/'){
                if (s[i + 1] == '/'){
                    state = SL_COMMENT;
                    continue;
                }
                else if (s[i + 1] == '*'){
                    state = ML_COMMENT;
                    continue;
                }
            }

            if (s[i] == '"'){
                state = STRING;
            }
            if (s[i] == '\''){
                state = CHAR;
            }
        }
        else {
            if (state == SL_COMMENT){
                if (s[i] == '\n'){
                    state = NORMAL;
                    putchar('\n');
                }
                continue;
            }
            else if (state == ML_COMMENT){
                if (s[i] == '*' && s[i + 1] == '/'){
                    state = NORMAL;
                    ++i;
                }
                continue;
            }

            if (s[i] == '\\'){
                putchar('\\');
                putchar(s[i + 1]);
                ++i;
                continue;
            }

            if (s[i] == '\'' && (state == CHAR)){
                state = NORMAL;
            }
            else if (s[i] == '"' && (state == STRING)){
                state = NORMAL;
            }
        }
        putchar(s[i]);
    }
}
