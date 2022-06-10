int prev=s[i][j];
                        s[i][j]+=15-newrow[i];
                        newrow[i]=15;
                        newcol[j]=newcol[j]+(s[i][j]-prev);
                        cost+=abs(s[i][j]-prev);
                        break;;
                    