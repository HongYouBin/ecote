# ecote

## https://github.com/ndb796/python-for-coding-test

### 10번 자물쇠와 열쇠 325p

https://school.programmers.co.kr/learn/courses/30/lessons/60059

https://github.com/HongYouBin/ecote/blob/main/10.cpp

- N\*N이 최대 400까지밖에 나오지 않아 모든 경우의 수를 완전탐색하면 되는 문제이다.
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
- dist전체 배열을 순열로 만들어 줘야 하는데 아이디어가 떠올리지 않았다. 앞에 13번 치킨 배달(https://github.com/HongYouBin/ecote/blob/main/13.cpp)에 나온 next_permutation 함수를 이용하면 됐다. while문 안에서 해당 함수가 실행될 때마다 자동으로 dist를 순열 배열로 만들어준다. 16행~27행에 구현되었다. next_permutation에 대해서 공부해본 결과 오름차순으로 되어있는 배열(ex 1,2,3,4)을 내림차순 배열(4,3,2,1)로 만든다고 한다. 따라서 dist를 sort를 통해 오름차순해야 되지만 문제 자체에서 처음 입력값을 알아서 오름차순 순서대로 넣어주는듯 하다. 구현 문제에서 순열, 조합을 사용하는 문제가 자주 나오니 구현 문제이다 싶으면 해당 아이디어를 활용할 수 있는지 확인해 봐야한다.
  - 참고 자료 https://mjmjmj98.tistory.com/38
- 해당 친구가 start로부터 최대로 갈 수 있는 거리를 구해준 뒤 새로운 취약 지점이 그 거리보다 더 큰 수가 나오면 다음 친구를 추가하는 방법으로 구현했다. 친구를 추가한 후 새로운 취약 지점부터 다시 최대로 갈 수 있는 거리를 계산하는 과정을 반복한다. 추가한 친구를 새로운 취약 지점부터 투입하기 때문에 문제 없이 다음 for문을 진행시킬 수 있다.
  - 최대로 갈 수 있는 위치보다 취약 지점이 크면 자동으로 추가된 친구 수(cnt)는 dist의 사이즈보다 커진다.

### 15번 특정 거리의 도시 찾기 339p

https://www.acmicpc.net/problem/18352

https://github.com/HongYouBin/ecote/blob/main/15.cpp

- bfs를 이용하여 구현했다.
  - 18행을 보면 vector를 이용하여 단방향 그래프를 만들었다. vt[출발 노드].push_back(출발노드)
  - bfs를 위해 마련한 queue에 pair<int,int>로 템플릿을 만들었다. 첫 번째 int는 다음 탐색할 노드의 번호이고 두 번째 int는 노드를 방문하기 까지 걸린 거리를 담도록 했다. 두 번째 노드가 k가 되면 ans vector에 담도록 했다.

### 16번 연구소 341p

https://www.acmicpc.net/problem/14502

https://github.com/HongYouBin/ecote/blob/main/16.cpp

https://github.com/HongYouBin/ecote/blob/main/16_1.cpp

- 전에 구현해본 문제이라 쉽게 풀었다. https://github.com/HongYouBin/baekjoon/blob/master/14502.cpp
- 문제 자체가 bfs/dfs만 잘한다고 풀 수 없다. 구현해야 할 내용이 까다롭고 복잡하기 때문에 구현으로 분류되기도 한다.
- bfs를 이용하여 풀었다. 전체 조합의 경우의 수가 64_C_3이라 2초를 초과하지 않는다. 이전에 배웠던 next_permutation을 이용하여 조합을 구현했다.
  - https://github.com/HongYouBin/ecote/blob/main/16.cpp
- 답을 보니 내가 구현한 bfs와 다르게 dfs로 구현했다. 어떤 방법을 사용해도 상관 없지만 같은 문제를 답을 참고하여 dfs로 다시 풀어봤다.
  - https://github.com/HongYouBin/ecote/blob/main/16_1.cpp
  - 37행부터 재귀를 사용하여 전체에서 3개의 조합을 구하는 경우의 수를 구현했다. next_permutation을 사용하지 않고 조합을 구했다. 아이디어가 괜찮았다. 암기 필요.
  - 38행부터 벽을 3개 세운 순간(cnt == 3이 된 순간) 47행부터 dfs를 실행하여 바이러스를 퍼트린다. 간단한 아이디어이다.

### 17번 경쟁적 전염 344p

https://www.acmicpc.net/problem/18405

https://github.com/HongYouBin/ecote/blob/main/17.cpp

- bfs를 써서 바이러스의 순서에 맞게 큐에 넣으면 되는 아이디어는 쉽게 떠올랐다. 구현하는데 크게 문제될 것도 없었다. 어렵지 않은 문제지만 결과적으로 문제를 틀렸는데 바이러스를 순서에 맞게 넣지 않았다. 예시에는 행과 열의 증가에 맞게 바이러스의 순서가 차근차근 들어가서 답이 틀리지 않았는데, 바이러스의 순서가 뒤죽박죽일 때를 고려하지 않았다. 좀더 조건을 꼼꼼하게 따져봐야 한다.
- 답지를 보니 queue와 vector에 넣을 virus 클래스를 만들었고 정렬을 위해 bool operator를 수정하였다. 나는 pair를 써서 구현했다. 뭐가 좋다 나쁘다 할 수 없지만 class를 만들고 operator를 수정하는 아이디어도 기억하는 것이 좋을 것 같다.
  - https://github.com/ndb796/python-for-coding-test/blob/master/13/3.cpp

### 18번 괄호 변환 346p

https://school.programmers.co.kr/learn/courses/30/lessons/60058

https://github.com/HongYouBin/ecote/blob/main/18.cpp

- 문제가 어렵지 않았지만, 이해하는데 시간이 오래 걸렸다.
- 재귀를 이용하여 문제를 풀었다.
- 25행에서 v를 만들 때 for문을 이용했다. 답지를 보니 나와 달리 string을 다룰 때 substr()로 구현했다.
  - https://psychoria.tistory.com/773

### 19번 연산자 끼워 넣기 349p

https://www.acmicpc.net/problem/14888

https://github.com/HongYouBin/ecote/blob/main/19.cpp

- 시간이 2초이고 n의 크기가 작아서 완전 탐색으로 문제를 풀었다.
- 10행부터 재귀를 이용하여 문제를 풀었다.
- 11행부터 종료 조건을 설정했다. 처음 구현할 때 종료조건을 쓰지 않았는데, 잊지 말아야 한다.

### 20번 감시 피하기 351p

https://www.acmicpc.net/problem/18428

https://github.com/HongYouBin/ecote/blob/main/20.cpp

https://github.com/HongYouBin/ecote/blob/main/20_1.cpp

- 벽을 세우기 위해 조합을 이용했다. 전체 경우의 수가 조합 64_C_3이라 시간을 초과하지 않는다.
- 초반 문제를 구현하는데 flag배열의 수를 잘못 설정하여 애를 먹었다. flag 배열을 선생 수와 같게 설정해야 하는데, 실술 3개를 설정했다. 실수하지 않도록 주의해야 한다.
- 처음 flag를 배열로 설정하여 풀었는데 너무 복잡했다. 단순화하여 가독성을 높이기 위해 flag를 배열이 아닌 하나의 변수로 설정하여 조건에 맞지 않으면 flag를 true로 조건에 맞으면 flase로 설정 후 74행부터 답을 출력하도록 했다.
- 선생이 학생을 만는지 안만나는지 재귀로 구현했다. 답을 참고해보니 재귀로 풀지 않고 반복문을 사용했다.
- 재귀문이 4개가 나왔고 코드가 비슷하여 복붙했다가 return에서 복사한 내용을 수정하지 않는 실수를 했다.

### 21번 인구 이동 353p

https://www.acmicpc.net/problem/16234

https://github.com/HongYouBin/ecote/blob/main/21.cpp

- bfs를 이용하여 구현했다. bfs에서 추가해야 하는 내용이 많아 복잡했는데 따로 함수로 만들어서 풀어 가독성을 높여야 한다.
- 20행 while문 안에서 종료 조건을 어떻게 설정해야 하나 고민했다. 답을 보니 간단하게 합친 국경의 수를 나타내는 변수 index를 설정하였고, index의 수가 n\*n이 되면 종료했다. 간단한 아이디어로 문제를 해결할 수 있었다. 나는 35행 idx로 구현했다.
- 31행에서 vector를 만들었고 49행에서 바꿔야 하는 배열의 행, 열값을 저장하도록 했다. 52행부터 vector내용을 참고해서 배열의 값을 바꿨다.

### 22번 인구 이동 353p

https://school.programmers.co.kr/learn/courses/30/lessons/60063

https://github.com/HongYouBin/ecote/blob/main/22.cpp

- bfs로 문제를 구현했다.
- 문제로 나온 로봇이 배열 2칸을 차지해서 구현하기가 까다로웠다. 로봇은 Node라는 class를 만들어 구현하도록 했다.
- 51행 매개변수로 제시된 배열 board를 간단하게 처리하기 위해 newBoard로 만들고 가장자리를 1로 채웠다.
- 23행 68행 check함수를 구현하여 움직이고 회전할 수 있는 조건인지 따져보았다. 문제에 제시된 조건을 침착하게 구현할 필요가 있다.
- 78행에서 이미 방문한 위치인지 나타내는 visited vector를 추가하지 않아서 시간 초과가 발생했다. 실수하지 않도록 조심해야 한다.

### 23번 국영수 359p

https://www.acmicpc.net/problem/10825

https://github.com/HongYouBin/ecote/blob/main/23.cpp

- 정렬 조건 설정을 위해 26행에 cmp 함수를 만들었다. 답 24행을 보면 정렬 조건을 operator 오버로딩으로 설정했다. sort로 정렬하면 default 값이 오름차순이기 때문에 '<' 연산자를 오버로딩했다.
  - https://forswdev.tistory.com/53

### 24번 안테나 360p

https://www.acmicpc.net/problem/18310

- 첫 번째 시도에서 for문을 써서 경우의 수 전부를 계산했고, 시간초과가 떴다. 연산 횟수를 줄일 필요가 있었다. 두 번째 시도는 각 위치의 평균값이 답이라고 생각했다가 틀렸다. 답은 전체 위치의 정렬한 후의 중간값이었다.
  - https://livlikwav.github.io/algorithm/boj-18310/

### 25번 실패율 361p

https://school.programmers.co.kr/learn/courses/30/lessons/42889

https://github.com/HongYouBin/ecote/blob/main/25.cpp

- 잘 구현했다고 생각했지만 계속 오답이 나왔다. 이유를 찾아보니 실수로 11행에 return을 뺐었다. 당연히 cmp의 return 값이 안나와서 오답이 나왔다. 실수하지 않도록 주의해야 한다.
- 20행에 인자 값을 찾는 count 함수를 사용했다.
  - https://notepad96.tistory.com/45

### 26번 카드 정렬하기 363p

https://www.acmicpc.net/problem/1715

https://github.com/HongYouBin/ecote/blob/main/26.cpp

- 우선순위 큐를 이용해 매번 가장 작은 두 수를 꺼내 더하고 다시 우선순위 큐에 넣는 방법으로 문제를 해결했다. 문제를 그리디 알고리즘으로도 분류 가능하다.
- 우선순위 큐를 사용할 때 넣으면 가장 큰 수가 top에 존재하게 된다. 이 문제는 가장 작은 수가 top에 있어야 하기 때문에 비교 연산자를 따로 설정을 해줘야 된다.
  - https://dolphins-it.tistory.com/43

### 27번 정렬된 배열에서 특정 수의 개수 구하기 367p

https://github.com/HongYouBin/ecote/blob/main/27_1.cpp
https://github.com/HongYouBin/ecote/blob/main/27_2.cpp

- 처음에 이진 탐색으로 처음 나타나는 x값을 찾고 for문으로 좌 우로 x값이 나타날 때마다 더하는 방식으로 문제를 구현했다. 이런 방식으로 풀면 최악의 경우의 시간 복잡도가 O(N)이 되기 때문에 시간 초과로 오답처리 된다.
- 답을 확인하니 간단하게 해결했다. 이진 탐색으로 처음으로 x가 나온 인덱스를 찾아낸 후 마지막으로 x가 나온 인덱스를 찾아 내 빼면 됐다. 이렇게 구현하면 시간 복잡도가 O(log N)이 되기 시간 초과가 되지 않는다.
- 27_1은 라이브러리를 사용하지 않고 직접 구현해봤다.
  - 21행에서 x값이 나오면 mid-1 인덱스의 값이 x값과 다른지 확인하는 과정을 거쳤다.
  - 26행에서 vt[mid]와 vt[mid-1]가 x와 같으면 왼쪽을 탐색하게 했는데, vt[mid-1]이 x값과 같은 경우에 x가 처음으로 나오는 인덱스를 찾아야 하기 때문에 왼쪽을 탐색하게 했다.
  - 같은 이유로 x가 나온 마지막 인덱스를 찾을 때 vt[mid]와 vt[mid+1]이 x와 같다면 오른쪽을 탐색하게 했다. 45행에서 확인 가능하다.
- 직접 코드를 구현하는 방법 말고 라이브러리를 활용하는 방법도 있었다. 27_2는 라이브러리를 활용해봤다.
  - 14행 lower_bound는 찾고자 하는 값보다 크거나 같은 첫 번째 원소 주소를 리턴한다. 15행 upper_bound는 찾고자 하는 값보다 큰 첫번째 원소의 주소를 반환한다.
    - 같은 배열에서 x값이 있다면 lower_bound와 upper_bound가 다른 주소를 리턴한다. (lower_bound -> x값과 같은 첫 번째 원소의 주소, upper_bound -> x값을 초과하는 원소의 주소) 반대로 배열에서 x값이 없다면 둘다 같은 주소를 리턴한다. (lower_bound -> x값보다 큰 첫 번 째 원소의 주소, upper_bound -> 처음으로 x 값을 초과하는 원소의 주소) 이 부분을 22행에서 활용했다.
    - lower_bound와 upper_bound 각각 주소값을 리턴하기 때문에 인덱스를 얻기 위해서는 14행, 15행처럼 시작 주소값(vt.begin())을 빼주거나 18행, 19행처럼 iterator를 활용해서 주소값을 구한 후, 두 값을 빼서 차이를 구해야 한다.
    - 둘다 시간 복잡도가 O(N)이기 때문에 이진 탐색에서 자주 활용하게 될 라이브러리이다. 활용하기 위해선 이미 배열이 정렬되어 있어야 한다. 관련된 문제가 나오면 잊지 않고 사용해야 한다.
    - https://cocoon1787.tistory.com/324
    - https://jokerkwu.tistory.com/128

### 28번 고정점 찾기 368p

https://github.com/HongYouBin/ecote/blob/main/28.cpp

- O(log N)으로 알고리즘을 설계해야 하기 때문에 이진 탐색을 이용해야 한다.
- arr[a] = b 라고 할 때 a > b 인 경우
  - a-1 > b-y (y>=1)
  - a+1 ? b+x (x>=1), 두 수의 대소 관계가 어떻게 될지 모른다.
    - 따라서 왼쪽을 볼 필요가 없어지기 때문에(b - y 가 무조건 작기 때문에 a와 b가 같게될 수 없다.) 오른쪽을 탐색하면 된다.
- 반대로 a < b 인 경우
  - a - 1 ? b - y (y>=1), 두 수의 대소 관계는 모른다.
  - a + 1 < b + x (x>=1)
    - 위와 비슷한 이유로 오른쪽을 볼 필요가 없기 때문에 왼쪽을 탐색하면 된다.

### 29번 공유기 설치 369p

https://www.acmicpc.net/problem/2110

https://github.com/HongYouBin/ecote/blob/main/29.cpp

- 최소의 공유기 거리를 설정하여 이진탐색으로 구현하였다. 정확히는 파라메트릭 서치를 이용하였다. 가장 인접한 공유기 사이의 거리를 최대로 하는 값이 무엇인가? -> 공유기 사이의 최소 거리를 r로 했을 때 모든 공유기를 설치할 수 있는가? (예 or 아니오) 로 문제를 바꿔 풀었다. 지금 학습하고 있는 내용이 이진 탐색이라 아이디어를 떠올릴 수 있었지만, 이진 탐색이라는 힌트가 없었을 때에는 파라메트릭 서치를 떠올리기 쉽지 않았을 것이다. 조건이 있는 최대, 최소 값을 구하는 경우 파라메트릭 서치를 사용할 수 있도록 훈련해야 된다.

  - https://velog.io/@lake/%EC%9D%B4%EB%B6%84%ED%83%90%EC%83%89-%ED%8C%8C%EB%9D%BC%EB%A9%94%ED%8A%B8%EB%A6%AD-%EC%84%9C%EC%B9%98Parametric-Search
  - https://ialy1595.github.io/post/parametric-search/
  - https://marades.tistory.com/7

- 아이디어를 다 구현해 놓고도 답을 틀렸는데 설치한 공유기 숫자를 제대로 세지 못하도록 설계를 하는 실수를 했다.(24행, 29행)

### 30번 가사 검색 379p

https://school.programmers.co.kr/learn/courses/30/lessons/60060

https://github.com/HongYouBin/ecote/blob/main/30.cpp

- words들 각각 아스키 값에 따라 정렬이 가능하다. 정렬한 후 이진 탐색을 이용하여 문제를 푸는 아이디어를 바로 떠올렸다. 하지만 몇가지 문제점이 발생했다.
  - 첫 번째 문제점은 단어마다 길이가 다르다는 점이다. 단어의 길이마다 정렬하는 배열을 다르게 할당하는 방법으로 문제를 해결했다. (48행)
  - 아이디어에 맞춰 구현하다가 queries[1]인 "????O"에서 오답이 발생했다. 첫 글자가 "?"가 아닌 경우 문제가 발생하지 않지만 첫 글자가 "?"인 경우 정렬한 words에서 이진 탐색을 적용하지 못한다. 따라서 해당 경우의 수를 해결하기 위해 단어를 뒤집어서 받는 배열을 할당해야 한다. (50행, 51행)
  - 이진 탐색을 위해 lower_bound와 upper_bound를 적용할 수 있는데, "?" 때문에 이진 탐색이 안된다는 문제가 발생했다. 답을 보니 찾고자 하는 첫 인덱스를 찾을 때(lower_bound (첫 번째로 찾고자 하는 값보다 크거나 같은 경우의 인덱스 출력)) "?"를 a로 바꿔주고, 조건에 해당하는 마지막 인덱스를 찾을 때 (upper_bound (찾고자 하는 값을 초과하는 인덱스 출력)) "?"를 z로 바꿔주는 방법을 이용했다. 이 방법을 통해 문제를 해결했다.
    - ?를 바꿔줄 때 for문을 이용하여 하나씩 비교한 후 바꿔줬다.(11행 19행) 답에서는 다른 방법으로 구현했다.(27행) 30행을 while문 안을 보면 find 함수로 찾고자 하는 값의 인덱스를 찾아준 후 replace로 찾은 인덱스의 값을 바꿔준 후 pos를 변경하는 방법을 이용했다. for문을 쓰는 것보다 빠른 시간안에 변경 가능하다.
      - str.find("원하는 문자 혹은 문자열" , startIndex);
        - https://chp747.tistory.com/62
      - npos, find() 함수에 의해서 found 되지 못하는 경우 npos값이 리턴
        - https://mg729.github.io/c++/2019/11/03/C++_string_npos/
      - str.replace(문자열 시작 위치, 길이, 치환할 문자열);
        - https://novlog.tistory.com/137
  - 아이디어에 맞춰 잘 구현했는데도 시간초과가 발생했다. 37행이 문제였다. vector<string> word로 매개변수를 구현했는데 배열 값을 복사하는 과정에서 시간 초과가 발생한 것 같다. '&' 참조를 이용하면 시간이 절약 된다. 비슷한 이유로 다른 사람의 답을 볼 때 배열과 관련된 for문을 보면 모두 참조를 이용했다. 46행의 for문을 -> for(string &word : words) 형식으로 바꿔서 구현하면 시간이 단축된다. 잊지 말고 활용해야 한다.
- 다른 풀이를 보니 이진 탐색말고 해시를 이용하여 풀었다. words의 string과 "?"을 조합해서 만들 수 있는 모든 경우의 수를 만든 후 map을 이용하여 해결했다. 2회독 할 때 이진 탐색이랑 해시 두가지 방법 모두 이용해볼 예정이다.

### 31번 금광 375p

https://github.com/HongYouBin/ecote/blob/main/31.cpp

- 해당 열과 칸에 해당했을 때 최대로 얻을 수 있는 금의 크기를 담은 dp 배열을 만들었다. 배열을 채우는 방법은 왼쪽 위, 왼쪽, 왼쪽 아래 중 가장 큰 수를 구한 후 그 칸에 해당하는 금광을 더하면 배열이 완성 된다.
  - dp[n][m] = max(dp[n+1][m-1], dp[n][m-1], dp[n-1][m-1]) 로 점화식을 세웠다.

### 32번 정수 삼각형 376p

https://www.acmicpc.net/problem/1932

https://github.com/HongYouBin/ecote/blob/main/32.cpp

- 31번 문제와 비슷하게 풀었다. 배열을 삼각형으로 만들면 내려갈 수 있는 칸이 아래칸, 아래에서 오른쪽 칸으로 움직일 수 있다.
  - dp[n][m] = max(dp[n-1][m], dp[n-1][m-1]) 로 점화식을 세웠다.

### 33번 정수 삼각형 377p

https://www.acmicpc.net/problem/14501

https://github.com/HongYouBin/ecote/blob/main/33_1.cpp
https://github.com/HongYouBin/ecote/blob/main/33_2.cpp

- 시험장에서 문제를 보면 다이나믹 프로그래밍이라는 아이디어를 떠올리기 쉽지 않았을 것 같다.
  - t배열을 거꾸로 생각하면 된다. x일에 얻는 최대 값은 {x+t[x]일의 최대값+x일에 해당하는 값, x일 이후부터 n일 사이까지 최대값} 을 비교한 후 큰 값으로 설정하면 된다.
    - dp[x] = max(dp[x + t[x]] + p[x], maxValue);
- dp로 풀지 않고 완전탐색으로도 구현했다. n의 최대값이 15이고, 시간 제한이 2초이기 때문에 완전탐색으로도 구현 가능하다.
  - next_permutation 이용해서 모든 조합의 경우의 수를 구한 후 최대 값을 구했다.

### 34번 병사 배치하기 380p

https://www.acmicpc.net/problem/18353

https://github.com/HongYouBin/ecote/blob/main/34.cpp

- 가장 긴 증가하는 부분 수열로 문제를 풀면 된다.

  - https://www.acmicpc.net/problemset?sort=ac_desc&algo=43
  - https://seohyun0120.tistory.com/entry/%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4LIS-%EC%99%84%EC%A0%84-%EC%A0%95%EB%B3%B5-%EB%B0%B1%EC%A4%80-%ED%8C%8C%EC%9D%B4%EC%8D%AC
  - https://namu.wiki/w/%EC%B5%9C%EC%9E%A5%20%EC%A6%9D%EA%B0%80%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4#toc

- 예전에 풀어본 경험이 있는 문제 유형이지만 시간이 흘러 비슷한 유형을 다시 풀어보니 아이디어를 떠올리지 못했다.
- 가장 긴 증가하는 부분 수열을 이진 탐색과 결합하여 풀 수 있는데 lower_bound를 이용하여 문제를 풀 수 있다. 처리해야 하는 값이 크면 사용하면 된다.
  - https://www.acmicpc.net/problem/12015
  - https://github.com/HongYouBin/ecote/blob/main/34(2).cpp
  - https://st-lab.tistory.com/285

### 35번 못생긴 수 381p

https://github.com/HongYouBin/ecote/blob/main/35.cpp

- 우선순위 큐를 이용하였다. 큐에 가장 큰 수가 root에 오도록 만들었다. 큐의 top을 뺀 후 이미 넣은 수면 넘어가고 넣지 않은 수면 vector에 넣은 후 맵으로 기록을 했다.
- 답을 보니 나와 다른 방법으로 풀었다. 이미 2, 3, 5로만 약수를 갖는 수에 다시 2, 3, 5를 곱하면 된다는 아이디어와 못생긴 수들을 작은 수부터 차례대로 확인하면 된다는 아이디어는 동일하나 구현을 다르게 했다. 내가 푼 방법보다 시간복잡도가 적고 메모리를 적게 소모하여 더 효율적인 방법이다.

### 35번 못생긴 수 382p

https://github.com/HongYouBin/ecote/blob/main/36.cpp

- 최소 편집 거리 알고리즘을 사용하면 됐다. dp 배열을 만드는데 각 칸마다 최소 편집 거리를 계산한 뒤 채워주면 된다. 문자열 a[i], b[j]가 다를때 dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1로 설정하면 된다. dp[i-1][j]로 채워질 때는 삭제된 경우이고, dp[i][j-1]로 채워질 때는 삽입된 경우이고, dp[i-1][j-1]로 채워질 때는 교체에 해당한다.
  - https://blog.naver.com/ndb796/220870218783

### 37번 플로이드 385p

https://www.acmicpc.net/problem/11404

https://github.com/HongYouBin/ecote/blob/main/37.cpp

- 플로이드 워셜로 문제를 해결했다. n의 최대 개수가 100이기 때문에 플로이드 워셜 시간복잡도가 O(N^3)이어도 1초안에 해결 가능하다.
- 문제를 풀면서 당황했던 부분이 시작 도시와 도착 도시를 연결하는 노선이 하나가 아닐 수 있다는 점이다. 따라서 28행처럼 시작 도시와 도착 도시의 비용을 배열에 담을 때 최소값이 담기도록 해야 정답이 된다.

### 38번 정확한 순위 386p

https://github.com/HongYouBin/ecote/blob/main/38_1.cpp

https://github.com/HongYouBin/ecote/blob/main/38_2.cpp

- 플로이드 워셜 테이블을 만든 후 0으로 초기화 했다. 두 학생의 성적 관계를 알면 테이블을 1로 바꿨다. 이 과정까지는 나와 답이 비슷했다.
- 42행부터 나와 답이 다르게 문제를 구현했다. 한 학생을 기준으로 그 학생을 가리키고 있는 다른 노드, 그 학생이 가리키고 있는 다른 노드를 구해줘야 했다. 나는 그 과정을 따로 따로 구현했는데, 답은 &&연산을 이용해서 한번에 구현했다.(38_2 45행)

### 39번 화성 탐사 388p

https://github.com/HongYouBin/ecote/blob/main/39.cpp

- 플로이드 워셜 문제로 해결하려 했으나 각 node와의 edge가 N\*N개 나와 시간을 초과한다. 문제를 보자마자 다잌스트라나 bfs로 구현해야 한다는 사실을 알았다.
- 다잌스트라로 구현했다.

### 40번 숨바꼭질 390p

https://github.com/HongYouBin/ecote/blob/main/40.cpp

- 다잌스트라로 1번 부터 각 노드의 최단 거리를 구한 후 가장 긴 최단 거리를 정답으로 출력했다.

### 41번 여행 계획 393p

https://github.com/HongYouBin/ecote/blob/main/41_1.cpp

https://github.com/HongYouBin/ecote/blob/main/41_2.cpp

- 각 노드가 연결여부만 확인하면 되기 때문에 서로소 집합 알고리즘을 이용했다. 구현은 어렵지 않았지만 답이 나보다 빠른 시간안에 문제를 풀었다. 나는 arr배열을 받고 집합 합치는 연산을 따로 구현했는데, 답은(41_2) arr배열을 삽입하는 과정과 집합 합치는 연산을 같이 구현했다.

### 42번 탑승구 395p

https://github.com/HongYouBin/ecote/blob/main/42.cpp

- 서로소 집합 알고리즘을 어떻게 사용할지 고민하다 결국 풀지 못했다. 풀이 과정을 보니 간단했다. 탑승구에 비행기가 들어올 때 그 비행기가 사용할 수 있는 최대한 큰 탑승구에 도킹한다. 약간 그리디하게 느껴졌다. 문제는 한비행기가 도킹한 후 다른 비행기들이 사용할 수 있는 최대한 큰 탑승구를 갱신해줘야 되는데 이때 서로소 집합 알고리즘이 사용된다. 비행기가 사용할 수 있는 최대한 큰 탑승구를 찾을 때마다 그 탑승구의 집합과 왼쪽에 있는 집합을 합친다. 새로 비행기가 들어왔을때 가장 사용할 수 있는 최대의 탑승구의 집합이 0이 되면 더이상 도킹 불가능하다.

### 43번 어두운 길 397p

https://github.com/HongYouBin/ecote/blob/main/43.cpp

- 크루스칼 알고리즘으로 최소 신장트리를 만들면 된다. 최소 신장트리의 길이가 답이 아니고 절약할 수 있는 최대 금액이기 때문에 총합에서 최소 신장트리 길이를 뺀 값을 출력하면 된다.

### 44번 행성 터널 398p

https://github.com/HongYouBin/ecote/blob/main/44.cpp

https://www.acmicpc.net/problem/2887

- 그래프를 만들어야 하는게 이 문제가 고난이도인 이유이다. 이전 문제들과 다르게 그래프가 주어지지 않아 직접 만들어야 했다. 모든 그래프를 만들 때 n개의 노드가 다른 n-1개의 노드와 연결되기 때문에 n(n-1)/2개의 경우가 생기고 시간복잡도 또한 O(N\*N)이 된다. 시간초과가 되기 때문에 문제를 해결하지 못한다. 여기까지 아이디어를 떠올리고 답을 봤다. 답에서 모든 경우의 그래프를 만들지 않았다. x, y, z를 정렬한 후 순서대로 비교하여 그래프를 만들었다. 그래프를 만드는 시간 복잡도가 O(NlogN)으로 줄었다.
- 그래프를 만들고 난 후 크루스칼 알고리즘을 사용하면 간단하게 문제가 해결됐다.

### 45번 최종 순위 399p

https://github.com/HongYouBin/ecote/blob/main/45.cpp

https://www.acmicpc.net/problem/3665

- 문제를 읽고난 후 기준이 모호한 상태에서 정렬을 하라는 부분에서 위상 정렬 알고리즘을 사용해야 한다는 사실을 알게되었다. 하지만 가장 확실한 순위를 만들지 못하는 경우와, 일관성이 없는 잘못된 경우 때문에 문제가 어렵게 느껴졌다.
- 내가 이 문제를 어렵게 느낀 이유는 위상 정렬 알고리즘의 과정과 결과값을 정확하게 알지 못하기 때문이었다.
  - indegree가 0일 때(들어오는 간선이 없을 때) 마련된 큐의 수가 2개 이상일 때 위상 정렬의 결과가 다양하게 바뀐다. 이 점을 이용하면 일관성이 없는 잘못된 경우를 해결할 수 있다.
  - 모든 노드의 방문 전에 큐가 비게 되면 사이클이 발생한 것이라고 한다. 사이클이 발생할 때 정렬이 안되기 때문에 확실한 올해 순위를 만들 수 없는 경우라고 판단하면 된다.
    - https://spongeb0b.tistory.com/215
- 구현해놓고 오답이 발생했다. 순위가 바뀐 팀의 정보를 알려준다고 했는데 설명을 보지 않고 예시를 보고(작년에 팀 13이 팀 6 보다 순위가 높았는데, 올해 팀 6이 팀 13보다 순위가 높다면, (6, 13)을 발표할 것이다.) 문제를 풀어서 괄호안에 있는 수 중 앞에 있는 수가 항상 크다고 설정하여 문제를 풀었다. 문제가 무엇을 요구하는지 정확하게 이해하고 풀어야 한다. 43행부터 if문을 사용하여 괄호안의 두 수에서 앞의 순위가 큰 경우와, 뒤의 수가 큰 경우를 나눠 문제를 해결했다.
