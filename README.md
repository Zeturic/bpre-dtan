## Dynamic Trade Animation Names

`special 0xFE` is what does the trade animation; it trades the Pokemon stored at `0x0202402C` for the Pokemon in the `var_8005`th slot in the player's party.

If you dynamically generate a Pokemon there and trade for it, there'll be a small bug. Specifically, the messages during the trade will be messed up - it reads the Pokemon's nickname and trainer's name out of the `var_8004`th entry in the in-game trade table. If `var_8004` happened to be `0`, the game will tell you about how "Reyley sent over Mimien", even if that's not what's being traded.

This changes the code responsible for setting up those buffers to read from the data at `0x0202402C`, to correct that. With this, the following will work.

```
// something to put the other trainer's Pokemon at 0x0202402C
// something to set `var_8005` with the party slot of the player's Pokemon

special 0xFE
```

Also, it now supports simply specifying a name for the trainer, so you can have them trade over a Pokemon they're not the OT of.

```
// something to put the other trainer's Pokemon at 0x0202402C
// something to set `var_8005` with the party slot of the player's Pokemon

setvar 0x8004 0xFFFF
bufferstring 0 @name
special 0xFE
```

### Build Instructions

See [here](https://gist.github.com/Zeturic/db1611cc7b17c3140f9b9af32e1b596b) for the prequisites and help in installing them.

#### Cloning the repo and building the tools

Open your terminal to whatever folder you want to download this repo into. Then, do the following to download the repo and build the included tools:

```shell
$ git clone https://github.com/Zeturic/bpre-dtan.git
$ cd bpre-dtan
$ ./build_tools.sh
```

#### Adding your ROM

Copy your ROM to this directory and rename it `rom.gba`.

#### Configuration

The build system is smart enough to find enough free space on its own, but if you want it to be inserted at a particular address, you can specify it by updating the definition of `START_AT` in `config.mk`.

If the given address is acceptable (i.e. is word-aligned and has enough bytes of free space), it will be inserted there. Otherwise, it will just use `START_AT` to determine where in the ROM it should start looking for free space.

#### Building the project itself

Once you're ready, run the following to build the project:

```shell
make
```

This won't actually modify `rom.gba`, instead your output will be in `test.gba`. Naturally, test it in an emulator.

### Credits

The project structure and some of the build tools are from [pokeemerald](https://github.com/pret/pokeemerald).
