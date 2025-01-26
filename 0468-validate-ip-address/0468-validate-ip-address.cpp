class Solution {
public:

    bool isValidIPv4Part(string part) {
        if (part.empty() || part.size() > 3 ||
            (part[0] == '0' && part.size() > 1))
            return false;

        for (auto c : part) {
            if (!isdigit(c))
                return false;
        }

        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    bool isValidIPv6Part(string part) {

        if (part.empty() || part.size() > 4)
            return false;

        for (auto c : part) {
            if (!isxdigit(c))
                return false;
        }
        return true;
    }

    string validIPAddress(string queryIP) {
        if (queryIP.empty() || queryIP.back() == '.' || queryIP.back() == ':')
            return "Neither";

        stringstream ss(queryIP);
        string token;

        if (queryIP.find('.') != string::npos) {

            int cnt = 0;
            while (getline(ss, token, '.')) {
                cnt++;

                if (!isValidIPv4Part(token))
                    return "Neither";
            }
            return cnt == 4 ? "IPv4" : "Neither";
        }

        else if (queryIP.find(':') != string::npos) {

            int cnt = 0;
            while (getline(ss, token, ':')) {
                cnt++;

                if (!isValidIPv6Part(token))
                    return "Neither";
            }
            return cnt == 8 ? "IPv6" : "Neither";
        }

        return "Neither";
    }
};