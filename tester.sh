#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

OK_COUNT=0
TOTAL=0

run_test() {
	arg="$1"
	label="$2"
	TOTAL=$((TOTAL + 1))

	RES=$(./push_swap $arg | ./checker_linux $arg)
	if [ "$RES" == "OK" ]; then
		echo -e "${GREEN}[$label] OK${NC}"
		OK_COUNT=$((OK_COUNT + 1))
	else
		echo -e "${RED}[$label] KO ← $arg${NC}"
	fi
}

test_range() {
	count=$1
	n=$2
	for i in $(seq 1 "$count"); do
		arg=$(shuf -i 0-$((n - 1)) -n "$n" | tr '\n' ' ')
		run_test "$arg" "$n-Element Test $i"
	done
}

echo -e "\n🔍 Running full test suite...\n"

# 3 to 6 elements, increasing test count
test_range 3 3
test_range 4 4
test_range 5 5
test_range 6 6

# 7–500 elements, 3 random tests each
for size in 7 8 10 12 15 50 100 250 500; do
	for i in {1..3}; do
		arg=$(shuf -i 0-$((size - 1)) -n "$size" | tr '\n' ' ')
		run_test "$arg" "Random $size-$i"
	done
done

# Summary
echo
if [ "$OK_COUNT" -eq "$TOTAL" ]; then
	echo -e "${GREEN}✅ ALL TESTS PASSED! ($OK_COUNT/$TOTAL)${NC}"
else
	echo -e "${RED}❌ $((TOTAL - OK_COUNT)) TEST(S) FAILED ($OK_COUNT/$TOTAL)${NC}"
fi
