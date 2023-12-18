# 3D Box Collision with camera control and movement

I couldn't find an example online for exactly this, so by pulling together various functionalities from different tutorials, this rudimentary "game" was created. The centered box is controlled using WASD keys, and when it touches one of the other boxes, the box being touched turns red (indicating it's dead).

The viewing angle/ camera itself can also be controlled using the arrow keys (note that there is a slight delay with it, due to some "sticky key reaction" behaviour).

I couldn't get the project to actually run in VS Code, but it runs by starting a CMD prompt window in the root folder of the project and then running this command:
```
make && helloworld
```
Also, the color of the boxes can be controlled (shaded vs flat color) by commenting/ uncommenting this define inside GL_Cube.h:
```
#define SHADED_CUBE
```

![Screenshot 2023-12-18 151236](https://github.com/Shardss/box_collission/assets/12223453/40ef9a4b-6088-4fce-bf8f-bbdb858b52ba)
![Screenshot 2023-12-18 151303](https://github.com/Shardss/box_collission/assets/12223453/86c7dc90-ad12-42c5-82f7-654a3be71ae4)
![Screenshot 2023-12-18 151320](https://github.com/Shardss/box_collission/assets/12223453/0cf759b5-c899-4057-8639-df3008b1fd1a)
![Screenshot 2023-12-18 151336](https://github.com/Shardss/box_collission/assets/12223453/40ea42d7-b5a1-4b27-b4cf-5ad63b59bb9a)
![Screenshot 2023-12-18 151423](https://github.com/Shardss/box_collission/assets/12223453/fc849287-116e-4dca-8cc7-ad2f005afe37)
![Screenshot 2023-12-18 151447](https://github.com/Shardss/box_collission/assets/12223453/0acc12f1-16fe-4b74-a349-945afee2cc97)





