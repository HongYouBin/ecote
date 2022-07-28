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
- 31행에서 vector를 만들었고 49행에서 바꿔야 하는 배열의 행, 열값을 저장하도록 했다. 52행부터 vector내용을 참고해서 배열의 값을 바꿨다. 답에서 나와 달리 전에 설정한 index를 사용했고 따로 새로운 배열을 만들어서 index를 저장하도록 했다. 새로운 배열을 참고해서 기존 배열의 값을 변경했다.

### 22번 인구 이동 353p

https://school.programmers.co.kr/learn/courses/30/lessons/60063

https://github.com/HongYouBin/ecote/blob/main/22.cpp

- bfs로 문제를 구현했다.
- 문제로 나온 로봇이 배열 2칸을 차지해서 구현하기가 까다로웠다. 로봇은 Node라는 class를 만들어 구현하도록 했다.
- 51행 매개변수로 제시된 배열 board를 간단하게 처리하기 위해 newBoard로 만들고 가장자리를 1로 채웠다.
- 23행 68행 check함수를 구현하여 움직이고 회전할 수 있는 조건인지 따져보았다. 문제에 제시된 조건을 침착하게 구현할 필요가 있다.
- 78행에서 이미 방문한 위치인지 나타내는 visited vector를 추가하지 않아서 시간 초과가 발생했다. 실수하지 않도록 조심해야 한다.
