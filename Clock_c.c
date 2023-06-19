#include <stdio.h>
#include <time.h> // to get current time

//declaring all functions
int cmp(char[], char[]);
int color_cmp(char*);
void number_print(int value, int,int);
void number_position(int (*digit_array)[6], int,int);
void colon(int);

int digit_array0[5][6]={            //0

        {1,1,1,1,1,1},
        {1,1,0,0,1,1},
        {1,1,0,0,1,1},
        {1,1,0,0,1,1},
        {1,1,1,1,1,1}
      };



int digit_array1[5][6]={			// 1

		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	  };



int digit_array2[5][6]={			// 2

		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1}
	  };

int digit_array3[5][6]={			// 3

		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	  };



int digit_array4[5][6]={			// 4

		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	  };



int digit_array5[5][6]={			// 5

		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	  };



int digit_array6[5][6]={			// 6

		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	  };



int digit_array7[5][6]={			// 7

		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	  };



int digit_array8[5][6]={            //8

		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	  };



int digit_array9[5][6]={			// 9

		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	  };

//main function
int main(int argc, char ** argv){
  int flag=0, c = 47;
  char arr[100];

  //checking argc and argv
  if(argc == 1){ //checking input ./prog

    flag = 1;

  }else{
    for(int i = 1; i < argc; i++){

      if(argv[i][0] == '-' && argv[i][1] == 'c'){
        if(argv[i][2] == '\0' && argc > i+1){//checking inputs like ./prog -c red or ./prog -c gghdh
          for(int j = 0; argv[i+1][j] != '\0'; j++){
            arr[j] = argv[i+1][j]; //get color input into an array for later use
          }
          if(color_cmp(argv[i+1])){
            flag = 1;
            c = color_cmp(argv[i+1]);

          }else if(color_cmp(argv[i+1]) == 0){
            //ignore '-' and 'c' in the array (it happens some inputs like ./prog -c -c -cred)
            if(arr[0] == '-' && arr[1] == 'c'){
              for(int k =0; arr[k] != '\0'; k++){
                arr[k] = arr[k+2];//updated array
              }
            }

          }

        }else{//checking inputs like ./prog -cred or ./prog -cgghdh


          for(int j = 2; argv[i][j] != '\0'; j++){
            arr[j-2] = argv[i][j]; //get color input to an array for check errors in input
          }

          if(color_cmp(arr)){
            flag = 1;
            c = color_cmp(arr);
          }else{
            if(argv[i][2] != '\0'){
              flag = -1;
            }

          }
        }
      }else if(argv[i][0] == '-' && argv[i][1] == '\0'){//checking inputs like ./prog -
        flag = 1;
      }else if(argv[i][0] != '-' && argv[i-1][0] != '-' && argv[i-1][1] != 'c'){ //checking inputs
        flag = 1;
      }else if(argv[i][0] == '-' && argv[i][1] == 'h' && argv[i][2] == '\0'){ //checking help input
        flag = 2;
      }
    }
  }



  if(flag == 1){
    printf("\033[2J"); //to clears entire screen
    printf("\033[?25l"); // to make cursor invisible

    time_t rawtime, date; //declare variables
    struct tm * timeinfo;

    while(1){
      //in here it update time and date to current time
      time(&rawtime);
      timeinfo = localtime(&rawtime);

      date = time(NULL);
      struct tm tm = *localtime(&date);

      //updates current time converts to the string
      char *str = asctime(timeinfo);

      colon(c); // call colon function which prints two colon in the screen

      int value = 0;
      for(int i = 11; i <= 18; i++){ // converts char values in time string to the integers
        if(str[i] < 58 && str[i] > 47){
          value++;
          number_print(str[i]-48,value,c);


        }
      }
      //printing date
      printf("\033[%dm\033[8;22H%d-%02d-%02d", c-10, tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);

    }
 //if user input worng color it shows colors which are allows in the program
  }else if(flag == -1){

    for(int i = 0; arr[i] != '\0'; i++){
         printf("%c", arr[i]);
    }
    printf(" :This is not a valid color, Please enter one of these colours: black, red, green, yellow, blue, magenta, cyan, white\n");

   //if user input -h or other wrong input it prints user mannuel
  }else{
     printf("Invalid use of arguments.\n");
    printf( "%-32s%s\n%-32s%s\n", "usage : clock -h", "quick help on cmd", "usage : clock -c <color>", "print clock with a color");
    if(flag == 2){
      printf("<color-black|red|green|yellow|blue|magenta|cyan|white>  supported colors\n");
    }


  }

  return 0;
}



//function which compre two strings. if strings same it return 0, else return 1.
int cmp(char str1[], char str2[]){
  int flag = 1;
  for(int i = 0; str1[i] != 0 || str2[i] != 0; i++){
    if(str1[i] != str2[i]){
      if(str1[i] - str2[i] == 32 || str1[i] - str2[i] == -32){
          flag = 1;
      }else{
          flag = 0;
          break;
      }
    }
  }
  return flag;
}


//this function checking the colors avalable in array and compare colors with user inputs
int color_cmp(char *str1){
    char *arr[] = {"black","red","green","yellow", "blue", "magenta", "cyan", "white"};
    int n = 0;
    for(int i = 0; i < (int)(sizeof(arr)/sizeof(arr[0])); i++){
        if(cmp(str1, arr[i])){ //if user input color is matched to one of the color in array it gives color code value
            n = i+40;
        }
    }

  return n;

}


//function which use to print a digit on the screen
void number_print(int value, int value1, int color){
  // for each digit(0-9) it calls specified array in below
    if(value == 0){

    number_position(digit_array0,value1,color);
    }

    else if(value==1){

    number_position(digit_array1,value1,color);

	}
	else if(value==2){

    number_position(digit_array2,value1,color);

	}
	else if(value==3){

    number_position(digit_array3,value1,color);
	}

	else if(value==4){

    number_position(digit_array4,value1,color);
	}

	else if(value==5){

    number_position(digit_array5,value1,color);
	}

	else if(value==6){

    number_position(digit_array6,value1,color);
	}

	else if(value==7){

    number_position(digit_array7,value1,color);
	}

	else if(value==8){

    number_position(digit_array8,value1,color);
	}

	else if(value==9){
    number_position(digit_array9,value1,color);
	}


}
//this function used to print digit in specified position
void number_position(int (*digit_array)[6], int position,int color){
  int start;
  //for each digit in the time has specific position
  if(position == 1){
    start = 2;
  }
  else if(position == 2){
    start = 9;
  }
  else if(position == 3){
    start = 21;
  }
  else if(position == 4){
    start = 28;
  }
  else if(position == 5){
    start = 40;
  }
  else if(position == 6){
    start = 47;
  }

  //print digit and chages color which is user need
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 6; j++){
      if(digit_array[i][j] == 1){
        printf("\033[%dm\033[%d;%dH%c", color, i+2,j+start,' '); //print space for each 1 in array and fill it with backgroung color

      }
      else{
        printf("\033[0m\033[%d;%dH%c",i+2,j+start,' '); // else print space and reset the colors
      }
      printf("\033[0m"); //after all reset the colors
    }

  }
}

//function which print two colon in the screen
void colon(int val){
  //considering each position
  printf("\033[%dm\033[%d;%dH%c\033[%d;%dH%c", val,3,17,' ',3,18,' ');
  printf("\033[%dm\033[%d;%dH%c\033[%d;%dH%c",val,5,17,' ',5,18,' ');
  printf("\033[%dm\033[%d;%dH%c\033[%d;%dH%c",val,3,36,' ',3,37,' ');
  printf("\033[%dm\033[%d;%dH%c\033[%d;%dH%c",val,5,36,' ',5,37,' ');
}
