class Solution {
    public char findTheDifference(String s, String t) {
        HashMap<Character,Integer> hp = new HashMap<Character,Integer>();
        char[] str = s.toCharArray();
       for(int i=0;i<str.length;i++){
            if(hp.containsKey(str[i])){
                hp.put(str[i],hp.get(str[i])+1);
            }
            else{
                hp.put(str[i],1);
            }
       }
        char ans=' ';
        char [] ts = t.toCharArray();
      for(int i=0;i<ts.length;i++){
        
          if(hp.containsKey(ts[i])){
              hp.put(ts[i],hp.get(ts[i])-1);
              if(hp.get(ts[i])==0){
                  hp.remove(ts[i]);
              }
          }
          else{
               ans = ts[i];
              break;
          }
      }
        return ans;
    
    }
};