#include "stdafx.h"
#include "base.h"
#include "sys.h"

void Render() {
  glClear(GL_COLOR_BUFFER_BIT);
}

void StartGame() {
}

void RunGame() {
}

void ProcessInput() {
}

// Game state (apart from entities and other standalone modules
float g_time = 0.f;

// Main
int Main(void) {
  // Start things up and load resources
  StartGame();

  // Set up rendering
  glViewport(0, 0, SYS_WIDTH, SYS_HEIGHT);
  glClearColor(0.0f, 0.1f, 0.3f, 0.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, G_WIDTH, 0.0, G_HEIGHT, 0.0, 1.0);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Main game loop
  while(!SYS_GottaQuit()) {
    Render();
    ProcessInput();
    RunGame();
    SYS_Show();
    SYS_Pump();
    SYS_Sleep(16);
    g_time += 1.f/60.f;
  }

  return 0;
}

