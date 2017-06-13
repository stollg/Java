//Garrett Stoll gstoll
//$Id: jcal.java,v 1.1 2015-01-20 22:48:18-08 - - $
import java.util.GregorianCalendar;
import static java.lang.System.*;
import static java.util.Calendar.*;
import java.util.Locale;




public class jcal {
    static int year, month, locale; //add locale later
    static Locale lg;
    static final int MONTHS_IN_YEAR = 12;
    static final int WEEKS_IN_MONTH =  6;
    static final int DAYS_IN_WEEK   =  7;
    static final int MAX_YEAR = 10000;
    static final int MIN_YEAR = 0;
    static final int MAX_MONTH = 12;
    static final int MIN_MONTH = 0;
    public static String[] month_name = {"January", "February",
    "March", "April", "May", "June", "July", "August", "September", 
    "October", "November","December"};
    public static String[] day_name = {"Su", "Mo", "Tu", 
       "We","Th","Fr","Sa"};
    public static GregorianCalendar jcal = new GregorianCalendar();

    static final GregorianCalendar CHANGE_DATE
               = new GregorianCalendar (1752, SEPTEMBER, 14);

    public static void main (String[] args) {
       int calmonth;
       int calyear;

       jcal.setGregorianChange (CHANGE_DATE.getTime());

       if (args.length == 2) {
         calmonth = Integer.parseInt (args[0]) - 1;
         calyear  = Integer.parseInt (args[1]);
       if(calmonth < MAX_MONTH && calmonth >= MIN_MONTH){

          if(calyear > MIN_YEAR && calyear < MAX_YEAR){
               jcal.set (calyear, calmonth, 1);
               int[][] made_month=make_month(calmonth, calyear);
               print_month(calmonth, made_month, calyear); 
           }else{ 
               misclib.die("illegal year value: use 1-9999");      
           }
        }
        else{
             misclib.die("illegal month value: use 1-12");
            }
      }
       else if(args.length == 1){
           calyear  = Integer.parseInt (args[0]);
           jcal.set (calyear, 0, 1);
           int[][][] made_year=make_year(calyear);
           print_year(calyear, made_year); 
       }
       else {         
         calmonth = jcal.get(GregorianCalendar.MONTH);
         calyear  = jcal.get(GregorianCalendar.YEAR);
      }       
  }

     public static int[][] make_month (int month, int year) {
        int[][] month_array = new int[WEEKS_IN_MONTH][DAYS_IN_WEEK];

        for (int i = 0; i < WEEKS_IN_MONTH; i++){
            for (int j = 0; j < DAYS_IN_WEEK; j++){
                month_array[i][j] = 0;
        }
        }
        int weeknum = 0;

        while (month == jcal.get(GregorianCalendar.MONTH)) {
           int day = jcal.get(GregorianCalendar.DAY_OF_MONTH);
           int weekday = (jcal.get(GregorianCalendar.DAY_OF_WEEK)) - 1;
           
           month_array[weeknum][weekday] = day; 

        if (weekday == 6) {
              weeknum++;
           }           
           jcal.add(GregorianCalendar.DAY_OF_MONTH, 1);
        }
        return month_array;        
     }


     public static int[][][] make_year(int year) {

        int[][][] year_array = new int[MONTHS_IN_YEAR][WEEKS_IN_MONTH]
            [DAYS_IN_WEEK];
        for(int i = 0; i < 12; i++){
            year_array[i] = make_month(i, year); 
        }

        return year_array;

     }


     public static int print_month(int month, int[][] made_month, 
     int year){
        System.out.printf("%10s %d%n", month_name[month], year);
        for (int i = 0; i < DAYS_IN_WEEK; i++){
            System.out.printf("%s ", day_name[i]);
        }
        System.out.printf("%n");

        for (int i = 0; i < WEEKS_IN_MONTH; i++){
            for (int j = 0; j < DAYS_IN_WEEK; j++){
                
                if(made_month[i][j] == 0){
                System.out.printf("   ");
            }
                else{           
                
                System.out.printf("%2s ", made_month[i][j]);
               }
             if(j == 6){
              System.out.printf("%n");  }
             }
         }         
     return 1;
     } 

    public static int print_year(int year, int[][][] made_year){
     System.out.printf("%34s%n", year);
     for(int i = 0; i < MAX_MONTH; i++){
        System.out.printf("%13s%n", month_name[i]);
        for (int j = 0; j < DAYS_IN_WEEK; j++){
            System.out.printf("%s ", day_name[j]);
        }
        System.out.printf("%n");

        for (int k = 0; k < WEEKS_IN_MONTH; k++){
            for (int l = 0; l < DAYS_IN_WEEK; l++){
                
                if(made_year[i][k][l] == 0){
                  System.out.printf("   ");
                }
                else{           
                
                System.out.printf("%2s ", made_year[i][k][l]);
               }
             if(l == 6){
              System.out.printf("%n");  }
             }
         }
        System.out.printf("%n");  
     }     
     return 1;

     }

}


