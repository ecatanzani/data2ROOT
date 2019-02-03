# data2ROOT
Fast data converter into ROOT TTree structure.

Data structure is fixed for now; it will be updated in the next release with a template structure, easy to manage and manipulate as it needs.
    
    Usage: ./dat2ROOT path_to_input_file path_to_output_file
    
INPUT_FILE_PATH --> path to the raw data
OUTPUT_FILE_PATH --> path to the output ROOT file

In order to set the printout verbosity a boolean variable has been crated ("verboseOut"), embedded into the code.
In case of verbosity set to "true" a fast statistycal study has been performed on the data, highlighting the max and min of each significant variable.

At the countrary the variable "inspectEvent" is used to study a single event.


Both these two arguments are needed.

Enjoy with the software ;-)
