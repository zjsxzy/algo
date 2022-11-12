set re=1
set ttyfast
set lazyredraw
set nocompatible
set syntax=on
set autoindent
set tabstop=4
set softtabstop=4
set shiftwidth=4
set number
set nobackup
set noswapfile
set ruler
set splitbelow
set splitright
set langmenu=zh_CN.UTF-8
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
language messages zh_CN.utf-8
set helplang=cn
filetype indent on
filetype plugin on
syntax enable
"color slate
colorscheme molokai
if has("gui_running")
  " Set a nicer font.
  set guifont=Consolas:h12:cDEFAULT
  " Hide the toolbar.
  set guioptions-=T
endif
inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {<CR>}<ESC>O
map <F2> gg"+yG
map <F3> "+P

map<f4> :call AddComment()<cr>
func AddComment()
    if matchstr(getline('.'), '[^ ]') == '/'
        normal ^xx
    else
        normal ^i//
    endif
endfunc

map <F5> :call CompileGcc()<CR>
func! CompileGcc()
exec "w"
exec "!g++ % -std=c++17 -O2"
endfunc

map <F12> :call SetTitle()<CR>Gkkk
func SetTitle()
let l = 0
let l = l + 1 | call setline(l, '#include <bits/stdc++.h>')
let l = l + 1 | call setline(l, 'using namespace std;')
let l = l + 1 | call setline(l, 'typedef long long LL;')
let l = l + 1 | call setline(l, '')
let l = l + 1 | call setline(l, 'void solve() {')
let l = l + 1 | call setline(l, '}')
let l = l + 1 | call setline(l, '')
let l = l + 1 | call setline(l, 'int main() {')
let l = l + 1 | call setline(l, '#ifndef ONLINE_JUDGE')
let l = l + 1 | call setline(l, '    freopen("in.txt", "r", stdin);')
let l = l + 1 | call setline(l, '#endif')
let l = l + 1 | call setline(l, '    int ts = 1;')
let l = l + 1 | call setline(l, '    // cin >> ts;')
let l = l + 1 | call setline(l, '    for (int t = 1; t <= ts; t++) {')
let l = l + 1 | call setline(l, '       solve();')
let l = l + 1 | call setline(l, '    }')
let l = l + 1 | call setline(l, '    return 0;')
let l = l + 1 | call setline(l, '}')
let l = l + 1 | call setline(l, '')
endfunc

vmap <C-c> :w! ~/.vimbuffer \| !cat ~/.vimbuffer \| clip.exe <CR><CR>
map <C-v> :r ~/.vimbuffer<CR>
