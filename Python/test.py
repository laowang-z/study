class Solution:
    def __init__(self, h_map, w) -> None:
        self.result = 0
        self.position = 0
        self.h_map = h_map
        self.w = w
        self.map_w = len(h_map)
    
    def func(self, h, start_p):
        self.position += 1
        curr_h = self.h_map[self.position]
        new_start_p = -1
        while curr_h <= h and self.position < self.map_w:
            curr_h = self.h_map[self.position]
            if curr_h == h:
                self.position += 1
            elif curr_h < h:
                if new_start_p == -1:
                    new_start_p = self.position
                self.func(curr_h, new_start_p)
            else:
                break
        self.result += (self.position - start_p) // self.w
        return
    
    def main(self):
        while self.position < self.map_w:
            if self.h_map[self.position] >= 0:
                self.position += 1
                continue
            self.func(self.h_map[self.position], self.position)
        return self.result
        
maps = [[0, -1, -2, -2],[0, 1, -2, -5, -3, -5, -5, -2], [-4, -5, -5, 0, -4, -4]]

for one_map in maps:
    sol = Solution(one_map, 2)
    result = sol.main()
    
print("-"*20, 'END', '-'* 20)