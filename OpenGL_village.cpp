#include <GL/glut.h>
#include <cmath>
// Global variables for cloud position
float cloud1X = -0.8f;
float cloud2X = 0.6f;


// Global variables for sun position
float sunY = 0.7f;
bool isSunRising = true;


// Global variables for person position
float personX = -0.8f;
float personY = -0.4f;
bool isPersonMoving = true;


void drawHouse() {
    // House body
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.5f, 0.3f); // Brown color
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

    // Roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.2f, 0.2f); // Red color
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    // Windows
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.7f, 0.9f); // Light blue color
    glVertex2f(-0.15f, 0.0f);
    glVertex2f(-0.05f, 0.0f);
    glVertex2f(-0.05f, 0.1f);
    glVertex2f(-0.15f, 0.1f);

    glVertex2f(0.05f, 0.0f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.15f, 0.1f);
    glVertex2f(0.05f, 0.1f);
    glEnd();

    // Door
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.2f, 0.1f); // Dark brown color
    glVertex2f(-0.07f, -0.2f);
    glVertex2f(0.07f, -0.2f);
    glVertex2f(0.07f, 0.0f);
    glVertex2f(-0.07f, 0.0f);
    glEnd();

    // Doorknob
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0.1f, 0.1f, 0.1f); // Black color
    glVertex2f(0.03f, -0.1f);
    glEnd();

    // Decorative elements (flower pots)
    glPushMatrix();
    glColor3f(0.2f, 0.5f, 0.2f); // Green color
    glTranslatef(-0.15f, -0.25f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);
    glTranslatef(0.3f, 0.0f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);
    glPopMatrix();
}




void drawTree() {
    // Tree trunk
    glColor3f(0.5f, 0.3f, 0.0f); // Brown color
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.5f);
    glVertex2f(0.05f, -0.5f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(-0.05f, -0.2f);
    glEnd();

    // Tree branches
    glColor3f(0.5f, 0.3f, 0.0f); // Brown color
    glBegin(GL_LINES);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(-0.15f, 0.0f);

    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.15f, 0.0f);
    glEnd();

    // Tree leaves
    glColor3f(0.0f, 0.7f, 0.0f); // Green color
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.2f, -0.2f);
    glEnd();
}


void drawSun() {
    // Sun

    glColor3f(1.0f, 0.9f, 0.0f); // Yellow color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.7f, sunY);
    for (int i = 0; i <= 360; i += 5) {
        float x = 0.7f + 0.1f * cos(i * 3.14159 / 180.0f);
        float y = sunY + 0.1f * sin(i * 3.14159 / 180.0f);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawCloud(float x, float y) {
    // Cloud
    glColor3f(0.9f, 0.9f, 0.9f); // Light gray color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i += 5) {
        float cx = x + 0.06f * cos(i * 3.14159 / 180.0f);
        float cy = y + 0.03f * sin(i * 3.14159 / 180.0f);
        glVertex2f(cx, cy);
    }
    glEnd();
}

void drawRoad() {
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f); // Gray color
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}


void drawPerson() {
    // Draw person (stick figure)
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    // Body
    glVertex2f(personX, personY);
    glVertex2f(personX, personY + 0.1f);
    // Arms
    glVertex2f(personX, personY + 0.05f);
    glVertex2f(personX - 0.05f, personY);
    glVertex2f(personX, personY + 0.05f);
    glVertex2f(personX + 0.05f, personY);
    // Legs
    glVertex2f(personX, personY);
    glVertex2f(personX - 0.05f, personY - 0.1f);
    glVertex2f(personX, personY);
    glVertex2f(personX + 0.05f, personY - 0.1f);
    glEnd();
    glLineWidth(1.0f);

    // Draw head
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glPointSize(15.0f);
    glBegin(GL_POINTS);
    glVertex2f(personX, personY + 0.13f);
    glEnd();
}

 ///////////////// Display /////////////////////

void display() {
  glClear(GL_COLOR_BUFFER_BIT);



   // Calculate the sky color gradient based on sun position (sunY)
    float blueSky = 0.5f + (sunY + 0.1f) * 0.5f; // Varies between 0.5 and 1.0
    float orangeSky = 1.0f - (sunY + 0.1f) * 0.5f; // Varies between 1.0 and 0.5

    // Draw sky gradient
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.7f, blueSky); // Light blue to dark blue
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(1.0f, orangeSky, 0.0f); // Dark blue to orange
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Draw sun
    glLoadIdentity();
    drawSun();

    // Draw road
    glLoadIdentity();
    drawRoad();

    // Draw houses
    glLoadIdentity();
    glTranslatef(-0.5f, -0.1f, 0.0f);
    drawHouse();

    glLoadIdentity();
    glTranslatef(0.2f, -0.2f, 0.0f);
    drawHouse();

    // Draw trees
    glLoadIdentity();
    glTranslatef(-0.7f, -0.4f, 0.0f);
    drawTree();

    glLoadIdentity();
    glTranslatef(0.5f, -0.4f, 0.0f);
    drawTree();

    // Draw clouds
    glLoadIdentity();
    drawCloud(cloud1X, 0.8f);
    drawCloud(cloud2X, 0.6f);

     // Draw person
    glLoadIdentity();
    drawPerson();

    glutSwapBuffers();

    glutPostRedisplay();
}

////////////////////////////////  update ////////////////////////////////

void update(int value) {
    // Cloud animation: Move clouds horizontally
    cloud1X += 0.001f;
    if (cloud1X > 1.2f)
        cloud1X = -1.2f;
    cloud2X += 0.0015f;
    if (cloud2X > 1.2f)
        cloud2X = -1.2f;

    //glutPostRedisplay();
    //glutTimerFunc(10, update, 0);



     // Sun animation: Rise and set
    if (isSunRising) {
        sunY += 0.001f;
        if (sunY >= 0.9f) // Change the value as needed for the sun's peak height
            isSunRising = false;
    } else {
        sunY -= 0.001f;
        if (sunY <= -0.1f) // Change the value as needed for the sun's lowest height
            isSunRising = true;
    }

    // Person animation: Run from one tree to another
    if (isPersonMoving) {
        personX += 0.001f;
        if (personX >= 0.7f) // Change the value as needed for the destination tree position
            isPersonMoving = false;
    } else {
        personX -= 0.001f;
        if (personX <= -0.8f) // Change the value as needed for the starting tree position
            isPersonMoving = true;
    }

    glutTimerFunc(10, update, 0);




}


void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}


///////////////////////int///////////////////////



///////////////////////////main////////////////////////

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Use GLUT_DOUBLE for double buffering
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Village");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(10, update, 0); // Move this line here
    glutMainLoop();
    return 0;
}
