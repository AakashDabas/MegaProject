/*
        If you need to run these codes then first you need to enable the graphics library and please make sure that the bgi
  folder is at the following location:
       C:TC\BGI

       Also you will need to paste the dat files which contains the pictures. You can download them from my website.
PLEASE VISIT MY WEBISTE: aakashdabas.weebly.com or entangler.in or just google Aakash Dabas Entangler
*/

#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <process.h>
#include <stdio.h>
#include <string.h>

void vibo(char ch[], int x);
void neutralize();
int x1, y1, x2, y2, xr, yr, xp, yp, rx1, rx2, ry1, ry2, fx1, fx2, fy1, fy2, rx3, ry3, fx3, fy3, rx4, rx5, rx6, ry4, ry5, ry6, fx4, fx5, fx6, fy4, fy5, fy6, ry7, ry8, rx7, rx8, fcode = BLUE, keyo = 0, keys = 0, keyg = 0;
void elp(int, int, int, int, int);
void color2(int x)
{
  for (int i = 0; i < 650; i++)
    for (int j = 0; j < 35; j++)
      if (getpixel(i, j) == 15)
        putpixel(i, j, x);
}
void color(int x, char a[], int xc = 50, int yc = 50, int st = 1, int sz = 1)
{
  setcolor(x);
  settextstyle(st, 0, sz);
  outtextxy(xc, yc, a);
}
void drwc(int x, int y, int r, int color, float t = 0.1)
{
  int xcord, ycord;
  for (int ra = 0; ra <= r; ra++)
    for (float i = 0; i <= 6.2857; i += t)
    {
      xcord = x + (ra * cos(i));
      ycord = y + (ra * sin(i));
      putpixel(xcord, ycord, color);
    }
}

int drwcg(int x, int y, int r = 4, int t = 1)
{
  int xcord, ycord;
  for (int ra = 0; ra <= r; ra++)
    for (float i = 0; i <= 6.2857; i += t)
    {
      xcord = x + (ra * cos(i));
      ycord = y + (ra * sin(i));
      if (getpixel(xcord, ycord) != 0)
        return getpixel(xcord, ycord);
    }
  return BLACK;
}
void cclrscr()
{
  cleardevice();
}
void neutralize()
{
  char CH;
  int x;
  while (kbhit())
    CH = getch();
  x = CH;
  x = 0;
  cout << x << "\b \b";
}

timerinput(char &ch)
{
  for (float i = 0; i < 10000; i += 0.03)
    if (kbhit())
    {
      ch = getch();
      neutralize();
      return 1;
    }
  ch = '~';
  return 0;
}
void snd(int, int, int);
void inputchk(char a[])
{
  char ch;
  int i = 0, chck = 0, das = 0;
  int k = 0;
  gotoxy(1, 1);
  while (a[i] != '\0')
  {
    chck = timerinput(ch);
    if (chck == 1 && ch != '0')
    {
      cout << ch;
      color2(14);
      snd(500, 3, 10);
      snd(200, 10, 20);
      das = 1;
    }
    else if (chck == 0 && das == 1)
    {
      cclrscr();
      color(3, "The Entered String Or Input is not defined for me");
      gotoxy(1, 1);
      delay(2000);
      cclrscr();
      das = 0;
      k = 0;
    }
    if (ch == '0')
      exit(0);
    if (ch == a[i] || ch == a[i] + 32)
    {
      i++;
    }
    else
      i = 0;
    k++;
    if (k == 25)
    {
      cclrscr();
      color(11, "I can't understand what you are saying. Please try to use the standard defined  language for me.");
      delay(2000);
      cclrscr();
      k = 0;
      neutralize();
    }
  }
  delay(1000);
}

int qua(int i, int mzr)
{
  if (i < mzr)
    return 1;
  else if (i < 2 * mzr)
    return 2;
  else if (i < 3 * mzr)
    return 3;
  else
    return 4;
}

void xycordset(int x, int y, int mzr, int mnr, int &setx, int &sety, int i)
{
  float z, vy;
  if (i > 4 * mzr)
  {
    i = (i - (i / (4 * mzr)) * mzr);
  }
  int quad = qua(i, mzr);

  if (i >= 3 * mzr)
  {
    i = i - 3 * mzr;
    z = mzr - i;
  }
  else if (i >= 2 * mzr)
  {
    i = i - 2 * mzr;
    z = i;
  }
  else if (i >= mzr)
  {
    i = i - mzr;
    z = mzr - i;
  }
  else
    z = i;
  vy = mnr * (sqrt(1 - ((z * z) / (mzr * mzr))));
  if (quad == 1)
  {
    setx = x - i;
    sety = y - vy;
  }
  else if (quad == 2)
  {
    setx = x - mzr + i;
    sety = y + vy;
  }
  else if (quad == 3)
  {
    setx = x + i;
    sety = y + vy;
  }
  else
  {
    setx = x + mzr - i;
    sety = y - vy;
  }
}

void drwcir(int x, int y, int r, int colour)
{
  int xcord, ycord;
  for (float i = 0; i <= 6.2857; i += 0.01)
  {
    xcord = x + (r * cos(i));
    ycord = y + (r * sin(i));
    putpixel(xcord, ycord, colour);
  }
}

void drwcir2(int x, int y, int r, int colour)
{
  int xcord, ycord;
  for (float i = 0; i <= 6.2857; i += 0.1)
  {
    xcord = x + (r * cos(i));
    ycord = y + (r * sin(i));
    putpixel(xcord, ycord, colour);
  }
}

void fltoscrnerth(char nam[], int a = 0, int b = 0, int code = -1)
{
  ifstream fin(nam, ios::binary);
  int x, y, c;
  while (fin)
  {
    fin.read((char *)&x, 4);
    fin.read((char *)&y, 4);
    fin.read((char *)&c, 4);
    if (getpixel(x + a, y + b) != 0 && getpixel(x + a, y + b) != fcode - 1)
      if (code == -1 && c == BLUE)
        putpixel(x + a, y + b, LIGHTBLUE);
      else if (code == -1)
        putpixel(x + a, y + b, c);
      else
        putpixel(x + a, y + b, code);
  }
}
void erth()
{
  for (int i = -35; !kbhit(); i++)
  {
    fltoscrnerth("wldmap.dat", i + 100, 200);
    if (i > 165)
      i = -35;
    delay(10);
  }
}

void earth()
{
  char ch;
  for (int i = 0; i <= 35; i++)
    drwcir(254, 248, i, LIGHTBLUE);
  while (kbhit())
    ch = getch();
  cout << ch << "\b \b";
  erth();
}

void cubereal()
{
  char ch = '#', temp = '#';
  int das = 1, x = 15, mnr = 20, s = 310, y1 = 175, y2 = 275, color1 = 1, pitch = 0;
  randomize();
  int i = 0, j = 50, k = 100, l = 150;
  while (ch != '0')
  {
    if (i > 200)
      i = 1;
    else if (i < 1)
      i = 200;
    if (j > 200)
      j = 1;
    else if (j < 1)
      j = 200;
    if (k > 200)
      k = 1;
    else if (k < 1)
      k = 200;
    if (l > 200)
      l = 1;
    else if (l < 1)
      l = 200;

    xycordset(s, y1, 50, mnr, rx1, ry1, i);
    xycordset(s, y1, 50, mnr, rx2, ry2, j);
    xycordset(s, y1, 50, mnr, rx3, ry3, k);
    xycordset(s, y1, 50, mnr, rx4, ry4, l);
    xycordset(s, y2, 50, mnr, rx5, ry5, i);
    xycordset(s, y2, 50, mnr, rx6, ry6, j);
    xycordset(s, y2, 50, mnr, rx7, ry7, k);
    xycordset(s, y2, 50, mnr, rx8, ry8, l);
    if (color1 == fcode + 1)
      setcolor(fcode + 3);
    else
      setcolor(color1);
    line(rx1, ry1, rx2, ry2);
    line(rx2, ry2, rx3, ry3);
    line(rx3, ry3, rx4, ry4);
    line(rx4, ry4, rx1, ry1);
    line(rx5, ry5, rx6, ry6);
    line(rx6, ry6, rx7, ry7);
    line(rx7, ry7, rx8, ry8);
    line(rx8, ry8, rx5, ry5);
    line(rx1, ry1, rx5, ry5);
    line(rx2, ry2, rx6, ry6);
    line(rx3, ry3, rx7, ry7);
    line(rx4, ry4, rx8, ry8);
    if (ch == '#')
    {
      setcolor(fcode + 2);
      outtext("PRESS THE DIRECTION KEY: ");
      ch = getch();
      cleardevice();
    }
    if (ch == 77)
    {
      pitch = 1000 + random(200);
      sound(pitch);
    }
    else if (ch == 75)
    {
      pitch = 800 + random(200);
      sound(pitch);
    }
    else
      nosound();
    delay(x);
    setcolor(fcode + 1);
    line(rx1, ry1, rx2, ry2);
    line(rx2, ry2, rx3, ry3);
    line(rx3, ry3, rx4, ry4);
    line(rx4, ry4, rx1, ry1);
    line(rx5, ry5, rx6, ry6);
    line(rx6, ry6, rx7, ry7);
    line(rx7, ry7, rx8, ry8);
    line(rx8, ry8, rx5, ry5);
    line(rx1, ry1, rx5, ry5);
    line(rx2, ry2, rx6, ry6);
    line(rx3, ry3, rx7, ry7);
    line(rx4, ry4, rx8, ry8);
    if (kbhit())
    {
      temp = getch();
      if (temp >= '1' && temp <= '9')
      {
        color1 = temp - 48;
        das = 0;
      }
      else if (temp == '!')
      {
        color1 = 10;
        das = 0;
      }
      else if (temp == '@')
      {
        color1 = 11;
        das = 0;
      }
      else if (temp == '#')
      {
        color1 = 12;
        das = 0;
      }
      else if (temp == '$')
      {
        color1 = 13;
        das = 0;
      }
      else if (temp == '%')
      {
        color1 = 14;
        das = 0;
      }
      else if (temp == '^')
      {
        color1 = 15;
        das = 0;
      }
      else if (temp == 'f')
      {
        if (x < 40)
          x++;
        das = 0;
      }
      else if (temp == 's')
      {
        if (x >= 5)
          x--;
        das = 0;
      }
      else if (temp == 75)
      {
        das = 0;
        ch = 75;
      }
      else if (temp == 77)
      {
        das = 0;
        ch = 77;
      }
      else if (temp == '0')
      {
        nosound();
        break;
      }
      else if (das == 1)
        ch = temp;
    }

    if (ch == 75)
    {
      i++;
      j++;
      k++;
      l++;
    }
    else if (ch == 77)
    {
      i--;
      j--;
      k--;
      l--;
    }
    else
    {
      nosound();
      nosound();
    }
  }
  nosound();
}

void elp(int x, int y, int mzr, int mnr, int colour)
{
  int vy, cy;
  for (float i = 0; i < mzr; i += 0.001)
  {

    vy = mnr * (sqrt(1 - ((i * i) / (mzr * mzr))));
    putpixel(x + i, y + vy, colour);
    putpixel(x + i, y - vy, colour);
    putpixel(x - i, y + vy, colour);
    putpixel(x - i, y - vy, colour);
  }
}

void flip()
{
  int a[100], x = 0, y;
  cin >> y;
  cout << "\b\b  \b\b";
  for (int i = 0; i < 650 || x == 0; i++)
    if (getpixel(i, 40) != 0)
      x = i;
  for (int j = 0; j < 550; j++)
    for (i = x; i < 650; i++)
      if (getpixel(i, j) != 0)
        putpixel(2 * x - i, j, RED);
}
int length(int x, int y, int s, int t)
{
  long int a = (x - s), b = (y - t);
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;
  a *= a;
  b *= b;
  return sqrt(a + b);
}

int takelen(int xc, int yc)
{
  char ch = '1';
  int xtemp, ytemp;
  int x = 0, y = 0, color = 0, modeky = 0;
  while (ch != '0')
  {
    ch = getch();
    if (modeky == 0)
      putpixel(x, y, color);
    if (ch == 72)
    {
      if (y != 0)
        y--;
    }
    else if (ch == 75)
    {
      if (x != 0)
        x--;
    }
    else if (ch == 77)
    {
      if (x < 640)
        x++;
    }
    else if (ch == 80)
    {
      if (y < 500)
        y++;
    }
    else if (ch == '0')
    {
      return length(xc, yc, x, y);
    }
    color = getpixel(x, y);
    putpixel(x, y, 15);
  }
  return 0;
}

void scrntofl(char nam[])
{
  ofstream fout(nam, ios::binary);
  int x, y, c;
  for (int i = 0; i < 650; i++)
    for (int j = 0; j < 500; j++)
      if (getpixel(i, j) != 0)
      {
        x = i;
        y = j;
        c = getpixel(i, j);
        fout.write((char *)&x, 4);
        fout.write((char *)&y, 4);
        fout.write((char *)&c, 4);
      }
  fout.close();
}
void fltoscrn(char nam[], int p = 0, int a = 0, int b = 0, int codekey = 1)
{
  ifstream fin(nam, ios::binary);
  int x, y, c, i = 0, k = 0;
  while (fin)
  {
    fin.read((char *)&x, 4);
    fin.read((char *)&y, 4);
    fin.read((char *)&c, 4);
    if (p != 0)
      c = p;
    if (k == 1)
    {
      i++;
      k = -1;
    }

    if (codekey == 0)
      putpixel(x + a, y + b, BLACK);
    else
    {
      c;
      putpixel(x + a, y + b, c);
    }
    k++;
  }
}

void fltoscrn2(char nam[], int x[], int y[], int c[])
{
  ifstream fin(nam, ios::binary);
  int i = 0;
  while (fin || i < 999)
  {
    fin.read((char *)&x[i], 4);
    fin.read((char *)&y[i], 4);
    fin.read((char *)&c[i], 4);
    i++;
  }
  c[i] = -1;
}

int colorpixeljump(int &i, int j, int imax = 650)
{
  int temp;
  while (getpixel(i, j) != 0 && i < imax)
    i++;
  temp = i;
  if (i == imax && getpixel(i, j) != 0)
    return 1;
  else if (i < imax)
  {
    while (temp < imax && getpixel(temp, j) == 0)
      temp++;
    if (getpixel(temp, j) != 0)
      return 1;
  }
  return 0;
}

void colorize(int code, int xmin = 1, int xmax = 650, int ymin = 1, int ymax = 500)
{
  int temp, key = 0;
  for (int j = ymin; j < ymax; j++)
    for (int i = xmin; i < xmax; i++)
    {
      if (getpixel(i, j) != 0)
      {
        temp = i;
        key = colorpixeljump(i, j, xmax);
        if (key != 0)
        {
          while (getpixel(i, j) == 0)
            i++;
          setcolor(code);
          line(temp + 1, j, i - 1, j);
        }
      }
    }
}

void pixelmove();

void drwline(int x, int y, int code)
{
  int color = '-1', l = 1, xcord[100], ycord[100], xmin = x, xmax = x, ymin = y, ymax = y;
  char ch = '1';
  for (int t = 0; t < 100; t++)
    xcord[t] = ycord[t] = 0;
  xcord[0] = x;
  ycord[0] = y;
  int key = 0;
  while (ch != '0')
  {
    ch = getch();
    if (color != -1)
      putpixel(x, y, color);
    if (ch == 72)
    {
      if (y != 0)
        y--;
    }
    else if (ch == 75)
    {
      if (x != 0)
        x--;
    }
    else if (ch == 77)
    {
      if (x < 640)
        x++;
    }
    else if (ch == '1')
      key = 1;
    else if (ch == '2')
      key = 2;
    else if (ch == 80)
    {
      if (y < 500)
        y++;
    }
    else if (ch == '#')
    {
      if (x > xmax)
        xmax = x;
      if (x < xmin)
        xmin = x;
      if (y > ymax)
        ymax = y;
      if (y < ymin)
        ymin = y;
      xcord[l] = x;
      ycord[l] = y;
      l++;
      if (key != 2)
        putpixel(x, y, 15);
    }
    color = getpixel(x, y);
    putpixel(x, y, code);
  }

  setcolor(code);

  if (key == 2)
  {
    for (int j = ymin; j < ymax; j++)
      for (int i = xmin; i < xmax; i++)
        putpixel(i, j, 0);
  }
  else
  {
    for (t = 0; xcord[t + 1] != 0; t++)
      line(xcord[t], ycord[t], xcord[t + 1], ycord[t + 1]);
    line(xcord[0], ycord[0], xcord[t], ycord[t]);
    if (key == 0)
      colorize(code, xmin, xmax, ymin, ymax);
  }
}

void squar(int s, int color, int x, int y)
{
  setcolor(color);
  line(x - s, y - s, x + s, y - s);
  line(x - s, y + s, x + s, y + s);
  line(x - s, y - s, x - s, y + s);
  line(x + s, y + s, x + s, y - s);
}

void densesquar(int s, int color, int x, int y)
{
  for (int i = 0; i <= s; i++)
    squar(i, color, x, y);
}

void pixelmove()
{
  setbkcolor(BLACK);
  char ch = '1', ch2 = 'a', a, b;
  int xtemp, ytemp, unn[5];
  float r;
  int x = 0, y = 0, color = 0, modeky = 0, code = 5, kcode;
  while (ch != '0')
  {
    if (modeky == 1)
      putpixel(x, y, 2);
    ch = getch();
    if (modeky == 0)
      putpixel(x, y, color);
    else if (modeky == 1)
      putpixel(x, y, code);

    if (ch == 72)
    {
      if (y != 0)
        y--;
    }
    else if (ch == 75)
    {
      if (x != 0)
        x--;
    }
    else if (ch == 77)
    {
      if (x < 640)
        x++;
    }
    else if (ch == 80)
    {
      if (y < 500)
        y++;
    }
    else if (ch == '*') //To shift between the painting and cursor mode.
    {
      if (modeky == 0)
        modeky = 1;
      else
      {
        modeky = 0;
        color = 0;
      }
    }
    else if (ch == '/') //To give the color code input
    {
      ch2 = getch();
      if (ch2 == '0')
        code = 0;
      else if (ch2 == 'b')
        code = 1; //BLUE
      else if (ch == 'm')
        code = 5; //Magenta
      else if (ch2 == 'c')
        code = 3; //Cyan
      else if (ch2 == 'g')
        code = 2; //Green
      else if (ch2 == 'r')
        code = 4;
      else if (ch2 == 'y')
        code = 14;         //Yellow
      else if (ch2 == 'l') //For More Color Options..
      {
        ch2 = getch();

        if (ch2 == 'g')
          code = 7; //Light Gray
        else if (ch2 == 'c')
          code = 11; //Light Cyan
        else if (ch2 == 'G')
          code = 8; //Dark Gray
        else if (ch2 == 'r')
          code = 12; //Light Red
        else if (ch2 == 'b')
          code = 9; //Light Blue
        else if (ch2 == 'B')
          code = 6; //Brown
        else
          code = 10; //Light Green
      }
      else
        code = 15; //White
    }
    else if (ch == 't') //Tells The Current Coordinates or the cursor.
    {
      cout << x << " " << y;
      getch();
      cout << "\b\b\b\b\b\b\b\b             \b\b\b\b\b\b\b\b\b\b\b\b";
    }
    else if (ch == 's')
    {
      keys = 1;
      break;
    }
    else if (ch == 'o')
    {
      keyo = 1;
      break;
    }
    else if (ch == 'f')
      flip();
    else if (ch == '|') //To Drow Line
    {
      drwline(x, y, code);
    }
    else if (ch == '\\') //To Color the bounded region on the screen.
      colorize(code);
    else if (ch == 'Q') //To Draw The Circle
    {
      xtemp = x;
      ytemp = y;
      putpixel(x, y, code);
      r = takelen(xtemp, ytemp);
      drwcir(xtemp, ytemp, r, code);
    }
    else if (ch == '!') //To Draw A dark square can be use as eraser
    {
      xtemp = x;
      ytemp = y;
      putpixel(x, y, code);
      r = takelen(xtemp, ytemp);
      densesquar(r, 0, xtemp, ytemp);
    }
    if (modeky == 1)
      putpixel(x, y, code);
    else
    {
      color = getpixel(x, y);
      putpixel(x, y, 15);
    }
    if (ch == '0')
      keyg = -1;
  }
  putpixel(x, y, 0);
}

void snd(int freq, int len, int t)
{
  for (int i = 0; i < len; i++)
  {
    sound(freq + i * 50);
    delay(t / len);
  }
  nosound();
}

void print()
{

  fltoscrn("ogofn.dat", 0, 250, 60);
  setcolor(9);
  for (int u = 0; u < 30; u++)
    line(245, 340 + u, 445, 340 + u);
  setcolor(CYAN);
  for (u = 0; u < 30; u++)
    line(240, 335 + u, 440, 335 + u);
}

void inputchk2(char a[])
{
  print();
  vibo("PASSWORD", LIGHTCYAN);
  vibo("        ", LIGHTCYAN);
  print();
  int key = 0, l = 0;
  while (key != 1)
  {
    while (!kbhit())
      ;
    char ch, b[20];
    int x = 0;
    while (ch != 13)
    {
      if (x < 20)
      {
        ch = getch();
        if (ch != 13)
        {
          b[x] = ch;
          for (int ij = 0; ij < 5; ij++)
            drwcir(250 + l, 350, ij, 12);
          snd(50, 5, 100);
          l += 10;
        }
      }
      x++;
    }
    if (stricmp(b, a) == 0)
      key = 1;

    else
    {
      sound(1500);
      delay(500);
      nosound();
      vibo("INCORRECT", RED);
      delay(2000);
      cclrscr();
      print();
      key = 0;
    }
    x = 0;
    ch = 'a';
    l = 0;
  }
}
void passwordchk(int a[])
{
  char ch[20] = "I'm The Entangler";
  inputchk2(ch);
  cout << a[0] << "\b\b\b   \b\b\b";
}

void vibo(char ch[], int x)
{
  for (int j = 0; j < 20; j++)
  {
    color(x, ch, 290, 335);
    delay(10);
    color(3, ch, 290, 335);
    color(x, ch, 292, 335);
    delay(10);
    color(3, ch, 292, 335);
    color(x, ch, 292, 335);
    if (j == 10)
      delay(1000);
  }
}

void drwcir1(int x, int y, int r, int code)
{
  for (int i = 1; i <= r; i++)
    drwcir2(x, y, i, code);
}
void rot()
{
  setcolor(CYAN);
  int r = 5, x = 300, y = 400, code = CYAN, t = 80;
  int xc[] = {0, 4, 9, 11, 13}, yc[] = {0, 3, 6, 9, 17};
  for (int i = 0; i < 5; i++)
  {
    for (int i1 = 0; i1 < 5; i1++)
    {
      drwcir1(x + xc[i1], y + yc[i1], r, code);
      delay(t);
      drwcir1(x + xc[i1], y + yc[i1], r, fcode);
    }
    for (i1 = 4; i1 >= 0; i1--)
    {
      drwcir1(x + xc[i1], y + 2 * yc[4] - yc[i1], r, code);
      delay(t);
      drwcir1(x + xc[i1], y + 2 * yc[4] - yc[i1], r, fcode);
    }
    for (i1 = 0; i1 < 5; i1++)
    {
      drwcir1(x - xc[i1], y + 2 * yc[4] - yc[i1], r, code);
      delay(t);
      drwcir1(x - xc[i1], y + 2 * yc[4] - yc[i1], r, fcode);
    }
    for (i1 = 4; i1 >= 0; i1--)
    {
      drwcir1(x - xc[i1], y + yc[i1], r, code);
      delay(t);
      drwcir1(x - xc[i1], y + yc[i1], r, fcode);
    }
  }
}
void start()
{
  setbkcolor(BLUE);
  int a[20] = {68, 34, 104, 27, 79, 99, 96, 27, 64, 105, 111, 92, 105, 98, 103, 96, 109};
  setcolor(RED);
  settextstyle(1, 0, 9);
  outtextxy(170, 140, "NTANGLER");
  rot();
  cclrscr();
  neutralize();
  passwordchk(a);
  print();
  for (int i = 0; i < 10; i++)
  {
    sound(i * 100 + 500);
    delay(50);
  }
  nosound();
  vibo("MATCHED", 1);
  delay(1000);
  cclrscr();
}

int pixeldetect(int x[], int y[], int c[], int a = 0, int b = 0)
{
  for (int i = 0; c[i] != 0; i++)
    if (getpixel(x[i] + a, y[i] + b) != fcode)
      return getpixel(x[i] + a, y[i] + b);
  return 100;
}

int cp = 0;

void snake()
{
  neutralize();
  int x[50] = {30, 40, 50, 60}, y[50] = {50, 50, 50, 50}, n = 4, colkey = -1, cxt = 0, cyt = 0, key = -1, akey = 1, okey = 1;
  int t = 5, o = 0;
  randomize();
  char ch = 77, chtmp = 77;
  drwc(x[0], y[0], t, GREEN, 0.5);
  drwc(x[1], y[0], t, GREEN, 0.5);
  drwc(x[2], y[0], t, GREEN, 0.5);
  drwc(x[3], y[0], t, BROWN, 0.5);
  getch();
  setcolor(GREEN);
  line(0, 0, 635, 0);
  line(0, 0, 0, 749);
  line(0, 479, 635, 479);
  line(635, 0, 635, 479);
  while (ch != '0')
  {

    if (okey == 1)
    {
      if (cxt != 0)
        drwc(cxt, cyt, 5, BLACK, 0.2);
      cxt = ((random(50) + random(50) + random(26)) * 5 + 15);
      cyt = ((random(4) + random(20) + random(random(20)) + random(50)) * 5 + 15);
    }
    if (okey == 1 && drwcg(cxt, cyt, t) == 0)
    {
      drwc(cxt, cyt, t, LIGHTMAGENTA, 0.2);
      okey = 0;
      colkey = -1;
      key = -1;
      o += 2;
    }
    colkey = -1;
    if (o > 29)
      delay(89 - o);
    else
      delay(60);
    if (kbhit())
      ch = getch();
    if (ch == '0')
      break;
    if (akey == 1)
    {
      drwc(x[0], y[0], t, BLACK, 0.1);
      for (int i = 0; i < n - 1; i++)
      {
        x[i] = x[i + 1];
        y[i] = y[i + 1];
      }
    }
    if (ch == 77 && chtmp != 75)
    {
      akey = 1;
      x[n - 1] += 2 * 5;
      chtmp = ch;
    }
    else if (ch == 75 && chtmp != 77)
    {
      akey = 1;
      x[n - 1] -= 2 * 5;
      chtmp = ch;
    }
    else if (ch == 72 && chtmp != 80)
    {
      akey = 1;
      y[n - 1] -= 2 * 5;
      chtmp = ch;
    }
    else if (ch == 80 && chtmp != 72)
    {
      akey = 1;
      y[n - 1] += 2 * 5;
      chtmp = ch;
    }
    else if (ch != '0')
      ch = chtmp;
    colkey = drwcg(x[n - 1], y[n - 1]);
    if (colkey == RED || colkey == GREEN)
      key = 0;
    if (colkey == LIGHTMAGENTA)
    {
      key = okey = 1;
      colkey = -1;
      drwc(cxt, cyt, 5, BLACK, 0.2);
    }
    if (key == 0)
    {
      cleardevice();
      outtextxy(50, 100, "Ops! You Collided");
      delay(1000);
      cleardevice();
      ch = '0';
    }
    else if (key == 1)
    {
      n++;
      x[n - 1] = x[n - 2];
      y[n - 1] = y[n - 2];
      akey = 0;
    }
    else if (key != 1)
    {
      drwc(x[n - 2], y[n - 2], t, GREEN, 0.5);
      drwc(x[n - 1], y[n - 1], t, BROWN, 0.5);
    }
  }
}

void main()
{
  neutralize();
  fcode = 0;
  clrscr();
  char ch = 77;
  randomize();
  int x[5] = {50, 150, 250, 350, 450}, i = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, temp[5], r[5], sp = 10, codetmp;
  int xcord[500], ycord[500], code[500], frkey[5], frcd[5] = {365, 365, 365, 365, 365}, scr = 0, key, hel = 5, scrkey = 10;
  long int exkey = 0;
  float w = 2;
  int menuch = -4, menutmp = 0, mnkey = 0, pss = 0;
  char menuin;
  char nam[30], tmpap;
  int a, b;
  int driver = DETECT, mode;
  initgraph(&driver, &mode, "c:\\tc\\bgi");
  setbkcolor(3);
  fltoscrn("strt.dat");
  int xt, yt, tt;
  ifstream fin("strt2.dat", ios::binary);
  while (fin)
  {
    fin.read((char *)&xt, sizeof(xt));
    fin.read((char *)&yt, sizeof(xt));
    fin.read((char *)&tt, sizeof(xt));
    putpixel(xt, yt, tt);
    delay(2);
  }
  fin.close();
  getch();
  fin.open("strt2.dat", ios::binary);
  while (fin)
  {
    fin.read((char *)&xt, sizeof(xt));
    fin.read((char *)&yt, sizeof(xt));
    fin.read((char *)&tt, sizeof(xt));
    putpixel(xt, yt, 0);
    delay(1);
  }
  cleardevice();
  setbkcolor(fcode);
  fltoscrn("ogofn.dat", 0, 10, 60);
  start();
  int txtc = 14, txt2 = 12;
  do
  {
    if (mnkey == 0)
    {
      cleardevice();
      setbkcolor(fcode + 1);
      for (int u = 160; u < 400; u++)
        for (int uv = 35; uv < 180; uv++)
        {
          putpixel(u, uv, CYAN);
          if (u == 160 || u == 399 || uv == 35 || uv == 179)
            putpixel(u, uv, MAGENTA);
        }

      color(MAGENTA, "MENU", 250, 10);
      color(txtc, "1). 3D CUBE", 200, 40);
      color(txtc, "2). Galaxy Run", 200, 60);
      color(txtc, "3). Caterpillar Run", 200, 80);
      color(txtc, "4). Painting", 200, 100);
      color(txtc, "5). Settings", 200, 120);
      color(txtc, "6). Earth", 200, 140);
      color(txtc, "EXIT", 200, 200);
      mnkey = 1;
    }
    menuin = getch();
    if (menuin == 80)
    {
      if (menutmp < 7)
        menutmp++;
    }
    else if (menuin == 72)
    {
      if (menutmp > 1)
        menutmp--;
    }
    else if (menuin == 13)
    {
      menuch = menutmp;
      mnkey = 0;
      menuin = '0';
    }
    switch (menutmp)
    {
    case 1:
      color(txt2, "1). 3D CUBE", 200, 40);
      color(txtc, "2). Galaxy Run", 200, 60);
      break;
    case 2:
      color(txt2, "2). Galaxy Run", 200, 60);
      color(txtc, "1). 3D CUBE", 200, 40);
      color(txtc, "3). Caterpillar Run", 200, 80);
      break;
    case 3:
      color(txtc, "2). Galaxy Run", 200, 60);
      color(txt2, "3). Caterpillar Run", 200, 80);
      color(txtc, "4). Painting", 200, 100);
      break;
    case 4:
      color(txt2, "4). Painting", 200, 100);
      color(txtc, "3). Caterpillar Run", 200, 80);
      color(txtc, "5). Settings", 200, 120);
      break;
    case 7:
      color(RED, "EXIT", 200, 200);
      color(txtc, "6). Earth", 200, 140);
      break;
    case 5:
      color(txtc, "6). Earth", 200, 140);
      color(txt2, "5). Settings", 200, 120);
      color(txtc, "4). Painting", 200, 100);
      break;
    case 6:
      color(txtc, "EXIT", 200, 200);
      color(txt2, "6). Earth", 200, 140);
      color(txtc, "5). Settings", 200, 120);
      break;
    }
    snd(1350, 5, 50);
    if (menuch == 7)
      break;
    else if (menuch == 1)
    {
      menutmp = 0;
      menuch = -4;
      cleardevice();
      cubereal();
    }
    else if (menuch == 2)
    {
      menutmp = 0;
      menuch = -4;
      cleardevice();
      pss = 1;
      codetmp = fcode;
      fcode = 0;
      setbkcolor(0);
    }
    else if (menuch == 6)
    {
      menutmp = 0;
      menuch = -4;
      cleardevice();
      earth();
    }
    else if (menuch == 3)
    {
      menutmp = 0;
      menuch = -4;
      cleardevice();
      setbkcolor(BLACK);
      outtextxy(10, 10, "Do you want to switch to HIGH DIFFICULTY MODE(Enter Y for yes) :");
      tmpap = getch();
      cleardevice();
      if (tmpap == 'Y' || tmpap == 'y')
        fltoscrn("mazemap.dat");
      snake();
    }
    else if (menuch == 4)
    {
      menutmp = 0;
      menuch = -4;
      cleardevice();
      gotoxy(1, 1);
      fltoscrn("help.dat");
      getch();
      while (keyg != -1)
      {
        cleardevice();
        pixelmove();
        if (keyo == 1)
        {
          keyo = 0;
          scrntofl("tmp.dat");
          gotoxy(1, 1);
          cout << "Enter the name of the file: ";
          gets(nam);
          cout << "Enter x :";
          cin >> a;
          cout << "Enter y : ";
          cin >> b;
          cleardevice();
          fltoscrn("tmp.dat");
          fltoscrn(nam, 0, a, b);
          pixelmove();
        }
        if (keys == 1)
        {
          keys = 0;
          scrntofl("tmp.dat");
          gotoxy(1, 1);
          cout << "Enter the name of the file : ";
          gets(nam);
          rename("tmp.dat", nam);
          cleardevice();
          fltoscrn(nam);
          pixelmove();
        }
      }
      keyg = 0;
    }
    else if (menuch == 5)
    {
      menutmp = 0;
      menuch = -4;
      gotoxy(1, 1);
      cleardevice();
      cout << "Enter the fcode : ";
      cin >> fcode;
      setbkcolor(fcode);
    }
    if (menuch != 0)
      menuch = 0;
    if (pss == 1)
    {
      setbkcolor(BLACK);
      fltoscrn("galogo.dat");
      scr = 1;
      while (!kbhit())
      {
        fltoscrn("press.dat");
      }
      cleardevice();
      setbkcolor(BLACK);
      fltoscrn2("stone.dat", xcord, ycord, code);
      fltoscrn("health.dat", 0, 0, 0, 5);
      do
      {
        hel = 5;
        while (ch != '0')
        {
          if (kbhit())
            ch = getch();
          else
            ch = '1';
          if (ch == 75)
          {
            if (cp != 0)
            {
              fltoscrn("shipfn.dat", 0, x[cp], 340, 0);
              cp--;
              fltoscrn("shipfn.dat", 0, x[cp], 340);
            }
          }
          else if (ch == 77)
          {
            if (cp != 4)
            {
              fltoscrn("shipfn.dat", 0, x[cp], 340, 0);
              cp++;
              fltoscrn("shipfn.dat", 0, x[cp], 340);
            }
          }
          else if (ch == 32)
          {
            frkey[cp] = 1;
            snd(2000, 5, 50);
          }
          fltoscrn("shipcab.dat", random(16), x[cp], 340);
          if (i == 0)
            for (int un = 0; un < 5; un++)
              r[un] = random(9);
          if (i % sp == 0)
          {
            if (c1 == 0)
            {
              temp[0] = random(r[0]) * 100;
            }
            if (c2 == 0)
            {
              temp[1] = random(r[1]) * 1000;
            }
            if (c3 == 0)
            {
              temp[3] = random(r[2]) * 5000;
            }
            if (c4 == 0)
            {
              temp[3] = 0;
            }
            if (c5 == 0)
            {
              temp[4] = random(r[4]) * 500;
            }

            if (i > temp[0])
            {
              fltoscrn("stone.dat", 0, 93, c1, 0);
              c1 += w;
              key = pixeldetect(xcord, ycord, code, 93, c1);
              if (key != 100)
                snd(100, 10, 50);
              if (key == 100)
                fltoscrn("stone.dat", 0, 93, c1);
              else if (key == 3)
              {
                c1 = 0;
                scr += scrkey;
                cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
                frkey[0] = 0;
                fltoscrn("laser.dat", 0, 112, frcd[0], 0);
                frcd[0] = 365;
              }
              else if (key == 14)
              {
                fltoscrn("stone.dat", 0, 93, c1, 0);
                c1 = 0;
                scr += scrkey;
                cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
                if (hel == 5)
                {
                  fltoscrn("h1.dat", 0, 0, 0, 0);
                }
                else if (hel == 4)
                {
                  fltoscrn("h2.dat", 0, 0, 0, 0);
                }
                else if (hel == 3)
                  fltoscrn("h3.dat", 0, 0, 0, 0);
                else if (hel == 2)
                  fltoscrn("h4.dat", 0, 0, 0, 0);
                else
                  ch = '0';
                hel--;
              }
            }
            if (i > temp[1])
            {
              fltoscrn("stone.dat", 0, 193, c2, 0);
              c2 += w;
              key = pixeldetect(xcord, ycord, code, 193, c2);
              if (key != 100)
                snd(100, 10, 50);
              if (key == 100)
                fltoscrn("stone.dat", 0, 193, c2);
              else if (key == 3)
              {
                c2 = 0;
                scr += scrkey;
                cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
                frkey[1] = 0;
                fltoscrn("laser.dat", 0, 212, frcd[1], 0);
                frcd[1] = 365;
              }
              else
              {
                fltoscrn("stone.dat", 0, 193, c2, 0);
                c2 = 0;
                scr += scrkey;
                cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
                if (hel == 5)
                  fltoscrn("h1.dat", 0, 0, 0, 0);
                else if (hel == 4)
                  fltoscrn("h2.dat", 0, 0, 0, 0);
                else if (hel == 3)
                  fltoscrn("h3.dat", 0, 0, 0, 0);
                else if (hel == 2)
                  fltoscrn("h4.dat", 0, 0, 0, 0);
                else
                  ch = '0';
                hel--;
              }
            }
            fltoscrn("stone.dat", 0, 293, c3, 0);
            c3 += w;
            key = pixeldetect(xcord, ycord, code, 293, c3);
            if (key != 100)
              snd(100, 10, 50);
            if (key == 100)
              fltoscrn("stone.dat", 0, 293, c3);
            else if (key == 3)
            {
              c3 = 0;
              scr += scrkey;
              cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
              frkey[2] = 0;
              fltoscrn("laser.dat", 0, 312, frcd[2], 0);
              frcd[2] = 365;
            }
            else
            {
              fltoscrn("stone.dat", 0, 293, c3, 0);
              c3 = 0;
              scr += scrkey;
              cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
              if (hel == 5)
                fltoscrn("h1.dat", 0, 0, 0, 0);
              else if (hel == 4)
                fltoscrn("h2.dat", 0, 0, 0, 0);
              else if (hel == 3)
                fltoscrn("h3.dat", 0, 0, 0, 0);
              else if (hel == 2)
                fltoscrn("h4.dat", 0, 0, 0, 0);
              else
                ch = '0';
              hel--;
            }
            fltoscrn("stone.dat", 0, 393, c4, 0);
            c4 += w;
            key = pixeldetect(xcord, ycord, code, 393, c4);
            if (key != 100)
              snd(100, 10, 50);
            if (key == 100)
              fltoscrn("stone.dat", 0, 393, c4);
            else if (key == 3)
            {
              c4 = 0;
              scr += scrkey;
              cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
              frkey[3] = 0;
              fltoscrn("laser.dat", 0, 412, frcd[3], 0);
              frcd[3] = 365;
            }
            else
            {
              fltoscrn("stone.dat", 0, 393, c4, 0);
              c4 = 0;
              scr += scrkey;
              cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
              if (hel == 5)
                fltoscrn("h1.dat", 0, 0, 0, 0);
              else if (hel == 4)
                fltoscrn("h2.dat", 0, 0, 0, 0);
              else if (hel == 3)
                fltoscrn("h3.dat", 0, 0, 0, 0);
              else if (hel == 2)
                fltoscrn("h4.dat", 0, 0, 0, 0);
              else
                ch = '0';
              hel--;
            }
            if (i > temp[4])
            {
              fltoscrn("stone.dat", 0, 493, c5, 0);
              c5 += w;
              key = pixeldetect(xcord, ycord, code, 493, c5);
              if (key != 100)
                snd(100, 10, 50);
              if (key == 100)
                fltoscrn("stone.dat", 0, 493, c5);
              else if (key == 3)
              {
                c5 = 0;
                scr += scrkey;
                cout << "\b\b\b\b\b\b\b\b\b\b" << scr;
                frkey[4] = 0;
                fltoscrn("laser.dat", 0, 512, frcd[4], 0);
                frcd[4] = 365;
              }
              else
              {
                fltoscrn("stone.dat", 0, 493, c5, 0);
                c5 = 0;
                scr += scrkey;
                gotoxy(1, 1);
                cout << scr;
                if (hel == 5)
                  fltoscrn("h1.dat", 0, 0, 0, 0);
                else if (hel == 4)
                  fltoscrn("h2.dat", 0, 0, 0, 0);
                else if (hel == 3)
                  fltoscrn("h3.dat", 0, 0, 0, 0);
                else if (hel == 2)
                  fltoscrn("h4.dat", 0, 0, 0, 0);
                else
                  ch = '0';
                hel--;
              }
            }
            if (c1 > 500)
            {
              c1 = 0;
              if (hel == 5)
                fltoscrn("h1.dat", 0, 0, 0, 0);
              else if (hel == 4)
                fltoscrn("h2.dat", 0, 0, 0, 0);
              else if (hel == 3)
                fltoscrn("h3.dat", 0, 0, 0, 0);
              else if (hel == 2)
                fltoscrn("h4.dat", 0, 0, 0, 0);
              else
                ch = '0';
              hel--;
            }
            if (c2 > 500)
            {
              c2 = 0;
              if (hel == 5)
                fltoscrn("h1.dat", 0, 0, 0, 0);
              else if (hel == 4)
                fltoscrn("h2.dat", 0, 0, 0, 0);
              else if (hel == 3)
                fltoscrn("h3.dat", 0, 0, 0, 0);
              else if (hel == 2)
                fltoscrn("h4.dat", 0, 0, 0, 0);
              else
                ch = '0';
              hel--;
            }
            if (c3 > 500)
            {
              c3 = 0;
              if (hel == 5)
                fltoscrn("h1.dat", 0, 0, 0, 0);
              else if (hel == 4)
                fltoscrn("h2.dat", 0, 0, 0, 0);
              else if (hel == 3)
                fltoscrn("h3.dat", 0, 0, 0, 0);
              else if (hel == 2)
                fltoscrn("h4.dat", 0, 0, 0, 0);
              else
                ch = '0';
              hel--;
            }
            if (c4 > 500)
            {
              c4 = 0;
              if (hel == 5)
                fltoscrn("h1.dat", 0, 0, 0, 0);
              else if (hel == 4)
                fltoscrn("h2.dat", 0, 0, 0, 0);
              else if (hel == 3)
                fltoscrn("h3.dat", 0, 0, 0, 0);
              else if (hel == 2)
                fltoscrn("h4.dat", 0, 0, 0, 0);
              else
                ch = '0';
              hel--;
            }
            if (c5 > 500)
            {
              c5 = 0;
              if (hel == 5)
                fltoscrn("h1.dat", 0, 0, 0, 0);
              else if (hel == 4)
                fltoscrn("h2.dat", 0, 0, 0, 0);
              else if (hel == 3)
                fltoscrn("h3.dat", 0, 0, 0, 0);
              else if (hel == 2)
                fltoscrn("h4.dat", 0, 0, 0, 0);
              else
                ch = '0';
              hel--;
            }
            if (i > 1000)
              ;
            i = 0;
            if (frkey[0] == 1)
            {
              if (frcd[0] > 0)
              {
                fltoscrn("laser.dat", 0, 112, frcd[0], 0);
                frcd[0] -= 10;
                fltoscrn("laser.dat", 0, 112, frcd[0]);
              }
              else
              {
                fltoscrn("laser.dat", 0, 112, frcd[0], 0);
                frkey[0] = 0;
                frcd[0] = 365;
              }
            }
            if (frkey[1] == 1)
            {
              if (frcd[1] > 0)
              {
                fltoscrn("laser.dat", 0, 212, frcd[1], 0);
                frcd[1] -= 10;
                fltoscrn("laser.dat", 0, 212, frcd[1]);
              }
              else
              {
                fltoscrn("laser.dat", 0, 212, frcd[1], 0);
                frkey[1] = 0;
                frcd[1] = 365;
              }
            }
            if (frkey[2] == 1)
            {
              if (frcd[2] > 0)
              {
                fltoscrn("laser.dat", 0, 312, frcd[2], 0);
                frcd[2] -= 10;
                fltoscrn("laser.dat", 0, 312, frcd[2]);
              }
              else
              {
                fltoscrn("laser.dat", 0, 312, frcd[2], 0);
                frkey[2] = 0;
                frcd[2] = 365;
              }
            }
            if (frkey[3] == 1)
            {
              if (frcd[3] > 0)
              {
                fltoscrn("laser.dat", 0, 412, frcd[3], 0);
                frcd[3] -= 10;
                fltoscrn("laser.dat", 0, 412, frcd[3]);
              }
              else
              {
                fltoscrn("laser.dat", 0, 412, frcd[3], 0);
                frkey[3] = 0;
                frcd[3] = 365;
              }
            }

            if (frkey[4] == 1)
            {
              if (frcd[4] > 0)
              {
                fltoscrn("laser.dat", 0, 512, frcd[4], 0);
                frcd[4] -= 10;
                fltoscrn("laser.dat", 0, 512, frcd[4]);
              }
              else
              {
                fltoscrn("laser.dat", 0, 512, frcd[4], 0);
                frkey[4] = 0;
                frcd[4] = 365;
              }
            }
          }
          i++;
          exkey++;
          if (exkey > 100000000)
            exkey = 0;
          if (exkey % 5000 == 0)
            scrkey += 50;
          w += 0.0001;
        }
        fltoscrn("retry.dat");
        ch = getch();
        fltoscrn("retry.dat", 0, 0, 0, 0);
        cleardevice();
        scr = 0;
        scrkey = 10;
        i = c1 = c2 = c3 = c4 = c5 = exkey = 0;
        w = 2;
        sp = 10;
        frcd[0] = frcd[1] = frcd[2] = frcd[3] = frcd[4] = 365;
        hel = 5;
        cout << "\b\b\b\b\b\b              \b\b\b\b\b\b\b\b";
        fltoscrn("health.dat");
      } while (ch != '0');
      pss = 0;
      fcode = codetmp;
    }
  } while (menuch != 7);
  cleardevice();
  setbkcolor(BLACK);
  while (!kbhit())
  {
    tt = random(16);
    fin.close();
    fin.open("strt2.dat", ios::binary);
    while (fin)
    {
      fin.read((char *)&xt, sizeof(xt));
      fin.read((char *)&yt, sizeof(xt));
      fin.read((char *)&x, sizeof(xt));
      putpixel(xt, yt, tt);
      delay(1);
    }
  }
  closegraph();
  clrscr();
  cout << 
  "Now Press ctrl+F9 to close.";
}