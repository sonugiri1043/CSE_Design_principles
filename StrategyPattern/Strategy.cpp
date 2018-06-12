/*
  Strategy Design Pattern

  The strategy pattern is intended to provide a means to define a family of algorithms,
  encapsulate each one as an object, and make them interchangeable. The strategy pattern
  lets the algorithms vary independently from clients that use them.
*/

#include <iostream>

using namespace std;

class SearchAlgo {
public:
  virtual void doSearch() = 0;
};

class BinarySearch : public SearchAlgo {
  void doSearch() {
    cout<< "Binary Search" << endl;
  }
};

class SequentialSearch : public SearchAlgo {
  void doSearch() {
    cout<< "Sequential Search" << endl;
  }
};


class SortAlgo {
public:
  virtual void doSort() = 0;
};

class QuickSort : public SortAlgo {
  void doSort() {
    cout<< "Quick sort" << endl;
  }
};

class MergetSort : public SortAlgo {
  void doSort() {
    cout<< "Merge Sort" << endl;
  }
};

class HeapSort : public SortAlgo {
  void doSort() {
    cout<< "Heap sort" << endl;
  }
};

class Collection {
private:
  SearchAlgo *search_;
  SortAlgo *sort_;
public:
  Collection( SearchAlgo *_search, SortAlgo *_sort ) {
    this->search_ = _search;
    this->sort_ = _sort;
  }

  void search() {
    this->search_->doSearch();
  }
  
  void sort() {
    this->sort_->doSort();
  }
};

int main() {
  cout<< "Strategy Design Pattern" << endl;
  SearchAlgo *bs =  new BinarySearch();
  SortAlgo *qs = new QuickSort();
  Collection *coll1 = new Collection( bs, qs );
  coll1->search();
  coll1->sort();

  SearchAlgo *ss =  new SequentialSearch();
  SortAlgo *hs = new HeapSort();
  Collection *coll2 = new Collection( ss, hs );
  coll2->search();
  coll2->sort();

  return 0;
}
