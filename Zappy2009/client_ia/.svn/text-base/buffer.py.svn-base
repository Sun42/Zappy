import brain
import command
import treat_command

def buf_recv(trantor, data):
    trantor['recv'] += data
    if trantor['recv'].count('\n') > 0:
        i = trantor['recv'].index('\n')
        try:
            treat_command.treat_cmd(trantor, trantor['recv'][:i], trantor['actions'])
        except:
            print '<<< Error : BUF_REC >>>'
        i += 1
        trantor['recv'] = trantor['recv'][i:]


def send_buffer(trantor):
    brain.brain_all(trantor)
    try:
        try:
            i = int(trantor['actions']['valid'][-1])
        except:
            i = 1
        if (i != 1):
            line = trantor['actions']['send'][-1]
            sended_size = trantor['server'].send(line)
            trantor['actions']['valid'][-1] = 1
            if (sended_size != len(line)):
               print "Commande reelle ", trantor['actions']['send'][-1][:sended_size]
               trantor['actions']['send'][-1] = trantor['actions']['send'][-1][sended_size:]
    except:
        print '<<< Error : BUF_SEND >>>'
        print 'Derniere commande recu :', trantor['recv']
        print 'Commandes envoyes :', trantor['actions']['send']
        return 0
    return 1
