class MPPoint : public MPGeometryItem {
    double x, y;
    shape Pointshape; //cross, box size d
public:
    void Scale(double s) override { if (s > MINIMAL_NONZERO) { x *= s; y *= s; } };
    virtual void Display() const {};
    void Write(std::ostream& file ) const override;
    virtual void Read(const char* path) {};
    friend MPPoint operator * (const MPPoint& left, const double right) {};
    friend MPPoint operator + (const MPPoint& left, const MPPoint& right) {};
};

