.#include <Keyboard.h> // Keyboard library
#include <Mouse.h>    // Mouse library


void keyboardPrint(String  a);
void keyboardPrintln(String  a);
void keyboardPressRelease(String a, String t, String b);
void keyboardReleaseAll();
void keyboardRelease(String a, String b);
void keyboardPress(String a, String b);
void mouseReleaseAll();
void mousePressRelease(String a, String t);
void mouseRelease(String a);
void mousePress(String a);
void mouseClick(String a);
void mouseMove(String x,String y,String w);

void keyboardWrite(String a, String b);
void setup(){
  Serial.begin(9600);
  Keyboard.begin();
  Mouse.begin();
}
String str = "";
int flag = 0;


void loop()
{
  if(Serial.available()){
    char read = Serial.read();
    if(read == '%'){
      str = "";
      flag = 0;
    }else if ( read == '?'){
      Serial.println("");
      flag = 1;
    }else {
      str = str + read;
    }
    
    if(flag == 1){
      Serial.println(str);
      Serial.println(str.indexOf('('));
      Serial.println(str.indexOf(')'));
      String fuc = str.substring(0,str.indexOf('('));
      Serial.println(fuc);
      String element = str.substring(str.indexOf('(')+1,str.indexOf(')'));
      Serial.println(element);
      
      
      int first = element.indexOf(','); 
      int second = element.indexOf(',',first+1);
      int len = element.length();
      Serial.println("====");
      Serial.println(first);
      Serial.println(second);
      Serial.println(len);
      Serial.println("====");
      
      char* a;
      char* b;
      char* c;
      String strA;
      String strB;
      String strC;
      
      
      if(first == -1){
        char tempA[element.length()];
        element.toCharArray(tempA,element.length()+1);
        a = tempA;
      }
      if(second == -1){
        strA = element.substring(0,first);
        char tempA[strA.length()];
        strA.toCharArray(tempA,strA.length()+1);
        strB = element.substring(first+1,len);
        char tempB[strB.length()];
        strB.toCharArray(tempB,strB.length()+1);
        a = tempA;
        b = tempB;
      }else{
        strA = element.substring(0,first);
        char tempA[strA.length()];
        strA.toCharArray(tempA,strA.length()+1);
        strB = element.substring(first+1,second);
        char tempB[strB.length()];
        strB.toCharArray(tempB,strB.length()+1);
        strC = element.substring(second+1,len);
        char tempC[strC.length()];
        strC.toCharArray(tempC,strC.length()+1);
      }
      Serial.println(strA);
      Serial.println(strB);
      Serial.println(strC);

      
      if(fuc.equals("KP")){
        Serial.println("keyboardPrint");
        keyboardPrint(strA);
      }else if(fuc.equals("KPL")){
        keyboardPrintln(strA);
      }if(fuc.equals("KPR")){
        keyboardPressRelease(strA,strB,strC);
      }if(fuc.equals("KRA")){
        keyboardReleaseAll();
      }if(fuc.equals("KR")){
        keyboardRelease(strA,strB);
      }if(fuc.equals("KPr")){
        keyboardPress(strA,strB);
      }if(fuc.equals("MRA")){
        mouseReleaseAll();
      }if(fuc.equals("MPR")){
        mousePressRelease(strA,strB);
      }if(fuc.equals("MR")){
        //mouseRelease(strA);
      }if(fuc.equals("MP")){
        mousePress(strA);
      }if(fuc.equals("MC")){
        mouseClick(strA);
      }if(fuc.equals("KW")){
        keyboardWrite(strA,strB);
      }if(fuc.equals("MM")){
        mouseMove(strA,strB,strC);
      }
      flag = 0;
      str = "";
    } 
  }
}


void mouseClick(String a){
  int ta = a.toInt();
  switch (ta){
      case 0: // 마우스 왼쪽클릭
        Mouse.click(MOUSE_LEFT);
        break;
      case 1: // 마우스 오른쪽클릭
        Mouse.click(MOUSE_RIGHT);
        break;
      case 2: // 마우스 휠 클릭
        Mouse.click(MOUSE_MIDDLE); 
        break;
  }
}
//마우스 움직임
void mousePress(String a){
  int ta = a.toInt();
  switch (ta){
      case 0: // 마우스 왼쪽 누르고있기
        Mouse.press(MOUSE_LEFT);
        break;
      case 1: // 마우스 오른쪽 누르고있기
        Mouse.press(MOUSE_RIGHT);
        break;
      case 2: // 마우스 휠 누르고있기
        Mouse.press(MOUSE_MIDDLE); 
        break;
  }
}

void mouseRelease(String a){
  int ta = a.toInt();
  switch (ta){
      case 0: // 마우스 왼쪽 떼기
        Mouse.release(MOUSE_LEFT);
        break;
      case 1: // 마우스 오른쪽 떼기
        Mouse.release(MOUSE_RIGHT);
        break;
      case 2: // 마우스 휠 떼기
        Mouse.release(MOUSE_MIDDLE); 
        break;
  }
}

void mouseMove(String x, String y, String w){
      int tx = x.toInt();
      int ty = y.toInt();
      int tw = w.toInt();
      Mouse.move(tx,ty,tw);
}

void mousePressRelease(String a, String t){
    int ta = a.toInt();
    int tt = t.toInt();
    switch (ta){
      case 0: // 마우스 왼쪽 누르고있기
        Mouse.press(MOUSE_LEFT);
        delay(tt);
        Mouse.release(MOUSE_LEFT);
        break;
      case 1: // 마우스 오른쪽 누르고있기
        Mouse.press(MOUSE_RIGHT);
        delay(tt);
        Mouse.release(MOUSE_RIGHT);
        break;
      case 2: // 마우스 휠 누르고있기
        Mouse.press(MOUSE_MIDDLE); 
        delay(tt);
        Mouse.release(MOUSE_MIDDLE); 
        break;
  }
}
//마우스 클릭 모두 떼기
void mouseReleaseAll(){
   Mouse.release(MOUSE_LEFT);
   Mouse.release(MOUSE_RIGHT);
   Mouse.release(MOUSE_MIDDLE); 
}

//키보드 a 누르고 있기
void keyboardPress(String a, String b){
  char ta = a.charAt(0);
  int tb = b.toInt();
  if(tb == 0){
    Keyboard.press(ta);
  }else{
    switch (tb){
      case 1:
      Keyboard.press(KEY_LEFT_CTRL);
      break;
      case 2:
      Keyboard.press(KEY_LEFT_SHIFT);
      break;
      case 3:
      Keyboard.press(KEY_LEFT_ALT);
      break;
      case 4:
      Keyboard.press(KEY_LEFT_GUI);
      break;
      case 5:
      Keyboard.press(KEY_RIGHT_CTRL);
      break;
      case 6:
      Keyboard.press(KEY_RIGHT_SHIFT);
      break;
      case 7:
      Keyboard.press(KEY_RIGHT_ALT);
      break;
      case 8:
      Keyboard.press(KEY_RIGHT_GUI);
      break;
      case 9:
      Keyboard.press(KEY_UP_ARROW);
      break;
      case 10:
      Keyboard.press(KEY_DOWN_ARROW);
      break;
      case 11:
      Keyboard.press(KEY_LEFT_ARROW);
      break;
      case 12:
      Keyboard.press(KEY_RIGHT_ARROW);
      break;
      case 13:
      Keyboard.press(KEY_BACKSPACE);
      break;
      case 14:
      Keyboard.press(KEY_TAB);
      break;
      case 15:
      Keyboard.press(KEY_RETURN);
      break;
      case 16:
      Keyboard.press(KEY_ESC);
      break;
      case 17:
      Keyboard.press(KEY_INSERT);
      break;
      case 18:
      Keyboard.press(KEY_DELETE);
      break;
      case 19:
      Keyboard.press(KEY_PAGE_UP);
      break;
      case 20:
      Keyboard.press(KEY_PAGE_DOWN);
      break;
      case 21:
      Keyboard.press(KEY_HOME);
      break;
      case 22:
      Keyboard.press(KEY_END);
      break;
      case 23:
      Keyboard.press(KEY_CAPS_LOCK);
      break;
      case 24:
      Keyboard.press(KEY_F1);
      break;
      case 25:
      Keyboard.press(KEY_F2);
      break;
      case 26:
      Keyboard.press(KEY_F3);
      break;
      case 27:
      Keyboard.press(KEY_F4);
      break;
      case 28:
      Keyboard.press(KEY_F5);
      break;
      case 29:
      Keyboard.press(KEY_F6);
      break;
      case 30:
      Keyboard.press(KEY_F7);
      break;
      case 31:
      Keyboard.press(KEY_F8);
      break;
      case 32:
      Keyboard.press(KEY_F9);
      break;
      case 33:
      Keyboard.press(KEY_F10);
      break;
      case 34:
      Keyboard.press(KEY_F11);
      break;
      case 35:
      Keyboard.press(KEY_F12);
      break;
    }
  }
   
}
//키보드 a 떼기
void keyboardRelease(String a, String b){
  char ta = a.charAt(0);
  int tb = b.toInt();
  if(tb == 0){
    Keyboard.release(ta);
  }else{
    switch(tb){
      case 1:
      Keyboard.release(KEY_LEFT_CTRL);
      break;
      case 2:
      Keyboard.release(KEY_LEFT_SHIFT);
      break;
      case 3:
      Keyboard.release(KEY_LEFT_ALT);
      break;
      case 4:
      Keyboard.release(KEY_LEFT_GUI);
      break;
      case 5:
      Keyboard.release(KEY_RIGHT_CTRL);
      break;
      case 6:
      Keyboard.release(KEY_RIGHT_SHIFT);
      break;
      case 7:
      Keyboard.release(KEY_RIGHT_ALT);
      break;
      case 8:
      Keyboard.release(KEY_RIGHT_GUI);
      break;
      case 9:
      Keyboard.release(KEY_UP_ARROW);
      break;
      case 10:
      Keyboard.release(KEY_DOWN_ARROW);
      break;
      case 11:
      Keyboard.release(KEY_LEFT_ARROW);
      break;
      case 12:
      Keyboard.release(KEY_RIGHT_ARROW);
      break;
      case 13:
      Keyboard.release(KEY_BACKSPACE);
      break;
      case 14:
      Keyboard.release(KEY_TAB);
      break;
      case 15:
      Keyboard.release(KEY_RETURN);
      break;
      case 16:
      Keyboard.release(KEY_ESC);
      break;
      case 17:
      Keyboard.release(KEY_INSERT);
      break;
      case 18:
      Keyboard.release(KEY_DELETE);
      break;
      case 19:
      Keyboard.release(KEY_PAGE_UP);
      break;
      case 20:
      Keyboard.release(KEY_PAGE_DOWN);
      break;
      case 21:
      Keyboard.release(KEY_HOME);
      break;
      case 22:
      Keyboard.release(KEY_END);
      break;
      case 23:
      Keyboard.release(KEY_CAPS_LOCK);
      break;
      case 24:
      Keyboard.release(KEY_F1);
      break;
      case 25:
      Keyboard.release(KEY_F2);
      break;
      case 26:
      Keyboard.release(KEY_F3);
      break;
      case 27:
      Keyboard.release(KEY_F4);
      break;
      case 28:
      Keyboard.release(KEY_F5);
      break;
      case 29:
      Keyboard.release(KEY_F6);
      break;
      case 30:
      Keyboard.release(KEY_F7);
      break;
      case 31:
      Keyboard.release(KEY_F8);
      break;
      case 32:
      Keyboard.release(KEY_F9);
      break;
      case 33:
      Keyboard.release(KEY_F10);
      break;
      case 34:
      Keyboard.release(KEY_F11);
      break;
      case 35:
      Keyboard.release(KEY_F12);
      break;
    }
  }
}

void keyboardReleaseAll(){
   Keyboard.releaseAll();
}

void keyboardPressRelease(String a, String t, String b){
  char ta = a.charAt(0);
  int tb = b.toInt();
  int tt = t.toInt();
  if(tb == 0){
    Keyboard.press(ta);
    delay(tt);
    Keyboard.release(ta);
  }else{
    switch(tb){
      case 1:
      Keyboard.press(KEY_LEFT_CTRL);
      delay(tt);
      Keyboard.release(KEY_LEFT_CTRL);
      break;
      case 2:
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(tt);
      Keyboard.release(KEY_LEFT_SHIFT);
      break;
      case 3:
      Keyboard.press(KEY_LEFT_ALT);
      delay(tt);
      Keyboard.release(KEY_LEFT_ALT);
      break;
      case 4:
      Keyboard.press(KEY_LEFT_GUI);
      delay(tt);
      Keyboard.release(KEY_LEFT_GUI);
      break;
      case 5:
      Keyboard.press(KEY_RIGHT_CTRL);
      delay(tt);
      Keyboard.release(KEY_RIGHT_CTRL);
      break;
      case 6:
      Keyboard.press(KEY_RIGHT_SHIFT);
      delay(tt);
      Keyboard.release(KEY_RIGHT_SHIFT);
      break;
      case 7:
      Keyboard.press(KEY_RIGHT_ALT);
      delay(tt);
      Keyboard.release(KEY_RIGHT_ALT);
      break;
      case 8:
      Keyboard.press(KEY_RIGHT_GUI);
      delay(tt);
      Keyboard.release(KEY_RIGHT_GUI);
      break;
      case 9:
      Keyboard.press(KEY_UP_ARROW);
      delay(tt);
      Keyboard.release(KEY_UP_ARROW);
      break;
      case 10:
      Keyboard.press(KEY_DOWN_ARROW);
      delay(tt);
      Keyboard.release(KEY_DOWN_ARROW);
      break;
      case 11:
      Keyboard.press(KEY_LEFT_ARROW);
      delay(tt);
      Keyboard.release(KEY_LEFT_ARROW);
      break;
      case 12:
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(tt);
      Keyboard.release(KEY_RIGHT_ARROW);
      break;
      case 13:
      Keyboard.press(KEY_BACKSPACE);
      delay(tt);
      Keyboard.release(KEY_BACKSPACE);
      break;
      case 14:
      Keyboard.press(KEY_TAB);
      delay(tt);
      Keyboard.release(KEY_TAB);
      break;
      case 15:
      Keyboard.press(KEY_RETURN);
      delay(tt);
      Keyboard.release(KEY_RETURN);
      break;
      case 16:
      Keyboard.press(KEY_ESC);
      delay(tt);
      Keyboard.release(KEY_ESC);
      break;
      case 17:
      Keyboard.press(KEY_INSERT);
      delay(tt);
      Keyboard.release(KEY_INSERT);
      break;
      case 18:
      Keyboard.press(KEY_DELETE);
      delay(tt);
      Keyboard.release(KEY_DELETE);
      break;
      case 19:
      Keyboard.press(KEY_PAGE_UP);
      delay(tt);
      Keyboard.release(KEY_PAGE_UP);
      break;
      case 20:
      Keyboard.press(KEY_PAGE_DOWN);
      delay(tt);
      Keyboard.release(KEY_PAGE_DOWN);
      break;
      case 21:
      Keyboard.press(KEY_HOME);
      delay(tt);
      Keyboard.release(KEY_HOME);
      break;
      case 22:
      Keyboard.press(KEY_END);
      delay(tt);
      Keyboard.release(KEY_END);
      break;
      case 23:
      Keyboard.press(KEY_CAPS_LOCK);
      delay(tt);
      Keyboard.release(KEY_CAPS_LOCK);
      break;
      case 24:
      Keyboard.press(KEY_F1);
      delay(tt);
      Keyboard.release(KEY_F1);
      break;
      case 25:
      Keyboard.press(KEY_F2);
      delay(tt);
      Keyboard.release(KEY_F2);
      break;
      case 26:
      Keyboard.press(KEY_F3);
      delay(tt);
      Keyboard.release(KEY_F3);
      break;
      case 27:
      Keyboard.press(KEY_F4);
      delay(tt);
      Keyboard.release(KEY_F4);
      break;
      case 28:
      Keyboard.press(KEY_F5);
      delay(tt);
      Keyboard.release(KEY_F5);
      break;
      case 29:
      Keyboard.press(KEY_F6);
      delay(tt);
      Keyboard.release(KEY_F6);
      break;
      case 30:
      Keyboard.press(KEY_F7);
      delay(tt);
      Keyboard.release(KEY_F7);
      break;
      case 31:
      Keyboard.press(KEY_F8);
      delay(tt);
      Keyboard.release(KEY_F8);
      break;
      case 32:
      Keyboard.press(KEY_F9);
      delay(tt);
      Keyboard.release(KEY_F9);
      break;
      case 33:
      Keyboard.press(KEY_F10);
      delay(tt);
      Keyboard.release(KEY_F10);
      break;
      case 34:
      Keyboard.press(KEY_F11);
      delay(tt);
      Keyboard.release(KEY_F11);
      break;
      case 35:
      Keyboard.press(KEY_F12);
      delay(tt);
      Keyboard.release(KEY_F12);
      break;
    }
  }

}

void keyboardPrint(String a){
  
   Keyboard.print(a);
}

void keyboardPrintln(String a){
   Keyboard.println(a);
}

void keyboardWrite(String a, String b){
    char ta = a.charAt(0);
    int tb = b.toInt();
  if(tb == 0){
    Keyboard.write(ta);
  }else{
    switch (tb){
      case 1:
      Keyboard.write(KEY_LEFT_CTRL);
      break;
      case 2:
      Keyboard.write(KEY_LEFT_SHIFT);
      break;
      case 3:
      Keyboard.write(KEY_LEFT_ALT);
      break;
      case 4:
      Keyboard.write(KEY_LEFT_GUI);
      break;
      case 5:
      Keyboard.write(KEY_RIGHT_CTRL);
      break;
      case 6:
      Keyboard.write(KEY_RIGHT_SHIFT);
      break;
      case 7:
      Keyboard.write(KEY_RIGHT_ALT);
      break;
      case 8:
      Keyboard.write(KEY_RIGHT_GUI);
      break;
      case 9:
      Keyboard.write(KEY_UP_ARROW);
      break;
      case 10:
      Keyboard.write(KEY_DOWN_ARROW);
      break;
      case 11:
      Keyboard.write(KEY_LEFT_ARROW);
      break;
      case 12:
      Keyboard.write(KEY_RIGHT_ARROW);
      break;
      case 13:
      Keyboard.write(KEY_BACKSPACE);
      break;
      case 14:
      Keyboard.write(KEY_TAB);
      break;
      case 15:
      Keyboard.write(KEY_RETURN);
      break;
      case 16:
      Keyboard.write(KEY_ESC);
      break;
      case 17:
      Keyboard.write(KEY_INSERT);
      break;
      case 18:
      Keyboard.write(KEY_DELETE);
      break;
      case 19:
      Keyboard.write(KEY_PAGE_UP);
      break;
      case 20:
      Keyboard.write(KEY_PAGE_DOWN);
      break;
      case 21:
      Keyboard.write(KEY_HOME);
      break;
      case 22:
      Keyboard.write(KEY_END);
      break;
      case 23:
      Keyboard.write(KEY_CAPS_LOCK);
      break;
      case 24:
      Keyboard.write(KEY_F1);
      break;
      case 25:
      Keyboard.write(KEY_F2);
      break;
      case 26:
      Keyboard.write(KEY_F3);
      break;
      case 27:
      Keyboard.write(KEY_F4);
      break;
      case 28:
      Keyboard.write(KEY_F5);
      break;
      case 29:
      Keyboard.write(KEY_F6);
      break;
      case 30:
      Keyboard.write(KEY_F7);
      break;
      case 31:
      Keyboard.write(KEY_F8);
      break;
      case 32:
      Keyboard.write(KEY_F9);
      break;
      case 33:
      Keyboard.write(KEY_F10);
      break;
      case 34:
      Keyboard.write(KEY_F11);
      break;
      case 35:
      Keyboard.write(KEY_F12);
      break;
    }
  }
  
}
