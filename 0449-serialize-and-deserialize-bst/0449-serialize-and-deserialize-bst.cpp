class Codec {
public:
    void serializehelper(TreeNode* root, string& s){
        if(root==nullptr) return;
        
        s+=to_string(root->val) + ","; 
        serializehelper(root->left, s);
        serializehelper(root->right, s);
    }
    
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        
        string s="";
        serializehelper(root, s);
        
        return s;
    }
    
    int convertStringtoInt(string& data, int& pos){ 
        pos=data.find(',');
        int value=stoi(data.substr(0, pos));
        return value;
    }
    
    TreeNode* deserializehelper(string& data, int min, int max) {
        if(data.size()==0) return nullptr; 
        
        int pos=0;
        int value = convertStringtoInt(data, pos); 
        if (value < min || value > max) return nullptr; 
        
        TreeNode* tnode = new TreeNode(value); 
        data=data.substr(pos+1); 
        
        tnode->left=deserializehelper(data, min, tnode->val); 
        tnode->right=deserializehelper(data, tnode->val, max);
        return tnode;
    }
    
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        return deserializehelper(data, INT_MIN, INT_MAX);
    }
};