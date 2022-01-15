//this code as made by tarcisioe


namespace fakestd {

template <typename T>
T&& move(T& obj) noexcept
{
    return static_cast<T&&>(obj);
}

template <typename T>
class uniq_ptr {
public:
    uniq_ptr() noexcept = default;

    uniq_ptr(T* ptr) noexcept : ptr_{ptr} {}

    uniq_ptr(uniq_ptr const&) = delete;

    template <typename U>
    uniq_ptr(uniq_ptr<U>&& other) noexcept:
        ptr_{other.release()}
    {}

    ~uniq_ptr()
    {
        delete ptr_;
    }

    T* release()
    {
        auto p = ptr_;
        ptr_ = nullptr;
        return p;
    }

    T* get() const noexcept
    {
        return ptr_;
    }

    T* operator*() const noexcept
    {
        return get();
    }

    T* operator->() const noexcept
    {
        return get();
    }

    friend void swap(uniq_ptr& lhs, uniq_ptr& rhs) noexcept
    {
        auto aux = lhs.ptr_;
        lhs.ptr_ = rhs.ptr_;
        rhs.ptr_ = aux;
    }

    uniq_ptr& operator=(uniq_ptr const& other) = delete;

    uniq_ptr& operator=(uniq_ptr&& other) noexcept
    {
        auto x = move(other);
        swap(*this, x);
        return *this;
    }

private:
    T* ptr_{nullptr};
};

template<typename T>
struct remove_reference
{
    using type = T;
};

template<typename T>
struct remove_reference<T&>
{
    using type = T;
};

template<typename T>
struct remove_reference<T&&>
{
    using type = T;
};

template <typename T>
using remove_reference_t = typename remove_reference<T>::type;

template<typename T>
T&& forward(remove_reference_t<T>& obj) noexcept
{
    remove_reference<T> t;
    return static_cast<T&&>(obj);
}

template<typename T>
T&& forward(remove_reference_t<T>&& obj) noexcept
{
    return static_cast<T&&>(obj);
}

template <typename T, typename ...Args>
uniq_ptr<T> make_uniq(Args&& ...args)
{
    return uniq_ptr<T>{ new T{forward<Args&&>(args)...} };
}

}