# include <stdio.h>
# include <stdint.h>
void aMayusc(char *str){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]>='a'&& str[i]<='z'){
            str[i] = str[i] + ('A'-'a');
        }
    }
}
int main(){
    char str[] = "Hola";
    aMayusc(str);
    printf("en mayuscula: %s\n", str);
}