#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define QUADRANTE1 0
#define QUADRANTE2 1
#define QUADRANTE3 2
#define QUADRANTE4 3
#define PI 3.1415926535897932384
#define OBJDIFERENTE 0
#define CIRCDIFERENTE 1


GLfloat moveObj1 = 100;
GLfloat moveObj1y = 150;
GLfloat moveObj2 = 500;
GLfloat moveObj2y = 300;
GLfloat moveObj3 = 400;
GLfloat moveObj3y = 70;

GLfloat y3;
GLfloat y4;
GLfloat y5;
GLfloat x1;
GLfloat x2;
GLfloat x3;
GLint sentido = QUADRANTE1;
GLint sentido2 = QUADRANTE2;
GLint sentido3 = QUADRANTE1;
GLint action = 0;
GLint opcao = CIRCDIFERENTE;

void iniciaParametrosVisualizacao(void) {
	//Fundo da cena preto
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 400);
}

void display(void){
	float aux = 0;
	float j = 0;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);


	if(opcao == OBJDIFERENTE){
		glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(moveObj1-50.0f, moveObj1y-50.0f);
			glColor3f(0.5f, 0.0f, 0.0f);
			glVertex2f(moveObj1+50.0f, moveObj1y-50.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2f(moveObj1+0.0f, moveObj1y+50.0f);
		glEnd();

		glBegin(GL_QUADS);
			glColor3f(0.0f, 0.0f, 0.4f); // definição da cor de desenho
			glVertex2f(moveObj2-50.0f, moveObj2y+50.0f);
			glVertex2f(moveObj2-50.0f, moveObj2y-50.0f);

			glColor3f(1.0f, 0.5f, 0.0f);
			glVertex2f(moveObj2+50.0f, moveObj2y-50.0f);
			glVertex2f(moveObj2+50.0f, moveObj2y+50.0f);
		glEnd();
	}

	if(opcao == CIRCDIFERENTE)	{
		glBegin(GL_POLYGON);
			glColor3f(1.0f, 0.5f, 0.0f);

			for (float i = 0; i < 2 * PI; i += 0.025f){
				aux = i-j;

				if(aux < 1.0f){
					glColor3f(aux+0.2f, aux+0.1f, aux);
				}
				else{
					j++;
					glColor3f(aux+0.2f-j, aux+0.1f-j, aux-j);
				}

				glVertex2f(50.0f * (float) -cos(i) + moveObj1, 50.0f * (float) sin(i) + moveObj1y);
			}
		glEnd();

		aux = 0;
		j = 0;

		glBegin(GL_POLYGON);
			glColor3f(0.0f, 0.0f, 0.8f);

			for (float i = 0; i < 2 * PI; i += 0.025f){
				aux = i-j;

				if(aux < 1.0f){
					glColor3f(aux+0.2f, aux, aux+0.1f);
				}
				else{
					j++;
					glColor3f(aux+0.2f-j, aux-j, aux+0.1f-j);
				}

				glVertex2f(50.0f * (float) -cos(i) + moveObj2, 50.0f * (float) sin(i) + moveObj2y);
			}
		glEnd();

	}

	aux = 0;
	j = 0;

	glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.6f, 0.4f);

		for (float i = 0; i < 2 * PI; i += 0.025f){
			aux = i-j;

			if(aux < 1.0f){
				glColor3f(aux, aux+0.1f, aux+0.2f);
			}
			else{
				j++;
				glColor3f(aux-j, aux+0.1f-j, aux+0.2f-j);
			}

			glVertex2f(50.0f * (float) -cos(i) + moveObj3, 50.0f * (float) sin(i) + moveObj3y);
		}
	glEnd();

	aux = 0;
	j = 0;

	glutSwapBuffers();
	glFlush();
}

void mudarObj1(void){

	if (sentido == QUADRANTE1) {
		moveObj1 += x1;
		moveObj1y += y3;
		if (moveObj1 >= 650.0f || moveObj1y >= 450.0f){
			while(moveObj1 > -52.0f && moveObj1y > -52.0f){
				moveObj1 -= x1;
				moveObj1y -= y3;
			}
			sentido = QUADRANTE1;
		}
	}
	
	if(sentido == QUADRANTE3) {
		moveObj1 -= x1;
		moveObj1y -= y3;
		if (moveObj1 <= -50.0f || moveObj1y <= -50.0f){
			while(moveObj1 < 652.0f && moveObj1y < 452.0f){
				moveObj1 += x1;
				moveObj1y += y3;
			}
			sentido = QUADRANTE3;
		}
	}

	if (sentido == QUADRANTE2){
		moveObj1 -= x1;
		moveObj1y += y3;
		if (moveObj1 <= -50.0f || moveObj1y >= 450.0f){
			while(moveObj1 < 652.0f && moveObj1y > -52.0f){
				moveObj1 += x1;
				moveObj1y -= y3;
			}
			sentido = QUADRANTE2;
		}
	}

	if (sentido == QUADRANTE4) {
		moveObj1 += x1;
		moveObj1y -= y3;
		if (moveObj1 >= 650.0f || moveObj1y <= -50.0f){
			while(moveObj1 > -52.0f && moveObj1y < 452.0f){
				moveObj1 -= x1;
				moveObj1y += y3;
			}
			sentido = QUADRANTE4;
		}
	}
}

void mudarObj2(void){

	if (sentido2 == QUADRANTE1) {
		moveObj2 += x2;
		moveObj2y += y4;
		if (moveObj2 >= 650.0f || moveObj2y >= 450.0f){
			while(moveObj2 > -52.0f && moveObj2y > -52.0f){
				moveObj2 -= x2;
				moveObj2y -= y4;
			}
			sentido2 = QUADRANTE1;
		}
	}
	
	if(sentido2 == QUADRANTE3) {
		moveObj2 -= x2;
		moveObj2y -= y4;
		if (moveObj2 <= -50.0f || moveObj2y <= -50.0f){
			while(moveObj2 < 652.0f && moveObj2y < 452.0f){
				moveObj2 += x2;
				moveObj2y += y4;
			}
			sentido2 = QUADRANTE3;
		}
	}

	if (sentido2 == QUADRANTE2){
		moveObj2 -= x2;
		moveObj2y += y4;
		if (moveObj2 <= -50.0f || moveObj2y >= 450.0f){
			while(moveObj2 < 652.0f && moveObj2y > -52.0f){
				moveObj2 += x2;
				moveObj2y -= y4;
			}
			sentido2 = QUADRANTE2;
		}
	}

	if (sentido2 == QUADRANTE4) {
		moveObj2 += x2;
		moveObj2y -= y4;
		if (moveObj2 >= 650.0f || moveObj2y <= -50.0f){
			while(moveObj2 > -52.0f && moveObj2y < 452.0f){
				moveObj2 -= x2;
				moveObj2y += y4;
			}
			sentido2 = QUADRANTE4;
		}
	}
}

void mudarObj3(void){

	if (sentido3 == QUADRANTE1) {
		moveObj3 += x3;
		moveObj3y += y5;
		if (moveObj3 >= 650.0f || moveObj3y >= 450.0f){
			while(moveObj3 > -52.0f && moveObj3y > -52.0f){
				moveObj3 -= x3;
				moveObj3y -= y5;
			}
			sentido3 = QUADRANTE1;
		}
	}
	
	if(sentido3 == QUADRANTE3) {
		moveObj3 -= x3;
		moveObj3y -= y5;
		if (moveObj3 <= -50.0f || moveObj3y <= -50.0f){
			while(moveObj3 < 652.0f && moveObj3y < 452.0f){
				moveObj3 += x3;
				moveObj3y += y5;
			}
			sentido3 = QUADRANTE3;
		}
	}

	if (sentido3 == QUADRANTE2){
		moveObj3 -= x3;
		moveObj3y += y5;
		if (moveObj3 <= -50.0f || moveObj3y >= 450.0f){
			while(moveObj3 < 652.0f && moveObj3y > -52.0f){
				moveObj3 += x3;
				moveObj3y -= y5;
			}
			sentido3 = QUADRANTE2;
		}
	}

	if (sentido3 == QUADRANTE4) {
		moveObj3 += x3;
		moveObj3y -= y5;
		if (moveObj3 >= 650.0f || moveObj3y <= -50.0f){
			while(moveObj3 > -52.0f && moveObj3y < 452.0f){
				moveObj3 -= x3;
				moveObj3y += y5;
			}
			sentido3 = QUADRANTE4;
		}
	}
}

void objeto(int passo){

	mudarObj1();
	mudarObj2();
	mudarObj3();

	//Forca o GLUT a pintar a cena novamente
	glutPostRedisplay();
	//Aciona novamente o timer
	glutTimerFunc(1, objeto, 1);
}

void CliqueObj1(int x, int z){
	double aux = 0;
	double cosseno = 0;

	if(x>moveObj1 && z>moveObj1y){
        sentido = QUADRANTE1;
    }

    if(x<moveObj1 && z>moveObj1y){
        sentido = QUADRANTE2;
    }

    if(x<moveObj1 && z<moveObj1y){
       	sentido = QUADRANTE3;
    }

    if(x>moveObj1 && z<moveObj1y){
       	sentido = QUADRANTE4;
    }

    aux = (x - moveObj1)/(sqrt(pow(x - moveObj1, 2) + pow(z - moveObj1y, 2)));
    cosseno = fabs(aux);
    x1 = 2*cosseno;
    y3 = sqrt((pow(x1, 2)/pow(cosseno,2))-pow(x1, 2));
}

void CliqueObj2(int x, int z){
	double aux = 0;
	double cosseno = 0;

	if(x>moveObj2 && z>moveObj2y){
        sentido2 = QUADRANTE1;
    }

    if(x<moveObj2 && z>moveObj2y){
        sentido2 = QUADRANTE2;
    }

    if(x<moveObj2 && z<moveObj2y){
       	sentido2 = QUADRANTE3;
    }

    if(x>moveObj2 && z<moveObj2y){
       	sentido2 = QUADRANTE4;
    }

    aux = (x - moveObj2)/(sqrt(pow(x - moveObj2, 2) + pow(z - moveObj2y, 2)));
    cosseno = fabs(aux);
    x2 = 2.5*cosseno;
    y4 = (sqrt((pow(x2, 2)/pow(cosseno,2))-pow(x2, 2)));
}

void CliqueObj3(int x, int z){
	double aux = 0;
	double cosseno = 0;

	if(x>moveObj3 && z>moveObj3y){
        sentido3 = QUADRANTE1;
    }

    if(x<moveObj3 && z>moveObj3y){
        sentido3 = QUADRANTE2;
    }

    if(x<moveObj3 && z<moveObj3y){
       	sentido3 = QUADRANTE3;
    }

    if(x>moveObj3 && z<moveObj3y){
       	sentido3 = QUADRANTE4;
    }

    aux = (x - moveObj3)/(sqrt(pow(x - moveObj3, 2) + pow(z - moveObj3y, 2)));
    cosseno = fabs(aux);
    x3 = 3*cosseno;
    y5 = sqrt((pow(x3, 2)/pow(cosseno,2))-pow(x3, 2));
}

void CliqueMouse(int button, int state, int x, int y){ 
	int z = (400-y);

    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
        	CliqueObj1(x, z);
        	CliqueObj2(x, z);
        	CliqueObj3(x, z);
        	
        	if(action == 0){
        		glutTimerFunc(1, objeto, 1);
        		action = 1;
        	}
        }
	}
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Moving Objetcs");
	iniciaParametrosVisualizacao();
	glutDisplayFunc(display);
	glutMouseFunc(CliqueMouse);
	glutMainLoop();
	return 0;
}