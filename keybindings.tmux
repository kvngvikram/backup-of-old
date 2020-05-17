bind-key -n M-k display-panes \; select-pane -U
bind-key -n M-j display-panes \; select-pane -D
bind-key -n M-h display-panes \; select-pane -L
bind-key -n M-l display-panes \; select-pane -R

bind-key -n M-i resize-pane -U
bind-key -n M-u resize-pane -D
bind-key -n M-y resize-pane -L
bind-key -n M-o resize-pane -R

bind-key -n M-p previous-window
bind-key -n M-n next-window

bind-key -n M-, display-panes \; split-window -h -c "#{pane_current_path}"    
bind-key -n M-/ display-panes \; split-window -v -c "#{pane_current_path}"
bind-key -n M-. new-window -c "#{pane_current_path}" \; rename-window "-"
bind-key -n M-m copy-mode

set -g prefix F12
unbind-key -n C-a

## Smart pane switching with awareness of Vim splits.
## See: https://github.com/christoomey/vim-tmux-navigator
#is_vim="ps -o state= -o comm= -t '#{pane_tty}' \
#    | grep -iqE '^[^TXZ ]+ +(\\S+\\/)?g?(view|n?vim?x?)(diff)?$'"
#bind-key -n 'M-h' if-shell "$is_vim" 'send-keys M-h'  'select-pane -L'
#bind-key -n 'M-j' if-shell "$is_vim" 'send-keys M-j'  'select-pane -D'
#bind-key -n 'M-k' if-shell "$is_vim" 'send-keys M-k'  'select-pane -U'
#bind-key -n 'M-l' if-shell "$is_vim" 'send-keys M-l'  'select-pane -R'
#tmux_version='$(tmux -V | sed -En "s/^tmux ([0-9]+(.[0-9]+)?).*/\1/p")'
#if-shell -b '[ "$(echo "$tmux_version < 3.0" | bc)" = 1 ]' \
#	"bind-key -n 'C-\\' if-shell \"$is_vim\" 'send-keys C-\\'  'select-pane -l'"
#if-shell -b '[ "$(echo "$tmux_version >= 3.0" | bc)" = 1 ]' \
#	"bind-key -n 'C-\\' if-shell \"$is_vim\" 'send-keys C-\\\\'  'select-pane -l'"
#
#bind-key -T copy-mode-vi 'M-h' select-pane -L
#bind-key -T copy-mode-vi 'M-j' select-pane -D
#bind-key -T copy-mode-vi 'M-k' select-pane -U
#bind-key -T copy-mode-vi 'M-l' select-pane -R
##bind-key -T copy-mode-vi 'C-\' select-pane -l
