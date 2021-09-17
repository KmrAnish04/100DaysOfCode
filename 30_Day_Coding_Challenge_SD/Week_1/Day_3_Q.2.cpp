string timeConversion(string s) {
    string hour;
    string zone;
    int hh=00;
    
    hour = s.substr(0,2); // Extracing hh from the given string.
    
    zone = s.substr(8,9); // Extracing zone(AM/PM) from the given string.
    
    hh=stoi(hour); // Converting hh part of the given string to int, which will help to                         calculate hh for 24 hour clock time.
    
    s.erase(8,9); // Erasing time zone from the end of the string.
    
    if(zone=="AM"){
        if(hour=="12"){
            s.replace(0,2,"00");  
        }
        else{
        }
    }
    else{
        if(hour=="12"){
        }
        else{
            hh = 12+hh;
            hour = to_string(hh);
            s.replace(0,2,hour);
        }
    }
    
    return s;
}