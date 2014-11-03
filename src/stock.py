'''
'''

def best_profit(spy):
  print "incoming: ", spy
  if len(spy) == 1:
    return 0
  else:
    spy = sorted(spy, key=itemgetter(1))
    print "sorted: ", spy
    return spy[len(spy)-1][1] - spy[0][1]

import unittest
from operator import itemgetter


class TestSequenceFunctions(unittest.TestCase):

    def setUp(self):
        self.spy = {0:10, 1:12, 2:10, 3:15, 4:20}
        self.spy = sorted(self.spy.items(), key=itemgetter(0))
        
    def test_only_one(self):
        prices = self.spy[:1]
        self.assertEqual(best_profit(prices), 0)
    
    def test_only_two(self):
        prices = self.spy[:2]
        self.assertEqual(best_profit(prices), 2)
    
    def test_only_three(self):
        prices = self.spy[:3]
        self.assertEqual(best_profit(prices), 2)



if __name__ == '__main__':
    unittest.main()
    
'''
    def test_choice(self):
        element = random.choice(self.seq)
        self.assertTrue(element in self.seq)

    def test_sample(self):
        with self.assertRaises(ValueError):
            random.sample(self.seq, 20)
        for element in random.sample(self.seq, 5):
            self.assertTrue(element in self.seq)

'''
