import treat_command
import fct_brain
import param
import move

def brain_all(trantor):
    trantor['cpt_action'] = int(trantor['cpt_action']) + 1
    if int(trantor['transformation']) == 1:
        return 0
    try :
        nb_actions = len(trantor['actions']['send'])
    except:
        nb_actions = 0
    if nb_actions > 1:
        return 0
    else:
        if (int(trantor['cpt_action']) == 4):
            trantor['cpt_action'] = 0
            fct_brain.fct_inventaire(trantor)
        elif trantor['bag']['nourriture'] < (5 * 126):
            famine(trantor)
        else:
            quest(trantor)


def quest(trantor):
    print "Quest"
    if fct_brain.fct_can_lvlup(trantor) == 1:
        fct_brain.fct_incantation(trantor)
    else:
        if trantor['vision'] == []:
            fct_brain.fct_see(trantor)
        else:
            if fct_brain.fct_can_take_obj(trantor) > 0:
                fct_brain.fct_take_case(trantor)
            else:
                if fct_brain.fct_move_all(trantor, 'linemate') == -1:
                    move.fct_dunno(trantor)

def famine(trantor):
    print "Famine !!"
    nb_food = fct_brain.fct_find_food(trantor)
    if trantor['vision'] == []:
        fct_brain.fct_see(trantor)
    elif (nb_food > 0):
        fct_brain.fct_take_food(trantor, nb_food)
        trantor['vision'] = []
    else:
        if fct_brain.fct_move_all(trantor, 'nourriture') == -1:
            move.fct_dunno(trantor)

