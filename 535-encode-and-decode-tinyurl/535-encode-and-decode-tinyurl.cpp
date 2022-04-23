class Solution {
public:
    unordered_map<string,string> urltocode,codetourl;
    string base,alphanumeric;
    
    Solution(){
        base = "http://tinyurl.com";
        alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    }
    // Encodes a URL to a shortened URL.
    string getcode(string longurl){
        string code="";
        for(int i=0;i<6;i++){
            code += alphanumeric[rand()%alphanumeric.length()];
        }
        return base + code;
    }
    string encode(string longUrl) {
        if(urltocode.find(longUrl)!=urltocode.end()) return urltocode[longUrl];
        string code = getcode(longUrl);
        while(codetourl.find(code)!=codetourl.end()){
            code = getcode(longUrl);
        }
        urltocode[longUrl] = code;
        codetourl[code] = longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codetourl[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));