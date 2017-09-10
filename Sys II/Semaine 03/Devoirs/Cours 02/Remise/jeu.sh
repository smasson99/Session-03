#Déclaration des variables:
rocheRes='roche'
papierRes='papier'
ciseauRes='ciseau'
quitRes='quit'
res=''
iaRes=''
if [ $res = $rocheRes ] || [ $res = $papierRes ] || [ $res = $ciseauRes ] then

			#Valide, donc jouer le tour de l'ordinateur
			seed=`date | cut -c18-20`

			rand=`expr \( \( $seed  \* 5 \)  / 3 \)  % 3`

			#Trouver la valeur choisie par l'ordinateur

			case $rand in

				[0]*)iaRes=$rocheRes ;;

				[1]*)iaRes=$papierRes ;;

				*)iaRes=$ciseauRes ;;

				esac

			#Écrire le résumé des choix

			messageFin=""

			echo "L'utilisateur a choisi " $res ", l'ordinateur a choisi " $iaRes

			#Déterminer qui gagne

			if [$res = $iaRes]
			then

				messageFin="Match nul"

			elif [ $res = $rocheRes ] && [ $iaRes = $papierRes ]
			then

				messageFin="L'ordinateur a gagné"

			elif [ $res = $papierRes ] && [ $iaRes = $ciseauRes ]
			then

				messageFin="L'ordinateur a gagné"

			elif [ $res = $ciseauRes ] && [ $iaRes = $rocheRes ]
			then

				messageFin="L'ordinateur a gagné"

			else

				messageFin="L'utilisateur a gangé"

			fi

			#Afficher le message de fin de partie

			echo $messageFin

		fi