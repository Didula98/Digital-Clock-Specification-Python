# Digital-Clock-Specification

This digital clock prints the current time on the linux terminal. If a color is given as an argument to the program, the program prints a colored output.

## Inputs:
### Command-line arguments:
If a colour is given as an argument to the program with the ‘-c’ flag, the program prints the clock using the given colour. If no argument is given, it prints white as default.

##### Eg: 
`python filename.py -c red`

![red](https://user-images.githubusercontent.com/84913495/178502075-63e1f91a-798f-4553-8340-217e59110587.PNG)


`python filename.py -c green`

![green](https://user-images.githubusercontent.com/84913495/178502255-fec3c396-50e1-403f-844d-5a8f1442b2ea.PNG)

program supports for these standard colors - black, red, green, yellow, blue, magenta, cyan




If a colour is given as `-c random`, it prints the output with a random color gradient

##### Eg: 

`python filename.py -c random`

![random1](https://user-images.githubusercontent.com/84913495/178505191-567fb1ec-76a1-4db5-b2a2-ffd802e63fb8.PNG)

![random2](https://user-images.githubusercontent.com/84913495/178505352-f170a1b4-f938-46ac-8480-76c571bec0d0.PNG)


If a command is given as `--animated`, it prints animated color output

##### Eg:

`python filename.py --animated`

![ezgif com-gif-maker](https://user-images.githubusercontent.com/84913495/178730271-50f34ba1-d113-4a1c-bad8-f29b160140f8.gif)


If -h flag is given or the given arguments are invalid, program prints the usages of your program (how the arguments should be given).
