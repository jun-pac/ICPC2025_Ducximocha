import numpy as np

# Read the input data
data = """10 100000
1 0.510700892049016 0.342125673118186
1 0.287150754954457 0.870638508800752
1 0.811070541193736 0.109243859062563
1 0.198831099101692 0.560678572384383
1 0.363034286617918 0.647433716877
1 0.457121067652057 0.283078532315841
1 0.951191706190919 0.25131036347911
1 0.554394442391324 0.0160225797264033
1 0.903358766632948 0.229412403285192
1 0.901062243305024 0.172649457963715"""

lines = data.strip().split('\n')
n, b = map(int, lines[0].split())

# Parse the data
pts = [(0.0, 0.0)]  # Start with origin like reference code
for i in range(1, n + 1):
    c, h, p = map(float, lines[i].split())
    # Reference code does: budget*health/cost, budget*potency/cost
    pts.append((b * h / c, b * p / c))

print("=" * 80)
print("REFERENCE CODE LOGIC (Mobilization_tgr.cpp)")
print("=" * 80)

# Sort by first coordinate (health)
pts_sorted = sorted(pts)
print("\nPoints after sorting by health (first coordinate):")
for i, (h, p) in enumerate(pts_sorted):
    print(f"Point {i}: ({h:.6f}, {p:.6f})")

# Compute stupid solution (max h*p)
stupid = max(h * p for h, p in pts_sorted)
print(f"\nStupid solution (max h*p): {stupid:.10f}")

# Build convex hull (upper hull)
print("\n" + "=" * 80)
print("CONVEX HULL CONSTRUCTION")
print("=" * 80)

def interplow(a, b, c):
    """Is the middle point below the a--b segment?"""
    delta = c[0] - a[0]
    if delta == 0:
        return b[1] < a[1] or b[1] < c[1]
    y = (a[1] * (c[0] - b[0]) + c[1] * (b[0] - a[0])) / delta
    return b[1] < y

hull = [pts_sorted[0]]
for i in range(1, len(pts_sorted)):
    print(f"\nProcessing point {i}: {pts_sorted[i]}")
    print(f"Current hull size: {len(hull)}")

    while len(hull) > 1 and interplow(hull[-2], hull[-1], pts_sorted[i]):
        removed = hull.pop()
        print(f"  Removed {removed} from hull (point is below segment)")

    hull.append(pts_sorted[i])
    print(f"  Added {pts_sorted[i]} to hull")
    print(f"  Hull now: {hull}")

print(f"\n" + "=" * 80)
print(f"FINAL CONVEX HULL (size {len(hull)}):")
for i, pt in enumerate(hull):
    print(f"  Hull[{i}]: ({pt[0]:.6f}, {pt[1]:.6f})")

# Check parabola vertices between consecutive hull points
print("\n" + "=" * 80)
print("CHECKING PARABOLA VERTICES")
print("=" * 80)

result = stupid
for i in range(len(hull) - 1):
    h1, p1 = hull[i]
    h2, p2 = hull[i+1]

    print(f"\nHull segment {i} -> {i+1}:")
    print(f"  Point 1: ({h1:.6f}, {p1:.6f})")
    print(f"  Point 2: ({h2:.6f}, {p2:.6f})")

    a = p2 - p1  # Reference code line 41
    b_coef = h1 - h2  # Reference code line 42
    c = a * h1 + b_coef * p1  # Reference code line 43

    print(f"  a (p2-p1) = {a:.6f}")
    print(f"  b (h1-h2) = {b_coef:.6f}")
    print(f"  c (a*h1 + b*p1) = {c:.6f}")

    if a != 0:
        bx = c / (2 * a)  # Reference code line 45
        print(f"  bx = c/(2*a) = {bx:.6f}")
        print(f"  Check: {h1:.6f} < {bx:.6f} < {h2:.6f}?", end=" ")

        if bx > h1 and bx < h2:
            print("YES")
            by = (c - a * bx) / b_coef  # Reference code line 47
            print(f"  by = (c - a*bx)/b = {by:.6f}")
            area = bx * by
            print(f"  Area = bx * by = {area:.10f}")
            result = max(result, area)
            print(f"  Updated result: {result:.10f}")
        else:
            print("NO - vertex outside segment range")
    else:
        print(f"  Skipped: a = 0 (vertical segment)")

print("\n" + "=" * 80)
print(f"FINAL ANSWER: {result:.10f}")
print("=" * 80)

# Now compare with YOUR CODE logic
print("\n\n" + "=" * 80)
print("YOUR CODE LOGIC (J.cpp)")
print("=" * 80)

# Your code doesn't sort, doesn't build hull
# It normalizes first, then scales by b
pts_your = []
for i in range(1, n + 1):
    c, h, p = map(float, lines[i].split())
    h_norm = h / c
    p_norm = p / c
    h_scaled = h_norm * b
    p_scaled = p_norm * b
    pts_your.append((h_scaled, p_scaled, i-1))

print("\nYour points (after normalization and scaling):")
for h, p, idx in pts_your:
    print(f"Point {idx}: ({h:.6f}, {p:.6f})")

ans = 0
for i, (h1, p1, idx1) in enumerate(pts_your):
    # Single point contribution
    ans = max(ans, h1 * p1)

    # Check all previous points
    for j in range(i):
        h2, p2, idx2 = pts_your[j]

        # Your condition
        if (p1 - p2) * (h1 - h2) >= 0:
            continue

        hv = h2 * (p1 - p2) - p2 * (h1 - h2)
        area = -hv * hv / 4 / (h1 - h2) / (p1 - p2)

        if area > ans:
            vertex_x = hv / (h1 - h2)
            vertex_y = -hv / (p1 - p2)
            print(f"\nNew best: pair ({idx1}, {idx2})")
            print(f"  h1={h1:.6f}, p1={p1:.6f}")
            print(f"  h2={h2:.6f}, p2={p2:.6f}")
            print(f"  vertex=({vertex_x:.6f}, {vertex_y:.6f})")
            print(f"  area={area:.10f}")
            ans = area

print(f"\n" + "=" * 80)
print(f"YOUR FINAL ANSWER: {ans:.10f}")
print("=" * 80)
