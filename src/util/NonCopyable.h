#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class NonCopyable {
public:
	NonCopyable() {}

private:
	NonCopyable(const NonCopyable&) {}
	NonCopyable& operator=(const NonCopyable&) {}
};

#endif
