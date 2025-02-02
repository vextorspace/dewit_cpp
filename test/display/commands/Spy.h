
#ifndef SPY_H
#define SPY_H



class Spy {
public:
    Spy() = default;
    void set_caught();
    [[nodiscard]] bool was_caught() const;
private:
    bool caught_ = false;
};



#endif //SPY_H
