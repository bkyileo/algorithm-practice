__author__ = 'BK'
class coder:
    def __init__(self):
        pass

    def say(self, message):
        print message
########################## Background###########################################
class PoorCoder(coder):
    def __init__(self):
        self.money = 0

    def get_money(self):
        print self.money


class RichCoder(coder):
    def __init__(self):
        self.money = max

    def get_money(self):
        print self.money
if __name__ == '__main__':
    poor_coder = PoorCoder()
    rich_coder = RichCoder()

    poor_coder.say('borrow me some money!')  # £¨¡¥¦ê¡¥£©
    rich_coder.say('how much?  ')  # (£þ¦Å(#£þ)¡î¨t¨ro(£þÃó£þ///)
    poor_coder.say('how about 1000? ')  # (¡ã©`¡ã¡¨)
    rich_coder.say('make up a round number!')  # o(Ò»¦äÒ»+)o
############################   next day   #######################################


    poor_coder.money = 1024  # (^V^) wish u happy everyday~!!!!!
