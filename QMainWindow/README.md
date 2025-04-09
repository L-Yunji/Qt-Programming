# QMainWindow MDI 실습 프로젝트

이 프로젝트는 Qt의 `QMainWindow`, `QMdiArea`, `QMdiSubWindow`를 활용하여  
여러 개의 문서(서브 윈도우)를 하나의 메인 창 안에서 다룰 수 있는  
다중 문서 인터페이스(MDI, Multiple Document Interface)를 구성한 실습 예제입니다.

## 폴더 구성

```
QMainWindow/
├── CMakeLists.txt
├── main.cpp
├── mdimainwindow.cpp
├── mdimainwindow.h
├── form.cpp
├── form.h
```

## 주요 기능

- `QMainWindow`의 중앙 위젯으로 `QMdiArea` 배치
- `QMdiSubWindow`를 생성하여 `QPushButton`, `QTextEdit` 등 위젯 삽입
- MDI 뷰 모드를 탭(Tab) 형식으로 구성
- 탭 닫기 및 이동 기능 지원
- 특정 서브 윈도우에 포함된 `Form` 위젯을 찾아 포커스를 주는 함수 구현

## 실행 화면
![image](https://github.com/user-attachments/assets/6f7b246c-f859-4de2-a7c9-51ee7882636c)
![image](https://github.com/user-attachments/assets/f54e5169-007f-4fc2-9c21-38b2029e136f)


## 학습 포인트

- `QMainWindow`를 활용한 고급 UI 구조 설계
- `QMdiArea`, `QMdiSubWindow`를 이용한 다중 문서 인터페이스 구현 방법
- 여러 개의 창을 생성하고 독립적으로 위젯을 제어하는 방식 이해
- 특정 서브 윈도우 위젯을 안전하게 캐스팅하고 포커스를 주는 방법 학습
