# CPP Module 01

## 1️⃣ 프로젝트 소개

CPP Module 01은 C++의 메모리 할당(new/delete), 참조(Reference)와 포인터(Pointer), 객체 수명과 소유권, 파일 스트림(I/O), 포인터-투-멤버(멤버 함수 포인터) 기반 디스패치를 실습으로 체득하게 하는 모듈입니다. 간단한 클래스들을 통해 스택 vs 힙, 레퍼런스 vs 포인터의 의미/제약, 문자열 치환 알고리즘, 로그 레벨 필터링 등을 구현합니다.

---

## 2️⃣ 과제 목표
	•	스택/힙 메모리 차이와 객체 수명 관리(new/delete, delete[]) 이해
	•	참조와 포인터의 차이(널 가능성, 재바인딩 가능 여부, 초기화 규칙) 숙지
	•	파일 스트림(ifstream/ofstream/fstream)으로 안전한 I/O 처리
	•	문자열 치환 알고리즘 구현 시 경계/중첩/빈 문자열 케이스 처리
	•	문자열 → 멤버 함수 디스패치 테이블(포인터-투-멤버) 설계

---

## 3️⃣ Exercise별 구현 사항

### ex00 — BraiiiiiiinnnzzzZ
* Zombie 클래스, newZombie()(힙 생성) / randomChump()(스택 생성) 구현
* 스택 vs 힙 객체 생성 방식과 수명 차이 확인(스택 자동 소멸, 힙 수동 삭제)

### ex01 — Moar brainz!
* zombieHorde(N, name)로 동적 배열 생성, delete[]로 해제
* 반복 초기화/반복 announce 로직

### ex02 — HI THIS IS BRAIN
* 문자열의 주소/값을 포인터와 참조로 각각 출력
* 포인터의 재할당 가능성과 참조의 초기화·불변 바인딩 대비

### ex03 — Weapon/HumanA/HumanB
* Weapon(mutable type), HumanA(Weapon&), HumanB(Weapon*)
* HumanA는 레퍼런스로 항상 무기를 가진 상태여야 함(널/디폴트 불가)
* HumanB는 포인터로 무기 부재/교체를 표현
* Weapon::setType()이 공유 참조를 통해 즉시 반영되는 동작 확인

### ex04 — Sed is for losers
* 입력 파일에서 문자열 s1을 s2로 치환하여 <filename>.replace 출력
* 중첩/자기치환 방지: 매칭 후 인덱스를 s1 길이만큼 전진
* s1이 빈 문자열인 경우 예외 처리(무한 루프 방지)

### ex05 — Harl 2.0
* 문자열 레벨(DEBUG/INFO/WARNING/ERROR) → 멤버 함수 포인터 배열로 매핑
* 입력 레벨에 해당하는 멤버 함수를 호출

### ex06 — Harl filter
* 입력 레벨 이상만 출력하도록 필터링
* 레벨 우선순위 테이블과 롱기스트-매치가 아닌 단순 등급 비교 설계

---

## 4️⃣ 배운 점

### 4.1 스택 vs 힙, 그리고 소유권(Ownership)
	•	스택 객체는 스코프 종료 시 자동 파괴되어 리소스 유출 위험이 적음.
	•	힙 객체는 명시적 delete/delete[]가 필요해, 해제 누락 시 메모리 누수.
	•	ex00/ex01을 통해 “누가 파괴 책임을 갖는가?”를 항상 명시해야 한다는 소유권 사고가 정착됨. (RAII로 확장될 토대)

### 4.2 참조(Reference) vs 포인터(Pointer)의 역할 분담
	•	참조는 널이 될 수 없고 생성 시 반드시 초기화, 이후 다른 객체로 재바인딩 불가 → “반드시 존재하는 의존성” 표현에 적합(HumanA)
	•	포인터는 널 가능, 재지정 가능 → “선택적/교체 가능한 의존성”에 적합(HumanB)
	•	설계 시 “레퍼런스는 강한 결합(필수), 포인터는 약한 결합(옵션)”이라는 도메인 의미 부여가 중요함.

### 4.3 공유 상태와 가시성(Reference Aliasing)
	•	Weapon의 type을 바꾸면 같은 무기를 참조하는 모든 객체에 즉시 반영됨.
	•	이는 공유 가변 상태(shared mutable state)의 장단점을 체감하게 함:
	  -	장점: 동기화된 일관성
	  -	단점: 예상치 못한 부작용 가능 → 불변 객체/복사 정책의 필요성을 직감

### 4.4 문자열 치환 알고리즘의 함정(ex04)
	•	자기치환(s1 == s2) 혹은 부분 중첩(예: s1=aaa, s2=aaaa)에서 검색 인덱스 전진 규칙을 잘못 두면 무한 루프/중복 치환 발생
	  -	해결: 매칭 후 인덱스를 idx = f_idx + s2.length();로 전진
	•	s1.length() == 0는 즉시 에러 처리해야 안전
	•	파일 스트림은 예외를 비켜가므로(badbit/failbit), 열기/쓰기 실패를 반드시 체크

### 4.5 멤버 함수 포인터 기반 디스패치(ex05/ex06)
	•	std::string level_list[LIST_SIZE] 배열/맵 + 포인터-투-멤버로 대응 → this->*func_ptr[i])() 호출
	•	if-else/switch 체인의 분기 노이즈를 제거하고 표 주도 로직(Table-driven) 으로 전환
	•	디스패치 테이블은 확장/유지보수에 유리(엔트리 추가만으로 기능 확장)

### 4.6 에러·경계 조건에 대한 습관화
	•	파일 경로/권한/빈 입력/EOF 등 현실적인 실패 케이스를 우선 설계
	•	“성공 플로우만 작성 → 실패 케이스 추가”가 아니라, 실패를 먼저 모델링하는 습관

### 4.7 빌드/구조화와 일관성
	•	헤더 가드/전방 선언, .hpp/.cpp 분리로 인터페이스-구현 경계 확립
	•	-Wall -Wextra -Werror -std=c++98로 경고=오류 정책 → 초기 설계부터 깨끗한 빌드 유지

---

## 5️⃣ Exercise별 실행 방법

### 공통

bash
```
make            # 전체 빌드
make clean / fclean / re
```

### ex00

bash
```
./zombie "hello"
./zombie              # 인자 없을 때 기본 메시지 처리
```

### ex01

bash
```
./horde 5 "Bob"      # 5마리 좀비 생성 → announce → delete[]
```

### ex02

bash
```
./brain               # 포인터/참조의 주소와 값 비교 출력
```

### ex03

bash
```
./weapon
# HumanA는 참조 기반 → 초기화 필수, 항상 무기 보유
# HumanB는 포인터 기반 → 무기 없음/변경 가능
```

### ex04

bash
```
./sed <infile> s1 s2  # <infile>.replace 생성
# 예외: s1 비어있음, 파일 열기 실패, 자기치환 처리
```

### ex05

bash
```
./harl DEBUG          # 레벨에 맞는 메시지 출력
```

### ex06

bash
```
./harl WARNING        # WARNING 이상 레벨만 출력
```

---

## 6️⃣ 기술 스택
	•	언어: C++98
	•	운영체제/환경: Unix/Linux
	•	빌드 도구: GNU Make
	•	표준 라이브러리: <iostream>, <fstream>, <string>, <iomanip>, <cstring>
