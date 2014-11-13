set autoread
syntax on
set number
" filetype ident on
"set autoindent
set expandtab
set cindent
set shiftwidth=4
autocmd FileType make setlocal noexpandtab

set tabstop=4
set showmatch
set matchtime=1
set smartindent
set scrolloff=3
set nocompatible   "no vim compatible
set encoding=utf-8
set fileencoding=utf-8
"set cursorline
set backspace=2
" f2 save file
map <F2> :w<CR>
" f5 compile fun
map <F5> :call CompileRun()<CR>
func! CompileRun()
    if &filetype == 'c'
        exec "!gcc -std=c99 % -o %<.out && ./%<.out"
    elseif &filetype == 'cpp'
        exec "!g++ -std=c++11 % -o %<.out && ./%<.out"
    elseif &filetype == 'sh'
        :!./%
    endif
endfunc

"gvim解决菜单乱码
language messages zh_CN.utf-8
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim

" miniBuf config
let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapWindowNavArrows = 1
let g:miniBufExplMapCTabSwitchBufs = 1
let g:miniBufExplModSelTarget = 1

" 把空格键映射成:
nmap <space> :
" 判断操作系统
if (has("win32") || has("win64") || has("win32unix"))
    let g:isWin = 1
else
    let g:isWin = 0
endif 
" 判断是终端还是gvim
if has("gui_running")
    let g:isGUI = 1
else
    let g:isGUI = 0
endif
if (g:isGUI)
    set cursorline
"    colorscheme wombat
    hi cursorline guibg=#333333
    hi CursorColumn guibg=#333333
    set guifont=YaHei\ Consolas\ Hybrid\ 12
    set mouse=a
endif
set laststatus=2      " 总是显示状态栏
" 用c-j,k在buffer之间切换
nn <C-J> :bn<cr>
nn <C-K> :bp<cr>
" Bash(Emacs)风格键盘绑定
imap <C-e> <END>
imap <C-a> <HOME>
"从系统剪切板中复制，剪切，粘贴
map <C-c> "+y
"map <F8> "+x
map <C-v> "+p

" 插件窗口的宽度，如TagList,NERD_tree等，自己设置
let s:PlugWinSize = 25
" NERD tree
" http://www.vim.org/scripts/script.php?script_id=1658
let NERDTreeShowHidden = 1
let NERDTreeWinPos = "left"
let NERDTreeWinSize = s:PlugWinSize 
nmap <leader>n :NERDTreeToggle<cr>

