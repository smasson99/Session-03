#***
#Ce programme fut développé par Samuel Masson 
#(matricule: 1632010) dans le cadre du cours 
#de Système d'Exploitation et Réseau II 2017,
#groupe 02.
#***

#***Début du programme
#!/bin/bash
#Nettoyer la console
clear
#Afficher la version actuelle
version=0.01
#Afficher le texte de base du lancement du programme
echo "Lancement du programme version:$version. Créé par Trilux Inc, tous les droits sont réservés."
echo ""
#Afficher les options d'installation
echo "Bienvenu, voici vos options d'installation:"
echo "1)Institutionnelle || 2)Industrielle || 3)Canceller l'installation"
echo ""
echo "Pour plus d'informations concernant l'organisation des fichiers du répertoire à créer, tappez \"information\" suivis d'un espacement et du numéro de l'option dont vous souhaitez connaître les informations."
echo ""
canStart=false
optionChosen=0
#Tant qu'un option n'est pas choisie, lire ce qui est entré par l'utilisateur
#et agir en fonction des données entrées
while [ $canStart = false ]
	do
		#Lire la commande entrée
		read result
		#Pour chaque cas...
		case $result in
			#Cas #01 : Choisi l'option d'installation 01
			1)
			optionChosen=$result
			canStart=true ;;
			#Cas #02 : Choisi l'option d'installation 02
			2)
			optionChosen=$result
			canStart=true ;;
			#Cas #03 : Demande des informations concernant l'option 01
			"information 1")
			echo "
		INSTITUT 
			PROGRAM 
				SYSTEME 
					PILOTE 
				UTIL 
			DONNEES 
				COURANTE 
					JOURNAL 
				ARCHIVE 
				TEMP 
				" ;;
			#Cas #03 : Demande des informations concernant l'option 02
			"information 2")
			echo "
		INDUSTR 
			PROGRAM 
				SYSTEME 
					PILOTE 
				UTIL 
			DONNEES 
				COURANTE 
					JOURNAL 
				PRODUCTION 
					JOURNAL 
				ARCHIVE 
				TEMP 
				" ;;
			#Cas #04 : Demande de cancellation l'installation
			fin|3) echo "L'installation s'est bel et bien cancellée. Relancez le programme pour recommencer.
" 
			exit;;
			#Cas DEFAULT : La commande entrée est invalide
			*)echo "Choisissez un option valide. (1, 2 ou 3)
" ;;
		esac
	done

#Selon l'option choisie, confirmer d'avoir bien reçu celle-ci
if [ $optionChosen = "1" ]
then
	echo "Information bien reçue: Version Institutionnelle.
"
else
	echo "Information bien reçue: Version Industrielle.
"
fi

#Demander l'adresse du répertoire de base pour procéder à l'installation.
echo "Veuillez entrer l'adresse du répertoire de base afin d'effectuer l'installation ou tappez \"fin\" pour canceller l'installation et fermer le programme.
"
#Déclaration des variables
canCon=false
#Début de la boucle
while [ $canCon = false ]
do
	#Lire le chemin d'accès entré par l'utilisateur
	read res
	#Si celui-ci existe
	if [ -d "/home/smasson99/$res" ] && [ ! $res = "" ] && [ ! -d "/home/smasson99/$res/INSTITUT" ] && [ ! -d "/home/smasson99/$res/INDUSTR" ]
	then
		#Assigner variable en mémoire
		chosenPath="/home/smasson99/$res"
		echo "
Chemin entré valide."
		#Demander la confirmation
		echo "
Êtes-vous certain(e) de vouloir installer le répertoir de fichiers dans ce dossier de base : /home/smasson99/$res (O/N)?
"
		hasCon=false
		while [ $hasCon = false ]
		do
			#Lire la confirmation et gérer les cas
			read res
			case $res in
			O|o|oui|yes)hasCon=true canCon=true ;;
			N|n|non|no)hasCon=true canCon=false
			echo "
Veuillez entrer l'adresse du répertoire de base afin d'effectuer l'installation ou tappez \"fin\" pour canceller l'installation et fermer le programme.
" ;;
			fin|exit)exit ;;
			*)echo "Invalide, veuillez choisir entre \"O\" pour OUI et \"N\" pour NON." ;;
		esac
		done
	#Sinon si "fin" est l'entrée
	elif [ "$res" = "fin" ]
	then
		#Envoyer message de fin et fermer
		echo "L'installation s'est bel et bien cancellée. Relancez le programme pour recommencer.
"
		exit
	else
		echo "Le chemin d'accès est invalide ou il existe déjà une des version d'installées, veuillez vérifier l'information et recommencer ou désinstaller la version courante."
	fi

done

#Ici, nous avons la confirmation, le chemin d'accès et le format de répertoire à générer... GO!

#Mes variables (aide-mémoire)
#optionChosen	#Le format de répertoire
#chosenPath	#Mon chemin d'accès au dossier de base

#Si nous avons l'option #1
if [ "$optionChosen" = "1" ]
then
	echo "Création du répertoire Institutionnel...
"
	mkdir ${chosenPath}/INSTITUT
	mkdir ${chosenPath}/INSTITUT/PROGRAM
	mkdir ${chosenPath}/INSTITUT/PROGRAM/SYSTEME
	mkdir ${chosenPath}/INSTITUT/PROGRAM/SYSTEME/PILOTE
	mkdir ${chosenPath}/INSTITUT/PROGRAM/UTIL
	mkdir ${chosenPath}/INSTITUT/DONNEES
	mkdir ${chosenPath}/INSTITUT/DONNEES/COURANTE
	mkdir ${chosenPath}/INSTITUT/DONNEES/COURANTE/JOURNAL
	mkdir ${chosenPath}/INSTITUT/DONNEES/ARCHIVE
	mkdir ${chosenPath}/INSTITUT/DONNEES/TEMP
	
#Dans le cas contraire, il s'agit de l'option #2
else
	echo "Création du répertoire Industriel...
"
	mkdir ${chosenPath}/INDUSTR
	mkdir ${chosenPath}/INDUSTR/PROGRAM
	mkdir ${chosenPath}/INDUSTR/PROGRAM/SYSTEME
	mkdir ${chosenPath}/INDUSTR/PROGRAM/SYSTEME/PILOTE
	mkdir ${chosenPath}/INDUSTR/PROGRAM/UTIL
	mkdir ${chosenPath}/INDUSTR/DONNEES
	mkdir ${chosenPath}/INDUSTR/DONNEES/COURANTE
	mkdir ${chosenPath}/INDUSTR/DONNEES/COURANTE/JOURNAL
	mkdir ${chosenPath}/INDUSTR/DONNEES/PRODUCTION
	mkdir ${chosenPath}/INDUSTR/DONNEES/PRODUCTION/JOURNAL
	mkdir ${chosenPath}/INDUSTR/ARCHIVE
	mkdir ${chosenPath}/INDUSTR/TEMP
fi
#Création des répertoires terminée
echo "La création des répertoires s'est terminée avec franc succès.
"
#Afficher le menu des options après l'installation:
echo "L'installation étant terminée, vous avez l'option de supprimer des parties du répertoire selon vos besoins, désinstaller le répertoire ou vous pouvez simplement quitter le programme. Tappez le numéro d'une de ces options : 
"

canFinish=false
while [ $canFinish = false ]
do
	echo "1)Personnalisation/Suppression || 2)Désinstaller le répertoire || 3)Quitter le programme
"
	read res
	case $res in
		1)
		echo "Veuillez entrer l'adresse du dossier à supprimer dans le répertoire de base \"$chosenPath\" :"
		read resSup
		if [ -d "$chosenPath/$resSup" ]
		then
			echo "Adresse entrée valide."
			canDelete=false
			while [ $canDelete = false ]
			do
				echo "Souhaitez-vous vraiment supprimer le dossier: $chosenPath/$resSup (O/N) ?"
				read resDel
				case $resDel in
					o|O)canDelete=true
					rm -rf "$chosenPath/$resSup"
					;;
					n|N)canDelete=true ;;
					fin|exit)exit ;;
					*)echo "Erreur. Veuillez entrer \"O\" pour OUI ou \"N\" pour NON." ;;
				esac
			done
			echo "Suppression du dossier..."
			if [ ! -d "$chosenPath/$resSup" ]
			then
				echo "Dossier supprimé avec succès.
"
			else
				echo "Erreur. Le dossier : $chosenPath/$resSup n'a pas pu être supprimé. Vérifiez son accès ainsi qu'aucun contenu de celui-ci ne soit ouvert dans un autre programme.
"
			fi
		fi
		;;
		2)
		echo "Quelle version utilisez-vous ( 1)Institutionnelle || 2)Industrielle ) ?"
		read resVer
		if [ "$resVer" = "1" ] || [ "$resVer" = "2" ]
		then
			canDelete=false
			while [ $canDelete = false ]
			do
				echo "Souhaitez-vous vraiment supprimer votre version (O/N) ?"
				read resDel
				case $resDel in
					o|O)canDelete=true
					case $resVer in
						1)rm -rf "$chosenPath/INSTITUT"
						chosen="INSTITUT" ;;
						2)rm -rf "$chosenPath/INDUSTR"
						chosen="INDUSTR" ;;
					esac
					echo "Suppression du dossier..."
					if [ ! -d "$chosenPath/$chosen" ]
					then
						echo "Dossier supprimé avec succès.
"
					else
						echo "Erreur. Le dossier : $chosenPath/$chosen n'a pas pu être supprimé. Vérifiez son accès ainsi qu'aucun contenu de celui-ci ne soit ouvert dans un autre programme."
					fi
					;;
					n|N)canDelete=true ;;
					fin|exit)exit ;;
					*)echo "Erreur. Veuillez entrer \"O\" pour OUI ou \"N\" pour NON." ;;
				esac
			done
		elif [ "$res" = "fin" ]
		then
			exit
		else
			echo "Veuillez entrer le numéro d'une des options disponibles."
		fi
		;;
		3|fin)exit ;;
		*)echo "Erreur. Entrez un chiffre de 1 à 3 en guise de réponse.
" ;;
	esac
done
