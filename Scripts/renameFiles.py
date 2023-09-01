# Python 3 code to rename multiple
# files in a directory or folder

# importing os module
import os

# Function to rename multiple files
def main():

    print("#####################################################################################")
    print("Aquest programa busca tots els fitxers que començen pel nom del grup desitjat")
    print(" i renombra el fitxer posant el nom del grup al final.")
    print("#####################################################################################")
    print()

	#to get the current working directory
    directory = os.getcwd()
    #print(directory)
    
    print('Escriu el nom del grup:')
    group = input()
    
    for cout, file in enumerate(os.listdir(directory)):
        #print(file)
        extension = ''
        
        newFile = file.split(".")
        if(len(newFile)>1):
            extension = newFile[1]
        
        newFileWithoutGroup = newFile[0].split(group + " ")
        #print(newFileWithoutGroup)
        
        if(len(newFileWithoutGroup) > 1):
            newFile = newFileWithoutGroup[1] + "_" + group + "." + extension
            print(newFile)
            os.rename(file, newFile)
        
        


# Driver Code
if __name__ == '__main__':

	# Calling main() function
	main()
