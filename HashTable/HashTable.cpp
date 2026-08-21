#include "HashTable.h"
#include <cstdint>

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
    // 모두 제거하는 함수 호출.
    Clear();
}

bool HashTable::Add(const std::string& key, const std::string& value)
{
    // 버킷 인덱스 구하기.
    int bucketIndex = GenerateBucketIndex(key);
    
    // 데이터를 저장할 2차 자료구조.
    Entry* current = table[bucketIndex];

    // 중복된 키가 이미 존재하는지 확인.
    // 현재 해시테이블에서는 중복 키를 허용하지 않음.
    while (current)
    {
        // 키 비교.
        if (current->key == key)
        {
            // 중복된 키가 있으면 데이터 추가 실패.
            return false;
        }

        // 다음 데이터 확인.
        current = current->next;
    }

    // 새로운 항목을 생성해서 연결 리스트 처음에 추가.
    // 처음에 추가하는 이유는 추가 연산이 빠르기 때문.
    Entry* newEntry = new Entry(key, value);
    newEntry->next = table[bucketIndex];

    // 첫 번째 데이터의 주소 업데이트.
    table[bucketIndex] = newEntry;

    // 저장 수 업데이트.
    ++count;
    return true;
}

bool HashTable::Delete(const std::string& key)
{
    // 저장된 위치 확인(해시함수 활용).
    int bucketIndex = GenerateBucketIndex(key);

    Entry* current = table[bucketIndex];
    Entry* trail = nullptr;

    // 삭제할 키 검색.
    while (current)
    {
        if (current->key == key)
        {
            break;
        }

        trail = current;
        current = current->next;
    }

    // 삭제할 키를 찾지 못한 경우.
    if (!current)
    {
        // 삭제 실패.
        return false;
    }

    // #1. 첫 번째 항목(head)을 삭제하는 경우.
    // -> 그 다음 위치를 테이블의 첫 번째 주소로 업데이트.
    if (!trail /*|| current == table[bucketIndex]*/)
    {
        // 첫 번째 노드의 주소를 원래 노드의 다음 노드 주소로 설정.
        table[bucketIndex] = current->next;
    }

    // #2. 중간 항목을 삭제하는 경우.
    // -> 이전 노드와 그 다음 노드를 연결.
    else
    {
        trail->next = current->next;
    }

    // 삭제할 노드 제거 처리.
    delete current;
    current = nullptr;

    // 데이터 수 감소 처리.
    --count;

    return true;
}

bool HashTable::Find(const std::string& key, std::string& outValue) const
{
    return false;
}

bool HashTable::Contains(const std::string& key) const
{
    return false;
}

void HashTable::Clear()
{}

void HashTable::Print() const
{}

bool HashTable::IsEmpty() const
{
    return false;
}

int HashTable::Count() const
{
    return 0;
}

int HashTable::GenerateBucketIndex(const std::string& key) const
{
    // 해시 값 저장 변수.
    uint32_t hashValue = 0;

    // 문자열의 각 문자를 활용해 해시 값 생성.
    for (char character : key)
    {
        hashValue = hashValue * 31 + static_cast<uint32_t>(character);
    }

    // 생성한 해시 값을 버킷 인덱스로 변환.
    return hashValue % bucketCount;
}
