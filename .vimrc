call plug#begin()
   Plug 'preservim/nerdtree'
call plug#end()



"NERDTree"
"autocmd vimenter * NERDTree"
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif

autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists("s:std_in") | exe 'NERDTree' argv()[0] | wincmd p | ene | exe 'cd '.argv()[0] | endif

map <C-n> :NERDTreeToggle<CR>
let g:NERDTreeWinSize=30
let NERDTreeShowHidden=1

"Change tab"
map  <C-l> :tabn<CR>
map  <C-h> :tabp<CR>

"ESC alternative"
inoremap <C-Space> <Esc>

set tabstop=3 softtabstop=3 shiftwidth=3 expandtab
set noswapfile
colo pablo

"disable arrow keys"
noremap <Up> <Nop>
noremap <Down> <Nop>
noremap <Left> <Nop>
noremap <Right> <Nop>


noremap! <Leader>h <left>   "move cursor left"
noremap! <Leader>j <down>   "move cursor down"
noremap! <Leader>k <up>     "move cursor up"
noremap! <Leader>l <right>  "move cursor right"
noremap! <Leader>w <esc>wi  "move one word forward"
noremap! <Leader>e <esc>ei  "move forward to the end of word"
noremap! <Leader>b <esc>bi  "move one word backward"
