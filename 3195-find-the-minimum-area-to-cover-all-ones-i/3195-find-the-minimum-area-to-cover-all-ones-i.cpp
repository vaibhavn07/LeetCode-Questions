class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        vector<vector<int>> row(grid.size(),vector<int>(2,-1));
        //row
        bool f = false,s = false;
        for(int i=0;i<grid.size();i++){
            f = false;
            s = false;
            int k;
            for(int j=0,k=grid[i].size()-1;j<grid[i].size()&&k>=0;j++,k--){
                if(grid[i][j]==1 && f==false){
                    f = true;
                     row[i][0] = j;
                }
                if(grid[i][k]==1 && s==false){
                    s = true;
                    row[i][1] = k;
                }
                if(s==true && f==true) break;
            }
        }
        
        //col
        //  for(int i=0;i<grid[0].size();i++){
        //     for(int j=0,k=grid.size()-1;j<grid.size(),k>=0;j++,k--){
        //         if(grid[j][i]==1 && f==false){
        //             f = true;
        //              col[i][0] = j;
        //         }
        //         if(grid[k][i]==1 && s==false){
        //             s = true;
        //             col[i][1] = k;
        //         }
        //         if(s==true && f==true) break;
        //     }
        // }
        
        
        //area
        int t ,b,minm= INT_MAX;

        f = false;
        s = false;
        
        for(int i=0,j=row.size()-1;i<row.size()&&j>=0;i++,j--){
            if(row[i][0]!=-1 && f!=true){ t = i;
                            f = true;}
            if(row[i][0]!=-1 && minm >row[i][0]){
                minm = row[i][0];
            }
            if(row[j][0]!=-1 && s!=true){ b = j;
                            s = true;}
       }
       
       int mi = INT_MIN;
    
       for(int i=0;i<row.size();i++){
           if(mi<row[i][1]){
               mi = row[i][1];
           }
       }
    
    int area = (b-t+1)*(mi-minm+1);
    return area;
           }
};