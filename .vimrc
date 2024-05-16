" Tabs
set tabstop=3
set softtabstop=3
set shiftwidth=3
set expandtab
"set number

" Try and keep columns less than 80 characters. Hilight the 80th character
" in gray
highlight ColorColumn ctermbg=gray
set colorcolumn=80

"Set the color scheme to any you like. You can see a list of them here:
"http://vimcolors.com/
"Use these commands:
"cd 
"mkdir .vim
"cd .vim
"mkdir colors
"cd colors
"git clone https://github.com/Yggdroot/duoduo
"cp duoduo/colors/duoduo.vim .
syntax on
colorscheme duoduo
" 
"Disable automatic comment insertion
"set formatoptions-=cro
au BufEnter * set fo-=c fo-=r fo-=o
