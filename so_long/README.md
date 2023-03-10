# so long
## 문제조건
|항목|조건|
|------|---|
|Program name|so_long|
|Turn in files|Makefile, *.h, *.c, maps, textures|
|External functs|* open, close, read, write, malloc, free, perror, strerror, exit <br> * All functions of the math library (-lm compiler option, man man 3 math) <br> * All functions of the MiniLibX <br> * ft_printf and any equivalent YOU coded|

## todo list
- [x] MiniLibX 사용법 알아보기
- [x] MiniLibX 내장 함수 알아보기
- [x] Makefile 만들기
- [x] 프로그램 형식은 .ber 확장자
- [x] 기능 목록 작성
    * player
    - [x] 수집할 수 있는 선물 모으기
    - [x] 4가지 방향으로 이동하기 이때 벽으로 이동제한
    * map
    - [x] map의 구성요소 포함
    * graphic
    - [x] 2D view 보여주기
    - [x] 창 이미지 보여주기
    - [x] 창이 부드럽게 유지
    - [x] ESC를 누르면 프로그램 정상 종료
    * error handler
    - [x] map이 규격에 맞지 않으면 종료 및 에러 반환
        - [x] 줄에서 check할 것 : 0, 1 C, E, P 말고 다른 것들이 들어오면 에러
        - [x] 줄 간 비교: 줄의 길이가 다르면 에러
        - [x] End of File 처리 : 개행이나 null문자가 오는 것 둘다 맞게 처리
        - [x] map이 벽으로 둘러싸인 형태가 아니면 에러 처리
        - [x] map에서 수집품, 탈출구가 0개고, 플레이어의 시작 위치 갯수가 1이 아니면 에러 처리
        - [x] 플레이어의 처음 위치에서 선물을 다 수집하지 못하거나, 탈출구에 도달하는 경로가 없으면 에러 처리
## so long 개요
### Game
* 플레이어의 목적 : 수집할 수 있는 선물을 모으고, 가능한 가장 짤은 경로로 탈출
* 플레이어는 4가지 방향으로 움직일 수 있다. (up, down, left, right)
* 플레이어는 벽으로 움직일 수 없다.
* 각 움직임마다 이동횟수가 shell에 보여져야 한다.
* 2D view 를 이용해야 한다. (topd -down or profile)
* 게임은 실제 시간일 필요는 없다.
* 예시는 돌핀 테마지만, 나만의 테마를 만들 수 있다.
* W, A, S, D는 player의 이동
### Graphic management
* 창에 이미지를 보여야 한다.
* 창의 부드럽게 유지가 되어야 한다.(다른 창으로 바꾸기, 최소화 등등..)
* ESC를 누르면 창을 닫고, 프로그램이 종료되어야 한다.
* MiniLIBX의 이미지들의 사용이 필수다.
### Map
* map의 구성요소
    * 벽, 수집품, 빈공간
    * 0 : 빈공간 1 : 벽 C : 수집품 E : map 탈출구 P : 플레이어 시작 지점
### Error Handler
* 에러 메시지 : 'Error\n' + explicit error message
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```
* map은 최소 유효한 탈출구 1개, 수집품 1개, 시작 위치 1개를 포함시켜야 한다.
* map은 직사각형이어야 한다.
* map은 벽으로 둘러싸여 있어야 한다. 그렇지 않으면 프로그램은 에러 값을 반환해야 한다.
*  파일에서 구성이 잘못되어 있으면, 프로그램은 종료되어야 하고 에러 메시지와 "Error\n"를 반환애야 한다.

## 참고 사항
* ./의 의미 : 현재 디렉토리
* 적절한 png 파일 찾기
    * 핀터레스트(Pinterest) : top down game 이런 식으로 검색
* xpm 파일에서 exit, collective 구성요소의 배경색을 없애는 방법
    * 배경색의 trgb대신 None을 넣는다.
* x_event, x_mask 파라미터로 이벤트 상황을 지정해준다.
    * miniLibX의 mlx_hook() 함수에서는 파라미터로 x_mask를 받지만 내부에서 사용을 하지 않으므로 0으로 값을 지정해도 무관하다.
* 바탕화면에서 빨간색 버튼을 누르면 종료되는 x_event는 17이다.
<img width="391" alt="image" src="https://user-images.githubusercontent.com/106499310/209092790-79b2f18c-5e54-47ae-877e-7484796ad1c4.png">

```c
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
```