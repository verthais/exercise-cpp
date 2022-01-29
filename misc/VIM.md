# Vim

In this file I've wrote down some usefull action that might be done in vim.

## Basic .vimrc

The basic `~/.vimrc` config to use with remote hosts.

    syntax on " Enable syntax highlighting
    filetype plugin indent on " Enable file type based indentation

    set autoindent " Respect indentation when starting a new line
    set expandtab  " Expand tabs to spaces
    set tabstop=4  " Number of spaces to use for autoindent
    set hlsearch " highlighting for the seach words
    set backspace=2 " Fix backspace behaviour on most terminals

    " set directory=%USERDATA%\.vim/swap
    " set noswapfile

    colorscheme murphy

    foldmethod=indent
    " foldcolumn=N " this will dedicate the first N cols to the left of the screen to indicate folds

To check the current value of the setting just type :colorscheme?


## Actions

### Open file

    vim {path}

### Inside vim

    :e {path}    e stands for edit

### Save file

save current file or create a new one

    :w {path:optional}

create new file from existing

    :saveas {path}

save and quit

    :x

quit file

    :q

You can force any action by adding `!` after action.

### Commands keys
#### Moving around
    w      move forward by word
    e      move forward until end of word
    W      move forward by WORD
    E      move forward until end of WORD
    b      move backwards to the begining of the word
    B      move backwards to the begining of the WORD
    {      move backwards by one paragrapth
    }      move forward by one paragrapth
    '.     jump to last edited place
    :{no}  jump to line {no}
    {no}gg jump to line {no}

#### Markers
    m{name}    creates marker {name} at current location
    '{name}    jumps to line of marker {name}
    `{name}    jumps to line and column of marker {name}
    d'{name}   delete from current line to marker {name}
    d`{name}
    c'{name}
    y`{name}
    :marks {name[, name...]:optional}
               list all (current) markers

### Edit keys

#### Activate insert mode
    a    after the cursor position
    A    at the end of the line
    I    at the begining of the line respecting indentation
    o    adding empty line after the cursor
    O    adding empty line before the cursor
    gi   where it was last exited

#### Delete/Change existing text
    c[hange]  removes set ammount of chars and enters insert mode (i.e. c4l
              removes 4 letters, cb removes letters up to begining of word)
    C         deletes the text to the right of the cursor
    cc[lear]  clears line and enters insert mode
    d[elete]  deletes characters
    di)       deletes text inside parentheses
    dd        deletes line
    r[eplace] replaces the charachter under cursor
    u[ndo]    undo one change


### Folding blocks of text/code

    zo   open current fold
    zc   close current fold
    za   toggle fold
    zR   open all of the folds
    zM   close all of the folds


### Schema for edition

verb number    adjective    Noun

d   i[nside]    )[parentheses]
c 2   a[outside]   w[ord]



### Coping, Pasting and Registers[a-z]

    y    yank (copy)
    d    cut
    p    paste
    "ayw yank text to register a
    "ap  paste text from register a



### Buffers

```
b[uffer]{number}    switch active buffer to {number}
b[uffer]{str}       try to match {str} with open buffers and switch active
                    buffer to match
ls                  list all loaded buffers
bd                  buffer delete
:sp[lit]            split horizontaly active buffer plane between two buffers
:vs[plit]           split vertically active buffer plane between two buffers
:res[ize]           +/-N increase/decrease the window row/col by the N rows/cols
ctrl+w -/+ ~        by one
:res[ize] vert[ical] +/-N
ctrl+w >/< ~        by one
ctrl+w arrow/hjkl   move to the window in the direction of arrow/hjkl
ctrl+w o/:on[ly]    will close all the buffers except the active
ctrl+w r            moves every window in the row/col to the right
ctrl+w x            exchanges the contents of a window with the next one
```

### Searching through files

    :vimgrep
    :grep
    :cn     next match
    :cp     prev match
    :copen  open a visual quickfix window
    :%s/{patter}/{replace}/gc    find globally(g) all(%) string (s) matching
            {pattern} and replace it with {replace} with confirmation (c)


### Plugins

#### Installation

    mkdir -p ~/.vim/pack/plugins/start
    add to the .vimrc
    packloadall " Load all plugins
    silent! helptags ALL " Load help files for all plugins

#### download plugin

    git clone https://github.com/scrooloose/nerdtree.git ~/.vim/pack/plugins/start/nerdtree

    git clone https://github.com/tpope/vim-unimpaired ~/.vim/pack/plugins/start/vim-unimpaired

## Final note

Use `:help` a lot. Most if not all the answers are right there.
