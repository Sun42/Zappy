import sys

def verif_args():
    if len(sys.argv) != 7 and len(sys.argv) != 5:
        print 'usage : ./client -n nom_equipe -p port -h nom_machine'
        return '', '', ''
    else:
        i = 1
        host = team = ''
        port = ''
        while i < len(sys.argv):
            if sys.argv[i] == '-n' and team == '':
                i += 1
                team = sys.argv[i]
            else:
                if sys.argv[i] == "-p" and port == '':
                    i += 1
                    port = sys.argv[i]
                else:
                    if sys.argv[i] == "-h" and host == '':
                        i += 1
                        host = sys.argv[i]
                    else:
                        print 'Arguments incorrect'
                        break
            i += 1
        if host == '':
            host = 'localhost'
            if port == '':
                print 'Port inconnu'
                if team == '':
                    print 'Nom equipe inconnu'
        return team, host, port
