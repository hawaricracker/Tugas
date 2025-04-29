from game.logic.base import BaseLogic
from game.models import GameObject, Board, Position

class HCLBot(BaseLogic):
    def __init__(self):
        pass

    def get_obj_pos(self, board: Board):
        self.diamonds = []
        self.bots = []
        self.teleport = []

        for obj in board.game_objects:
            if obj.type == "DiamondGameObject" or obj.type == "DiamondButtonGameObject":
                self.diamonds.append(obj)
            elif obj.type == "BotGameObject":
                self.bots.append(obj)
            elif obj.type == "TeleportGameObject":
                self.teleport.append(obj)
    
    def calculate_distance(self,x1,y1,x2,y2) -> float:
        return ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
    
    def check_enemy(self,board_bot: GameObject, board: Board) -> tuple[Position, bool]:
        for bot in self.bots:
            if bot.id != board_bot.id and self.calculate_distance(board_bot.position.x, board_bot.position.y, bot.position.x, bot.position.y) < 2:
                return bot.position, True
        return bot.position, False

    def next_move(self, board_bot: GameObject, board: Board):
        self.get_obj_pos(board)
        min_dist = float('inf')
        goals_pos = self.diamonds[0]
        if board_bot.properties.diamonds == board_bot.properties.inventory_size:
            if self.check_enemy(board_bot, board)[1]:
                goals_pos = self.check_enemy(board_bot, board)[0]
            else:
                goals_pos = board_bot.properties.base
        else:
            inventory_space = board_bot.properties.inventory_size - board_bot.properties.diamonds
            for d in self.diamonds:
                if self.check_enemy(board_bot, board)[1]:
                    goals_pos = self.check_enemy(board_bot, board)[0]
                elif self.calculate_distance(board_bot.position.x, board_bot.position.y, d.position.x, d.position.y) < min_dist:
                    point = d.properties.points or 0
                    if point <= inventory_space:
                        goals_pos = d.position
                        min_dist = self.calculate_distance(board_bot.position.x, board_bot.position.y, d.position.x, d.position.y)
        
        if(board_bot.position.x > goals_pos.x):
            delta_x = -1
            delta_y = 0
        elif(board_bot.position.x < goals_pos.x):
            delta_x = 1
            delta_y = 0
        elif(board_bot.position.y > goals_pos.y):
            delta_x = 0
            delta_y = -1
        else:
            delta_x = 0
            delta_y = 1

        return delta_x, delta_y
