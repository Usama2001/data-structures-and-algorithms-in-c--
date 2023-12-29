import tkinter
import random
import colors 



class Game (tkinter.Frame): # this is the main class of game 
    def __init__(self):
        tkinter.Frame.__init__(self)
        self.grid()
        self.master.title('2048')

        self.main_grid = tkinter.Frame(
            self, bg=colors.GC, bd=10, width=2, height=2)
        self.main_grid.grid(pady=(120, 0))
        self.GUI()
        self.initial()

        self.master.bind("<Left>", self.left)
        self.master.bind("<Right>", self.right)
        self.master.bind("<Up>", self.up)
        self.master.bind("<Down>", self.down)

        self.mainloop()


    def GUI(self):# This function make grid of 4 by 4 
        self.cells = []
        for i in range(4):
            row = []
            for j in range(4):
                cell_frame = tkinter.Frame(
                                          self.main_grid,
                                          bg=colors.ECC,
                                          width=120,
                                          height=120)
                cell_frame.grid(row=i, 
                                column=j, 
                                padx=2,
                                pady=2)
                cell_number = tkinter.Label(self.main_grid, bg=colors.ECC)
                cell_number.grid(row=i,
                                 column=j)
                cell_data = {"frame": cell_frame, 
                             "number": cell_number}
                row.append(cell_data)
            self.cells.append(row)

        # make score header
        score_frame = tkinter.Frame(self)
        score_frame.place(relx=0.5,
                          y=60, 
                          anchor="center")
        tkinter.Label(
            score_frame,
            text="Score",
            font=colors.SCORE_LABEL_FONT).grid(row=0)
        self.score_label = tkinter.Label(score_frame,
                                         text="0", 
                                         font=colors.SCORE_FONT)
        self.score_label.grid(row=1)


    def initial(self):    #This function  create 4 dimensional array  of 0 
        self.list = [[0] * 4 for _ in range(4)]

        row = random.randint(0, 3) # fill 2 random cells with 2s
        col = random.randint(0, 3)
        self.list[row][col] = 2
        self.cells[row][col]["frame"].configure(bg=colors.CELL_COLORS[2])
        self.cells[row][col]["number"].configure(
            bg=colors.CELL_COLORS[2],
            fg=colors.CELL_NUMBER_COLORS[2],
            font=colors.CELL_NUMBER_FONTS[2],
            text="2")
        while(self.list[row][col] != 0):
            row = random.randint(0, 3)
            col = random.randint(0, 3)
        self.list[row][col] = 2
        self.cells[row][col]["frame"].configure(bg=colors.CELL_COLORS[2])
        self.cells[row][col]["number"].configure(
            bg=colors.CELL_COLORS[2],
            fg=colors.CELL_NUMBER_COLORS[2],
            font=colors.CELL_NUMBER_FONTS[2],
            text="2")

        self.score = 0


    
    def stack(self):   # this function compress all non zero numbers   
        list1 = [[0] * 4 for _ in range(4)]
        for i in range(4):
            a = 0
            for j in range(4):
                if self.list[i][j] != 0:
                    list1[i][a] = self.list[i][j]
                    a += 1
        self.list = list1


    def combine(self): # This function combine same number if possible  
        for i in range(4):
            for j in range(3):
                if self.list[i][j] != 0 and self.list[i][j] == self.list[i][j + 1]:
                    self.list[i][j] *= 2
                    self.list[i][j + 1] = 0
                    self.score += self.list[i][j]


    def reverse(self): # This function reverse the oder of each row in 4 dimensional array  
        list1 = []
        for i in range(4):
            list1.append([])
            for j in range(4):
                list1[i].append(self.list[i][3 - j])
        self.list = list1


    def transpose(self): # This function return the transpose of 4 dimensional array 
        list1 = [[0] * 4 for _ in range(4)]
        for i in range(4):
            for j in range(4):
                list1[i][j] = self.list[j][i]
        self.list = list1


    
    
    def add_tile(self): # This function add 2 or 4 tile randomly to an empty cell
        row = random.randint(0, 3)
        col = random.randint(0, 3)
        while(self.list[row][col] != 0):
            row = random.randint(0, 3)
            col = random.randint(0, 3)
        self.list[row][col] = random.choice([2, 4])


    
    def new_GUI(self):  # This function update the GUI to match the list
        for i in range(4):
            for j in range(4):
                cell_value = self.list[i][j]
                if cell_value == 0:
                    self.cells[i][j]["frame"].configure(bg=colors.ECC)
                    self.cells[i][j]["number"].configure(
                        bg=colors.ECC, text="")
                else:
                    self.cells[i][j]["frame"].configure(
                        bg=colors.CELL_COLORS[cell_value])
                    self.cells[i][j]["number"].configure(
                        bg=colors.CELL_COLORS[cell_value],
                        fg=colors.CELL_NUMBER_COLORS[cell_value],
                        font=colors.CELL_NUMBER_FONTS[cell_value],
                        text=str(cell_value))
        self.score_label.configure(text=self.score)
        self.update_idletasks()


    # these functions control the each press of buttons

    def left(self, event):
        self.stack()
        self.combine()
        self.stack()
        self.add_tile()
        self.new_GUI()
        self.game_over()


    def right(self, event):
        self.reverse()
        self.stack()
        self.combine()
        self.stack()
        self.reverse()
        self.add_tile()
        self.new_GUI()
        self.game_over()


    def up(self, event):
        self.transpose()
        self.stack()
        self.combine()
        self.stack()
        self.transpose()
        self.add_tile()
        self.new_GUI()
        self.game_over()


    def down(self, event):
        self.transpose()
        self.reverse()
        self.stack()
        self.combine()
        self.stack()
        self.reverse()
        self.transpose()
        self.add_tile()
        self.new_GUI()
        self.game_over()


    

    def game_over(self):   # this function check Game is Over 
        if any(2048 in row for row in self.list):
            game_over_frame = tkinter.Frame(self.main_grid, borderwidth=2)
            game_over_frame.place(relx=0.5, rely=0.5, anchor="center")
            tkinter.Label(
                game_over_frame,
                text="You win!",
                bg=colors.WINNER_BG,
                fg=colors.GAME_OVER_FONT_COLOR,
                font=colors.GAME_OVER_FONT).pack()
        elif not any(0 in row for row in self.list) and not self.horizontal_move() and not self.vertical_move():
            game_over_frame = tkinter.Frame(self.main_grid, borderwidth=2)
            game_over_frame.place(relx=0.5, rely=0.5, anchor="center")
            tkinter.Label(
                game_over_frame,
                text="Game over!",
                bg=colors.LOSER_BG,
                fg=colors.GAME_OVER_FONT_COLOR,
                font=colors.GAME_OVER_FONT).pack()
 

    def horizontal_move(self): #  this function check the possibility of move 
        for i in range(4):
            for j in range(3):
                if self.list[i][j] == self.list[i][j + 1]:
                    return True
        return False


    def vertical_move(self):  #  this function check the possibility of move
        for i in range(3):
            for j in range(4):
                if self.list[i][j] == self.list[i + 1][j]:
                    return True
        return False


def main():
    Game()

if __name__ == "__main__":
    main()


