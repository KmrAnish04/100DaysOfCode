string catAndMouse(int x, int y, int z) {
    
    
    if(abs(z-x)<abs(z-y)){
        return "Cat A";
    }
    else if(abs(z-y)<abs(z-x)){
        return "Cat B";
    }
    else{
        return "Mouse C";
    }
    
}  