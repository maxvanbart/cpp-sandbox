//
// Created by maxva on 12-3-2023.
//

#ifndef SANDBOX_CAT_H
#define SANDBOX_CAT_H


class Cat {
private:
    int age_;
public:
    // Default constructor
    Cat();
    // Specific constructor
    explicit Cat(int age);

    int getAge() const;
};


#endif //SANDBOX_CAT_H
