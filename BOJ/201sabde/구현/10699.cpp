#include <iostream>
#include <ctime>
#include <iomanip> // setw, setfill 사용을 위한 헤더

int main() {
    // 현재 UTC 시간을 가져옴
    time_t now = time(0);
    
    // UTC 시간을 tm 구조체로 변환
    tm *utc_tm = gmtime(&now);

    // 한국 표준시로 변환 (UTC+9)
    utc_tm->tm_hour += 9;

    // 만약 시간이 24시를 넘는다면, tm 구조체가 자동으로 날짜를 계산해줌
    mktime(utc_tm);

    // 년, 월, 일을 출력 (형식: YYYY-MM-DD)
    std::cout << 1900 + utc_tm->tm_year << "-";
    std::cout << std::setw(2) << std::setfill('0') << 1 + utc_tm->tm_mon << "-";
    std::cout << std::setw(2) << std::setfill('0') << utc_tm->tm_mday << std::endl;

    return 0;
}