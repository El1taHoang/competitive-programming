" Credit: William Lin for many of the lines in this .vimrc (https://github.com/tmwilliamlin168/CP-YouTube/blob/master/.vimrc)
" use ':so %' to refresh .vimrc without restarting vim 
set guifont=Lucida_Console:h12
set ruler
set ts=2
set sw=2
set smartindent
set backspace=indent,eol,start

syntax enable

" Enter fullscreen
au GUIEnter * simalt ~x

cd ~/Desktop/Desktop/coding-contests

inoremap {<CR> {<CR><BS>}<Esc>O

imap <C-BS> <C-W>

autocmd filetype c nnoremap <F9> :w <bar> !cls && gcc -g -O2 % -o %:r -Wl,--stack,268435456 && echo C File Compiled<CR>
autocmd filetype c nnoremap <F10> :!cls && Echo Input: && %:r<CR>
autocmd filetype cpp nnoremap <F6> :w:!cls && powershell -command "Get-Clipboard" > input.txt && echo Compiling... && g++ -g -O2 -std=c++17 % -o %:r -Wl,--stack,268435456 -D DEBUG && echo. && echo ------------- Input ------------- && type input.txt && echo ------------- Output ------------- && %:r < input.txt && echo ---------------------------------- && del input.txt
autocmd filetype cpp nnoremap <F7> :!cls && powershell -command "Get-Clipboard" > input.txt && echo. && echo ------------- Input ------------- && type input.txt && echo ------------- Output ------------- && %:r < input.txt && echo ---------------------------------- && del input.txt
autocmd filetype cpp nnoremap <F8> :w <bar> !cls && g++ -g -O2 -std=c++17 % -o %:r -Wl,--stack,268435456 && echo C++ File Compiled<CR>
autocmd filetype cpp nnoremap <F9> :w <bar> !cls && g++ -g -O2 -std=c++17 % -o %:r -Wl,--stack,268435456 -D DEBUG && echo C++ File Compiled With Debug<CR>
autocmd filetype python nnoremap <F9> :w <bar> !cls && echo Input: && python %:r.py<CR>
autocmd filetype cpp nnoremap <F10> :!cls && Echo Input: && %:r<CR>
autocmd filetype java nnoremap <F9> :w <bar> !cls && java %:r<CR>
" Go to C:\MinGW\bin and run mingw-get.exe install gdb
" To use gdb, use the commands run and backtrace
autocmd filetype cpp nnoremap <F11> :w <bar> !cls && gdb %:r<CR>

set number
augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set relativenumber
    autocmd BufLeave,FocusLost,InsertEnter * set norelativenumber
augroup END

" A list of actions that occur automatically when you enter a file. These were written by Aaron He (me).
autocmd BufNewFile *.cpp 0r ~/main.cpp 
autocmd BufNewFile *.cpp norm ggO// Author: Aaron He// Created: :put=strftime('%e %B %Y (%A)')kJGddk

" autocmd BufNewFile *.py norm ggO# Author: Aaron He# Created: :put=strftime('%A, %d %B %Y, %X %z')kJG
autocmd BufNewFile *.py norm ggO# Author: Aaron He# Created: :put=strftime('%A, %e %B %Y')kJG

" A list of convenient vim macros written by Aaron He (me). To enter special characters like escape, hit Ctrl-V and enter the special character in insert mode
let @t = 'oint t;cin >> t;while (t--) {ddk$'
let @a = 'oint n;cin >> n;vector<int> a(n);for (int i = 0; i < n; i++) {cin >> a[i];j'
let @c = ':%y+'
let @f = 'ofor (int i = 0; i < n; i++) {ddk$Fn'
let @l = '2ggo#include <algorithm>#include <climits>'
let @q = '2ggo#include <queue>'
" Credit: Gennady Korotkevich for the idea of using #ifdef as a debugging tool
" I use Gennady Korotkevich's debug template: https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
let @d = '/using namespace stdo#ifdef DEBUG#include "../../debug.cpp"#else#define debug(...)#endif'
let @g = 'oint n, m;cin >> n >> m;vector<vector<int>> adj(n);for (int i = 0; i < m; i++) {int u, v;cin >> u >> v;u--, v--;adj[u].push_back(v);adj[v].push_back(u);j'
nnoremap <nowait> \fio /int main<CR>oios_base::sync_with_stdio(0);<CR>cin.tie(0);<Esc>
nnoremap \mod :w:e ../../modular_arithmetic_2.cpp/includeyG/using namespace stdopkddGk/static const int mod = 1e9 + 7<CR>^
nnoremap \oldmod :w:e ../../modular_arithmetic.cppggyG/using namespace stdopkdd/int main/MOD = 1e9 + 7<CR>^
nnoremap \prime :w:e ../../prime.cppggyG/using namespace stdopkdd
nnoremap \segtree :w:e ../../segment_tree.cppggyG/using namespace stdopkdd
nnoremap \arr oint n;cin >> n;vector<int> a(n);for (int i = 0; i < n; i++) {cin >> a[i];}
nnoremap \test oint t;cin >> t;while (t--) {ddk$
nnoremap \alg 2ggo#include <algorithm>
nnoremap \clim 2ggo#include <climits>
nnoremap \debug /using namespace stdo#ifdef DEBUG#include "../../debug.cpp"#else#define debug(...)#endif
nnoremap \rand 2ggo#include <chrono><CR>#include <random><esc>/int main<CR>omt19937 rng(chrono::steady_clock::now().time_since_epoch().count());<esc>
nnoremap \set 2ggo#include <set><esc>
nnoremap \que 2ggo#include <queue><esc>
nnoremap \map 2ggo#include <map><esc>
nnoremap \cass 2ggo#include <cassert><esc>
