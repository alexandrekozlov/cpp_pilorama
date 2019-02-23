// This example is a bit archaic, but compiles and works
// perfectly. Unfortunately it has a bug and leaks memory.
//
// Can you explain where it leaks, why and how to fix it?

#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

class DataStorageInterface {
public:
  virtual void SetData(const std::vector<int> &data) = 0;
  virtual std::vector<int> GetData() const = 0;
  virtual const int *GetComputedDataLazy() const = 0;
};

class DataStorageImpl : public DataStorageInterface {
public:
  ~DataStorageImpl() {
     delete[] cache_;
  }

  void SetData(const std::vector<int> &data) override {
    data_ = data;
  }

  std::vector<int> GetData() const override {
    return data_;
  }

  const int *GetComputedDataLazy() const override {
    if (cache_ != nullptr)
      delete[] cache_;

    cache_ = new int[data_.size()];
    for (auto i = 0; i < data_.size(); ++i)
      cache_[i] = i + data_[i];

    return cache_;
  }

private:
  std::vector<int> data_;
  mutable int *cache_ = nullptr;
};

std::unique_ptr<DataStorageInterface> CreateDataStorage() {
  return std::make_unique<DataStorageImpl>();
}

int main() {
  auto data_storage = CreateDataStorage();
  data_storage->SetData(std::vector<int> { 0x42, 0x43 });

  std::cout << "Computed data ptr: " << data_storage->GetComputedDataLazy() << std::endl;

  return 0;
}
