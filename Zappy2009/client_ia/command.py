import random

def check_cmd():
    r = random.randint(0, 5)
    tabcmd = ["avance\n", "gauche\n", "droite\n", "inventaire\n", "voir\n", "prend nourriture\n"]
    return tabcmd[r]
