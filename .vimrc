call plug#begin()
   Plug 'preservim/nerdtree'
   Plug 'ryanoasis/vim-devicons'
   Plug 'chiel92/vim-autoformat'
call plug#end()

"requirements 3270Medium Nerd Font or Agave Font for devicons"

"OPEN NERDTREE EXTENSION WHEN STARTING VIM"
"autocmd vimenter * NERDTree"

autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif

autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists("s:std_in") | exe 'NERDTree' argv()[0] | wincmd p | ene | exe 'cd '.argv()[0] | endif

map <C-n> :NERDTreeToggle<CR>
let g:NERDTreeWinSize=35
let NERDTreeShowHidden=1

"CHANGE TAB"
map <C-l> :tabn<CR>
map <C-h> :tabp<CR>

"ESC ALTERNATIVE"
inoremap <C-K> <Esc>

"LINE NUMBER"
set number

"TAB SHIFT. INDENT"
set tabstop=3 softtabstop=3 shiftwidth=3 expandtab

"DISABLE SWAP FILE CREATING"
set noswapfile

"COLOR SCHEME"
colo async 

"DISABLE KEY"
for key in ['<Up>', '<Down>', '<Left>', '<Right>']
   exec 'noremap'  key '<NOP>' 
   exec 'inoremap' key '<Nop>'
   exec 'cnoremap' key '<Nop>'
endfor

inoremap <ESC> <NOP>

"GIT EXTENSION"
noremap <F2> :GitGutterEnable<CR>
noremap <F3> :GitGutterDisable<CR>

"AUTO FORMAT"
noremap <F4> :Autoformat<CR>

inoremap " ""<left>
inoremap ' ''<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O


inoremap <C-e> <C-o>A
inoremap <S-Tab> <esc>la
