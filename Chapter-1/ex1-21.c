


/*
 *                                           NEEDS IMPROVEMENT
 *
 * Tabs are replaced by spaces. Returns number of characters, excluding the '\0' at the end of the line 
 */
int myGetLine(){

  int col = 0, c = 0, step = 0, nCol = 0, len = 0;
  extern char line[];
  //loop needs to improve -> MAXLINE? Last character != EOF|newline 
  while((c = getchar()) != EOF){

    if(c == '\t'){
      step = TABSTOP - (col % TABSTOP);
      nCol = col + step;
      while(col != nCol){
        line[col] = ' ';
        ++col;
      }
    }
    else if(c == '\n'){
      line[col] = '\n';
      len = col;
      ++col;
      break;
    }
    else{
      line[col] = c;
      ++col;
    }
  }
  line[col] = '\0';
  return len;
}

#define IN 1
#define OUT 0
int entab(char line[]){
  int c,mode;
  while ((c=getchar()) != EOF){
    //Track if in or outside word
    switch(c){
      case ' ':
        mode = OUT;
      case '\t':
        mode = IN;
      case '\n':
      default:
    }
  }
  return len;
}
