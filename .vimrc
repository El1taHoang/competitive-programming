" Credit: William Lin for many of the lines in this .vimrc (https://github.com/tmwilliamlin168/CP-YouTube/blob/master/.vimrc)
" use ':so %' to refresh .vimrc without restarting vim 
set guifont=Lucida_Console:h12
set ruler
set ts=2
set sw=2
set smartindent
set backspace=indent,eol,start

" enter fullscreen
au GUIEnter * simalt ~x

cd ~/Desktop/Desktop/coding-contests

inoremap {<CR> {<CR><BS>}<Esc>O
imap <C-BS> <C-W>
syntax enable

autocmd BufNewFile *.cpp 0r ~/main.cpp

autocmd filetype cpp nnoremap <F8> :w <bar> !g++ -g -std=c++14 % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -g -std=c++14 % -o %:r -Wl,--stack,268435456 -D DEBUG<CR>
autocmd filetype python nnoremap <F9> :w <bar> !python %:r.py<CR>
autocmd filetype cpp nnoremap <F10> :!%:r <CR>
autocmd filetype java nnoremap <F9> :w <bar> !java %:r<CR>
" Go to C:\MinGW\bin and run mingw-get.exe install gdb
autocmd filetype cpp nnoremap <F11> :w <bar> !gdb %:r<CR>

set number
augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set relativenumber
    autocmd BufLeave,FocusLost,InsertEnter * set norelativenumber
augroup END

" A list of convenient vim macros written by me. To enter special characters like escape, hit Ctrl-V and enter the special character in insert mode
let @t = '7ggoint t;cin >> t;while (t--) {ddk$'
let @a = 'oint n;cin >> n;vector<int> a(n);for (int i = 0; i < n; i++) {cin >> a[i];j'
let @f = 'ofor (int i = 0; i < n; i++) {ddk$'
let @c = 'ggO#include <climits>'
let @q = 'ggO#include <queue>'
let @l = 'ggO#include <algorithm>'
let @m = ':w:e ../../modular_arithmetic.cppggyGggOpkdd'
" Credit: Gennady Korotkevich for the idea of using #ifdef as a debugging tool
" I use Gennady Korotkevich's debug template: https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
let @d = 'ggO#ifdef DEBUG#include "../../debug.cpp"#else#define debug(...) ""#endif'
