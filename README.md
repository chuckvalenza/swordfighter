# Swordfighter

[![Travis](https://img.shields.io/badge/latest%20release-v0.02-brightgreen.svg)](https://github.com/chuckvalenza/swordfighter/releases/tag/v0.01)

A simple top-down Android game about slashing your way out of problems.
Currently a work in progress...pre-alpha with no releases yet.

For the most up-to-date version, checkout the 'dev' branch.

## Release Roadmap

### v0.01 - Movement and basic world creation

- [x] Splash screen
- [x] React-native main menu which starts GameActivity
- [x] On-screen joystick and quick-inventory controls
- [x] Rigid base class
- [x] Physics on rigids and not units
- [x] Unit base class
- [x] Player
- [x] World composed of chunks
- [x] Player movement in world
- [x] Training dummy unit
- [x] Basic Collision between units

### v0.02 - Combat

- [x] Slash attack
- [x] Punch attack
- [x] Change attack animation depending on weildable type
- [x] Physics detection of attacks
- [x] Enemy damage

### v0.03 - Basic enemy AI

- [ ] Enemies move in 1 direction and then reverse direction (back-and-forth patrolling with nothing else)
- [ ] Enemies move toward player when provoked
- [ ] Enemies attack player when close enough
- [ ] Enemies can sense player without provocation if player is close enough and they are looking in the player's direction
- [ ] Enemies can sense player without provocation if player is close enough and moving quickly enough (they hear the player)

### v0.04 - Projectiles

- [ ] Projectile weapon for the player
- [ ] Projectile weapon for the enemy

### v0.05 - Basic friendly AI

- [ ] Turret friendly AI
- [ ] Make turret a deployable item

### v0.05 - Equipment menu to change player gear

- [ ] Multiple different player armors and weapons (already placed in inventory)
...

### v0.06 - Sound

- [ ] Walking sound on player movement
- [ ] Walking sound on enemy movement
- [ ] Wooshing sound on slash through air
- [ ] Slicing sound on slash through enemy
- [ ] Different sound dependent on rigid the attack makes contact with

### v0.0? - Basic seed-based world generation

...
