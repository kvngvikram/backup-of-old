"""""""""""""""""""""""""""""   vim-plug   """""""""""""""""""""""""""""
" refer: https://github.com/junegunn/vim-plug
" vim-plug auto install if not installed 
if empty(glob('~/.vim/autoload/plug.vim'))
	silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
				\https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
	call plug#begin()    " This line not found in the github (presently when writing this)
	autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif
" For new plugins add them to the list
call plug#begin('~/.vim/plugged')
Plug 'https://github.com/ajh17/VimCompletesMe'
Plug 'jupyter-vim/jupyter-vim' 		" refer : https://github.com/wmvanvliet/jupyter-vim
call plug#end()
" To install new plugins enter this command once vim in opened 
" :PlugInstall


" This is to have a bash like autocomplete
set completeopt=menu,longest

" dictionary path
set dictionary+=/usr/share/dict/british-english

set nu rnu
set cursorline
set ruler


" always show statusline
set laststatus=2
set statusline=\ %F\ »\ %h%m%r\ %y%=\ %n\ »\ %-10.(%l,%c%V%)\ →\ %P

set smarttab
set tabstop=4
set shiftwidth=4
 
filetype plugin on 
filetype plugin indent on 
set autoindent
set smartindent

" Echo commands as they are being entered
set showcmd

syntax on
set background=dark
"color slate

" Disable beeping
set noerrorbells
" flash the screen for bell
"set visualbell 

" while searching jump to match
set incsearch
set hlsearch

" change the current working directory whenever you open a file, switch,delete buffer or open/close a window
set autochdir


"""""""""""""""""""""""""""""   mappings   """""""""""""""""""""""""""""
" mapping Esc key to ;; in insert mode and also save the file and just Esc in
" Visual mode
inoremap ;; <Esc>:w<CR><Esc>
vnoremap ;; <Esc><Esc>
nnoremap ;; <Esc><Esc>
" mapping , to showing .vimrc file in normal mode 
nnoremap , :tabnew ~/.vimrc<ENTER>
"Map j,k so that it will move DOWN,UP line by line for long wrapped lines.
nnoremap j gj
nnoremap k gk
" Mapping for navigation using relative numbers when lines are wrapped
" cant use <number>j when j is mapped to gj above. Refer: https://vi.stackexchange.com/a/16944
nnoremap <expr> j v:count == 0 ? 'gj' : "\<Esc>".v:count.'j'
nnoremap <expr> k v:count == 0 ? 'gk' : "\<Esc>".v:count.'k'
""""""""""""""""""jupyter-vim plugin mappings""""""""""""""""""
" There are default mappings for jupyter-vim aswell
" These are only for .py files
" open jupiter qtconsole and connect to it. Note: no spaces before \
" qtconsole can be opened with configurations, refer ~/.jupyter/jupyter_qtconsole_config.py
autocmd BufReadPost,BufNewFile *.py, 
			\nnoremap ^ :!jupyter qtconsole --JupyterWidget.syntax_style="paraiso-dark"&<ENTER>
			\:sleep 500m <ENTER>
			\:JupyterConnect<ENTER>
autocmd BufReadPost,BufNewFile *.py, nmap m V<Plug>JupyterRunVisual
autocmd BufReadPost,BufNewFile *.py, vmap m <Plug>JupyterRunVisual
autocmd BufReadPost,BufNewFile *.py, nmap & oclear<Esc>V<Plug>JupyterRunVisualddk:w<CR>
autocmd BufReadPost,BufNewFile *.py, nmap mqt o%matplotlib<Space>qt<Esc>V<Plug>JupyterRunVisualddk:w<CR>
""""""""""""""""""     tex file mappings     """"""""""""""""""
autocmd BufReadPost,BufNewFile *.tex, inoremap ;q <Esc>:w<CR><Esc>:!pdflatex %<CR><CR>
autocmd BufReadPost,BufNewFile *.tex, nnoremap ;q <Esc>:w<CR><Esc>:!pdflatex %<CR><CR>

"""""""""""""""""""""""""""""   filetype   """""""""""""""""""""""""""""
function! Text_file_commands()
	"syntax might not work with spell
	syntax off
	" enable the spell check
	set spell  
	" disable the cursorline
"	set nocursorline 
"	hi clear SpellBad
"	hi SpellBad cterm=underline
	" replace a word with the first suggestion from dictionary
	nnoremap m z=1<ENTER><ENTER> 
	" Lines from
	" http://www.panozzaj.com/blog/2016/03/21/ignore-urls-and-acroynms-while-spell-checking-vim/
	" Donn't mark URL-like things as spelling errors
	syn match UrlNoSpell '\w\+:\/\/[^[:space:]]\+' contains=@NoSpell
	" Don't count acronyms / abbreviations as spelling errors
	" (all upper-case letters, at least three characters)
	" Also will not count acronym with 's' at the end a spelling error
	" Also will not count numbers that are part of this
	" Recognizes the following as correct:
	syn match AcronymNoSpell '\<\(\u\|\d\)\{3,}s\?\>' contains=@NoSpell
endfunction
" execute the following for some particular files
autocmd BufReadPost,BufNewFile *.txt, call Text_file_commands()
