make;

mkdir outputs
while getopts "fdar" opt;
do
	case $opt in
		r)
			read -e -p "Directory to evaluate (Default /resources/bin/): " dir
			dir=${dir:-resources/bin}
			declare -a arr=("")
			for i in "$dir"/*;
			do
				arr+=($i)
			done
			len=$((${#arr[@]} - 1))
			for i in {1..1000};
			do
				f1=${arr[$(jot -r 1 0 len)]}
				f2=${arr[$(jot -r 1 0 len)]}
				f3=${arr[$(jot -r 1 0 len)]}
				f4=${arr[$(jot -r 1 0 len)]}
				if [[ ( -z $f1 && -z $f2 && -z $f3 && -z $f4 ) ]]
				then

					continue
				fi
				printf "\033[32mEvaluating %s %s %s %s\033[0m\n" $f1 $f2 $f3 $f4;
				./prueba  $f1 $f2 $f3 $f4 -i > outputs/our.txt;
				./corewar  $f1 $f2 $f3 $f4 -v 4 > outputs/real.txt;
				diff outputs/our.txt outputs/real.txt > outputs/diff.txt;
				if [ -s outputs/diff.txt ]
				then
					printf "\033[31mDiferences of:\n%s %s %s %s\nStored in outputs/diff.txt\033[0m\n"  $f1 $f2 $f3 $f4;
					exit 2
				else
					printf "\033[32mOK\033[0m\n"
				fi
			done
			;;
		f)
			read -e -p "Enter files: " dir
			printf "\033[1;32mEvaluating %s\033[0m\n" "$dir";
			./prueba $dir -i > outputs/our.txt;
			#			ex=$?; if [[ $ex != 0 ]]; then exit $ex; fi
			./corewar $dir -v 4 > outputs/real.txt;
			#			ex=$?; if [[ $ex != 0 ]]; then exit $ex; fi
			diff outputs/our.txt outputs/real.txt > outputs/diff.txt;
			if [ -s outputs/diff.txt ]
			then
				printf "\033[31mDiferences of:\n%s\nStored in outputs/diff.txt\033[0m\n" "$dir";
			else
				printf "\033[32mOK\033[0m\n"
			fi
			;;
		a)
			read -e -p "Directory to evaluate (Default /resources/sources/): " dir
			dir=${dir:-resources/sources}
			for f1 in $dir/*;
			do
				printf "\033[32mEvaluating %s\033[0m\n" $f1;
				printf "Our says:"
				./srcs_asm/asm $f1
				printf "\n"
				our=$(echo $f1 | sed 's/\(.*\.\)s/\1cor/g')
				cat $our > outputs/our.cor
				rm -f $our
				printf "Real says:"
				./srcs_asm/vm_champs/asm $f1
				printf "\n"
				real=$(echo $f1 | sed 's/\(.*\.\)s/\1cor/g')
				cat $real > outputs/real.cor
				rm -f $real
				diff outputs/our.cor outputs/real.cor > outputs/diff.txt;
				if [ -s outputs/diff.txt ]
				then
					printf "\033[31mDiferences of:\n%s %s %s %s\nStored in outputs/diff.txt\033[0m\n"  $(basename $f1);
					exit 2
				else
					printf "\033[32mOK\033[0m\n"
				fi
			done
			;;
		d)
			read -e -p "Directory to evaluate (Default /resources/bin/): " dir
			dir=${dir:-resources/bin}
			declare -a arr=("")
			for i in "$dir"/*;
			do
				arr+=($i)
			done
			for f1 in "${arr[@]}";
			do
				for f2 in "${arr[@]}";
				do
					for f3 in "${arr[@]}";
					do
						for f4 in "${arr[@]}";
						do
							if [[ ( -z $f1 && -z $f2 && -z $f3 && -z $f4 ) ]]
							then

								continue
							fi
							printf "\033[32mEvaluating %s %s %s %s\033[0m\n" $f1 $f2 $f3 $f4;
							./prueba  $f1 $f2 $f3 $f4 -i > outputs/our.txt;
							./corewar  $f1 $f2 $f3 $f4 -v 4 > outputs/real.txt;
							diff outputs/our.txt outputs/real.txt > outputs/diff.txt;
							if [ -s outputs/diff.txt ]
							then
								printf "\033[31mDiferences of:\n%s %s %s %s\nStored in outputs/diff.txt\033[0m\n"  $f1 $f2 $f3 $f4;
								exit 2
							else
								printf "\033[32mOK\033[0m\n"
							fi
						done
					done
				done
			done
			;;
		\?)
			echo "\033[31mInvalid option: -$OPTARG\033[0m" >&2
			exit 1
			;;
		:)
			echo "\033[31mOption: -$OPTARG requires argument\033[0m" >&2
			exit 1
			;;
	esac
done
