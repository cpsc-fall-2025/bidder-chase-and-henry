#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// ============================================================================
// INSTRUCTIONS
// ============================================================================
// 1. Implement the three functions below.
// 2. You may use the main() function at the bottom to test your code locally.
// 3. Do not change the function signatures.
// ============================================================================

// TODO: Implement this function to return a vector of strings
// containing the names of everyone on your team.
std::vector<std::string> GetTeamMembers() {
  // Your code here
  return {"Chase Vong", "Henry Gallardo"};
}

// TODO: Implement this function to return a string that describes
// the strategy your logic uses to bid (e.g., "We bid high early on").
std::string GetStrategy() {
  // Your code here
  return "We decided to use the tortoise method with a twist. We use this "
         "method only during the beginning and the end of the rounds, "
         "skipping the middle rounds.";
}

// TODO: Implement the bidding logic.
// parameters:
//   rounds: The total number of rounds in the game.
//   budget: The total points available to spend across all rounds.
//   output_filename: The name of the file where the bids should be written.
//
// Logic:
//   1. Calculate how much to bid in each round.
//   2. Open 'output_filename' for writing.
//   3. Write the bid for each round on a new line in the file.
//
// Constraints:
//   - You must write exactly 'rounds' number of lines.
//   - The sum of all bids must not exceed 'budget'.
//   - Bids must be non-negative integers.
void GenerateBids(int rounds, int budget, std::string output_filename) {
  // Your code here
  std::ofstream outfile(output_filename);

  if (!outfile.good()) {
    std::cout << "error: cannot write to file\n";
    return;
  }

  // Simple even distribution
  int bid_per_round = 0;
  if (rounds > 0) {
    bid_per_round = budget / rounds;
  }

  // Write the same bid each round
  for (int i = 0; i < rounds; i++) {
    outfile << bid_per_round << "\n";
  }
}

// ============================================================================
// MAIN FUNCTION
// Use this to test your code.
// This function will be ignored by the "make test" command.
// ============================================================================
int main() {
  // Test example — you can change these for debugging locally.
  int rounds = 10;
  int budget = 100;
  std::string filename = "test_output.txt";

  GenerateBids(rounds, budget, filename);

  std::cout << "Finished writing bids to " << filename << "\n";
  return 0;
}
