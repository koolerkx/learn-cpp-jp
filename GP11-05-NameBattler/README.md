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

## ŠjS—VE—Ş•Ê

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

## Dé¦Œn“—Ş•Ê

### `Battle`
- Battle round
- Draw dice
- calculate multiply to base ability

### `Card`
- Abstract class for card
- `AttackCard`
- `HealCard`
- `DefenseCard`

## ›‰—pH‹ï˜ax‰‡—Ş•Ê

- `exception.h`
- `utils.h`
