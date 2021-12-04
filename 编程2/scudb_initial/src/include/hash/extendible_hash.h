/*
 * extendible_hash.h : implementation of in-memory hash table using extendible
 * hashing
 *
 * Functionality: The buffer pool manager must maintain a page table to be able
 * to quickly map a PageId to its corresponding memory location; or alternately
 * report that the PageId does not match any currently-buffered page.
 */

#pragma once

#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <mutex>

#include "hash/hash_table.h"

namespace scudb {

template <typename K, typename V>
class ExtendibleHash : public HashTable<K, V> {
  struct Bucket {
    Bucket() = default;
    explicit Bucket(size_t i, int d) : id(i), depth(d) {}
    std::map<K, V> items;	// ��ֵ��      
    size_t id = 0;	// Ͱ��id           
    int depth = 0;	// �ֲ����             
  };
public:
  // constructor
  ExtendibleHash(size_t size);
  // helper function to generate hash addressing
  size_t HashKey(const K &key);
  // helper function to get global & local depth
  int GetGlobalDepth() const;
  int GetLocalDepth(int bucket_id) const;
  int GetNumBuckets() const;
  // lookup and modifier
  bool Find(const K &key, V &value) override;
  bool Remove(const K &key) override;
  void Insert(const K &key, const V &value) override;
  size_t Size() const { return pair_count_; }

private:
  // add your own member variables here
  mutable std::mutex mutex_;	// ������ 
  const size_t bucket_size_;	// ÿ��Ͱ�����ɵ�Ԫ�ظ���
  int bucket_count_;	// ���õ�Ͱ��
  size_t pair_count_;	// ��ϣ���м�ֵ�Եĸ���
  int depth;	// ȫ�����
  std::vector<std::shared_ptr<Bucket>> bucket_;	  // Ͱ����
  std::shared_ptr<Bucket> split(std::shared_ptr<Bucket> &);   // ������Ͱ
};
} // namespace scudb
