void topView1(node *root, int level, int dist, map<int, pair<int, int> > &mp) {
    if(root == NULL) {
        return;
    }
    if(mp.find(dist) == mp.end() or level<mp[dist].second) {
        mp[dist] = {root->data, level};
    }
    topView1(root->left, level+1, dist-1, mp);
    topView1(root->right, level+1, dist+1, mp);
}
void topView(node *root)
{
   map<int, pair<int, int> >mp;
   topView1(root, 0, 0, mp);
   for(auto val:mp){
       cout<<val.second.first<<" ";
   }
}
 