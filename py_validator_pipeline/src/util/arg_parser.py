import argparse

def parse_args():

    # Argument parser guides user in providing the required arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("-b", "--bin_golden_ref", help="absolute path of the binary file for the golden reference", required=True)
    parser.add_argument("-i", "--ini_golden_ref", help="absolute path of the ini file for the golden reference", required=True)
    parser.add_argument("-c", "--bin_isuv", help="absolute path of the binary file for the instruction set under verification", required=True)
    parser.add_argument("-j", "--ini_isuv", help="absolute path of the ini file for the instruction set under verification", required=True)
    parser.add_argument("-s", "--src", help="name of source code file, e.g. hello.c", required=True)
    parser.add_argument("-f", "--fun", help="name of the function, e.g. foo", required=True)
    parser.add_argument("-e", "--etiss_path", help="absolute path of bare metal ETISS", required=True)
    parser.add_argument("-x", "--etiss_executable", help="name of bare metal ETISS", required=True)
    parser.add_argument("-d", "--debug", help="Debug additionally includes comparison for Function Prologue and Epilogue", action="store_true")
    parser.add_argument("-v", "--verbose", help="Produce more verbose output", action="store_true")


    return parser.parse_args()