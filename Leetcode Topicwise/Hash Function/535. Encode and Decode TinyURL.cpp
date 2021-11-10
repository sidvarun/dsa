https://leetcode.com/problems/encode-and-decode-tinyurl/
class Solution {
public:
    unordered_map<string, string> encoder;
    unordered_map<string, string> decoder;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encoder.find(longUrl) != encoder.end())
            return encoder[longUrl];
        string shortUrl = to_string(encoder.size() + 1);
        string Url = "http://tinyurl.com/" + shortUrl;
        encoder[longUrl] = Url;
        decoder[Url] = longUrl;
        return Url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoder[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
