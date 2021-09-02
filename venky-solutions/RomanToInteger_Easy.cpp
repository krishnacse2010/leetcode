class Solution {
public:
    int romanToInt(string s) {
        std::string::iterator iter, temp;
        int finalAnswer = 0;
        for(iter = s.begin();iter!=s.end(); iter++)
        {
            switch(*iter)
            {
                case 'I':
                    {
                        //peek ahead
                        temp = iter; temp++;
                        if(temp!=s.end())
                        {
                            if(*temp == 'V')
                            {
                                finalAnswer += 4;
                                iter = temp;
                            }
                            else if(*temp == 'X')
                            {
                                finalAnswer += 9;
                                iter = temp;
                            }
                            else
                                finalAnswer += 1;
                            
                        }
                        else
                            finalAnswer += 1;
                    }
                    break;
                    
                case 'X':
                    {
                         //peek ahead
                        temp = iter; temp++;
                        if(temp!=s.end())
                        {
                            if(*temp == 'L')
                            {
                                finalAnswer += 40;
                                iter = temp;
                            }
                            else if(*temp == 'C')
                            {
                                finalAnswer += 90;
                                iter = temp;
                            }
                            else
                                finalAnswer += 10;
                            
                        }
                        else
                            finalAnswer += 10;
                    }
                    break;
                    
                case 'C':
                    {
                        //peek ahead
                        temp = iter; temp++;
                        if(temp!=s.end())
                        {
                            if(*temp == 'D')
                            {
                                finalAnswer += 400;
                                iter = temp;
                            }
                            else if(*temp == 'M')
                            {
                                finalAnswer += 900;
                                iter = temp;
                            }
                            else
                                finalAnswer += 100;
                            
                        }
                        else
                            finalAnswer += 100;
                    }
                    break;
                    
                case 'V':
                {
                    finalAnswer += 5;
                }
                break;
                    
                case 'L':
                    {
                        finalAnswer += 50;
                    }
                    break;
                    
                case 'D':
                    {
                        finalAnswer += 500;
                    }
                    break;
                    
                case 'M':
                    {
                        finalAnswer += 1000;
                    }
                    break;
                       
            }
        }
        return finalAnswer;
    }
};
