char* convert(char* s, int numRows) {
    if(numRows==1) return s;

    int len=strlen(s);
    char* result=(char*)malloc(len+1);
    int index=0;

    int cyclelen=2*numRows-2;

    for(int row=0;row<numRows;row++){
        for(int j=row;j<len;j+=cyclelen){
            result[index++]=s[j];
            int second=j+cyclelen-2*row;

            if(row!=0 && row!=numRows-1 && second<len){
                result[index++]=s[second];
            }
        }
    }
    result[index++]='\0';
    return result;
}
