import os

path = "/homse/user/sublime_text_3" 
fileSizeTupleList = []
largestSize = 0

pathh = path.split("//")

if (os.path.isdir("/" + pathh[0])== False):
       print("Wrong disk!!!")
#       
	
for root, dirs, files in os.walk(path):
    for file in files:
        fileSizeTupleList.append((file, os.path.getsize(os.path.join(root, file))))

try: 
    for fileName, fileSize in fileSizeTupleList:
        if fileSize > largestSize:
            largestSize = fileSize
            largestFile = fileName
    print("*********************************************")
    print("Результат:   ",largestFile, largestSize, "bytes")
    print("*********************************************")
except:
	print("Error!!! Wrong path")