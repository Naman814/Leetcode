class Solution {
    public boolean detectCapitalUse(String word) {
        int x=0,y=0,z=0;
        int n=word.length(); char ch;
        for(int i=0;i<word.length();i++){
             ch=word.charAt(i);
            if(ch>='a' && ch<='z'){
                x++;
            }
            if(ch>='A' && ch<='Z'){
                y++;
            }
        }
        for(int i=1;i<word.length();i++){
            ch=word.charAt(i);
            if(ch>='a' && ch<='z'){
                z++;
            }
        }
        if(x==n || y==n){
            return true;
        }
        ch=word.charAt(0);
        if((ch>='A' && ch<='Z') && z==(n-1)){
            return true;
        }
        return false;
    }
}