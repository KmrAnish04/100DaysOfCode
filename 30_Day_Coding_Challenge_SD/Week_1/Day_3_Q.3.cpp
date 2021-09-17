vector<int> gradingStudents(vector<int> grades) {
    
    for(int i=0; i<grades.size(); i++){
        if(grades[i]>=38 && ((grades[i]+1)%5==0 || (grades[i]+2)%5==0)){
            if((grades[i]+1)%5==0) grades[i] += 1;
            else grades[i] += 2;
        }
    }
    
    return grades;
}
