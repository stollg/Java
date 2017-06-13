//Garrett Stoll gstoll@ucsc.edu
//$Id: airport.java,v 1.2 2015-02-18 00:38:57-08 - - $


//
// Starter code for the airport utility.
//

import java.io.*;
import java.util.Scanner;
import static java.lang.System.*;
//private satic final int EXIT_SUCCESS = 0;
//private satic final int EXIT_FAILURE = 1;
class airport {
   private static final String STDIN_FILENAME = "-";

   public static treemap load_database (String database_name) {
      treemap tree = new treemap ();
      try {
         Scanner database = new Scanner (new File (database_name));
         for (int linenr = 1; database.hasNextLine(); ++linenr) {
            String line = database.nextLine();
            if (line.matches ("^\\s*(#.*)?$")) continue;
            String[] keyvalue = line.split (":");
            if (keyvalue.length != 2) {
               misc.warn (database_name, linenr, "invalid line");
               continue;
            }
            tree.put (keyvalue[0], keyvalue[1]);
            
             
         }
         database.close();
      }catch (IOException error) {
         misc.warn (error.getMessage());
      }
      return tree;
   } 

   public static void main (String[] args) {
      treemap tree = load_database (args[0]);
      Scanner stdin = new Scanner (in);
      while (stdin.hasNextLine()) {
         String airport = stdin.nextLine().toUpperCase().trim();
         String airport_name = tree.get (airport);
         if (airport_name == null) {
            out.printf ("%s: no such airport%n", airport);
         }else {
            out.printf ("%s = %s%n", airport, airport_name);
         }
      }
      tree.debug_tree ();
      exit (misc.exit_status);
   }

}
