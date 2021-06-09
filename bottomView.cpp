
void bottomViewHelper(node* root, int level, int dist, map<int,pair<int,int>> mp){
  if(root==NULL){
    return;
  }
  if(mp.find[dist] == mp.end() and level >= mp[dist].second){
    mp[dist] = {root->data,level};

  }
  bottomViewHelper(root,level+1, dist-1,mp);
  bottomViewHelper(root,level+1, dist+1, mp);
}
void bottomView(node* root){
  map<int,pair<int,int> mp;
  bottomViewHelper(root,)
  for(auto val:mp){
    cout<<val.second.first<<" ";
  }
}