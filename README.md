# Minibanking
- 간단한 은행업무가 가능한 프로그램입니다.

# 개요
- 본 은행 업무 프로그램은 일반 예금 계좌와 신용 거래 계좌를 구분지어 개설하도록 구현하였다.
- 각 계좌에는 기본 이율을 지정할 수 있고, 신용 거래 계좌에는 등급제를 적용하여 각 등급 별로 추가 이율을 받을 수 있도록 구현하였다.

# 시스템 구조도
- 본 프로그램은 구조체 포인터 배열을 이용하여 구현되어있다.
- 정보를 입력 받을 때와 변화가 있을 때(대여, 반납)마다 파일로 저장하고 읽어온다.
- 현재 구성된 각 구조체들은 100개의 정보를 입력받아 저장과 출력이 가능하고, 추후 그 개수를 늘려 나갈 수 있다.

# 개발환경
- OS :　windows 7 Professional K 64 bit
- CPU : intel(R) Core™ i7-5790 CPU @ 3.60GHz
- RAM : 8G RAM
- IDE : Microsoft Visual studio 2017 Version 15.9.6
- Compiler : Version _MSC_VER 1916
- 언어 : C++

# 구동 영상 URL
-	https://hoy.kr/n9Squ

# 추후 개선사항
- 대여 이력 조회 시 대여 일을 날짜순으로 정렬되도록 한다.
- 대여 이력이 없는 DVD 조회 시 대여 이력이 없다는 안내메시지를 출력하도록 한다.
- 메뉴에서 문자 입력 시 직전에 입력받은 숫자 값을 사용하지 않도록 한다.
- 좀 더 다양한 정보들을 입력, 저장하고 출력 할 수 있도록 한다.
- 고객 정보와 DVD 정보 삭제 기능을 추가하도록 한다.
- 입력받은 데이터들을 CLOUD 서비스에 따로 저장을 하거나, DB와 연동하여 신뢰성 있고 안정적으로 데이터 관리를 하도록 해야 한다.
