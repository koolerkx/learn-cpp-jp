# NameBattler

## roadmap
- refactor
  - battle class
  - game flow
- feature
  - level
  - battle tower
  - ability balancing
  - money

## �j�S�V�E�ޕ�

### `GameManager`
- Singleton
- Game Entry
- Game loop
- Main menu
- Save Data S/L

### `Hero`
- Used for battle
- Ability random
- Card random
- Random seed by name

### `PlayerHero` / `PlayerHeroAI`
- Hero used for battle
- With battle statue
  - HP
  - Shield
  - Attack
- interact with card

## �D馌n���ޕ�

### `Battle`
- Battle round
- Draw dice
- calculate multiply to base ability

### `Card`
- Abstract class for card
- `AttackCard`
- `HealCard`
- `DefenseCard`

## ���p�H��a�x���ޕ�

- `exception.h`
- `utils.h`
