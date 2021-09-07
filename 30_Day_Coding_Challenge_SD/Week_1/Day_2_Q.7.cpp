void staircase(int n) {
    
    for(int i=0; i<n; i++){
        int spaces=n-(i+1);
        int symbol=i+1;
        
        for(int j=0; j<spaces; j++) cout<<" ";
        for(int k=0; k<symbol; k++) cout<<"#";
        cout<<"\n";
    }
    

}