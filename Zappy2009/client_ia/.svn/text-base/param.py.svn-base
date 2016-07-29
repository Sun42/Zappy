time_command = dict(avance = 7, droite = 7, gauche = 7, voir = 7, \
                        prend = 7, pose = 7, expulse = 7, broadcast = 7, \
                        inventaire = 1, fork = 42, incantation = 300)

tab_command = ["avance\n", "droite\n", "gauche\n", "voir\n", \
                   "prend ", "pose ", "expulse\n", "broadcast ", \
                   "inventaire\n", "fork\n", "incantation\n"]


tab_object = ["linemate\n", "deraumere\n", "sibur\n", "mendiane\n", \
              "phiras\n", "thystame\n", "nourriture\n"]


def init_bag():
    bag = dict(nourriture = 0, linemate = 0, deraumere = 0, sibur = 0, mendiane = 0, \
               phiras = 0, thystame = 0)
    return bag


def init_trantor(team, server):
    trantor = {}
    trantor['server'] = server
    bag = init_bag()
    trantor['bag'] = bag
    trantor['level'] = 1
    trantor['fork'] = 0
    trantor['team'] = team
    trantor['vision'] = []
    trantor['actions'] = dict(send = [], valid = [])
    trantor['recv'] = ''
    trantor['transformation'] = 0
    trantor['cpt_action'] = 3
    return trantor
