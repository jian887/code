from  tkinter import *
class App(Frame):
    def __init__(self,master=None):
        Frame.__init__(self,master)
        self.pack()
        self.createWindows()

    def createWindows(self):
        self.hLabel = Label(self,None,"hello world")
        self.hLabel.pack()
        self.qButton = Button(self,text="quit",command=self.quit())
        self.qButton.pack()


ap = App()
ap.master.title("hello")
ap.mainloop()