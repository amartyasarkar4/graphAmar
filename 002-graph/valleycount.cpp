int valleyCount=0;
    int seaLevel=0;
    int curPos=0;
    for(int i=0;i<steps;i++){
        // cout<<path[i];
        int prevCurPos=curPos;
        if(path[i]=='U'){
            curPos++;
        }else if(path[i]=='D'){
            curPos--;
        }
        if(prevCurPos==0&&curPos<0){
            valleyCount++;
        }
    }
    return valleyCount;