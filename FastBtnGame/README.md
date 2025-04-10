# FastBtnGame – Qt 반응 속도 테스트 게임

**FastBtnGame**은 사용자의 반응 속도를 측정하는 **Qt 기반 데스크탑 게임**입니다.  
[시작] 버튼을 누르면 화면에 일정 시간 후 신호가 나타나고,  
신호가 나타난 뒤 사용자가 얼마나 빠르게 반응하는지를 **밀리초 단위로 측정**합니다.

## 🎮 게임 진행 흐름

1. [시작] 버튼을 클릭하면 게임이 시작됩니다.  
게임은 READY 상태로부터 시작됩니다.

![시작 상태](https://github.com/user-attachments/assets/d69e030f-ec6a-4cd0-8653-1b693669f8e5)


2. 버튼은 잠시 빨간색(RED)으로 표시되고, 사용자는 기다립니다.  
이 상태에서는 버튼을 누를 수 없습니다.

![RED 상태](https://github.com/user-attachments/assets/a070668f-9b1b-40c9-8303-c6968efee458)


3. 일정 시간이 지나면 버튼이 파란색(BLUE)으로 바뀌고, 이때 클릭하면 반응 시간이 측정됩니다.

![BLUE 상태](https://github.com/user-attachments/assets/915b4b99-5d55-4840-9f27-c7826140f414)


4. 측정된 반응 속도(ms)는 화면에 표시됩니다.  
결과 메시지를 확인할 수 있으며, 이후 다시 게임을 시작할 수 있습니다.

![결과 상태](https://github.com/user-attachments/assets/eb8a8463-92f8-4265-9dc9-9cd2946da182)

5. 이후 다시 초기 상태로 돌아가 [시작] 버튼을 눌러 새로운 게임을 할 수 있습니다.

  

---

## ⏱ 반응 속도 측정 로직

1. 사용자가 시작 버튼을 누르면:
   - 상태: `READY → RED`
   - 랜덤 시간(1~5초) 후 `waitTimer`가 timeout 발생

2. 타이머가 끝나면:
   - 상태: `RED → BLUE`
   - `reactionTimer.start()`로 시간 측정 시작

3. 사용자가 버튼을 누르면:
   - `reactionTimer.elapsed()`로 반응 속도 측정
   - 상태: `BLUE → READY`
   - 결과 메시지를 라벨에 출력


---

## 학습 포인트

- `QTimer`와 `QElapsedTimer`를 함께 사용한 반응 시간 측정 방식
- 상태 전이 기반의 UI 로직 관리
- Signal-Slot 연결로 동적 UI 반응 구현
- QPushButton과 QLabel을 활용한 간단한 GUI 구성
- 실시간 사용자 반응 처리 (반응 게임 기초 구현)
