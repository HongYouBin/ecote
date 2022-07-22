# ecote

### 10번 자물쇠와 열쇠 325p
https://school.programmers.co.kr/learn/courses/30/lessons/60059

https://github.com/HongYouBin/ecote/blob/main/10.cpp
- N*N이 최대 400까지밖에 나오지 않아 모든 경우의 수를 완전탐색하면 되는 문제이다.
- 2차원 vector를 다루는게 익숙하지 않아 구현에 문제가 발생했다. 계산을 편하게 하기 위해 vector를 3배로 해야 했지만 2차원 vector를 어떻게 초기화 해야되나 문제가 발생했다. 2가지 블로그를 참고하여 2차원 vector의 초기화 방법을 알아냈다. 앞으로 자주 마주하게될 문제이기 때문에 암기가 필요하며 2차원 vector에 익숙해질 필요가 있다. 34행과 9행에서 구현되었다.
    - https://velog.io/@yoonjong/C-2%EC%B0%A8%EC%9B%90-vector-%EC%B4%88%EA%B8%B0%ED%99%94   
    - https://sosal.kr/524
- 36행부터 40행까지 새로만든 2차원 vector를 초기화해주지 않아 오답이 나왔었다. 
- 42행부터 newLock의 값을 한개씩 비교하고 4번 돌려주는 방법으로 문제를 해결한다. 
  - i와 j를 0부터 어디까지 증가시킬지 고민했다. 처음엔 3*n-m만큼 증가시키려 했으나 그럴 필요 없이 마지막까지 자물쇠와 열쇠가 겹칠 수 있는 부분인 2*n만큼만 돌리면 된다. 
- 48행에서 newLock의 index와 key의 index를 어떻게 맞춰줘야 되나 고민했다. 간단하게 더해주는 방법으로 해결 가능했다. 
- 열쇠를 돌리는 것또한 구현에 어려움을 겪었다. 12항 주석에서 나왔듯이 시계방향으로 90도 회전하면 arr[i][j]값이 arr[j][n-i-1]로 이동한다. 앞으로 자주 쓰일 코드이니 암기해야한다. 좀더 정확한 코드는 주석 65행에 구현해놓았다.

### 11번 뱀 327p
https://www.acmicpc.net/problem/3190

https://github.com/HongYouBin/ecote/blob/main/11.cpp
- 차근차근 설명에 나온 방법으로 구현하면 쉬운 문제였다. 침착하게 대응하지 못했다.
- 14행 
  - 함수를 만들 때 삼항연산자를 사용하면 간단하게 작성할 수 있다. 조건문이 다양하게 나올 때 삼항연산자를 사용하도록 할 것
- 20행, 21행 
  - 방향 전환할 때 dx는 row(행), dy는 colum(열)로 작성해야 한다. 반대로 해서 결과가 잘못 나왔다. 남쪽으로 갈수록 증가한다. 행의 값이 아래로 갈수록 증가 반대로 생각해서 결과가 잘못 나왔다.
- 41행
  - 뱀이 머물고 있는 방향을 설정할 때 배열을 하나 더 만들어서 메모리를 잡아먹었는데 그럴 필요 없이 기존 배열 arr를 재활용 하면 된다. 0이면 방문하지 않은 곳, 1이면 사과가 있는곳, 2이면 방문한 곳으로 설정
- 42행 
  - 뱀이 사과를 먹지 않아 크기가 늘어나지 않을 때 뱀이 가장 마지막에 방문한 곳을 지워줘야 한다. 아이디어가 떠오르지 않았다. 답을 보니 queue를 사용하여 마지막으로 방문한 곳을 지웠다. 해결 방법을 좀더 고민해봤어야 할 것 같다
  - 55행에서 queue를 이용하여 마지막 방문한 곳을 지우는 과정 확인 가능하다.
- 44행
  - 왼쪽 위부터 시작해 1, 1부터 시작했어야 했지만 실수로 오른쪽 위부터 시작하도록 좌표를 설정하는 실수를 했다.
- 14행
  - 함수 turn에서 왼쪽으로 방향을 바꿀 때 direction - 1 연산을 해줘야 되지만 더했다. 정신차리고 실수하지 않도록 확인해야 한다.
  
### 12번 기둥과 보 설치 329p
https://programmers.co.kr/learn/courses/30/lessons/60061

https://github.com/HongYouBin/ecote/blob/main/12.cpp
- 아이디어를 떠오르는 것은 어렵지 않았으나 코드 구현과정이 복잡하여 실수할 가능성이 높고, 중간중간 위기가 찾아왔다. 
- 시간을 5초 줬기 때문에 제시된 조건을 처음부터 끝까지 하나하나 다 확인 가능하다. 새로 추가되거나 삭제될 때 조건을 만족하는지 현재 answer에 저장된 내용을 처음부터 끝까지 따져보는게 가능하다. 처음 문제를 풀 때 시간을 확인 안했는데 앞으로 까먹는 일이 없도록 해야된다.
- 처음 시간을 줄일려고 보와 기둥을 저장하는 배열을 따로 저장했는데 그럴 필요 없없다. answer에 다 넣어서 확인한다. 
- 50행 
  - tmp vector를 만들어 넣은 후 answer에 넣으면 2차원 vector를 구현할 수 있다. 카카오에서 vector를 기본 입력값으로 주기 때문에 앞으로 많이 활용할 것 같다.
- 55행
  - 건설할 때 조건을 만족하면 answer에 넣고 조건을 만족하지 않으면 answer에서 빼준다. 
- 60행
  - 삭제할 내용을 일일이 찾아 인덱스를 저장한 후 조건에 맞으면 answer에서 지워준다. 조건에 맞지 않으면 다시 넣어야 하기 때문에 erase에 삭제할 내용을 백업한 후 다시 넣어준다.
  - 67행에서 erase 함수를 넣는 방법을 자주 쓰게 될 것 같다. 잊지않고 기억할 것
- 7행
  - 앞에서 말했듯이 조건을 하나하나 확인하여 따져본다.
- 14행, 15행, 21행
  - 이번 문제에서 처리가 곤란했다. 왼쪽 보와 오른쪽 보를 따로 확인했어야 했는데 같이 확인하여 당연히 값이 달라 false가 뜨게 되었다. 조건을 확실하게 따져보고 틀린 부분이 없나 검토해봐야한다.

### 13번 치킨 배달 333p
https://www.acmicpc.net/problem/15686

https://github.com/HongYouBin/ecote/blob/main/13.cpp

https://github.com/HongYouBin/ecote/blob/main/13-1.cpp

- 크게 2가지 방법으로 문제를 해결하였다. 두가지 방법 모두 brute force 방법으로 해결 가능하다.
- 1
  - 조합을 이용한다. 13_C_M 이기 때문에 경우의 수가 작게 나타난다.
  - C++에서 조합을 하는 방법을 헤맸다. 답을 보고 검색을 한 후에 해결 가능했다. next_permutaion이라는 stl을 사용했다. 앞으로 많이 나올 수 있으니 외워야 된다(https://blog.uniony.me/cpp/next_permutation/). 40행에서 46행까지 구현되었다. 구현할 때 어려웠던 부분은 앞 부분이 모두 0이고 뒷부분이 모두 1이어야 순열처럼 움직인다. 따라서 36행 주석처럼 구현하면 안되고 37행 처럼 앞은 0 뒤는 1로 구현해줘야 한다. 또한 vector에서 end를 작성할 때 헷갈린 부분이 있었는데 end는 vector 마지막 부분 다음의 iterator를 반환한다.
  - 11항
    - check함수를 이용해 하나하나 계산한다. 
- 2
  - dfs방법으로 문제를 해결한다.
    - 아이디어를 떠올리는 것은 쉬웠으나 매번 dfs 함수에 접근할 때마다 값을 계산하려 했고 종결 조건을 설정하는 과정에서 애를 먹었다. 답을 참고하니 visited 배열을 만들어서 방문할 때마다 true 값을 넣어 true 값이 나올 때만 계산하는 방법을 이용했다. cnt값이 m과 같아질 때 방문한 chickent 배열을 계산하였다.
    - dfs로 풀 때 종결 조건을 고민해보고 인수, 반환값, 해결 방법등을 자세히 고민해야 한다. 머리로만 구현하면 추후에 애먹는 일이 발생할 가능성이 있다. 코딩전 설계를 탄탄히 할 것


### 14번 외벽 점검 335p
https://school.programmers.co.kr/learn/courses/30/lessons/60062

https://github.com/HongYouBin/ecote/blob/main/14.cpp

- 처음에 greedy 방법으로 시도했다가 풀지 못했다. greedy 방법말고 n과 weak, dist배열이 작기 때문에 완전 탐색으로 풀이 가능하다. 전체 순열이 dist 최대값이 8이기 때문에 8_P_8에 weak 배열이 최대 15이기 때문에 1초를 넘기지 않는다. 
- 원으로 이루어져 있기 때문에 구현이 까다로웠는데 어렵게 생각할 필요 없이 전체 길이를 2배 해주면 된다. 좋은 아이디어이기 때문에 앞으로 비슷한 문제가 나오면 사용해야 한다. weak 배열을 2배로 만드
는 과정을 13행에서 확인 가능하다.
- dist전체 배열을 순열로 만들어 줘야 하는데 아이디어가 떠올리지 않았다. 앞에 13번 치킨 배달(https://github.com/HongYouBin/ecote/blob/main/13.cpp)에 나온 next_permutation 함수를 이용하면 됐다. while문 안에서 해당 함수가 실행될 때마다 자동으로 dist를 순열 배열로 만들어준다. 16행~27행에 구현되었다. next_permutation에 대해서 공부해본 결과 오름차순으로 되어있는 배열(ex 1,2,3,4)을 내림차순 배열(4,3,2,1)로 만든다고 한다. 따라서 dist를 sort를 통해 오름차순해야 되지만 문제 자체에서 처음 입력값을 알아서 오름차순 순서대로 넣어주는듯 하다.
    - 참고 자료 https://mjmjmj98.tistory.com/38
- 해당 친구가 start로부터 최대로 갈 수 있는 거리를 구해준 뒤 그 거리보다 더 큰 수가 나오면 다음 친구를 추가하는 방법으로 구현했다. 친구를 추가한 후 다시 최대로 갈 수 있는 거리를 계산하는 과정을 반복한다.
    - 최대로 갈 수 있는 위치보다 취약 지점이 크면 자동으로 추가된 친구 수(cnt)는 dist의 사이즈보다 커진다.
