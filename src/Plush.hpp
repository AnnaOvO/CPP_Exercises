#pragma once
class Plush{
    public:
    Plush()
        : _cout { 10 }
    {
        
    }
    Plush(int value)
        : _cout { value }
    {
        
    }
    int get_cost() const
    {
        return _cout;
    }
    
    void set_cost(int n)
    {
        _cout = n;
    }
    private:
    int _cout;
};
