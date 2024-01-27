#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE


// end of helper functions
void ULListStr::push_back(const std::string& val){
  if (this->empty() || (tail_ && tail_->last == ARRSIZE)) {
    Item* newItem = new Item();
    newItem->val[newItem->last++] = val;

    if (this->empty()) {
      newItem->prev = nullptr;
      newItem->next = nullptr;
      head_ = newItem;
      tail_ = newItem;
    } else {
      newItem->prev = tail_;
      newItem->next = nullptr;
      tail_->next = newItem;
      tail_= newItem;
    }
  } else if (tail_->last < ARRSIZE) {
      tail_->val[tail_->last++] = val;
  }
  size_++;
}

// only allocate new item if current head has no space in front of first
 void ULListStr::push_front(const std::string& val) {
  if (this->empty() || head_->first == 0) {
    Item* newItem = new Item();
    newItem->val[ARRSIZE - 1] = val;
    newItem->first = ARRSIZE - 1;
    newItem->next = head_;
    newItem->last = ARRSIZE;
    newItem->prev = nullptr;
    
    if (!this->empty()) {
      head_->prev = newItem;
    } else {
      tail_ = newItem;
    }
    head_ = newItem;
  } else {
    --head_->first;
    head_->val[head_->first] = val;
  }
  size_++;
}

void ULListStr::pop_back() {
  if (this->empty()) {
    return;
  } else if (tail_->last == 1) {
      if (head_ == tail_) {
          delete tail_;
          head_ = tail_ = nullptr;
      } else {
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete temp;
      }
  } else {
    tail_->last--;
  }
  size_--;
}


void ULListStr::pop_front() {
  if (this->empty()) {
    return;
  }
  size_--;

  if (head_->first == ARRSIZE -1) {
    Item* temp = head_;

    if (head_ == tail_) {
        head_ = tail_ = nullptr;
    } else {
        head_ = head_->next;
        head_->prev = nullptr;
    }
    delete temp; 
  } else {
    head_->first++;
    if (head_->first == head_->last) {
      Item* temp = head_;
      head_ = head_->next;

      if (head_) {
        head_->prev = nullptr;
      } else {
        tail_ = nullptr;
      }
      delete temp;
    } 
  }
}

  // if (this->empty()) {
  //   return;
  // } 
  // size_--;
  // Item* temp = head_;
  
  // if (head_->first == ARRSIZE - 1) {
  //   head_ = head_->next;
    
  //   if (head_) {
  //     head_->prev = nullptr;
  //   } else {
  //     tail_ = nullptr;
  //   }
  //   delete temp;
  // } else {
  //   head_->first++;
  // }


std::string const & ULListStr::back() const {
  return tail_->val[tail_->last -1];
}


std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  Item* temp = head_;
  while (temp != nullptr) {
    if (loc < temp->last - temp->first) {
      size_t indexInArray = temp->first +loc;
      return &(temp->val[indexInArray]);
    }
    loc = loc - (temp->last - temp->first);
    temp = temp->next;
  }
  return nullptr;
}

// DO NOT TOUCH
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


// if list empty
  // point head to new node
  // if list exists
  // point tail to new node