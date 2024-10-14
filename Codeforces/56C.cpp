#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

struct Employee {
    string name;
    vector<Employee*> subordinates;
};

Employee* parse_employee(const string& desc, int& pos) {
    string name;

    while (pos < sz(desc) && desc[pos] != ':' && desc[pos] != '.') {
        name += desc[pos++];
    }

    Employee* employee = new Employee{name, {}};

    if (pos < sz(desc) && desc[pos] == ':') {
        pos++;
        while (pos < sz(desc) && desc[pos] != '.') {
            employee->subordinates.push_back(parse_employee(desc, pos));
            if (desc[pos] == ',')
                pos++;
        }
    }

    pos++;
    return employee;
}

int count_pairs(Employee* root, unordered_map<string, int>& name_count) {
    int count = 0;
    name_count[root->name]++;

    if (name_count[root->name] > 1) {
        count += name_count[root->name] - 1;
    }

    for (Employee* subordinate : root->subordinates) {
        count += count_pairs(subordinate, name_count);
    }

    name_count[root->name]--;
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string desc;
    cin >> desc;

    int pos = 0;
    vector<Employee*> employees;

    while (pos < sz(desc)) {
        employees.push_back(parse_employee(desc, pos));
        if (pos < sz(desc) && desc[pos] == ',') pos++;
    }

    int res = 0;

    for (Employee* employee : employees) {
        unordered_map<string, int> name_count;
        res += count_pairs(employee, name_count);
    }

    cout << res << '\n';
    return 0;
}
