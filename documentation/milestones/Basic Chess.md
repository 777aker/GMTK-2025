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

- [ ] Chess Board
	- [x] display board ✅ 2025-07-31
	- [ ] get the board left aligned, centered vertically
	- [ ] piece class with what piece is in each square
	- [ ] call function of class based on where mouse is (ie mx / 10 % 50 = i in 2d array)
	- [ ] call select function, then clicked
- [ ] Chess Pieces
	- [ ] piece super class
	- [ ] where it can move function
	- [ ] move function
	- [ ] die function
	- [ ] subclass for each piece type
	- [ ] display
	- [ ] select function (who is selecting, ie if other player selects just show where can move)
	- [ ] clicked after select


## Done

- [ ] Get Basic OpenGL Project Working
	- [x] window ✅ 2025-07-31
	- [x] fps ✅ 2025-07-31




%% kanban:settings
```
{"kanban-plugin":"board","list-collapse":[false,false,false]}
```
%%