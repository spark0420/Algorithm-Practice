#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

#define PSEUDO_EOF char(129)
#define CHARACTER_CODE_SEPARATOR char(130)
#define HEADER_ENTRY_SEPARATOR char(131)
#define End_Header char(132)

using namespace std;

class HuffmanNode{
public:
    char symbol;
    long frequency;
    string codeword;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode() {
        left = right = NULL;
    }

    HuffmanNode(char sym, long freq, HuffmanNode *leftN = 0, HuffmanNode *rightN = 0) {
        symbol = sym;
        frequency = freq;
        left = leftN;
        right = rightN;
    }
};

class FreqSource {
public:
    char symbol;
    long frequency;

    FreqSource() {
        frequency = 1;
    }

    FreqSource(char sym, long freq){
        symbol = sym;
        frequency = freq;
    }

    bool operator == (const FreqSource &dr) const { // used by find();
        return symbol == dr.symbol;
    }

    bool operator < (const FreqSource &fs) const { // used by sort();
        return frequency < fs.frequency;
    }

    void printFreq(){
        cout << "Symbol: " << symbol << " Freq: " << frequency << endl;
    }
}; 
class ListNode {
public:
    HuffmanNode *HuffNode;
    ListNode *next, *prev;

    ListNode() {
        next = prev = 0;
    }

    ListNode(HuffmanNode *node) {
        HuffNode = node;
    }

    ListNode(HuffmanNode *node, ListNode *previousL, ListNode *nextL) {
        HuffNode = node;
        prev = previousL;
        next = nextL;
    }

};

class HuffmanCoding{
private :
    vector<FreqSource> frequencyTable;
HuffmanNode *HuffmanTree;
ofstream fOut;
map<char, int> freqMap;


void error(char *s){
    cerr << s << endl;
    exit(1);
}

public:

    void GenerateFreqTable(ifstream &fIn) {
    char currSym;
    vector<FreqSource>::iterator i;
    FreqSource curr;

    while (!fIn.eof()) {
        currSym = fIn.get();
        curr.symbol = currSym;

        if ((i = find(frequencyTable.begin(), frequencyTable.end(), curr)) == frequencyTable.end()){
            frequencyTable.push_back(curr);
        }
        else{
            i->frequency++;
        }
    }
    curr.symbol = PSEUDO_EOF;
    curr.frequency = 1;
    frequencyTable.push_back(curr);
    sort(frequencyTable.begin(), frequencyTable.end());

}

void createHuffmanTree() {
    ListNode *head, *tail;
    ListNode *tmp, *newNode;
    HuffmanNode *sumNode;
    head = new ListNode();
    head -> HuffNode = new HuffmanNode(frequencyTable[0].symbol, frequencyTable[0].frequency);
    tail = head;
    
    for (int i = 1; i < frequencyTable.size(); i++) { 
        HuffmanNode *curr = new HuffmanNode(frequencyTable[i].symbol, frequencyTable[i].frequency);
        ListNode *currList = new ListNode(curr);
        
        tail -> next = currList;
        currList -> prev = tail;
        tail = tail -> next;
    }
    
    
    while (head != tail) { 
        long leftFreq = head -> HuffNode -> frequency;
        long rightFreq = head -> next -> HuffNode -> frequency;
        long FreqSum = leftFreq + rightFreq;
        
        tmp = tail;
        long tmpFreq = tmp -> HuffNode -> frequency;
        while(tmp != NULL && tmpFreq > FreqSum){
            tmp = tmp -> prev;
            tmpFreq = tmp -> HuffNode -> frequency;
        }
        
        sumNode = new HuffmanNode('\0', FreqSum, head -> HuffNode, head -> next->HuffNode);
        newNode = new ListNode(sumNode, tmp, tmp -> next);
        tmp -> next = newNode;
        if (tmp == tail){
            tail = newNode;
        }else{
            newNode -> next -> prev = newNode;
        }

        head = head->next->next;
        delete head->prev->prev;
        delete head->prev;
        head->prev = NULL;
    }
    
    HuffmanTree = head -> HuffNode;
    delete head;
    createCodewords(HuffmanTree, "");
}


void createCodewords(HuffmanNode *node, string code){
    if (node -> left == NULL && node -> right == NULL){
        node -> codeword = code;
        cout << "Symbol: " << node -> symbol << " code: " << node -> codeword << endl;
    }else{
        createCodewords(node -> left, code + '0');
        createCodewords(node -> right, code + '1');
    }
}

void store_tree(HuffmanNode *head){
    if(!head -> left && !head -> right)
    {
        fOut.put('1');
        cout << "1";
        fOut << head -> symbol;
        cout << head -> symbol;
    }
    else{
        fOut.put('0');
        cout << "0";
        store_tree(head -> left);
        store_tree(head->right);
    }
}

//for remaking the tree while decoding
HuffmanNode* Make_Huffman_tree(ifstream &fIn){
    char ch;
    ch = fIn.get();
    cout << "ch: " << ch << endl;
    if(ch == '1'){
        fIn.get(ch);
        HuffmanNode *curr = new HuffmanNode;
        curr -> symbol = ch;
        return curr;
    }
    else{
        HuffmanNode* leftN = Make_Huffman_tree(fIn);
        HuffmanNode* rightN = Make_Huffman_tree(fIn);
        HuffmanNode* curr2;
        curr2 -> symbol = '\0';
        curr2 -> left = leftN;
        curr2 -> right = rightN;
        return curr2;
    }
}

void writeToFile(string code){
    long codeInt;
    char *s = new char[4];
    codeInt = stol(code,0,2); // string to long

    for (int i = 4 - 1; i >= 0; i--) {
        s[i] = codeInt & 0xff; //0xff == 11111111
        codeInt >>= 8;
    }
    for (int i = 0; i < 4; i++){
        fOut.put(s[i]);
    }
}

HuffmanNode* findInfo(char ch){
    HuffmanNode *tmp = HuffmanTree;
    stack<HuffmanNode* > st;
    HuffmanNode* ret;
    string code;

    if(tmp == NULL){
        cout << "There is an error compressing the file.\n";
        error("A problem in encode()");
    }
    else{
        st.push(tmp);
        while(!st.empty()){
            tmp = st.top();
            st.pop();
            if(tmp -> symbol == ch){
                ret = tmp;
            }

            if(tmp -> right != NULL){
                st.push(tmp -> right);
            }

            if(tmp -> left != NULL){
                st.push(tmp -> left);
            }
        }
    }
    return ret;
}

void writeCompressedCode(ifstream& fIn){
    fIn.clear();
    fIn.seekg(0, ios::beg);
    HuffmanNode *ret;
    string code, hold, final32Code = "";
    char ch;
    int codelen, leftOver, lenLimit = 32, currlen = 0;
    bool reachedEnd = 0;

    while(!reachedEnd){
        if(!fIn.eof()){
            ch = fIn.get();
            ret = findInfo(ch);
            code = ret -> codeword;
            codelen = code.size();
        }else{
            ret = findInfo(PSEUDO_EOF);
            code = code = ret -> codeword;
            codelen = code.size();
            reachedEnd = 1;
        }

        if(codelen < lenLimit - currlen){
            final32Code += code;
            currlen += codelen;
        }
        else{
            leftOver = lenLimit - currlen;
            if(leftOver != codelen){
                hold = code.substr(0, leftOver);
                final32Code += hold;
            }
            else{
                final32Code += code;
            }
            writeToFile(final32Code);

            if(leftOver != codelen){
                final32Code = code.substr(leftOver, codelen-1);
                currlen = final32Code.size();
            }
            else{
                currlen = 0;
            }
        }
    }
    

    if(currlen != 0){
        leftOver = lenLimit - currlen;
        for(int i = 0; i < leftOver; i++){
            final32Code += '0';
        }
        writeToFile(final32Code);
    }
}

void printRec1(){
    int size = frequencyTable.size();

    for(int i = 0; i < size; i++){
        frequencyTable.at(i).printFreq();
    }
    cout << "--------------------------------------\n";
}

void iter_preorder(){
    HuffmanNode *tmp = HuffmanTree;
    stack<HuffmanNode * > preorder_st;

    if(tmp == NULL){
        return;
    }
    else{
        preorder_st.push(tmp);

        while(!preorder_st.empty()){
            tmp = preorder_st.top();
            preorder_st.pop();
            cout << "tmp - symbol: " << tmp -> symbol << " freq: " << tmp -> frequency << endl;

            if(tmp -> right != NULL){
                preorder_st.push(tmp -> right);
            }

            if(tmp -> left != NULL){
                preorder_st.push(tmp -> left);
            }
        }
    }
}

void writeHeader(){
    char currChar;
    int currFreq, size = frequencyTable.size();

    for(int i = 0; i < size; i++){
        currChar = frequencyTable.at(i).symbol;
        fOut.put(currChar);
        fOut.put(CHARACTER_CODE_SEPARATOR);// 130
        currFreq = frequencyTable.at(i).frequency;
        fOut.put(currFreq);
        fOut.put(HEADER_ENTRY_SEPARATOR);// 131
    }
    fOut.put(End_Header);// 132
}

void readHeader(ifstream &fIn) {
    FreqSource curr;
    char ch;
    fIn.get(ch);
    char currFreq;
    char currChar = ch;
    while(ch != End_Header){
        if(ch == CHARACTER_CODE_SEPARATOR){
            fIn.get(ch);
            while(ch != HEADER_ENTRY_SEPARATOR){
                currFreq = ch;
                curr.symbol = currChar;
                curr.frequency = currFreq;
                frequencyTable.push_back(curr);
                fIn.get(ch);
            }
        }
        else{
            currChar = ch;
            fIn.get(ch);
        }

    }
}
void readCompressedCode(ifstream &fIn){
    HuffmanNode *tmp = HuffmanTree;
    char ch, bit, tmpChar;
    string eightCode;
    int index, chInt;

    while(!fIn.eof()){
        index = 0;
        ch = fIn.get();
        chInt = (int)ch;
        eightCode = "";
        for (int i = 7; i >= 0; i--) {
            int k = chInt >> i;
            if (k & 1){
                tmpChar = '1';
            }
            else{
                tmpChar = '0';
            }
            eightCode += tmpChar;
            
        }

        while(index < 8){
            bit = eightCode[index];
            if(tmp -> left == NULL && tmp -> right == NULL){
                if(tmp -> symbol != PSEUDO_EOF){
                    fOut.put(tmp -> symbol);
                    cout << "Character: " << tmp -> symbol << endl;
                    tmp = HuffmanTree;
                }else{
                    return;
                }
            }
            else{
                if(bit == '0'){
                    tmp = tmp -> left;
                }else{
                    tmp = tmp -> right;
                }
                index++;
            }
        }
    }
}

void compress(char *inFileName, ifstream &fIn){
    char outFileName[30];
    strcpy(outFileName, inFileName);

    if (strchr(outFileName, '.')){
        strcpy(strchr(outFileName, '.') + 1, "huf");
    }else{
        strcat(outFileName, ".huf");
    }
    fOut.open(outFileName, ios::out | ios::binary);

    GenerateFreqTable(fIn);
    printRec1();
    createHuffmanTree();
    //iter_preorder();
    writeHeader();
    cout << "\n";
    writeCompressedCode(fIn);
    fIn.clear();
    cout.precision(2);
    cout << "Compression rate = " << 100.0 * (fIn.tellg() - fOut.tellp()) / fIn.tellg() << "%\n";
    fOut.close();
}
void decompress(char *inFileName, ifstream &fIn){
    char outFileName[30];
    strcpy(outFileName, inFileName);

    if (strchr(outFileName, '.')){
        strcpy(strchr(outFileName, '.') + 1, "txt");
    }
    else{
        strcat(outFileName, "_huf.txt");
    }
    fOut.open(outFileName, ios::out | ios::binary);
    frequencyTable.clear();
    readHeader(fIn);
    printRec1();
    createHuffmanTree();
    cout << "--------------------------------------\n";
    readCompressedCode(fIn);
    fOut.close();
}
};

int main(int argc,char* argv[]) {
    string sFilename;

    if(argc>=2)
    {
        if (strcmp(argv[1], "-c") == 0) {
            sFilename = argv[2];
            cout << "Compressing file: " << sFilename << endl;
        } else if (strcmp(argv[1], "-d") == 0){
            sFilename = argv[2];
            cout << "Decompressing file: " << sFilename << endl;
        } else{
            cout << "Error: unknown flag. Check list of arguments available for this program." << endl;
        }

    } else{
        cout << "This compressor adds <.huf> as a file format after it's compressed." << endl;
        cout << "Arguments:" << endl;
        cout << "-c filename" << endl;
        cout << "-d filename" << endl;
        cout << "Description:" << endl;
        cout << "<flag -c represents compression>" << endl;
        cout << "<flag -d represents decompression>" << endl;
        cout << "Compression example:" << endl;
        cout << "./compressor.out -c testfile.txt" << endl;
        cout << "Output:" << endl;
        cout << "testfile.huf" << endl;
        cout << "Decompression example:" << endl;
        cout << "./compressor.out -d testfile.huf" << endl;
        cout << "Output:" << endl;
        cout << "testfile_huf.txt" << endl;
        cout << "WARNING: DO NOT FORGET TO INCLUDE <.huf> AT THE END OF YOUR "
                "FILENAME FOR THE DECOMPRESSION FUNCTION" << endl;
        exit(-1);
    }

    int nChars = sFilename.length();
    char filename[nChars + 1];
    strcpy(filename, sFilename.c_str());

    HuffmanCoding huff;
    ifstream fIn(filename, ios::binary);

    if (fIn.fail()) {
        cerr << "ERROR: CANNOT OPEN " << filename << ". PLEASE PUT A VALID FILENAME"<< endl;
        return 0;
    }

    if (strcmp(argv[1], "-c") == 0) {
        huff.compress(filename, fIn);
    } else if (strcmp(argv[1], "-d") == 0){
        sFilename.erase(nChars-4, nChars);
        char compFilename[sFilename.length() + 1];
        strcpy(compFilename, sFilename.c_str());
        huff.decompress(compFilename, fIn);
    }
    fIn.close();

    return 0;
}