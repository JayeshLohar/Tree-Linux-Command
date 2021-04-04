# Tree-Linux-Command

To compile the code, give the command : make all

To run the code : ./tree OPTION FOLDERNAME

Try './tree --help' to understand bc

  ------- Listing options -------
  -a            All files are listed.
  -d            List directories only.
  -f            Print the full path prefix for each file.
  -L level      Descend only level directories deep.
  -P pattern    List only those files that match the pattern given.
  -I pattern    Do not list files that match the given pattern.
    ------- File options -------
  -Q            Quote filenames with double quotes.
  -p            Print the protections for each file.
  -s            Print the size in bytes of each file.
  -D            Print the date of last modification or (-c) status change.
  -u            Displays file owner or UID number.
  -g            Displays file group owner or GID number.
    ------- Graphics options -------
  -i            Don't print indentation lines.
  -S            Print with CP437 (console) graphics indentation lines.
  -n            Turn colorization off always (-C overrides).
  ------- XML/JSON options -------
  -X            Prints out an XML representation of the tree.
  -J            Prints out an JSON representation of the tree.
    ------- Miscellaneous options -------
  --version     Print version and exit.
  --help        Print usage and this help message and exit.
