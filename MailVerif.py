# Python program to validate an Email 
  
# import re module 
  
# re module provides support 
# for regular expressions 
import re 
  
# Make a regular expression 
# for validating an Email 
regex = '^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$'
      
# Define a function for 
# for validating an Email 


def check(inputAddress):  
  	inputAddress = input('Please enter the emailAddress to verify:')
	addressToVerify = str(inputAddress)
    # pass the regualar expression 
    # and the string in search() method 
    if(re.search(regex,inputAddress)):  
        print("Valid Email")  
          
    else:  
        print("Invalid Email")  
      
  
# Driver Code  
if __name__ == '__main__' :  
      
    # Enter the email  
	
    
      
    # calling run function  
    check(inputAddress) 
  
    
