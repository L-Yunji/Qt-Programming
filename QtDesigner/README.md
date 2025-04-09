# Qt Designer 연동 실습 프로젝트

이 프로젝트는 Qt Designer를 활용하여 `.ui` 파일을 설계하고, 해당 UI를 C++ 코드(`widget.cpp`, `main.cpp`)와 연동하여 GUI 프로그램을 구성한 실습 예제입니다.

## 폴더 구성

```
QtDesigner/
├── CMakeLists.txt
├── main.cpp
├── modelint.cpp
├── modelint.h
├── widget.cpp
├── widget.h
├── widget.ui
```

## 주요 기능

- Qt Designer에서 생성한 `.ui` 파일을 기반으로 GUI 구성
- 슬라이더, 스핀박스 등을 사용하여 UI 요소 간 Signal-Slot 연동
- `modelint` 클래스는 내부 데이터를 캡슐화하고 값을 관리하는 모델 역할

## 실행 화면
![image](https://github.com/user-attachments/assets/9e6f7c08-a7ae-429e-bec3-b11a5d35a9c9)
![image](https://github.com/user-attachments/assets/07ccd0db-b1bb-495c-9adb-8570ea63e966)


## 학습 포인트

- `.ui` 파일을 C++ 코드에서 어떻게 불러와 사용하는지 이해
- Qt Designer로 만든 위젯과 직접 작성한 클래스 간 연동 방법
- 모델 클래스(`modelint`)를 통한 데이터 구조와 UI 분리 설계
