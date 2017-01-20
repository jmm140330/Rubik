#include "Cube.hpp"
#include "OLL.hpp"
#include <iostream>
#include <string>

void OLL::solveOLL(Cube &cube) {
  int state = findState(cube);
  while (state == 0) {
    cube.moves("U");
    state = findState(cube);
  }
  solveCase(cube, state);
}

void OLL::solveCase(Cube &cube, int state) {
  switch(state) {
    case 1:
      cube.moves("FRURRRUUUFFF");
      break;
    case 2:
      cube.moves("FRURRRUUURURRRUUUFFF");
      break;
    case 3:
      cube.moves("FRURRRUUURURRRUUURURRRUUUFFF");
      break;
    case 4:
      cube.moves("BULUUULLLBBB");
      break;
    case 5:
      cube.moves("BULUUULLLULUUULLLBBB");
      break;
    case 6:
      cube.moves("BBBUUURRRURB");
      break;
  }
}

int OLL::findState(Cube &cube) {
  int topLayer[9];
  int redSide[3];
  int greenSide[3];
  int orangeSide[3];
  int blueSide[3];

  for (int i=0; i<9; ++i) {
    topLayer[i] = 0;
  }

  for (int i=0; i<2; ++i) {
    redSide[i] = 0;
    greenSide[i] = 0;
    orangeSide[i] = 0;
    blueSide[i] = 0;
  }

  if (cube.cubies[0][1] == 1) {
    topLayer[0] = 1;
  }
  if (cube.cubies[1][1] == 1) {
    topLayer[1] = 1;
  }
  if (cube.cubies[2][1] == 1) {
    topLayer[2] = 1;
  }
  if (cube.cubies[3][1] == 1) {
    topLayer[3] = 1;
  }
  if (cube.cubies[4][1] == 1) {
    topLayer[4] = 1;
  }
  if (cube.cubies[5][1] == 1) {
    topLayer[5] = 1;
  }
  if (cube.cubies[6][1] == 1) {
    topLayer[6] = 1;
  }
  if (cube.cubies[7][1] == 1) {
    topLayer[7] = 1;
  }
  if (cube.cubies[8][1] == 1) {
    topLayer[8] = 1;
  }
  //red layer top side
  if (cube.cubies[0][2] == 1) {
    redSide[0] = 1;
  }
  if (cube.cubies[1][2] == 1) {
    redSide[1] = 1;
  }
  if (cube.cubies[2][2] == 1) {
    redSide[2] = 1;
  }
  //green
  if (cube.cubies[0][3] == 1) {
    greenSide[0] = 1;
  }
  if (cube.cubies[1][3] == 1) {
    greenSide[1] = 1;
  }
  if (cube.cubies[2][3] == 1) {
    greenSide[2] = 1;
  }

  if (cube.cubies[0][4] == 1) {
    orangeSide[0] = 1;
  }
  if (cube.cubies[1][4] == 1) {
    orangeSide[1] = 1;
  }
  if (cube.cubies[2][4] == 1) {
    orangeSide[2] = 1;
  }

  if (cube.cubies[0][5] == 1) {
    blueSide[0] = 1;
  }
  if (cube.cubies[1][5] == 1) {
    blueSide[1] = 1;
  }
  if (cube.cubies[2][5] == 1) {
    blueSide[2] = 1;
  }

  if (topLayer[2] && topLayer[3] && topLayer[4] && topLayer[5] && topLayer[8] && redSide[1] && orangeSide[1] && blueSide[0] && blueSide[2]) {
     return 1;
  }
  else if (topLayer[1] && topLayer[3] && topLayer[4] && redSide[1] && redSide[2] && greenSide[1] && orangeSide[0] && blueSide[0] && blueSide[2]) {
    return 2;
  }
  else if (topLayer[1] && topLayer[3] && topLayer[4] && topLayer[5] && topLayer[7] && redSide[0] && redSide[2] && orangeSide[0] && orangeSide[2]) {
    return 3;
  }
  else if (topLayer[2] && topLayer[4] && topLayer[5] && topLayer[7] && topLayer[8] && orangeSide[1] && blueSide[0] && blueSide[1] && blueSide[2]) {
    return 4;
  }
  else if (topLayer[3] && topLayer[4] && topLayer[5] && redSide[1] && redSide[2] && orangeSide[0] && orangeSide[1] && blueSide[0] && blueSide[2]) {
    return 5;
  }
  else if (topLayer[0] && topLayer[3] && topLayer[4] && topLayer[6] && topLayer[7] && greenSide[0] && greenSide[1] && greenSide[2] && orangeSide[1]) {
    return 6;
  }
  else if (topLayer[1] && topLayer[4] && topLayer[5] && redSide[0] && redSide[1] && greenSide[0] && greenSide[2] && orangeSide[2] && blueSide[1]) {
    return 7;
  }
  else if (topLayer[2] && topLayer[4] && topLayer[5] && topLayer[7] && redSide[2] && greenSide[1] && greenSide[2] && orangeSide[1] && blueSide[0] && blueSide[1]) {
    return 8;
  }
  else if (topLayer[0] && topLayer[3] && topLayer[4] && topLayer[7] && redSide[2] && greenSide[1] && greenSide[2] && orangeSide[1] && blueSide[2]) {
    return 9;
  }
  else {
    return 0;
  }

}
