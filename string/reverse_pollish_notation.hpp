long long ReversePolishNotation(vector<string> &vec) {
    stack<long long> s;
    fore (i, vec) {
        if (i == "+" or i == "-" or i == "*") {
            long long a1 = s.top(); s.pop();
            long long a2 = s.top(); s.pop();
            if (i == "+") s.push(a2 + a1);
            else if (i == "-") s.push(a2 - a1);
            else if (i == "*") s.push(a2 * a1);
        }
        else {
            s.push(stoll(i));
        }
    }
    return s.top();
}