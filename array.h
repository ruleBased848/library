class array_int {
  public:
    explicit array_int(int initSize = 0);
    ~array_int();
    int& operator[](int index);
    const int& operator[](int index) const;
    int size() const;
    void push_back(int x);
    int pop_back();
    void insertion_sort();
    void selection_sort();

  private:
    int theSize;
    int theCapacity;
    int* theArray;
};