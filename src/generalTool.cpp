#include "generalTool.h"

generalTool::generalTool(int x_pos, int y_pos, bool white) : _x(x_pos), _y(y_pos), _isWhite(white) {}

generalTool::~generalTool() {}

int generalTool::getX() { return _x; }

int generalTool::getY() { return _y; }

bool generalTool::isWhite() { return isWhite; }

void generalTool::setPosition(int x_pos, int y_pos) { _x = x_pos; _y = y_pos; }