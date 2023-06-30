ll ReversePolishNotation(V<string> &vec) {
    stack<ll> s;
    fore (i, vec) {
        if (i == "+" or i == "-" or i == "*") {
            ll a1 = s.top(); s.pop();
            ll a2 = s.top(); s.pop();
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