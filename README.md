Hello. My C++ learning journey continues and today I wrote a GUI program to visualize punctual charges and their 
electrical field. The physics and maths were derived from Columb's law (which is really not complicated).

![](data/output.gif)

### Usage

Clone and compile the program

```
git clone git@github.com:longuyen97/electric-field.git
cd electric-field
mkdir build
cd build
cmake ..
make
```

Run the executable

```
./main
```

I made a small video and uploaded it to Youtube: https://www.youtube.com/watch?v=4WNF9Z6TBV0

### Generate GIF

```
ffmpeg  -t 30 -i input.mp4 -vf "fps=30,scale=800:-1:flags=lanczos,split[s0][s1];[s0]palettegen[p];[s1][p]paletteuse" -loop 0 output.gif
```