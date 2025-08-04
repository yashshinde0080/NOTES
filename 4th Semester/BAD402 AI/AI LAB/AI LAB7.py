def forward_chaining(rules, facts, goal):
    inferred = set(facts)
    changed = True

    while changed:
        changed = False
        for rule in rules:
            premises, conclusion = rule
            if all(premise in inferred for premise in premises):
                if conclusion not in inferred:
                    inferred.add(conclusion)
                    changed = True
                    print(f"Inferred: {conclusion}")
                if conclusion == goal:
                    return True
    return goal in inferred

def backward_chaining(rules, facts, goal, depth=0):
    indent = " " * depth
    print(f"{indent}Checking: {goal}")
    if goal in facts:
        print(f"{indent}{goal} is a known fact.")
        return True

    for rule in rules:
        premises, conclusion = rule
        if conclusion == goal:
            print(f"{indent}Trying rule: {premises} => {conclusion}")
            if all(backward_chaining(rules, facts, p, depth + 1) for p in premises):
                print(f"{indent}All premises true for {goal}")
                return True

    print(f"{indent}Failed to prove: {goal}")
    return False

if __name__ == "__main__":
    rules = [
        (['A', 'B'], 'C'),
        (['C', 'D'], 'E')
    ]
    facts = {'A', 'B', 'D'}
    goal = 'E'

    print("=== Forward Chaining ===")
    result_fc = forward_chaining(rules, facts, goal)
    print("Goal Reached." if result_fc else "Goal Not Reachable.")

    print("\n=== Backward Chaining ===")
    result_bc = backward_chaining(rules, facts, goal)
    print("Goal Reached." if result_bc else "Goal Not Reachable.")
