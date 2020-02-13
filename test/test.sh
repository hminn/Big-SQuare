RANGE=1000
DEN=100
echo
clear
number=$RANDOM
let "number %= $RANGE"
echo "테스트중입니다.."
for ((i=0;i<30;i++)); do
	num1=$RANDOM
	let "num1 %= $RANGE"
	num2=$RANDOM
	let "num2 %= $RANGE"
	num3=$RANDOM
	let "num3 %= $DEN"
	echo "$(($i + 1)) 번째 케이스 테스트 중..."
	echo "가로 : $num1 , 세로 : $num2, 밀도 : $num3 ..."
	echo ""
	./map.pl $num1 $num2 $num3 > bsq_test_map
	StartTime=$(date +%s)
	./bsq bsq_test_map > test_result_1
	EndTime=$(date +%s)
	Time1=$(($Time1 + $(($EndTime - $StartTime))))
	sleep .5
	StartTime=$(date +%s)
	./bsq_opp bsq_test_map > test_result_2
	EndTime=$(date +%s)
	Time2=$(($Time2 + $(($EndTime - $StartTime))))
done
EndTime=$(date +%s)
echo "나의 BSQ는 지도 30개를 검사하는데 $Time1 초 걸림"
echo "너의 bsq는 지도 30개를 검사하는데 $Time2 초 걸림"
echo "두 지도의 차이점은 diff_result에 저장되었습니다."
diff test_result_1 test_result_2 > diff_result
rm bsq_test_map test_result_1 test_result_2
