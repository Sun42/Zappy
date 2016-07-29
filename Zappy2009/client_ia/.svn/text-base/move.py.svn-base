import param
import random

def fct_dunno(trantor):
    i = random.randint(0, 3)
    if i == 0:
        fct_avance(trantor)
    if i == 1:
         fct_left(trantor)
    if i == 2:
        fct_right(trantor)
    if i == 3:
        fct_avance(trantor)

def fct_avance(trantor):
    trantor['actions']['send'].insert(0, 'avance\n')
    trantor['actions']['valid'].insert(0, 0)

def fct_left(trantor):
    trantor['actions']['send'].insert(0, 'gauche\n')
    trantor['actions']['valid'].insert(0, 0)

def fct_right(trantor):
    trantor['actions']['send'].insert(0, 'droite\n')
    trantor['actions']['valid'].insert(0, 0)

