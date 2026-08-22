char* longestPalindrome(char* s) {
    int n=strlen(s);
    int max=1;
    int left,right,start=0;
    for(int i=0;s[i]!='\0';i++){
        left=i;
        right=i;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>max){
                start=left;
                max=right-left+1;
            }
            left--;
            right++;
        }
        left=i;
        right=i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>max){
                start=left;
                max=right-left+1;
            }
            left--;
            right++;
        }
    }
    char* ans=malloc((max+1)*sizeof(char));
    for(int i=0;i<max;i++){
        ans[i]=s[start+i];
    }
    ans[max]='\0';
    return ans;
}
