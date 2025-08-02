---

kanban-plugin: board

---

## TODO

- [ ] Chess AI
	- [ ] some library where you feed board it gives you best move. convert that to our format
	- [ ] after player moves ai make move
- [ ] 2 Player
	- [ ] after one player makes a move other player can make a move
- [ ] Game Over
	- [ ] call someone a loser and have reset button
- [ ] Menu
	- [ ] AI
	- [ ] 2 Player
	- [ ] Difficulty? maybe out of scope
	- [ ] Basic settings?
	- [ ] customization settings like style or sound etc


## In Progress

- [ ] All Pieces
	- [ ] pawn
	- [x] bishop ✅ 2025-08-02
	- [ ] castle
	- [ ] queen
	- [ ] king


## Done

- [ ] Chess Pieces
	- [x] piece super class ✅ 2025-08-01
	- [x] where it can move function ✅ 2025-08-02
	- [x] move function ✅ 2025-08-02
	- [x] die function ✅ 2025-08-02
	- [x] subclass for each piece type ✅ 2025-08-02
	- [x] display ✅ 2025-08-02
	- [x] select function (who is selecting, ie if other player selects just show where can move) ✅ 2025-08-02
	- [x] clicked after select ✅ 2025-08-02
- [ ] Chess Board
	- [x] display board ✅ 2025-07-31
	- [x] get the board left aligned, centered vertically ✅ 2025-08-01
	- [x] piece class with what piece is in each square ✅ 2025-08-01
	- [x] call function of class based on where mouse is (ie mx / 10 % 50 = i in 2d array) ✅ 2025-08-01
	- [x] call select function, then clicked ✅ 2025-08-01
	- [x] init pieces on board ✅ 2025-08-02
- [ ] Get Basic OpenGL Project Working
	- [x] window ✅ 2025-07-31
	- [x] fps ✅ 2025-07-31




%% kanban:settings
```
{"kanban-plugin":"board","list-collapse":[false,false,false]}
```
%%