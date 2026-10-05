// entab returns the amount of elements in line[] except '\0'
int entab(char line[]){
  int c;
  int column = 0;
  while ((c=getchar()) != EOF && c != '\n'){
    switch(c){
      case ' ':
        int space = getSpaces();
        while(spaces % TABSTOP) != 0){
          line[column] = ' ';
          ++column;
          --spaces;
        }
        for(int i = 0;i < spaces/TABSTOP; i=(i+TABSTOP)){
          line[column] = '\t';
          ++column;
        }
      default:
        line[column] = c;
        ++column;
    }
  }
  if(col == 0 && c == '\n'){
    return 0;
  }
  else if(c == '\n'){
    line[column] = '\n';  
    ++column;
    len = column;
    return len;
  }
  else{ //in case EOF

    return column;
  }
}
case '\n':


int getSpaces(){
  int spaces;
  while ((c = getchar()) == ' '){
    ++spaces;
  }
  return spaces;
}

int main(void){
  int len = 0, i = 0;
  while(len > 0){
    while(line[i] != '\0')
  }
}


