vector<string> split(string &s, char delimiter) {
    vector<string> words;
    string token;
    stringstream tokenStream(s);

    while (getline(tokenStream, token, delimiter)) {
        words.push_back(token);
    }
    return words;
}
