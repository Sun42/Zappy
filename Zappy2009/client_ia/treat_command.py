import re

def rcv_inventaire(trantor, commande, action):
	try:
		commande = commande.replace(","," ")
		commande = commande.replace("  "," ")
		tabinvent = commande.split(" ")
		trantor['bag']['nourriture'] = (int(tabinvent[1]) * 126) - 1
		trantor['bag']['linemate'] = tabinvent[3]
		trantor['bag']['deraumere'] = tabinvent[5]
		trantor['bag']['sibur'] = tabinvent[7]
		trantor['bag']['mendiane'] = tabinvent[9]
		trantor['bag']['phiras'] = tabinvent[11]
		trantor['bag']['thystame'] = tabinvent[13][0]
		action['send'].pop()
		action['valid'].pop()
	except:
		print '%%% Error inventaire'


def rcv_take(trantor, commande , action):
	trantor['bag']['nourriture'] =  int(trantor['bag']['nourriture']) - 7
	if commande == "ok":
		try:
			save = action['send'][-1].split(" ")
			save2 = save[1].rstrip("\n")
			trantor['bag'][save2] = int(trantor['bag'][save2]) + 1
		except:
			print "%%% Error Nom objet invalide"
	action['send'].pop()
	action['valid'].pop()


def rcv_pose(trantor, commande ,action):
	trantor['bag']['nourriture'] =  int(trantor['bag']['nourriture']) - 7
	if commande == "ok":
		try:
			save = action['send'][-1].split(" ")
			save2 = save[1].rstrip("\n")
			trantor['bag'][save2] = int(trantor['bag'][save2]) - 1
		except:
			print "%%% Error Nom objet invalide"
	action['send'].pop()
	action['valid'].pop()


def rcv_avance(trantor,commande ,action):
	print "jai avance"
	trantor['bag']['nourriture'] =  int(trantor['bag']['nourriture']) - 7
	trantor['vision'] = []
	action['send'].pop()
	action['valid'].pop()



def rcv_left(trantor,commande ,action):
	print "J'ai tourne a gauche"
	trantor['bag']['nourriture'] = int(trantor['bag']['nourriture']) - 7
	trantor['vision'] = []
	action['send'].pop()
	action['valid'].pop()



def rcv_right(trantor,commande ,action):
	print "J'ai tourne a droite"
	trantor['bag']['nourriture'] =  int(trantor['bag']['nourriture']) - 7
	trantor['vision'] = []
	action['send'].pop()
	action['valid'].pop()



def rcv_elevation(trantor,commande ,action):
	trantor['bag']['nourriture'] =  int(trantor['bag']['nourriture']) - 300
	if commande != 'ko':
		print "Je debute l'incantation"
		trantor['transformation'] = 1
	else:
		print "J'ai fail l'incantation"
	trantor['actions']['send'].insert(0, 'avance\n')
	trantor['actions']['valid'].insert(0, 0)


def rcv_fin_elevation(trantor, commande, action):
	print "Jai fini d'incanter"
	trantor['transformation'] = 0
	action['send'].pop()
	action['valid'].pop()
	Py_Exit(0)

def rcv_voir(trantor, commande, action):
	print "Jai vu"
	trantor['vision'] = commande
	trantor['bag']['nourriture'] =  int(trantor['bag']['nourriture']) - 7
	action['send'].pop()
	action['valid'].pop()

def rcv_else(trantor, commande, action):
	i = 1


def rcv_fork(trantor, commande, action):
	trantor['bag']['nourriture'] = int(trantor['bag']['nourriture']) - 42
	if commande == 'ok':
		trantor['fork'] = 1
	action['send'].pop()
	action['valid'].pop()


def treat_cmd(trantor, commande, action):
	tabcmd = [rcv_inventaire, rcv_voir, rcv_fork, rcv_avance, \
			  rcv_take, rcv_pose, rcv_elevation, \
			  rcv_fin_elevation, rcv_left, rcv_right, rcv_else]
	try:
		lastcmd = action['send'][-1]
		indice = get_icmd(commande, action)
		if indice  != -1:
			tabcmd[indice](trantor, commande, action)
	except:
		print ""
def get_icmd(commande, action):
	if action['send'][-1] == 'inventaire\n':
		if commande[0] == '{' and commande[1] != ' ':
			print "inventaire recu"
			return 0
		else:
			return 8
	elif action['send'][-1] == 'voir\n':
		if commande[0] == '{' and commande[1] == ' ':
			return 1
		else:
			return 8
	elif action['send'][-1] == 'fork\n':
		if commande == 'ko' or commande == 'ok':
			return 2
		else:
			return 8
	elif action['send'][-1] == 'avance\n':
		if commande == 'ko' or commande == 'ok':
			return 3
		else:
			return 8
	elif action['send'][-1] == 'gauche\n':
		if commande == 'ko' or commande == 'ok':
			return 8
	elif action['send'][-1] == 'droite\n':
		if commande == 'ko' or commande == 'ok':
			return 9
		else:
			return 8
	elif re.match("^prend ", action['send'][-1]):
		if commande == "ko" or commande == "ok":
			return 4
		else:
			return 8
	elif re.match("^pose ", action['send'][-1]):
		if commande == "ko" or commande == "ok":
			return 5
		else:
			return 8
	elif action['send'][-1] == 'incantation\n':
		if commande == "ko" or commande == "elevation en cours":
			return 6
		else:
			return 8
	elif re.match("^niveau actuel"):
		return 7
	else:
		return 8
