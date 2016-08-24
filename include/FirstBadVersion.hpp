#ifndef FIRST_BAD_VERSION_HPP_
#define FIRST_BAD_VERSION_HPP_

class FirstBadVersion {
public:
    typedef bool (*VersionChecker)(int);

public:
    FirstBadVersion(VersionChecker checker);

    int firstBadVersion(int n);

private:
    VersionChecker isBadVersion;
};

#endif // FIRST_BAD_VERSION_HPP_
