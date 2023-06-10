#include "raylib_headers/raylib.h"
#include <math.h>

// equation use here : y=a*sin(bx)
/*
 * value of a = 2
 * value of b = 1
 *
 */

int screen_width = 700;
int screen_height = 600;
int main(){
	InitWindow(screen_width, screen_height, "wave gen");
	float frequency = 1;
	float periodicity = 1;
	float amplitude = 50;
	float i = 0;
	SetTargetFPS(144);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLineV(
			(Vector2){0, (float)screen_height/2},
			(Vector2){screen_width, (float)screen_height/2},
			WHITE
		);	
	
		DrawText(TextFormat("periodicity : %f", periodicity), 
			30, 
			30, 
			30, 
			PINK);
	
		DrawText(TextFormat("amplitude : %f", amplitude), 
			30, 
			60, 
			30, 
			PINK);
		/*
		DrawText(TextFormat("angle : %f", x), 
			30, 
			90, 
			30, 
			PINK)
			*/
		if(IsKeyDown(KEY_W)){
			amplitude += 3;
		}
		
		if(IsKeyDown(KEY_S)){
			amplitude -= 3;
		}

		if(IsKeyDown(KEY_UP)){
			periodicity += 0.05;
		}
		if(IsKeyDown(KEY_DOWN)){
			periodicity -= 0.05;
		}

		//periodicity = 1;
		i += 0.05;	
		
		for(int x = 0; x < 700; x += 1){
			int y = amplitude*sin((PI/180)*x*periodicity + i); 
			DrawCircle(x, 
			y + screen_height/2, 
			3,
			PURPLE	

			);
		}
		
		EndDrawing();
	}
	
}
