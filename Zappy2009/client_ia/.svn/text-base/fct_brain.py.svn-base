import treat_command
import move
import param


def fct_see(trantor):
    trantor['actions']['send'].insert(0, param.tab_command[3])
    trantor['actions']['valid'].insert(0, 0)


def fct_fork(trantor):
    trantor['actions']['send'].insert(0, param.tab_command[9])
    trantor['actions']['valid'].insert(0, 0)


def fct_inventaire(trantor):
    trantor['actions']['send'].insert(0, param.tab_command[8])
    trantor['actions']['valid'].insert(0, 0)


def fct_incantation(trantor):
    if trantor['level'] == 1:
        trantor['actions']['send'].insert(0, param.tab_command[5] + 'linemate\n')
        trantor['actions']['send'].insert(0, param.tab_command[10])
        trantor['actions']['valid'].insert(0, 0)
        trantor['actions']['valid'].insert(0, 0)


def fct_take_food(trantor, nbfood):
    while nbfood > 0:
        var = param.tab_command[4] + param.tab_object[6]
        trantor['actions']['send'].insert(0, var)
        trantor['actions']['valid'].insert(0, 0)
        nbfood -= 1


#retourne le nombre d'objet sur la case 0
def fct_see_nb_obj(trantor, obj):
    print "je cherche sur ma case ->", obj
    try:
        commande = trantor['vision'].replace("{ ","")
        commande = commande.replace(" }", "")
        tabvision = commande.split(',')
        nb_obj = tabvision[0].count(obj)
        return nb_obj
    except :
        return 0

# verifie si le trantor dispose des objets requis pour un level
def fct_can_lvlup(trantor):
    if trantor['level'] == 1:
        if int(trantor['bag']['linemate']) >= 1:
            return 1
        else:
            return 0
    return 0

def fct_find_food(trantor):
    try:
        commande = trantor['vision'].replace("{ ","")
        commande = commande.replace(" }", "")
        tabvision = commande.split(',')
        nb_food = tabvision[0].count('nourriture')
        return nb_food
    except:
        return 0


# return nb ressources linemate ou food
def fct_can_take_obj(trantor):
    try:
        commande = trantor['vision'].replace("{ ","")
        commande = commande.replace(" }", "")
        tabvision = commande.split(',')
        nb_obj = tabvision[0].count(' ') + 1
        case = tabvision[0].split(' ')
        cpt = 0
        while nb_obj > 0:
            if case[nb_obj - 1] != 'joueur' and (case[nb_obj - 1] == 'linemate' or case[nb_obj - 1] == 'nourriture'):
                cpt += 1
            nb_obj =  nb_obj - 1
        return cpt
    except:
        return 0

#rafle toutes les ressources sur la case
def fct_take_case(trantor):
    print "Vidage de la case"
    try:
        commande = trantor['vision'].replace("{ ","")
        commande = commande.replace(" }", "")
        tabvision = commande.split(',')
        nb_obj = tabvision[0].count(' ') + 1
        case = tabvision[0].split(' ')
        while nb_obj > 0:
            mycase = case[nb_obj - 1].replace(' ', '')
            if mycase != 'joueur':
                save = 'prend ' + mycase + '\n'
                trantor['actions']['send'].insert(0, save)
                trantor['actions']['valid'].insert(0, 0)
            nb_obj =  nb_obj - 1
            trantor['vision'] = []
    except:
        print "error find obj"

# return la case ou se trouve l'objet obj, sinon -1
def fct_calc_num_case(trantor, obj):
    try:
        commande = trantor['vision'].replace("{ ","")
        commande = commande.replace(" }", "")
        max = commande.count(',') + 1
        tabvision = commande.split(',')
        i = 0
        while i < max:
            j = 0
            nb_obj = tabvision[i].count(' ') + 1
            elem = tabvision[i].split(' ')
            while j < nb_obj:
                if elem[j][:len(obj)] == obj:
                    return i
                j += 1
            i += 1
        return -1
    except:
        return -1


def fct_move_all(trantor, obj):
    num_case = fct_calc_num_case(trantor, obj)
    if num_case == -1:
        print "J'ai pas trouve  dans ma vision de", obj
        return -1
    else:
        print "J'ai trouve  dans ma vision  des " , obj
        if (int(num_case) < 4) and (int(num_case) > 0):
            move.fct_avance(trantor)
            if (int(num_case) % 2 != 0):
                if num_case < 2:
                    move.fct_left(trantor)
                    move.fct_avance(trantor)
                else:
                    move.fct_right(trantor)
                    move.fct_avance(trantor)
    fct_take_case(trantor)

