#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(int presentCapacities, int nBatteries) {
  struct CountsBySoH counts;
  int ratedcapacities=120;
  int SoH=(presentCapacities/ratedcapacities)*100.0;
  if(SoH>80 && SoH<=100)
    counts.healthy++;
  else if(SoH>62 && SoH<=80)
    counts.exchange++;
  else if(SoH<=62)
    counts.failed++;
  return counts;
}

void testBucketingByHealth() {
  int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
