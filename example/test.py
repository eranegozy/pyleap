# simple test app for pyleap.
# if hand is detected, show graphical representation of hand x-position using ASCII art

import sys, os
sys.path.insert(0, os.path.abspath('..'))

from time import sleep
import numpy as np

from pyleap.leap import getLeapInfo, getLeapFrame


while True:
    # get new data each frame
    info = getLeapInfo()
    hand = getLeapFrame().hands[0]
    hand_x = hand.palm_pos[0]

    # status text
    status = 'service:{} connected:{} focus:{}  '.format(*[('NO ', 'YES')[x] for x in info])

    # create ascii art for hand position
    txt_len = 30
    pos = int(np.interp(hand_x, [-200, 200], [0, txt_len - 1]))
    hand_txt = ['.'] * txt_len
    if hand.id != -1:
        hand_txt[pos] = 'x'
    hand_txt = ''.join(hand_txt)

    print(status + hand_txt, end='\r', flush=True)
    sleep(0.01)
