    #include<bits/stdc++.h>
    #include<iostream>
    #include<vector>
    //#include<array>
    //#include<queue>
    using namespace std;
    void print(vector<vector<int> >);
    void printParent(map<vector<vector<int> >,vector<vector<int> > > parent,vector<vector<int> > myvec,vector<vector<int> > myvec1)
    {
      stack<vector<vector<int> > >st;
      while(1)
      {
        st.push(myvec1);
        if(myvec1 == myvec)
          break;
        myvec1=parent[myvec1];
      }

      while(!st.empty())
      {
        print(st.top());
        st.pop();
      }
    }
    void print(vector<vector<int> > myvec1){
      int i,j;
      //cout<<endl<<endl;
      for(i=0;i<myvec1.size();i++)
      {
        for(j=0;j<myvec1.size();j++)
          cout<<myvec1[i][j]<<" ";
        //cout<<endl;
      }
      cout<<endl;
    }
     
    void func(vector<vector<int> >&myvec,vector<vector<int> >&myvec1)
    {
     
      int i,j,n=myvec.size();
      int t ,t1 ;
      int count = 0;
      //  cout<<n<<"size";
      //  vector<vector<int> >::iterator it;
     
      queue<vector<vector<int> > > Q;
     
      map<vector<vector<int> > ,int>color;
     
      map<vector<vector<int> > ,vector<vector<int> > > parent;
      //vector<vector<int> > parent(myvec.size(),vector<int>(myvec.size()));
     
      vector<vector<int> > u(myvec.size(),vector<int>(myvec.size()));
     
      vector<vector<int> > v(myvec.size(),vector<int>(myvec.size()));
      vector<vector<int> > w(myvec.size(),vector<int>(myvec.size()));
      map<vector<vector<int> > ,int>even;
      int temp;
      //cout<<even[myvec]<<endl;
      Q.push(myvec);
      color[myvec]=1;
      parent[myvec] = myvec;
      even[myvec] = 1;
      while(!Q.empty())
      {
      //cout<<"g";
        u = Q.front();
        if(u==myvec1)
        {
          printParent(parent,myvec,myvec1);
          return;
        }
        Q.pop(); 
    //    cout<<"start"<<endl;
        for(i=0;i<v.size();i++)
        {
          v = u;
          t = n-1;
          while(t--)
          {
            temp = v[i][n-1];
            //  cout<<temp<<endl;
            for(j = v.size()-1;j>=1;j--)
     
            {
     
              v[i][j] = v[i][j-1];
     
            }
            v[i][0] = temp;
            w=v;
            if(even[u]%2==0)
              w[0][0] = 0;
            
            if(color[w] == 0){
              
              even[w] = even[u] + 1;
              color[w]=1;
              Q.push(w);
              parent[w] = u;
            }
          }
        }
        for(i=0;i<v.size();i++)
        {
          v = u;
          t = n-1;
          while(t--){
            temp = v[n-1][i];
            for(j = v.size()-1;j>=1;j--)
     
            {
     
              v[j][i] = v[j-1][i];
     
            }
            v[0][i] = temp;
            w=v;
            if(even[u]%2==0)
            {
                w[0][0] = 0;
            }
              
            if(color[w] == 0)
            {
              
              
                even[w] = even[u] + 1;

              color[w]=1;
              Q.push(w);
              parent[w] = u;
             }
          }
        }
      }
    }
     
     
    int main(){
      vector<int>::iterator it;
      int t,n,i,j;
      cin>>t;
      while(t--){
        cin>>n;
        vector<vector<int> > myvec(n,vector<int>(n));
     
        vector<vector<int> > myvec1(n,vector<int>(n));
     
        for(i=0;i<n;i++)
        {
          for(j=0;j<n;j++)
            cin>>myvec[i][j];
        }
        for(i=0;i<n;i++)
        {
          for(j=0;j<n;j++)
            cin>>myvec1[i][j];
        }
      
        //print(myvec);
    //    print(myvec1);
        func(myvec,myvec1);
     
      }
      return 0;
    }