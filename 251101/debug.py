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
points = []
for i in range(1, n + 1):
    c, h, p = map(float, lines[i].split())
    h_norm = h / c
    p_norm = p / c
    points.append((h_norm, p_norm, i-1))

print("Analyzing the problem:")
print("=" * 80)

# Check single point contributions
print("\nSingle point contributions (h * p):")
for i, (h, p, idx) in enumerate(points):
    area = h * p
    print(f"Point {idx}: h={h:.6f}, p={p:.6f}, area={area:.6f}")

max_single = max(h * p for h, p, _ in points)
print(f"\nMax single point area: {max_single:.10f}")
print(f"Scaled by b²: {max_single * b * b:.10f}")

# Check pairs
print("\n" + "=" * 80)
print("Checking all pairs:")
print("=" * 80)

max_area = max_single
best_config = "single point"

for i, (h1, p1, idx1) in enumerate(points):
    for j, (h2, p2, idx2) in enumerate(points):
        if i >= j:
            continue

        # The condition from your code
        if (p1 - p2) * (h1 - h2) >= 0:
            print(f"\nPair ({idx1}, {idx2}): SKIPPED - condition (p1-p2)*(h1-h2) >= 0")
            print(f"  (p1-p2) = {p1-p2:.6f}, (h1-h2) = {h1-h2:.6f}")
            print(f"  Product = {(p1-p2)*(h1-h2):.6f}")
            continue

        # Calculate vertex position
        hv = (h2 * (p1 - p2) - p2 * (h1 - h2))
        area = -hv * hv / 4 / (h1 - h2) / (p1 - p2)

        vertex_x = hv / (h1 - h2)
        vertex_y = -hv / (p1 - p2)

        print(f"\nPair ({idx1}, {idx2}):")
        print(f"  h1={h1:.6f}, p1={p1:.6f}")
        print(f"  h2={h2:.6f}, p2={p2:.6f}")
        print(f"  hv = {hv:.6f}")
        print(f"  Vertex: ({vertex_x:.6f}, {vertex_y:.6f})")
        print(f"  Area: {area:.6f}")
        print(f"  (h1-h2) = {h1-h2:.6f}, (p1-p2) = {p1-p2:.6f}")

        if vertex_x < 0 or vertex_y < 0:
            print(f"  WARNING: Negative vertex coordinate!")

        if area > max_area:
            max_area = area
            best_config = f"pair ({idx1}, {idx2})"

print("\n" + "=" * 80)
print(f"Maximum area: {max_area:.10f}")
print(f"Scaled by b²: {max_area * b * b:.10f}")
print(f"Best configuration: {best_config}")
