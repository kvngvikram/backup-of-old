" Things to note: 
"
" Reserved Registers:
" z - temporary register
" r - is used for General_Vimux_mapping
"
" Reserved marks:
" z - temporary mark
" i - <Leader>i mapping to insert at last edited location
"
" This configuration assumes that vim is running inside a tmux session (while
" writing this, byobu is used instead of tmux).
" 
" There are mappings to directly open this file in new tab 
" 'kj' is mapped to escape and save the file.
"
" <Enter> or <CR> key is used in mappings assuming that it is not of much use
" in normal and visual mode. For the rest of the mappings a Leader key is used
" which can be changed. 


"""""""""""""""""""""""""""""   vim-plug   """""""""""""""""""""""""""""
" refer: https://github.com/junegunn/vim-plug
" vim-plug auto install if not installed 
if empty(glob('~/.vim/autoload/plug.vim'))
	" !curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
	!wget -P ~/.vim/autoload/ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim 
	call plug#begin()    " This line not found in the github (presently when writing this)
	autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif



"""""""""""""""""""""""""""""    plugins   """""""""""""""""""""""""""""
" For new plugins add them to the list
call plug#begin('~/.vim/plugged')

Plug 'https://github.com/ycm-core/YouCompleteMe'
Plug 'https://github.com/ajh17/VimCompletesMe'

Plug 'benmills/vimux'
Plug 'jupyter-vim/jupyter-vim' 		" refer : https://github.com/jupyter-vim/jupyter-vim
Plug 'julienr/vim-cellmode'
"Plug 'ivanov/vim-ipython'

"Plug 'goerz/jupytext.vim'

Plug 'scrooloose/nerdtree'
Plug 'jistr/vim-nerdtree-tabs'

Plug 'christoomey/vim-tmux-navigator'

Plug 'vim-airline/vim-airline'
"Plug 'powerline/powerline'

Plug 'vim-scripts/SyntaxRange'
call plug#end()
" To install new plugins enter this command once vim in opened 
" :PlugInstall



"""""""""""""""""""""""""""""   general    """""""""""""""""""""""""""""
"let mapleader = ","
let mapleader = "\<Space>"

" This is to have a bash like autocomplete
" set completeopt=menu,longest
set completeopt+=longest

""""""""""""""""""""""""""""" YCM
let g:ycm_autoclose_preview_window_after_insertion = 1

""""""""""""""""""""""""""""" cellmode
let g:cellmode_default_mappings='0'

""""""""""""""""""""""""""""" cellmode
let g:jupyter_mapkeys='0'

""""""""""""""""""""""""""""" NERDTree-tabs
nnoremap <Leader>t :NERDTreeTabsToggle<CR>

""""""""""""""""""""""""""""" vim-tmux-navigator
let g:tmux_navigator_no_mappings = 1
nnoremap <C-h> :TmuxNavigateLeft<cr>
nnoremap <C-j> :TmuxNavigateDown<cr>
nnoremap <C-k> :TmuxNavigateUp<cr>
nnoremap <C-l> :TmuxNavigateRight<cr>

""""""""""""""""""""""""""""" SyntaxRange
" For python in .sh scripts
autocmd BufReadPost,BufNewFile *.sh, :call SyntaxRange#Include('#python_begin','#python_end','python','NonText')

" dictionary path
set dictionary+=/usr/share/dict/british-english

set nu rnu
set cursorline
set ruler

" always show statusline
"set laststatus=2
"set statusline=\ %F\ »\ %h%m%r\ %y%=\ %n\ »\ %-10.(%l,%c%V%)\ →\ %P

set smarttab
set tabstop=4
set shiftwidth=4
 
let fortran_free_source=1
let fortran_do_enddo=1
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
" mapping Esc key in insert mode and also save the file and just Esc in
" Also mark the location with 'i'
inoremap kj <Esc>:w<CR>mi
" Insert at the last inserted position
nnoremap <Leader>i `ia

vnoremap <Leader><Leader> <Esc><Esc>
nnoremap <Leader><Leader> <Esc>:w<CR><Esc>
" mapping , to showing .vimrc file in normal mode 
nnoremap <Leader>, :tabnew ~/.vimrc<ENTER>

" Map j,k so that it will move DOWN,UP line by line for long wrapped lines.
" Also Mapping for navigation using relative numbers when lines are wrapped
" Refer: https://vi.stackexchange.com/a/16944
nnoremap <expr> j v:count == 0 ? 'gj' : "\<Esc>".v:count.'j'
nnoremap <expr> k v:count == 0 ? 'gk' : "\<Esc>".v:count.'k'

" General_Vimux_mapping
nnoremap <Leader>r :call VimuxRunCommand(@r)<CR>

" for warpping lines
nnoremap <Leader>w :set wrap!<CR>

" Visual search
vnoremap // "zy/\V<C-R>=escape(@z,'/\')<CR><CR>
" for '\V' refer :help /\V

" Toggle spell check 
nnoremap <Leader>sp :set spell!<CR>
" Toggle syntax coloring
nnoremap <Leader>sn :if exists("g:syntax_on") <Bar>
			\	syntax off <Bar>
			\else <Bar>
			\	syntax on <Bar>
			\endif <CR><CR>




"""""""""""""""""""""""""""""   tex_file   """""""""""""""""""""""""""""
"autocmd BufReadPost,BufNewFile *.tex, inoremap <Leader>q <Esc>:w<CR><Esc>:!pdflatex %<CR><CR>
"autocmd BufReadPost,BufNewFile *.tex, nnoremap <Leader>q <Esc>:w<CR><Esc>:!pdflatex %<CR><CR>

function! Tex_file_commands()
"	inoremap <Leader>q <Esc>:w<CR><Esc>:!pdflatex %<CR><CR>
	nnoremap <Leader>q <Esc>:w<CR><Esc>:!pdflatex %<CR><CR>:!pdflatex %<CR><CR>
	nnoremap <Leader>r <Esc>:w<CR><Esc>:call VimuxRunCommand("pdflatex ".@%." && bibtex ".@%[0:-5].".aux && pdflatex ".@%." && pdflatex ".@%." && exit")<CR><CR>
endfunction
autocmd BufReadPost,BufNewFile *.tex, :call Tex_file_commands()


"""""""""""""""""""""""""""""  text_file   """""""""""""""""""""""""""""
function! Text_file_commands()
	"syntax might not work with spell
	"syntax off
	" enable the spell check
	set spell  
	" disable the cursorline
"	set nocursorline 
"	hi clear SpellBad
"	hi SpellBad cterm=underline
	" replace a word with the first suggestion from dictionary
	nnoremap <CR> z=1<ENTER><ENTER> 
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
	" Jump to next and previous misspelled words
	nnoremap <Leader>n ]s
	nnoremap <Leader>p [s
endfunction
" execute the following for some particular files
autocmd BufReadPost,BufNewFile *.txt, call Text_file_commands()

"""""""""""""""""""""""""""""   py_file    """""""""""""""""""""""""""""
function! Python_file_commands()
	" The following is for ease of writing py2nb compactable codes.
	nmap <Leader>o o#\|<Space>
	nmap <Leader>O O#\|<Space>
endfunction
" execute the following for some particular files
autocmd BufReadPost,BufNewFile *.py, call Python_file_commands()


"""""""""""""""""""""""""""""    Vimux     """""""""""""""""""""""""""""
" Function that can be called for Vimux
function! Vimux_commands()
	let g:VimuxOrientation = "h" 	" Open a new tmux pane to the right
	let g:VimuxHeight = "40"	" This is percentage

	nnoremap <Leader>^ :call VimuxOpenRunner()<CR>:call VimuxRunCommand("cd ".getcwd())<CR>
	nnoremap <CR> mz0v$h"zy:call VimuxRunCommand(@z)<CR><Esc>`z
	vnoremap <CR> "zy:call VimuxRunCommand(@z)<CR>
	nmap <Leader>i <Esc>:VimuxInterruptRunner<CR>
endfunction
autocmd BufReadPost,BufNewFile *.sh, call Vimux_commands()


""""""""""""""""""""""""""""" Jupyter-vim  """""""""""""""""""""""""""""
"function! Jupyter_vim_qtconsole_commands()
"	" open jupiter qtconsole and connect to it. Note: no spaces before \
"	" qtconsole can be opened with configurations, refer ~/.jupyter/jupyter_qtconsole_config.py
"	nnoremap <Leader>^ :!jupyter qtconsole --JupyterWidget.syntax_style="paraiso-dark" --JupyterWidget.font_size=12&<ENTER>
"				\:sleep 500m <ENTER>
"				\:JupyterConnect<ENTER>
"	nmap <CR> V<Plug>JupyterRunVisual
"	vmap <CR> <Plug>JupyterRunVisual
"	nmap & oclear<Esc>V<Plug>JupyterRunVisualddk:w<CR>
"	nmap <Leader>qt o%matplotlib<Space>qt<Esc>V<Plug>JupyterRunVisualddk:w<CR>
"	nmap <Leader>q :JupyterRunFile<CR>
"endfunction


""""""""""""""""""""""""""""" JPy_console  """""""""""""""""""""""""""""
"" Note : this needs both jupyter-vim/jupyter-vim and benmills/vimux
function! Jupyter_vim_console_commands()
	let g:VimuxOrientation = "h" 	" Open a new tmux pane to the right
	let g:VimuxHeight = "40"	" This is percentage

	" open jupiter console and connect to it. Note: no spaces before \
	nnoremap <Leader>^ :call VimuxRunCommand("cd ".getcwd())<CR>
				\:call VimuxRunCommand("jupyter console")<CR>
				\:call VimuxRunCommand("%matplotlib qt")<CR>
				\:sleep 500m<CR>
				\:JupyterConnect<CR>

	"nmap <CR> mzV:JupyterSendRange<CR>:sleep 20m<CR>:call VimuxSendKeys("Enter")<CR>`z
	nnoremap <CR> mz0v$h"zy:call VimuxSendText(@z)<CR>:call VimuxSendKeys("M-Enter")<CR><Esc>`z
	"nmap <CR> V<Plug>JupyterRunVisual:call VimuxSendKeys("Enter")<CR>
	"vmap <Leader><CR> <Plug>JupyterRunVisual:sleep 20m<CR>:call VimuxSendKeys("Enter")<CR>
	vmap <Leader><CR> <Plug>JupyterRunVisual
	vnoremap <CR> "zy:call VimuxSendText(@z)<CR>:call VimuxSendKeys("M-Enter")<CR>
	"vnoremap <CR> "zy:call VimuxSendText(@z)<CR>:call VimuxSendKeys("Enter")<CR>
	"vnoremap <CR> "zy:call VimuxRunCommand(@z)<CR>

	"" Here the Vimux command is not used along with jupyter-vim, because if the time taken to run the cell is high then additional Vimux <Enter> with raise a warning. And if that happens then in ipython each time to enter a line (manually), <Enter> should be pressed 3 times (or Alt+Enter or Ctrl+o should be used).
	"nmap <Leader><CR> mzVgg:JupyterSendRange<CR>`z
	""nmap <Leader>q :JupyterRunFile<CR>
	"nmap <Leader>r :call VimuxRunCommand("%run -i ".getcwd()."/".@%)<CR>:call VimuxSendKeys("C-o")<CR>
	
	" cellmode
	let g:cellmode_default_mappings='0' 	" disable the default mappings
	let g:cellmode_tmux_panenumber='1'

	nnoremap <Leader>r mzggVG:call RunTmuxPythonChunk()<CR>:call VimuxSendKeys("M-Enter")<CR>`z
	nnoremap <Leader><CR> mzVgg:call RunTmuxPythonChunk()<CR>:call VimuxSendKeys("M-Enter")<CR>`zzz
	
	"nmap <Leader>qt o%matplotlib<Space>qt<Esc>V<Plug>JupyterRunVisualddk:w<CR>:call VimuxSendKeys("Enter")<CR>
	nmap <Leader>qt :call VimuxRunCommand("%matplotlib qt")
	nnoremap <Leader>& :call VimuxSendText("clear")<CR>:call VimuxSendKeys("M-Enter")<CR>

endfunction


""""""""""""""""""""""""""""" vim-cellmode """""""""""""""""""""""""""""
"let g:cellmode_default_mappings='0' 	" disable the default mappings
"let g:cellmode_tmux_panenumber='0'
"function! Cellmode_commands()
"	vmap <CR> :call RunTmuxPythonChunk()<CR>
"	nmap <CR> 0v$h:call RunTmuxPythonChunk()<CR>
"endfunction


"autocmd BufReadPost,BufNewFile *.py, call Vimux_python_commands()
"autocmd BufReadPost,BufNewFile *.py, call Jupyter_vim_qtconsole_commands()
autocmd BufReadPost,BufNewFile *.py, call Jupyter_vim_console_commands()



