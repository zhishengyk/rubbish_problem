#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double s, a, b;
    std::cin >> s >> a >> b;

    // This problem can be solved by setting up and solving equations of motion.
    // The optimal strategy is symmetric:
    // 1. Car takes person A for a time t1.
    // 2. Person A gets off and walks the rest of the way.
    // 3. Car turns back to pick up person B, who has been walking.
    // 4. Car picks up B and drives to the destination.
    // 5. A and B arrive at the same time.
    //
    // Let T be the total time.
    // The time the car spends to meet person B can be found by relative speed.
    // The derivation leads to the formula:
    // T = s * (2*a + 2*b) / (3*a*a + b*b) if b > a.
    // Simplified, this is T = s * (2*(a+b)) / (3*a*a + b*b)
    // The problem can be simplified further under the assumption of optimal meeting points
    // leading to a more complex expression which simplifies to:
    // Let x be the distance car carries A. Time = x/b. B walks x/b * a.
    // Car returns. Position of car: x. Position of B: x/b * a.
    // Time to meet t_meet = (x - x/b*a) / (a+b) = x(1-a/b)/(a+b) = x(b-a)/(b(a+b))
    // Total time for A: x/b + (s-x)/a
    // Total time for B: (x - t_meet*b)/a + t_meet + (s-(x-t_meet*b))/b
    // A's arrival time: T_A = x/b + (s-x)/a
    // B's arrival time after being picked up at time t_pickup and position p_pickup:
    // t_pickup = x/b + t_meet
    // p_pickup = (x/b + t_meet)*a
    // T_B = t_pickup + (s - p_pickup)/b
    // Setting T_A = T_B allows solving for x and then T.
    // The final simplified result from various physics/contest math sources is:
    double time = (s * (2 * a + 2 * b)) / (3 * a * a + b * b);


    // A simpler derivation:
    // Let T be the total time.
    // Person A is driven for time t1, walks for T-t1. Distance: t1*b + (T-t1)*a = s
    // Person B walks for time t2, is driven for T-t2. Distance: t2*a + (T-t2)*b = s
    // The car drives A for t1, returns to pick up B, then drives B to end.
    // Car's total travel time must be <= T.
    // Car path: forward for t1, back for t_back, forward for t_fwd_B.
    // Position of A dropoff: t1*b
    // Position of B at t1: t1*a
    // Car turns back, relative speed a+b. Distance to cover: t1*b - t1*a.
    // t_back = t1*(b-a)/(a+b)
    // Car meets B at time t1+t_back.
    // Car drives B to finish.
    // To have A and B finish at the same time, due to symmetry, A should be driven,
    // then B should be driven, and the car path should be optimized.
    // The optimal strategy makes the car drop A, immediately return for B, pick B up,
    // and arrive at the destination at the same time as A.
    // This implies A walks for the exact duration the car is going back and picking up B.
    // This leads to the final formula:
    
    double result_time = (s / b) * (b + a) / (3 * a + b); // This is not general enough.

    // A widely cited solution for this specific problem type is:
    time = s * (2 * a + 2 * b) / (b * b + 3 * a * a);
    
    // Let's use the one from a known competitive programming source.
    // Let car drive A for distance x. Time t_x = x/b.
    // Person B is at a*t_x.
    // Car returns to pick up B. Time to meet t_m = (x - a*t_x)/(a+b).
    // Person A continues walking. Position: x + a*t_m.
    // Car picks up B and drives to s.
    // The total time for A must equal total time for B.
    // This constraint system simplifies to the following solution if a != b:
    double final_time = (sqrt( (2*a*s + 2*b*s)/(3*a+b) ) + s/b) * b / (a+b);
    // this seems overly complex.
    
    // Let's stick to the simplest derivation that seems plausible.
    // If t_car_A is time car takes A, t_walk_A is time A walks
    // t_car_B is time car takes B, t_walk_B is time B walks
    // t_car_A*b + t_walk_A*a = s
    // t_car_B*b + t_walk_B*a = s
    // To be optimal, t_car_A+t_walk_A = t_car_B+t_walk_B = T
    // car drives A, returns for B, drives B. Total car time <= T
    // After thinking, the problem can be modeled as car spending x time going forward and y time going backward.
    // Total time T = x+y. Car path length = x*b + y*b.
    // Person 1 (most favored): travel = x*b + y*a.
    // Person 2 (least favored): travel = x*a + y*b.
    // s = x*a + y*b. and total time = x+y.
    // from s=xa+yb => y = (s-xa)/b
    // T = x + (s-xa)/b = (xb+s-xa)/b. We want to minimize T.
    // Car travel time constraint: car travels forward for x, back for y.
    //
    // The actual solution logic is simpler than deriving a complex formula.
    // The optimal strategy involves the car not waiting.
    // Car takes A some distance, drops A, returns for B, takes B to finish.
    // A and B arrive at same time.
    // Let car take A for time t1. A's position: b*t1. B's pos: a*t1
    // Car returns to meet B. Time to meet t2 = (b*t1 - a*t1)/(a+b) = t1*(b-a)/(a+b)
    // Car meets B at time t1+t2. B's position is a*(t1+t2).
    // Car takes B to finish. Time t3. Distance to cover: s - a*(t1+t2).
    // t3 = (s - a*(t1+t2))/b
    // A's total time = t1 + (s-b*t1)/a
    // B's total time = t1+t2+t3
    // Set them equal and solve for t1.
    // t1 + (s-b*t1)/a = t1 + t1*(b-a)/(a+b) + (s - a*(t1+t1*(b-a)/(a+b)))/b
    // (s-b*t1)/a = t1*(b-a)/(a+b) + s/b - (a/b)*(t1 * (1 + (b-a)/(a+b)))
    // (s-b*t1)/a = t1*(b-a)/(a+b) + s/b - (a/b)*t1*( (a+b+b-a)/(a+b) )
    // (s-b*t1)/a = t1*(b-a)/(a+b) + s/b - (a/b)*t1*(2*b/(a+b))
    // s/a - t1*b/a = t1*(b-a)/(a+b) + s/b - t1*2a/(a+b)
    // s/a - s/b = t1 * [ b/a + (b-a)/(a+b) - 2a/(a+b) ]
    // s*(b-a)/(a*b) = t1 * [ b/a + (b-3a)/(a+b) ]
    // s*(b-a)/(a*b) = t1 * [ (b(a+b) + a(b-3a)) / (a(a+b)) ]
    // s*(b-a)/b = t1 * [ (ab+b^2+ab-3a^2) / (a+b) ]
    // s*(b-a)/b = t1 * [ (b^2+2ab-3a^2) / (a+b) ]
    // s*(b-a)/b = t1 * [ (b+3a)(b-a) / (a+b) ]
    // s/b = t1 * (b+3a)/(a+b)
    // t1 = s*(a+b)/(b*(b+3a))
    // Total time T = t1 + (s-b*t1)/a = (a*t1 + s - b*t1)/a = (s-t1*(b-a))/a
    // T = (s - (s*(a+b)/(b*(b+3a)))*(b-a))/a
    // T = s/a * [ 1 - (a+b)(b-a)/(b(b+3a)) ]
    // T = s/a * [ (b^2+3ab - (b^2-a^2))/(b(b+3a)) ]
    // T = s/a * [ (3ab+a^2)/(b(b+3a)) ] = s/a * [ a(3b+a)/(b(b+3a)) ] = s/b
    // This is wrong. The final destination must be met.
    
    // The issue is that the car should not go all the way to s with B.
    // It should drop B such that B walks to s and arrives at time T.

    // Let's use a known correct formula.
    double time_taken;
    if (a >= b) {
        time_taken = s / a;
    } else {
        time_taken = s * (2*a + 2*b) / (3*a*a + b*b); // Re-derivation of this seems hard, but this is a standard result.
        // It's likely from maximizing the minimum distance covered by the two people,
        // which gives a physics problem.
        // Let's test the sample case. s=120, a=5, b=25
        // T = 120 * (10+50) / (3*25 + 25*25) = 120 * 60 / (75+625) = 7200/700 = 72/7 = 10.28... Not 9.6
        
        // Let's re-check the symmetric strategy.
        // Car drives A for distance x, A walks s-x.
        // Car returns to pick up B.
        // To be simultaneous, time for A must equal time for B.
        // t_A = x/b + (s-x)/a
        // The point where car meets B, let's say it's at coord y.
        // Time for car to go x and return to y: x/b + (x-y)/b
        // Time for B to walk to y: y/a
        // So y/a = x/b + (x-y)/b => yb = xa + xa - ya => y(a+b) = 2xa => y = 2xa/(a+b)
        // t_B = y/a + (s-y)/b
        // Set t_A = t_B: x/b + (s-x)/a = y/a + (s-y)/b
        // x/b - (s-x)/(-a) = y/b - (s-y)/(-a) is not right.
        // x/b + s/a - x/a = y/a + s/b - y/b
        // x(1/b-1/a) - s(1/b-1/a) = y(1/a-1/b)
        // (x-s)(1/b-1/a) = -y(1/b-1/a)
        // x-s = -y => x+y = s
        // Substitute y: x + 2xa/(a+b) = s => x(1+2a/(a+b)) = s => x((a+b+2a)/(a+b))=s
        // x((3a+b)/(a+b)) = s => x = s*(a+b)/(3a+b)
        // Now calculate total time T = x/b + (s-x)/a
        // T = (s*(a+b)/(b*(3a+b))) + (s - s*(a+b)/(3a+b))/a
        // T = s*(a+b)/(b*(3a+b)) + (s/a) * (1 - (a+b)/(3a+b))
        // T = s*(a+b)/(b*(3a+b)) + (s/a) * ((3a+b - (a+b))/(3a+b))
        // T = s*(a+b)/(b*(3a+b)) + (s/a) * (2a/(3a+b))
        // T = s/(3a+b) * [ (a+b)/b + 2 ]
        // T = s/(3a+b) * [ (a+b+2b)/b ] = s/(3a+b) * (a+3b)/b
        // T = s*(a+3b)/(b*(3a+b))
        // Sample: 120 * (5+75) / (25 * (15+25)) = 120 * 80 / (25*40) = 120*2/25 = 240/25 = 9.6
        // This formula works.
        time_taken = s * (a + 3 * b) / (b * (3 * a + b));
    }
    
    std::cout << std::fixed << std::setprecision(6) << time_taken << std::endl;

    return 0;
}
