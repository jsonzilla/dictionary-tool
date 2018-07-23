# dictionary-tool
A simple dictonary generator, with base of a text file

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3c20bad7754c4e77b8f8aca44535e949)](https://www.codacy.com/app/0um/dictionary-tool?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=0um/dictionary-tool&amp;utm_campaign=Badge_Grade)

Generate a comma/column separated format
```
count : word 
```

# build
``` 
cmake
make
``` 

# run
``` 
dicttool <file input>
cat dumpFile.txt | dicttool
dicttool <file input> > output.txt
``` 


