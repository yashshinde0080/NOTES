from typing import List, Dict, Tuple
import copy

def unify(x, y, subst):
    if subst is None:
        return None
    elif x == y:
        return subst
    elif is_variable(x):
        return unify_var(x, y, subst)
    elif is_variable(y):
        return unify_var(y, x, subst)
    elif isinstance(x, list) and isinstance(y, list):
        return unify(x[1:], y[1:], unify(x[0], y[0], subst))
    else:
        return None

def is_variable(x):
    return isinstance(x, str) and x[0].islower()

def unify_var(var, x, subst):
    if var in subst:
        return unify(subst[var], x, subst)
    elif x in subst:
        return unify(var, subst[x], subst)
    elif occurs_check(var, x, subst):
        return None
    else:
        subst_copy = copy.deepcopy(subst)
        subst_copy[var] = x
        return subst_copy

def occurs_check(var, x, subst):
    if var == x:
        return True
    elif isinstance(x, list):
        return any(occurs_check(var, xi, subst) for xi in x)
    elif x in subst:
        return occurs_check(var, subst[x], subst)
    return False

def substitute(clause, subst):
    result = []
    for literal in clause:
        if isinstance(literal, list):
            result.append(apply_subst(literal, subst))
        else:
            result.append(literal)
    return result

def apply_subst(expr, subst):
    if isinstance(expr, str):
        return subst.get(expr, expr)
    return [apply_subst(e, subst) for e in expr]

def complementary(l1, l2):
    if l1[0] == 'not' and l2[0] != 'not':
        return l1[1] == l2[0]
    if l2[0] == 'not' and l1[0] != 'not':
        return l2[1] == l1[0]
    return False

def resolve(ci, cj):
    for li in ci:
        for lj in cj:
            if complementary(li, lj):
                subst = unify(li[1] if li[0] == 'not' else li,
                              lj[1] if lj[0] == 'not' else lj, {})
                if subst is not None:
                    new_ci = [l for l in ci if l != li]
                    new_cj = [l for l in cj if l != lj]
                    resolvent = substitute(new_ci + new_cj, subst)
                    return resolvent
    return None

def resolution(clauses: List[List]):
    new = set()
    while True:
        n = len(clauses)
        for i in range(n):
            for j in range(i + 1, n):
                resolvent = resolve(clauses[i], clauses[j])
                if resolvent == []:
                    print("Derived empty clause: contradiction found.")
                    return True
                if resolvent:
                    resolvent_tuple = tuple(map(tuple, resolvent))
                    if resolvent_tuple not in new:
                        new.add(resolvent_tuple)
        if all(tuple(map(tuple, c)) in new for c in clauses):
            print("No new clauses: resolution failed.")
            return False
        clauses += [list(r) for r in new if list(r) not in clauses]

if __name__ == "__main__":
    clauses = [
        [['not', ['P', 'x']], ['Q', 'x']],
        [['not', ['Q', 'x']]],
        [['P', 'a']]
    ]
    print("Resolution Result:", resolution(clauses))
