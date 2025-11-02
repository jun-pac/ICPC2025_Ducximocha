import matplotlib.pyplot as plt
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

# Create visualization
fig, axes = plt.subplots(2, 2, figsize=(14, 12))

# Plot 1: Points in (h, p) space
ax1 = axes[0, 0]
h_vals = [p[0] for p in points]
p_vals = [p[1] for p in points]
ax1.scatter(h_vals, p_vals, c='blue', s=100, alpha=0.6, zorder=3)
for i, (h, p, idx) in enumerate(points):
    ax1.annotate(f'{idx}', (h, p), xytext=(5, 5), textcoords='offset points', fontsize=8)
ax1.set_xlabel('h (normalized)', fontsize=12)
ax1.set_ylabel('p (normalized)', fontsize=12)
ax1.set_title('Points in (h, p) space', fontsize=14)
ax1.grid(True, alpha=0.3)

# Plot 2: Lines in dual space (each point (h,p) represents line y = px - h)
ax2 = axes[0, 1]
x_range = np.linspace(-1, 3, 1000)
for i, (h, p, idx) in enumerate(points):
    y = p * x_range - h
    ax2.plot(x_range, y, alpha=0.7, label=f'Line {idx}')
ax2.set_xlabel('x', fontsize=12)
ax2.set_ylabel('y', fontsize=12)
ax2.set_title('Lines in dual space: y = px - h', fontsize=14)
ax2.grid(True, alpha=0.3)
ax2.set_ylim(-2, 2)
ax2.legend(fontsize=6, loc='upper left')

# Plot 3: Upper envelope (convex hull)
ax3 = axes[1, 0]
x_range = np.linspace(-1, 3, 1000)

# Compute the upper envelope
upper_envelope = np.full_like(x_range, -np.inf)
line_at_x = np.zeros_like(x_range, dtype=int)

for i, (h, p, idx) in enumerate(points):
    y = p * x_range - h
    mask = y > upper_envelope
    upper_envelope[mask] = y[mask]
    line_at_x[mask] = idx

# Plot all lines faintly
for i, (h, p, idx) in enumerate(points):
    y = p * x_range - h
    ax3.plot(x_range, y, alpha=0.2, color='gray')

# Plot the upper envelope
ax3.plot(x_range, upper_envelope, 'r-', linewidth=3, label='Upper Envelope')
ax3.set_xlabel('x', fontsize=12)
ax3.set_ylabel('y', fontsize=12)
ax3.set_title('Upper Envelope (Convex Hull of Lines)', fontsize=14)
ax3.grid(True, alpha=0.3)
ax3.set_ylim(-2, 2)
ax3.legend(fontsize=10)

# Plot 4: Analyze the parabola intersections
ax4 = axes[1, 1]

# For each pair of lines, find the vertex of the parabola
max_area = 0
best_pair = None
best_vertex = None

results = []
for i, (h1, p1, idx1) in enumerate(points):
    for j, (h2, p2, idx2) in enumerate(points):
        if i >= j:
            continue

        # Check if the lines form a valid parabola (opposite slopes in some sense)
        if (p1 - p2) * (h1 - h2) >= 0:
            continue

        # Calculate vertex position
        hv = (h2 * (p1 - p2) - p2 * (h1 - h2))
        area = -hv * hv / 4 / (h1 - h2) / (p1 - p2)

        results.append((area, idx1, idx2, hv / (h1 - h2), -hv / (p1 - p2)))

        if area > max_area:
            max_area = area
            best_pair = (idx1, idx2)
            best_vertex = (hv / (h1 - h2), -hv / (p1 - p2))

# Sort by area and show top results
results.sort(reverse=True)

print("\nTop 10 parabola configurations:")
print("Area\t\tLine1\tLine2\tVertex_x\tVertex_y")
for k in range(min(10, len(results))):
    area, i1, i2, vx, vy = results[k]
    print(f"{area:.6f}\t{i1}\t{i2}\t{vx:.4f}\t\t{vy:.4f}")

print(f"\nMax area (before scaling by b²): {max_area:.10f}")
print(f"Scaled by b² = {b}²: {max_area * b * b:.10f}")
print(f"Best pair: lines {best_pair[0]} and {best_pair[1]}")
print(f"Vertex at: ({best_vertex[0]:.4f}, {best_vertex[1]:.4f})")

# Plot the best parabola
if best_pair is not None:
    i1, i2 = best_pair
    h1, p1 = points[i1][0], points[i1][1]
    h2, p2 = points[i2][0], points[i2][1]

    # Parabola: maximize h*x - p*x² subject to being below both lines
    x_range_parab = np.linspace(0, max(h1, h2) * 1.5, 1000)

    # Plot the two lines
    y1 = p1 * x_range_parab - h1
    y2 = p2 * x_range_parab - h2
    ax4.plot(x_range_parab, y1, 'b-', linewidth=2, label=f'Line {i1}')
    ax4.plot(x_range_parab, y2, 'g-', linewidth=2, label=f'Line {i2}')

    # The envelope of the parabola family
    # For parabola y = h*x - p*x², touching both lines
    if best_vertex is not None:
        vx, vy = best_vertex
        ax4.plot(vx, vy, 'ro', markersize=10, label=f'Vertex ({vx:.3f}, {vy:.3f})')

        # Plot the parabola
        y_parab = vy + (vx - x_range_parab)**2 / (2 * (h1 - h2)) * (p1 - p2)
        ax4.plot(x_range_parab, y_parab, 'r--', linewidth=2, alpha=0.7, label='Best Parabola')

    ax4.set_xlabel('x', fontsize=12)
    ax4.set_ylabel('y', fontsize=12)
    ax4.set_title(f'Best Configuration: Lines {i1} & {i2}', fontsize=14)
    ax4.grid(True, alpha=0.3)
    ax4.legend(fontsize=10)
    ax4.set_ylim(-1, 2)

plt.tight_layout()
plt.savefig('convex_hull_visualization.png', dpi=150, bbox_inches='tight')
print("\nVisualization saved as 'convex_hull_visualization.png'")
plt.show()
