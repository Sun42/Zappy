def fct_calc_view_level(num_case, level_case = 0, i = 1):
    max_level_case = i * (i + 2)
    if (num_case > level_case and num_case < max_level_case):
        return i
    fct_calc_view_level(num_case, max_level_case, i + 1)

def fct_calc_view_mid(num_case, lvl):
    max_num_in_lvl = lvl * (lvl + 2)
    lvl -= 1;
    nb_case_in_lvl = max_num_in_lvl - lvl * (lvl + 2)
    mid_num_in_lvl = max_case_in_lvl - (nb_case_in_lvl / 2)
    return num_case - mid_num_in_lvl
